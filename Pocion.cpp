#include "Pocion.h"
#include "Jugador.h"
#include <iostream>

Pocion::Pocion(const std::string& nombre,
               const std::string& descripcion,
               int recuperacion)
        : Objeto(nombre, "Pocion", descripcion, recuperacion),
          recuperacion(recuperacion) {}

void Pocion::aplicar(Jugador* jugador) {
    int antes = jugador->getSalud();

    jugador->setSalud(antes + recuperacion);
    int curado = jugador->getSalud() - antes;

    std::cout << "\n" << getNombre() << " consumida!\n";
    std::cout << " " << getDescripcion() << "\n";
    std::cout << " Recuperas +" << curado << " HP.\n";
    std::cout << " Salud actual: "
              << jugador->getSalud() << "/"
              << jugador->getSaludMaxima() << "\n\n";
}
