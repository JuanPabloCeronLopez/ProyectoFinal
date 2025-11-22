#include "Jugador.h"
#include <iostream>

// Constructor
Jugador::Jugador(const std::string& nombre, int salud, int ataque)
    : Personaje(nombre, salud, ataque),
      experiencia(0), nivel(1) {}

// Implementación del ataque
void Jugador::atacar() {
    std::cout << nombre << " ataca con " << ataque << " de daño!\n";
}

// Ganar experiencia (por si lo necesitas)
void Jugador::ganarExperiencia(int exp) {
    experiencia += exp;
    std::cout << exp << " XP obtenidos!\n";
}
