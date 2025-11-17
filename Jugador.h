
#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_JUGADOR_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_JUGADOR_H

#include "Personaje.h"  // ← Incluir el header

class Jugador : public Personaje {  // ← Herencia
private:
    int experiencia;
    int nivel;

public:
    // Constructor que llama al constructor de Personaje
    Jugador(const std::string& nombre, int salud, int ataque);

     // se implementa el metodo virtual
    void atacar() override;

    // Métodos propios
    void ganarExperiencia(int exp);

};
#endif