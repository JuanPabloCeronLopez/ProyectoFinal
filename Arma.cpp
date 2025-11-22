#include "Arma.h"
#include "Jugador.h"
#include <iostream>

Arma::Arma(const std::string& nombre,
           const std::string& descripcion,
           int danoExtra)
        : Objeto(nombre, "Arma", descripcion, danoExtra),
          danoExtra(danoExtra) {}

void Arma::aplicar(Jugador* jugador) {
    jugador->setAtaque(jugador->getAtaque() + danoExtra);

    std::cout << "\n" << getNombre() << " equipada!\n";
    std::cout << " " << getDescripcion() << "\n";
    std::cout << " Ataque aumentado +" << danoExtra << " pts.\n";
    std::cout << " Ataque actual: " << jugador->getAtaque() << "\n\n";
}
