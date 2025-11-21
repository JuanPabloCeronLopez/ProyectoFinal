//
// Created by USER on 20/11/2025.
//

#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_INVENTARIO_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_INVENTARIO_H
#include "Objeto.h"
#include <vector>
#include <string>


class Inventario {

private:
    std::vector<Objeto*> objetos;  // Colección polimórfica
    int capacidadMaxima;

public:
    // Constructor
    Inventario(int capacidad = 10);

    // Destructor - DEBE liberar memoria de objetos
    virtual ~Inventario();

    // metodos principales
    bool agregar(Objeto* objeto);
    bool usar(const std::string& nombreObjeto, Jugador* jugador);
    void mostrar() const;

    // utilidades
    bool estaLleno() const;
    int getCantidad() const;
    Objeto* buscarObjeto(const std::string& nombre);
};

#endif

