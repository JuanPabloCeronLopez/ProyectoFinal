//
// Created by USER on 20/11/2025.
//

#include "Enemigo.h"
#include <iostream>

// Enemigo como clase base

Enemigo::Enemigo(const std::string& nombre, int salud, int ataque, int exp)
    : Personaje(nombre, salud, ataque), expRecompensa(exp) {
}

void Enemigo::atacar() {
    std::cout << " " << nombre << " ataca ferozmente!\n";
    std::cout << " Daño: " << ataque << " puntos\n";
}

// Implementacion clase heredada Guerrero Corrupto

GuerreroCorrupto::GuerreroCorrupto()
    : Enemigo("Guerrero Corrupto", 150, 15, 30) {
}

void GuerreroCorrupto::atacar() {
    std::cout << " " << nombre << " ejecuta un tajo horizontal!\n";
    std::cout << " Su espada oxidada inflige " << ataque << " puntos de daño.\n";
}

// Implementacion del gigante

Gigante::Gigante()
    : Enemigo("Gigante", 200, 25, 50) {
}

void Gigante::atacar() {
    std::cout << " " << nombre << " golpea el suelo con su puño masivo!\n";
    std::cout << " El impacto causa " << ataque << " puntos de daño.\n";
    std::cout << " ¡El suelo tiembla!\n";
}

// Implementación de clase Ladron
Ladron::Ladron()
    : Enemigo("Ladrón del bosque", 70, 18, 25) {
}

void Ladron::atacar() {
    std::cout << " " << nombre << " realiza un ataque furtivo con dagas!\n";
    std::cout << "   Cortes rápidos infligen " << ataque << " puntos de daño.\n";
}

// Implementación de la clase Golem

Golem::Golem()
    : Enemigo("Golem Ancestral", 250, 25, 60) {
}

void Golem::atacar() {
    std::cout << " " << nombre << " dispara fragmentos de cristal!\n";
    std::cout << "   Los cristales causan " << ataque << " puntos de daño.\n";
    std::cout << "   Su cuerpo brilla con energía arcana.\n";
}


// Implementación clase base - Boss

Boss::Boss(const std::string& nombre, int salud, int ataque, int exp)
    : Enemigo(nombre, salud, ataque, exp), faseEnfurecida(false) {
}

void Boss::verificarFase() {
    if (!faseEnfurecida && salud <= saludMaxima / 2) {
        faseEnfurecida = true;
        ataque = static_cast<int>(ataque * 1.5);

        std::cout << "\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
        std::cout << "┃   ¡" << nombre << " ENFURECE!  ┃\n";
        std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
        std::cout << "Su poder aumenta dramáticamente!\n";
        std::cout << "Ataque aumentado a " << ataque << "!\n\n";
    }
}

// Implementación de clase Señor de la Sombra

SenorDeLaSombra::SenorDeLaSombra()
    : Boss("Señor de la Sombra", 500, 30, 150) {
}

void SenorDeLaSombra::atacar() {
    verificarFase();

    std::cout << " " << nombre << " invoca rayos de oscuridad!\n";
    std::cout << "   Las sombras perforan con " << ataque << " puntos de daño.\n";

    if (faseEnfurecida) {
        std::cout << "   [ENFURECIDO] ¡El ataque es aún más devastador!\n";
    }
}

void SenorDeLaSombra::usarHabilidad() {
    std::cout << "\n╔═══════════════════════════════════════╗\n";
    std::cout << "║   ¡ABRAZO DE LA MUERTE!                 ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n";
    std::cout << nombre << " drena la esencia vital de su enemigo!\n";

    int danoEspecial = ataque + 20;
    std::cout << "Daño: " << danoEspecial << " puntos\n";

    int curacion = 20;
    salud += curacion;
    if (salud > saludMaxima) salud = saludMaxima;

    std::cout << "¡" << nombre << " recupera " << curacion << " HP!\n";
    std::cout << "Salud actual: " << salud << "/" << saludMaxima << "\n";
}

//Implementación clase Dragón Rojo
DragonRojo::DragonRojo()
    : Boss("Dragón Rojo ", 1000, 45, 500) {
}

void DragonRojo::atacar() {
    verificarFase();

    std::cout << nombre << " lanza una llamarada desde sus fauces!\n";
    std::cout << " El fuego infernal causa " << ataque << " puntos de daño.\n";

    if (faseEnfurecida) {
        std::cout << "   [ENFURECIDO] ¡Las llamas arden con furia descontrolada!\n";
    }
}

void DragonRojo::usarHabilidad() {
    std::cout << "\n╔═══════════════════════════════════════╗\n";
    std::cout << "║   ¡ALIENTO DE FUEGO INFERNAL!     ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n";
    std::cout << nombre << " concentra todo su poder dracónico!\n";
    std::cout << "Un torrente de fuego apocalíptico emerge de su garganta!\n";

    int danoMasivo = ataque * 2;
    std::cout << " DAÑO DEVASTADOR: " << danoMasivo << " puntos! \n";

    if (faseEnfurecida) {
        std::cout << "¡Y está ENFURECIDO, aumentando aún más el daño!\n";
    }
}