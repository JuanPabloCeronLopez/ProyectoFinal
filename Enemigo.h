//
// Created by USER on 20/11/2025.
//

#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_ENEMIGO_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_ENEMIGO_H

#include "Personaje.h"

class Enemigo : public Personaje { // Clase base para TODOS los enemigos del juego
    // Hereda de Personaje pero NO es abstracta (implementa atacar)
protected:
    int expRecompensa;

public:
    Enemigo(const std::string& nombre, int salud, int ataque, int exp);
    virtual ~Enemigo() = default;

    //Implementación de atacar
     void atacar() override;

    int getExpRecompensa() const { return expRecompensa; }
};

class GuerreroCorrupto : public Enemigo {
public:
    GuerreroCorrupto();
    void atacar() override;
};

class Gigante : public Enemigo {
public:
    Gigante();
    void atacar() override;
};

class Ladron : public Enemigo {
public:
    Ladron();
    void atacar() override;
};

class Golem : public Enemigo {
public:
    Golem();
    void atacar() override;
};

class Boss : public Enemigo {
protected:
    bool faseEnfurecida;

public:
    Boss(const std::string& nombre, int salud, int ataque, int exp);
    virtual ~Boss() = default;

    virtual void usarHabilidad() = 0;
    void verificarFase();
};

class SenorDeLaSombra : public Boss {
public:
    SenorDeLaSombra();
    void atacar() override;
    void usarHabilidad() override;
};

class DragonRojo : public Boss {
public:
    DragonRojo();
    void atacar() override;
    void usarHabilidad() override;
};

#endif