#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_HABITACION_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_HABITACION_H

#include <string>
#include <map>
#include <vector>
#include "Objeto.h"
#include "Enemigo.h"

class Habitacion {
private:
    std::string id;
    std::string nombre;
    std::string descripcion;

    std::map<std::string, Habitacion*> salidas;
    std::vector<Enemigo*> enemigos;
    std::vector<Objeto*> objetos;

public:

    Habitacion(const std::string& id,
               const std::string& nombre,
               const std::string& descripcion);

    ~Habitacion();

    // GETTERS
    std::string getID() const { return id; }
    std::string getNombre() const { return nombre; }

    std::vector<Enemigo*>& getEnemigos() { return enemigos; }
    std::vector<Objeto*>& getObjetos() { return objetos; }

    // ENEMIGOS
    void agregarEnemigo(Enemigo* e);
    void eliminarPrimerEnemigo();

    // OBJETOS
    void agregarObjeto(Objeto* obj);
    void eliminarPrimerObjeto();

    // MOVIMIENTO
    Habitacion* obtenerSalida(const std::string& dir);
    void conectar(Habitacion* hab, const std::string& direccion);

    // MOSTRAR
    void mostrarDescripcion() const;
    void mostrarContenido() const;
};

#endif