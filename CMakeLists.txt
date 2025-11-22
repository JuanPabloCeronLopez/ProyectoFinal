cmake_minimum_required(VERSION 3.26)
project(VideoJuego_Proyecto_finalPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(VideoJuego_Proyecto_finalPOO
        main.cpp
        Personaje.cpp
        Jugador.cpp
        Simon.cpp
        JuanPablo.cpp
        Inventario.cpp
        Objeto.cpp
        Enemigo.cpp
        RoomManager.cpp
        Habitacion.cpp
        GameController.cpp
        GameController.h
        Arma.cpp
        Arma.h
        Pocion.cpp
        Pocion.h
)
