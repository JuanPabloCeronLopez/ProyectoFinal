
#include "Jugador.h"

// Constructor: llama al constructor de la clase base
Jugador::Jugador(const std::string& nombre, int salud, int ataque)
    : Personaje(nombre, salud, ataque), experiencia(0), nivel(1) {
    // Personaje(nombre, salud, ataque) ← llama al constructor padre
};


void Jugador::atacar() {
    std::cout << nombre << " ataca con " << ataque << " de daño!\n";
    // Puede acceder a 'nombre' y 'ataque' porque son protected
};

void Jugador::ganarExperiencia(int exp) {
    experiencia += exp;
    std::cout << exp << " XP!\n";
};