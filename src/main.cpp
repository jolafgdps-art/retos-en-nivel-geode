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
    void onEnterTransitionDidFinish() {
        PlayLayer::onEnterTransitionDidFinish();

        // This is called after the level scene has entered, so Notification::show()
        // has a valid scene on Android as well as on desktop.
        Notification::create(
            randomChallenge(),
            NotificationIcon::Info,
            NOTIFICATION_LONG_TIME
        )->show();
    }
};