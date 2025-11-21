#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_HABITACION_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_HABITACION_H

#include <string>
#include <map>
#include <vector>
#include "Objeto.h"
#include "Enemigo.h"

class Habitacion {
private:
    std::string id;              // ID interna (templo, bosque, montana)
    std::string nombre;          // Nombre visible
    std::string descripcion;     // Texto de descripción

    std::map<std::string, Habitacion*> salidas; // Conexiones
    std::vector<Enemigo*> enemigos;             // Enemigos presentes
    std::vector<Objeto*> objetos;               // Objetos presentes

public:
    Habitacion(const std::string& id,
               const std::string& nombre,
               const std::string& descripcion);

    ~Habitacion();

    // GETTERS
    std::string getID() const { return id; }
    std::string getNombre() const { return nombre; }
    std::vector<Enemigo*>& getEnemigos() { return enemigos; }

    // ACCIONES
    void agregarEnemigo(Enemigo* e);
    void eliminarPrimerEnemigo();

    void agregarObjeto(Objeto* obj);

    // MOVIMIENTO
    void conectar(Habitacion* hab, const std::string& direccion);
    Habitacion* obtenerSalida(const std::string& dir);

    // MOSTRAR
    void mostrarDescripcion() const;
    void mostrarContenido() const;
};

#endif