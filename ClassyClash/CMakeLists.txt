cmake_minimum_required(VERSION 3.11)
project(ClassyClash)

set(CMAKE_CXX_STANDARD 17)

find_library(RAYLIB_LIBRARY
        NAMES raylib
        PATHS "C:/raylib/lib" "C:/raylib"
        REQUIRED
)

find_path(RAYLIB_INCLUDE_DIR
        NAMES raylib.h
        PATHS "C:/raylib/include" "C:/raylib"
        REQUIRED
)

include_directories(${RAYLIB_INCLUDE_DIR})

add_executable(ClassyClash main.cpp
        Character/Character.cpp
        Character/Character.h
        Prop/Prop.cpp
        Prop/Prop.h
        Character/Enemy.cpp
        Character/Enemy.h)
target_link_libraries(ClassyClash ${RAYLIB_LIBRARY})

if(WIN32)
    target_link_libraries(ClassyClash opengl32 gdi32 winmm)
endif()