
#include "Simon.h"
#include <iostream>

// Constructor
Simon::Simon()
    : Jugador("Simon el Valiente", 120, 25), furia(0) {
    // Llamamos al constructor de Jugador con valores fijos
    // Jugador a su vez llamará al constructor de Personaje
    // furia empieza en 0 (sin ira inicial)
}

// Implementación de atacar
void Simon::atacar() {
    std::cout << "\n " << nombre << " blande su espada con fuerza! \n";

    // Calcula el daño total: ataque base + furia acumulada
    int danoTotal = ataque + furia;
    std::cout << "Daño infligido: " << ataque << " (base)";

    if (furia > 0) {
        std::cout << " + " << furia << " (furia)";
    }
    std::cout << " = " << danoTotal << " total \n";

    // Después de atacar, la furia se consume
    furia = 0;
}

// Habilidad especial
void Simon::cargaDelValor() {
    // Simon acumula 10 puntos de furia
    furia += 10;

    std::cout << " ¡CARGA DEL VALOR!\n";
    std::cout << nombre << " concentra su valentía y acumula ira. \n";
    std::cout << "Furia actual: " << furia << " puntos \n";
    std::cout << "El próximo ataque será más devastador! \n";

// Recuperar Furia

}