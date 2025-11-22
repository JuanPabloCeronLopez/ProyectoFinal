
#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_JUGADOR_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_JUGADOR_H

#include "Personaje.h"

class Jugador : public Personaje {
private:
    int experiencia;
    int nivel;

public:
    Jugador(const std::string& nombre, int salud, int ataque);

    // Implementación del metodo cirttual
    void atacar() override;

    // Métodos propios
    void ganarExperiencia(int exp);

    // ===== NECESARIOS PARA OBJETO.CPP =====
    int getSalud() const { return salud; }
    int getAtaque() const { return ataque; }
    int getSaludMaxima() const { return saludMaxima; }

    void setSalud(int nueva) { salud = nueva; }
    void setAtaque(int nuevo) { ataque = nuevo; }
};

#endif
