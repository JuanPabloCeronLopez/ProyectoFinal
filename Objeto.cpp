//
// Created by USER on 20/11/2025.
//

#include "Objeto.h"
#include "Jugador.h"  // AQUÍ sí incluimos Jugador completo
#include <iostream>

// Constructor de objeto
Objeto::Objeto(const std::string& nombre,
               const std::string& tipo,
               const std::string& descripcion,
               int valor)
    : nombre(nombre), tipo(tipo), descripcion(descripcion), valor(valor) {
}

// Constructor de Arma
Arma::Arma(const std::string& nombre,
           const std::string& descripcion,
           int danoExtra)
    : Objeto(nombre, "Arma", descripcion, danoExtra),
      danoExtra(danoExtra) {
}

void Arma::aplicar(Jugador* jugador) {
    // Aumenta permanentemente el ataque del jugador
    jugador->setAtaque(jugador->getAtaque() + danoExtra);

    std::cout << "\n " << nombre << " equipada!\n";
    std::cout << "   " << descripcion << "\n";
    std::cout << "   Ataque aumentado en +" << danoExtra << " puntos!\n";
    std::cout << "   Ataque actual: " << jugador->getAtaque() << "\n";
}

// Contructor de objeto
Pocion::Pocion(const std::string& nombre,
               const std::string& descripcion,
               int recuperacion)
    : Objeto(nombre, "Poción", descripcion, recuperacion),
      recuperacion(recuperacion) {
}

void Pocion::aplicar(Jugador* jugador) {
    int saludAnterior = jugador->getSalud();
    jugador->setSalud(jugador->getSalud() + recuperacion);
    int saludRecuperada = jugador->getSalud() - saludAnterior;

    std::cout << "\n " << nombre << " consumida!\n";
    std::cout << "   " << descripcion << "\n";
    std::cout << "   Salud recuperada: +" << saludRecuperada << " HP\n";
    std::cout << "   Salud actual: " << jugador->getSalud()
              << "/" << jugador->getSaludMaxima() << "\n";
}

// Contructor de encantamiento
Encantamiento::Encantamiento(const std::string& nombre,
                             const std::string& descripcion,
                             int buffAtaque)
    : Objeto(nombre, "Encantamiento", descripcion, buffAtaque),
      buffAtaque(buffAtaque),
      duracion(3) {  // Dura 3 turnos
}

void Encantamiento::aplicar(Jugador* jugador) {
    jugador->setAtaque(jugador->getAtaque() + buffAtaque);

    std::cout << "\n " << nombre << " activado!\n";
    std::cout << "   " << descripcion << "\n";
    std::cout << "   Ataque aumentado temporalmente en +" << buffAtaque << "!\n";
    std::cout << "   (Durará " << duracion << " turnos)\n";
    std::cout << "   Ataque actual: " << jugador->getAtaque() << "\n";
}