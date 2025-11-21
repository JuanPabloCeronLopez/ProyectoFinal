
#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_SIMON_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_SIMON_H
#include "Jugador.h"

class Simon : public Jugador {
private:
    int furia;  // Atributo único de Simon

public:
    // Constructor
    Simon();

    // Destructor (usa el de Jugador, no necesita uno especial)
    ~Simon() = default;

    // Se debe confirmar la implemnetación
    void atacar() override;

    //Metodo unico de simon
    void cargaDelValor();
};

#endif