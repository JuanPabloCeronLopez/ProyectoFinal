#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_OBJETO_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_OBJETO_H

#include <string>

class Jugador; // Declaración adelantada

class Objeto {
protected:
    std::string nombre;
    std::string tipo;
    std::string descripcion;
    int valor;

public:
    Objeto(const std::string& nombre,
           const std::string& tipo,
           const std::string& descripcion,
           int valor);

    virtual ~Objeto();  // Destructor virtual

    // polimorfismo
    virtual void aplicar(Jugador* jugador) = 0;

    // Getters
    std::string getNombre() const { return nombre; }
    std::string getDescripcion() const { return descripcion; }
    std::string getTipo() const { return tipo; }
    int getValor() const { return valor; }
};

#endif
