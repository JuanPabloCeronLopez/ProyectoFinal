//
// Created by USER on 22/11/2025.
//

#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_POCION_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_POCION_H

#include "Objeto.h"

class Pocion : public Objeto {
private:
    int recuperacion;

public:
    Pocion(const std::string& nombre,
           const std::string& descripcion,
           int recuperacion);

    void aplicar(Jugador* jugador) override;
};

#endif

