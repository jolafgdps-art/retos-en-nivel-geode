# Retos en Nivel

Mod de Geode para Geometry Dash Android 2.2081.

Al entrar a un nivel muestra un reto aleatorio mediante una notificación de Geode.

## Compatibilidad

- Geometry Dash Android 2.2081
- Geode 5.10.1
- Android ARM64 / android64
- ID del mod: jolaf.retosenivel

## Descarga

La versión compilada está disponible en la [release pública v1.2.1](https://github.com/jolafgdps-art/retos-en-nivel/releases/tag/v1.2.1).

[Descargar el archivo .geode directamente](https://github.com/jolafgdps-art/retos-en-nivel/raw/v1.2.1/releases/jolaf.retosenivel-1.2.1.geode)

## Compilación

Necesitas Geode SDK 5.10.1, bindings de Geometry Dash 2.2081 y Android NDK. Configura CMake con Android ARM64 y ejecuta:

    cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-24
    cmake --build build

## Soporte

Discord: https://discord.gg/MGJ67skaG5

## Autor

Jolaf
