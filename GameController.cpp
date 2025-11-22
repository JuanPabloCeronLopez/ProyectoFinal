// Referencia según APA 7:
// OpenAI. (2025). ChatGPT (versión GPT-5.1) [Modelo de lenguaje generativo].
// Código generado parcialmente con apoyo del modelo para estructurar clases y lógica.
#include "GameController.h"
#include <iostream>
#include <algorithm>

using namespace std;

GameController::GameController()
    : jugador(nullptr),
      juegoActivo(true),
      enCombate(false),
      ataquesRealizados(0),
      pocionesUsadas(0) {}

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

    jugador = (opcion == 1) ? (Jugador*) new Simon() : (Jugador*) new JuanPablo();

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

    if (cmd == "salir") {
        cout << "Fin del juego.\n";
        juegoActivo = false;
        return;
    }

    // MODO EXPLORACIÓN
    if (!enCombate) {
        if (cmd == "ayuda") { mostrarOpcionesExploracion(); return; }
        if (cmd == "1") { manager.printCurrentRoom(); return; }
        if (cmd == "2") { jugador->mostrarEstado(); return; }
        if (cmd == "3") {
            cout << "Direccion (norte/sur/este/oeste): ";
            string d; getline(cin, d);
            mover(d);
            return;
        }
        if (cmd == "4") { iniciarCombate(); return; }
        if (cmd == "5") { recogerObjeto(); return; }

        cout << "Comando no reconocido.\n";
        return;
    }

    // MODO COMBATE
    if (cmd == "ayuda") { mostrarOpcionesCombate(); return; }
    if (cmd == "1") { combatir(); return; }
    if (cmd == "2") { usarHabilidad(); return; }
    if (cmd == "3") { usarPocion(); return; }
    if (cmd == "4") { jugador->mostrarEstado(); return; }
    if (cmd == "5") { huirCombate(); return; }

    cout << "Comando no valido en combate.\n";
}

void GameController::mostrarOpcionesExploracion() {
    cout << "\n=== COMANDOS DE EXPLORACIÓN ===\n";
    cout << "1. Mirar habitación\n";
    cout << "2. Ver estado del jugador\n";
    cout << "3. Moverse\n";
    cout << "4. Atacar (si hay enemigos)\n";
    cout << "5. Recoger objetos\n";
    cout << "salir. Terminar juego\n\n";
}

void GameController::mostrarOpcionesCombate() {
    cout << "\n=== COMANDOS DE COMBATE ===\n";
    cout << "1. Atacar\n";
    cout << "2. Usar habilidad especial\n";
    cout << "3. Usar poción\n";
    cout << "4. Ver estado\n";
    cout << "5. Huir\n";
}

void GameController::mover(const string& dir) {
    Habitacion* actual = manager.getCurrentRoom();
    Habitacion* next = actual->obtenerSalida(dir);

    if (!next) {
        cout << "No puedes ir hacia " << dir << ".\n";
        return;
    }

    pocionesUsadas = 0;
    ataquesRealizados = 0;

    manager.setCurrentRoom(next->getID());
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
    ataquesRealizados = 0;

    cout << "\n--- COMBATE INICIADO ---\n";
    mostrarOpcionesCombate();
}

void GameController::huirCombate() {
    cout << "\nIntentas huir...\n";
    enCombate = false;
    cout << "Logras escapar del combate.\n";
}

void GameController::combatir() {
    Habitacion* hab = manager.getCurrentRoom();
    Enemigo* enemigo = hab->getEnemigos().front();

    cout << "\nPeleas contra: " << enemigo->getNombre() << "\n";

    ataquesRealizados++;

    jugador->atacar();
    enemigo->recibirDano(jugador->getAtaque());

    if (!enemigo->estaVivo()) {
        cout << enemigo->getNombre() << " derrotado.\n";
        hab->eliminarPrimerEnemigo();

        enCombate = false;
        revisarFinDeJuego();
        return;
    }

    enemigo->atacar();
    jugador->recibirDano(enemigo->getAtaque());

    if (!jugador->estaVivo()) {
        cout << "Has muerto.\n";
        juegoActivo = false;
    }
}

void GameController::usarPocion() {
    if (pocionesUsadas >= MAX_POCIONES) {
        cout << "Ya no puedes usar más pociones.\n";
        return;
    }

    jugador->setSalud(jugador->getSalud() + 30);
    pocionesUsadas++;

    cout << "Usaste una poción (+30 HP).\n";
    jugador->mostrarEstado();
}

void GameController::usarHabilidad() {
    if (ataquesRealizados < 2) {
        cout << "Debes atacar 2 veces antes de usar tu habilidad.\n";
        return;
    }

    ataquesRealizados = 0;

    if (auto s = dynamic_cast<Simon*>(jugador))
        s->cargaDelValor();
    else if (auto j = dynamic_cast<JuanPablo*>(jugador))
        j->tormenta();
}

void GameController::recogerObjeto() {
    Habitacion* hab = manager.getCurrentRoom();

    if (hab->getObjetos().empty()) {
        cout << "No hay objetos.\n";
        return;
    }

    Objeto* obj = hab->getObjetos().front();
    hab->eliminarPrimerObjeto();

    cout << "Recogiste: " << obj->getNombre() << "\n";

    obj->aplicar(jugador);

    delete obj;
}

void GameController::revisarFinDeJuego() {
    Habitacion* hab = manager.getCurrentRoom();

    if (hab->getID() == "montana" && hab->getEnemigos().empty()) {
        cout << "\n*** Recuperaste el CRISTAL DEL AMANECER ***\n";
        cout << " FIN DEL JUEGO \n";
        juegoActivo = false;
    }
}
