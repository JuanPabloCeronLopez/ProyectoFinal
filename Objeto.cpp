#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

Objeto::Objeto(const std::string& nombre,
               const std::string& tipo,
               const std::string& descripcion,
               int valor)
    : nombre(nombre),
      tipo(tipo),
      descripcion(descripcion),
      valor(valor) {}

Objeto::~Objeto() {}