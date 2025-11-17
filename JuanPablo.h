
#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_JUANPABLO_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_JUANPABLO_H


#include "Jugador.h"

// JuanPablo es un mago, hereda de Jugador
class JuanPablo : public Jugador {
private:
    int mana;        // Energía mágica actual
    int manaMaximo;  // Límite de mana

public:
    // Constructor
    JuanPablo();

    // Destructor por defecto
    ~JuanPablo() = default;

    // Se debe confirmar la implemnetación
    void atacar() override;

    // Se activa la habilidad especial
    void tormenta();  // Habilidad de área (ataca a todos)

    // los Getters perimten leer los atributos privados y protected sin modificarlos
    int getMana() const { return mana; }
    int getManaMaximo() const { return manaMaximo; }

    // Metodo para regenerarse
    void recuperarMana(int cantidad);
};


#endif