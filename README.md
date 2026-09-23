# Retos en Nivel

Mod de Geode para Geometry Dash Android 2.2081.

Al entrar a un nivel muestra un reto aleatorio mediante una notificación de Geode. Al terminar el nivel muestra **Reto completado**; si el jugador muere, reinicia o sale del nivel antes de completarlo, muestra **Reto no completado**.

## Compatibilidad

- Geometry Dash Android 2.2081
- Geode 5.10.1
- Android ARM64 / android64
- ID del mod: jolaf.retosenivel
- Versión del código: 1.2.2

## Descarga

La versión compilada anterior está disponible en la [publicación de GitHub](https://github.com/jolafgdps-art/retos-en-nivel/releases/tag/v1.2.1). La versión 1.2.2 requiere compilar el código actualizado.

## Compilación

Necesitas Geode SDK 5.10.1, bindings de Geometry Dash 2.2081 y Android NDK. Configura CMake con Android ARM64 y ejecuta:

    cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-24
    cmake --build build

## Soporte

Discord: https://discord.gg/MGJ67skaG5

## Autor

Jolaf
