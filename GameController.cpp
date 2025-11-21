// Referencia según APA 7:
// OpenAI. (2025). ChatGPT (versión GPT-5.1) [Modelo de lenguaje generativo].
// Código generado parcialmente con apoyo del modelo para estructurar clases y lógica.
#include "GameController.h"
#include <iostream>
#include <algorithm>

using namespace std;

GameController::GameController()
    : jugador(nullptr), juegoActivo(true),
      enCombate(false), pocionesUsadas(0) {}

GameController::~GameController() {
    delete jugador;
}

void GameController::iniciar() {
    cout << "Aventura Textual\n\n";

    cout << "Selecciona tu personaje:\n";
    cout << "1. Simon\n";
    cout << "2. Juan Pablo\n";
    cout << "> ";

    int opcion;
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) jugador = new Simon();
    else jugador = new JuanPablo();

    manager.loadDefaultRooms();
    manager.printCurrentRoom();

    cout << "\nEscribe 'ayuda' para ver comandos.\n";
}

void GameController::loopPrincipal() {
    while (juegoActivo) {
        cout << "> ";
        string cmd;
        getline(cin, cmd);
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

        procesarComando(cmd);
    }
}

void GameController::procesarComando(const string& cmd) {
    // comandos globales
    if (cmd == "salir") {
        cout << "Fin del juego.\n";
        juegoActivo = false;
        return;
    }

    if (!enCombate) {
        // modo exploración
        if (cmd == "ayuda") {
            mostrarOpcionesExploracion();
            return;
        }

        if (cmd == "mirar") {
            manager.printCurrentRoom();
            return;
        }

        if (cmd == "estado") {
            jugador->mostrarEstado();
            return;
        }

        if (cmd.rfind("ir ", 0) == 0) {
            mover(cmd.substr(3));
            return;
        }

        if (cmd == "atacar") {
            iniciarCombate();
            return;
        }

        if (cmd == "recoger") {
            cout << "Aun no implementado.\n";
            return;
        }

        cout << "Comando no reconocido.\n";
        return;
    }

    // modo combate
    if (cmd == "ayuda") {
        mostrarOpcionesCombate();
        return;
    }

    if (cmd == "estado") {
        jugador->mostrarEstado();
        return;
    }

    if (cmd == "atacar") {
        combatir();
        return;
    }

    if (cmd == "curar") {
        usarPocion();
        return;
    }

    if (cmd == "habilidad") {
        usarHabilidad();
        return;
    }

    if (cmd == "huir") {
        huirCombate();
        return;
    }


    cout << "Comando no valido en combate.\n";
}

void GameController::mostrarOpcionesExploracion() {
    cout << "\n=== Comandos de Exploración ===\n";
    cout << "mirar        - ver habitacion\n";
    cout << "estado       - ver estadisticas\n";
    cout << "ir <dir>     - moverse\n";
    cout << "atacar       - iniciar combate\n";
    cout << "recoger      - tomar objetos\n";
    cout << "salir        - terminar juego\n";
}

void GameController::mostrarOpcionesCombate() {
    cout << "\n=== Comandos de Combate ===\n";
    cout << "atacar       - ataque normal\n";
    cout << "habilidad    - usar habilidad especial\n";
    cout << "curar        - usar poción (max 2)\n";
    cout << "estado       - ver vida y estado\n";
    cout << "huir         - abandonar combate\n";
    cout << "salir        - terminar juego\n";
}

void GameController::mover(const string& dir) {
    Habitacion* actual = manager.getCurrentRoom();
    Habitacion* next = actual->obtenerSalida(dir);

    if (!next) {
        cout << "No puedes ir hacia " << dir << ".\n";
        return;
    }

    manager.setCurrentRoom(next->getID());
    pocionesUsadas = 0;  // reinicio por nueva habitación
    manager.printCurrentRoom();
}

void GameController::iniciarCombate() {
    Habitacion* hab = manager.getCurrentRoom();

    if (hab->getEnemigos().empty()) {
        cout << "No hay enemigos.\n";
        return;
    }

    enCombate = true;
    pocionesUsadas = 0;

    cout << "\n*** Inicias un combate ***\n";
    mostrarOpcionesCombate();
}

void GameController::combatir() {
    Habitacion* hab = manager.getCurrentRoom();
    Enemigo* enemigo = hab->getEnemigos().front();

    cout << "\nCombates contra: " << enemigo->getNombre() << "\n";

    // turno jugador
    jugador->atacar();
    enemigo->recibirDano(jugador->getAtaque());

    if (!enemigo->estaVivo()) {
        cout << enemigo->getNombre() << " derrotado.\n";
        hab->eliminarPrimerEnemigo();

        enCombate = false;
        return;
    }

    // turno enemigo
    enemigo->atacar();
    jugador->recibirDano(enemigo->getAtaque());

    if (!jugador->estaVivo()) {
        cout << "Has muerto.\n";
        juegoActivo = false;
    }
}

void GameController::usarPocion() {
    if (pocionesUsadas >= MAX_POCIONES) {
        cout << "Ya usaste todas las pociones en este combate.\n";
        return;
    }

    jugador->setSalud(jugador->getSalud() + 30);
    pocionesUsadas++;

    cout << "Usas una pocion (+30 HP).\n";
    jugador->mostrarEstado();
}

void GameController::usarHabilidad() {
    if (Simon* s = dynamic_cast<Simon*>(jugador)) {
        s->cargaDelValor();
        return;
    }

    if (JuanPablo* j = dynamic_cast<JuanPablo*>(jugador)) {
        j->tormenta();
        return;
    }
}

void GameController::huirCombate() {
    enCombate = false;
    cout << "Huyes del combate.\n";
}

