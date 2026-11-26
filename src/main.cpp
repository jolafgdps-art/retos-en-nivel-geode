#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include <array>
#include <chrono>
#include <random>

using namespace geode::prelude;

namespace {
    constexpr std::array<char const*, 10> CHALLENGES = {{
        "Reto: no uses el modo practica.",
        "Reto: llega al 20% sin morir.",
        "Reto: no pulses el boton de practica.",
        "Reto: completa este intento sin pausar.",
        "Reto: consigue una moneda secreta.",
        "Reto: supera tu mejor porcentaje.",
        "Reto: no mantengas pulsado durante todo el intento.",
        "Reto: termina el nivel sin usar checkpoints.",
        "Reto: llega al siguiente portal sin morir.",
        "Reto: juega este nivel con calma."
    }};

    char const* randomChallenge() {
        static std::mt19937 generator([] {
            auto now = std::chrono::steady_clock::now().time_since_epoch();
            return static_cast<std::mt19937::result_type>(
                std::chrono::duration_cast<std::chrono::nanoseconds>(now).count()
            );
        }());

        std::uniform_int_distribution<size_t> distribution(0, CHALLENGES.size() - 1);
        return CHALLENGES[distribution(generator)];
    }
}

class $modify(RetosPlayLayer, PlayLayer) {
    struct Fields {
        bool attemptStarted = false;
        bool levelCompleted = false;
        bool resultShown = false;
    };

    void showChallengeResult(bool completed) {
        if (m_fields->resultShown) {
            return;
        }

        m_fields->resultShown = true;
        Notification::create(
            completed ? "Reto completado" : "Reto no completado",
            NotificationIcon::Info,
            NOTIFICATION_LONG_TIME
        )->show();
    }

    void onEnterTransitionDidFinish() {
        PlayLayer::onEnterTransitionDidFinish();

        m_fields->attemptStarted = true;
        m_fields->levelCompleted = false;
        m_fields->resultShown = false;

        Notification::create(
            randomChallenge(),
            NotificationIcon::Info,
            NOTIFICATION_LONG_TIME
        )->show();
    }

    void levelComplete() {
        m_fields->levelCompleted = true;
        showChallengeResult(true);
        PlayLayer::levelComplete();
    }

    void resetLevel() {
        if (m_fields->attemptStarted && !m_fields->levelCompleted) {
            showChallengeResult(false);
        }

        PlayLayer::resetLevel();
    }

    void onQuit() {
        if (m_fields->attemptStarted && !m_fields->levelCompleted) {
            showChallengeResult(false);
        }

        PlayLayer::onQuit();
    }
};
