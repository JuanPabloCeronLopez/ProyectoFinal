
#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_ARMA_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_ARMA_H


#include "Objeto.h"

class Arma : public Objeto {
private:
    int danoExtra;

public:
    Arma(const std::string& nombre,
         const std::string& descripcion,
         int danoExtra);

    void aplicar(Jugador* jugador) override;
};

#endif