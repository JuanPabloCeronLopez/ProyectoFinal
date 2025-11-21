
#include "Inventario.h"
#include <iostream>
#include <algorithm>

// Constructor del inventario
Inventario::Inventario(int capacidad)
    : capacidadMaxima(capacidad) {
}

// Destructor
Inventario::~Inventario() {
    // Liberar memoria de TODOS los objetos
    for (auto obj : objetos) {
        delete obj;
    }
    objetos.clear();
}

// agregar objeto
bool Inventario::agregar(Objeto* objeto) {
    if (estaLleno()) {
        std::cout << " ¡Inventario lleno! No puedes llevar más objetos.\n";
        return false;
    }

    objetos.push_back(objeto);
    std::cout << "✓ " << objeto->getNombre()
              << " agregado al inventario.\n";
    return true;
}

// usar objeto
bool Inventario::usar(const std::string& nombreObjeto, Jugador* jugador) {
    // Usar std::find_if con LAMBDA (Clase 23 - Algoritmos STL)
    auto it = std::find_if(objetos.begin(), objetos.end(),
        [&nombreObjeto](Objeto* obj) {
            return obj->getNombre() == nombreObjeto;
        });

    if (it != objetos.end()) {
        // Objeto encontrado
        (*it)->aplicar(jugador);  // Aplicar efecto
        delete *it;                // Liberar memoria
        objetos.erase(it);         // Remover del vector
        return true;
    }

    std::cout << " Objeto '" << nombreObjeto
              << "' no encontrado en el inventario.\n";
    return false;
}

// mostrar inventario
void Inventario::mostrar() const {
    std::cout << "\n invetario \n";
    std::cout << " Capacidad: " << objetos.size() << "/" << capacidadMaxima;

    // Relleno de espacios para alinear
    int espacios = 43 - 13 - std::to_string(objetos.size()).length()
                   - std::to_string(capacidadMaxima).length();
    for(int i = 0; i < espacios; i++) {
        std::cout << " ";
    }
    std::cout << " \n";
    std::cout << " \n";

    if (objetos.empty()) {
        std::cout << "║ (Vacío)";
        for(int i = 0; i < 35; i++) std::cout << " ";
        std::cout << "║\n";
    } else {
        for (size_t i = 0; i < objetos.size(); i++) {
            std::cout << "║ " << (i + 1) << ". "
                      << objetos[i]->getNombre()
                      << " [" << objetos[i]->getTipo() << "]";

            int espacios = 43 - 5 - std::to_string(i+1).length()
                          - objetos[i]->getNombre().length()
                          - objetos[i]->getTipo().length() - 3;
            for(int j = 0; j < espacios; j++) std::cout << " ";
            std::cout << "║\n";
        }
    }

    std::cout << "\n";
}

// verifdicar si esta lleno
bool Inventario::estaLleno() const {
    return objetos.size() >= static_cast<size_t>(capacidadMaxima);
}

// obtener calidad
int Inventario::getCantidad() const {
    return objetos.size();
}

// buscar objeto
Objeto* Inventario::buscarObjeto(const std::string& nombre) {
    auto it = std::find_if(objetos.begin(), objetos.end(),
        [&nombre](Objeto* obj) {
            return obj->getNombre() == nombre;
        });

    return (it != objetos.end()) ? *it : nullptr;
}