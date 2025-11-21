#include "Habitacion.h"
#include <iostream>
#include <algorithm>

using namespace std;

Habitacion::Habitacion(const string& id,
                       const string& nombre,
                       const string& descripcion)
    : id(id), nombre(nombre), descripcion(descripcion) {}


Habitacion::~Habitacion() {
    for (auto e : enemigos) delete e;
    for (auto o : objetos) delete o;
}


void Habitacion::agregarEnemigo(Enemigo* e) {
    enemigos.push_back(e);
}

void Habitacion::eliminarPrimerEnemigo() {
    if (!enemigos.empty()) {
        delete enemigos.front();
        enemigos.erase(enemigos.begin());
    }
}

void Habitacion::agregarObjeto(Objeto* obj) {
    objetos.push_back(obj);
}


Habitacion* Habitacion::obtenerSalida(const string& dir) {
    if (salidas.count(dir)) return salidas[dir];
    return nullptr;
}

void Habitacion::conectar(Habitacion* hab, const string& direccion) {
    salidas[direccion] = hab;
}


void Habitacion::mostrarDescripcion() const {
    cout << "\n" << nombre << "\n";
    cout << descripcion << "\n\n";
}


void Habitacion::mostrarContenido() const {

    if (!enemigos.empty()) {
        cout << "Enemigos presentes:\n";
        for (auto e : enemigos)
            cout << " - " << e->getNombre() << "\n";
    }

    if (!objetos.empty()) {
        cout << "\nObjetos disponibles:\n";
        for (auto o : objetos)
            cout << " - " << o->getNombre() << "\n";
    }

    if (salidas.empty()) {
        cout << "\nNo hay salidas visibles.\n";
    } else {
        cout << "\nSalidas:\n";
        for (auto& s : salidas)
            cout << " - " << s.first << "\n";
    }

    if (enemigos.empty() && objetos.empty())
        cout << "\nNo hay nada interesante aquí.\n";
}
