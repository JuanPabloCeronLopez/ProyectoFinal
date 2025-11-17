
#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_PERSONAJE_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_PERSONAJE_H

#include <string>
#include <iostream>

class Personaje { //se crea la clase base Personaje
protected: // se acceden a los atributos para que las otras clases hijas (Simón y Juan Pablo) puedan gheredarlas
    std::string nombre;
    int salud;
    int saludMaxima;
    int ataque;

public:
    //Se implementa el constructor para inicializar el objeto personaje cuando se crea, y se marcan las referencias
    Personaje(const std::string& nombre, int salud, int ataque);

    //Se utiliza un destructor para la clase que se este implementadno
    virtual ~Personaje() = default;
    // se utiliza el metodo virtual para que las clases hijas proporcionen sus proias implementaciones.
    virtual void atacar() = 0;

    //Mostrar metodos concretos
    void recibirDano(int dano);
    bool estaVivo() const;
    void mostrarEstado() const;


    //los Getters perimten leer los atributos privados y protected sin modificarlos
    std::string getNombre() const { return nombre; }
    int getSalud() const { return salud; }
    int getAtaque() const { return ataque; }
    int getSaludMaxima() const { return saludMaxima; }

    // los Setters permiten modificar los atributos de forma controlada
    void setSalud(int nuevaSalud);
    void setAtaque(int nuevoAtaque);
};
#endif //cierra y guarda toda la clase
