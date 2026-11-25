cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(RetosChallenge VERSION 1.2.4)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(4{PROJECT_NAME} SHARED 4{SOURCES})

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK is not set")
endif()

add_subdirectory(4{GEODE_SDK} 4{CMAKE_CURRENT_BINARY_DIR}/geode)
setup_geode_mod(4{PROJECT_NAME})
