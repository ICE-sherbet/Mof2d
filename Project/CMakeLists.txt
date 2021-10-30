cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(../)
include_directories(../../)
include_directories(../../MofLibrary)
include_directories(../../MofLibrary/Include)
include_directories(.)
include_directories(./Mylibrary)
include_directories(./Mylibrary/Include)

link_directories(../../MofLibrary/Library)



add_executable(Project
        ./Mylibrary/Include/HSV.h
        ./Mylibrary/Include/RGBA.h
        collider_2d.h
        component.cpp
        component.h
        entity_2d.cpp
        entity_2d.h
        GameApp.cpp
        GameApp.h
        object.cpp
        object.h
        Observer.h
        position.cpp
        position.h
        Subject.h
        WinMain.cpp
        input_observer.cpp
        input_observer.h
        collider_2d_box.cpp
        Sprite.cpp
        Sprite.h
        kadai3.h
        kadai3.cpp
        )
