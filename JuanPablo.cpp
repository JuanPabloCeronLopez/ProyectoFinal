
#include "JuanPablo.h"
#include <iostream>

// Se crea el constructor
JuanPablo::JuanPablo()
    : Jugador("Juan Pablo el Sabio", 90, 30),
      mana(100),
      manaMaximo(100) {
    // Juan Pablo es más frágil (80 HP) pero más poderoso (30 ATK)
    // Empieza con el mana lleno
}

// Implementación del Mana
void JuanPablo::atacar() {
    const int COSTO_MANA = 20;

    if (mana >= COSTO_MANA) {
        // Tiene suficiente mana para un ataque mágico
        mana -= COSTO_MANA;

        std::cout << "\n" << nombre << " lanza un rayo arcano!\n";
        std::cout << "Danio magico: " << ataque << " puntos\n";
        std::cout << "Mana restante: " << mana << "/" << manaMaximo << "\n";

    } else {
        // Sin mana suficiente, ataque débil físico
        std::cout << "\nMana insuficiente!\n";
        std::cout << nombre << " golpea con su baston (ataque debil).\n";
        std::cout << "Danio fisico: " << (ataque / 2) << " puntos\n";
        std::cout << "Necesitas " << COSTO_MANA << " de mana para atacar magicamente.\n";
    }
}
// Habilidad Especial
void JuanPablo::tormenta() {
    const int COSTO_TORMENTA = 50;

    if (mana >= COSTO_TORMENTA) {
        mana -= COSTO_TORMENTA;

        std::cout << "\n¡TORMENTA ARCANA!\n";
        std::cout << nombre << " invoca el poder de los cielos!\n";
        std::cout << "Rayos caen sobre TODOS los enemigos!\n";
        std::cout << "Daño masivo: " << (ataque * 2) << " puntos a cada enemigo\n";
        std::cout << "Mana restante: " << mana << "/" << manaMaximo << "\n";

    } else {
        std::cout << "\n Mana insuficiente para Tormenta!\n";
        std::cout << "Necesitas " << COSTO_TORMENTA << " de mana.\n";
        std::cout << "Mana actual: " << mana << "/" << manaMaximo << "\n";
    }
}

// Recuperar Mana
void JuanPablo::recuperarMana(int cantidad) {
    mana += cantidad;

    // No puede exceder el máximo
    if (mana > manaMaximo) {
        mana = manaMaximo;
    }

    std::cout << " Mana recuperado: +" << cantidad << "\n";
    std::cout << "Mana actual: " << mana << "/" << manaMaximo << "\n";
}