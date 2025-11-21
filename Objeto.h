//
// Created by USER on 20/11/2025.
//

#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_OBJETO_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_OBJETO_H

#include <string>

// Forward declaration (evita dependencia circular)
class Jugador;

// Clase base abstracta para todos los objetos del juego
class Objeto {
protected:
    std::string nombre;
    std::string tipo;        // "Arma", "Poción", "Encantamiento"
    std::string descripcion;
    int valor;               // Valor numérico del efecto

public:
    // Constructor
    Objeto(const std::string& nombre,
           const std::string& tipo,
           const std::string& descripcion,
           int valor);

    // Destructor virtual
    virtual ~Objeto() = default;

    // Metodo Virtual puro
    // Cada tipo de objeto aplica su efecto de forma diferente
    virtual void aplicar(Jugador* jugador) = 0;

    // ========== GETTERS ==========
    std::string getNombre() const { return nombre; }
    std::string getTipo() const { return tipo; }
    std::string getDescripcion() const { return descripcion; }
    int getValor() const { return valor; }
};

// Implementación clase Arma
class Arma : public Objeto {
private:
    int danoExtra;

public:
    Arma(const std::string& nombre,
         const std::string& descripcion,
         int danoExtra);

    void aplicar(Jugador* jugador) override;
    int getDanoExtra() const { return danoExtra; }
};

// Implementación clase poción
class Pocion : public Objeto {
private:
    int recuperacion;

public:
    Pocion(const std::string& nombre,
           const std::string& descripcion,
           int recuperacion);

    void aplicar(Jugador* jugador) override;
};

// Implementación clase encantamiento
class Encantamiento : public Objeto {
private:
    int buffAtaque;
    int duracion;  // Turnos que dura el efecto

public:
    Encantamiento(const std::string& nombre,
                  const std::string& descripcion,
                  int buffAtaque);

    void aplicar(Jugador* jugador) override;
};

#endif


