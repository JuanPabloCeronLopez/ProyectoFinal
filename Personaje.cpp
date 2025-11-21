
#include "Personaje.h"

// Se crea el constructor para generara el valor de sus
Personaje::Personaje(const std::string& nombre, int salud, int ataque)
    : nombre(nombre), salud(salud), saludMaxima(salud), ataque(ataque) {
    // Lista de inicialización (más eficiente que asignar en el cuerpo)
}

// Recibir daño
void Personaje::recibirDano(int dano) {
    salud -= dano;

    // Asegurar que la salud no sea negativa
    if (salud < 0) {
        salud = 0;
    }

    std::cout  << nombre << " recibe " << dano << " puntos de daño.\n";
    std::cout << "   Salud restante: " << salud << "/" << saludMaxima << "\n";

    if (!estaVivo()) { // Se imprime la informacion del daño
        std::cout  << nombre << " ha sido derrotado!\n";
    }
}

// Verificación del estado del personaje
bool Personaje::estaVivo() const {
    return salud > 0;
}

void Personaje::mostrarEstado() const {
    std::cout << "\n";
    std::cout << nombre;

    // Agregar espacios para alinear
    for(size_t i = nombre.length(); i < 31; i++) {
        std::cout << " ";
    }
    std::cout << "\n";

    std::cout << " Salud: " << salud << "/" << saludMaxima;
    int espacios = 31 - 11 - std::to_string(salud).length()
                   - std::to_string(saludMaxima).length();
    for(int i = 0; i < espacios; i++) {
        std::cout << " ";
    }
    std::cout << "\n";

    //Calculo de la vida

    std::cout << " Ataque: " << ataque;
    espacios = 31 - 12 - std::to_string(ataque).length();
    for(int i = 0; i < espacios; i++) {
        std::cout << " ";
    }
    std::cout << "\n";

    std::cout << "\n";
}

// No puede superar la salud máxima
void Personaje::setSalud(int nuevaSalud) {
    salud = nuevaSalud;

    //
    if (salud > saludMaxima) {
        salud = saludMaxima;
    }

    // No puede ser negativa
    if (salud < 0) {
        salud = 0;
    }
}

// seaplica que el ataque que sea mayor que cero
void Personaje::setAtaque(int nuevoAtaque) {
    ataque = nuevoAtaque;
    if (ataque < 0) {
        ataque = 0;
    }
    if (ataque > saludMaxima) {
        ataque = saludMaxima;
    }
}