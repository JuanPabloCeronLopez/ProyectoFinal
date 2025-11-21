// Referencia según APA 7:
// OpenAI. (2025). ChatGPT (versión GPT-5.1) [Modelo de lenguaje generativo].
// Código generado parcialmente con apoyo del modelo para estructurar clases y lógica.
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H


#include "RoomManager.h"
#include "Jugador.h"
#include "Simon.h"
#include "JuanPablo.h"
#include <string>

class GameController {
private:
    RoomManager manager;
    Jugador* jugador;

    bool juegoActivo;
    bool enCombate;

    int pocionesUsadas;
    static const int MAX_POCIONES = 2;

public:
    GameController();
    ~GameController();

    void iniciar();
    void loopPrincipal();
    void procesarComando(const std::string& cmd);

private:
    void mostrarOpcionesExploracion();
    void mostrarOpcionesCombate();

    void mover(const std::string& dir);
    void iniciarCombate();
    void combatir();
    void usarHabilidad();
    void usarPocion();
    void huirCombate();
};


#endif