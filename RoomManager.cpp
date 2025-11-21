#include "RoomManager.h"
#include <iostream>
#include "Enemigo.h"

// ===== SUBCLASES DE HABITACIÓN ===== //

class TemploDelAmanecer : public Habitacion {
public:
    TemploDelAmanecer()
        : Habitacion("templo",
                     "Templo del Amanecer",
                     "Un antiguo templo iluminado por la luz del alba.") {}
};

class BosqueEsmeralda : public Habitacion {
public:
    BosqueEsmeralda()
        : Habitacion("bosque",
                     "Bosque Esmeralda",
                     "Un bosque brillante lleno de energía vital.") {}
};

class MontanaDelOlvido : public Habitacion {
public:
    MontanaDelOlvido()
        : Habitacion("montana",
                     "Montaña del Olvido",
                     "La cumbre final donde descansa el enemigo supremo.") {}
};


// ===== IMPLEMENTACIÓN DEL ROOM MANAGER ===== //

RoomManager::RoomManager() : currentRoom(nullptr) {}

RoomManager::~RoomManager() {
    // Liberar TODAS las habitaciones creadas
    for (auto& pair : rooms) {
        delete pair.second;
    }
    rooms.clear();
}

void RoomManager::addRoom(const std::string& id, Habitacion* room) {
    rooms[id] = room;
}

void RoomManager::setCurrentRoom(const std::string& id) {
    auto it = rooms.find(id);
    if (it != rooms.end()) {
        currentRoom = it->second;
    } else {
        std::cout << "No existe la habitación con ID '" << id << "'\n";
    }
}

Habitacion* RoomManager::getCurrentRoom() {
    return currentRoom;
}

void RoomManager::printCurrentRoom() {
    if (currentRoom) {
        currentRoom->mostrarDescripcion();
        currentRoom->mostrarContenido();
    } else {
        std::cout << "No estás en ninguna habitación.\n";
    }
}

void RoomManager::loadDefaultRooms() {
    // Crear habitaciones del mundo
    TemploDelAmanecer* templo = new TemploDelAmanecer();
    BosqueEsmeralda* bosque = new BosqueEsmeralda();
    MontanaDelOlvido* montana = new MontanaDelOlvido();

    // Enemigos
    templo->agregarEnemigo(new GuerreroCorrupto());
    bosque->agregarEnemigo(new Ladron());
    montana->agregarEnemigo(new SenorDeLaSombra());

    // Conexiones entre habitaciones
    templo->conectar(bosque, "norte");
    bosque->conectar(templo, "sur");
    bosque->conectar(montana, "este");
    montana->conectar(bosque, "oeste");

    // Registrar en el mapa
    addRoom("templo", templo);
    addRoom("bosque", bosque);
    addRoom("montana", montana);

    // Habitación inicial
    setCurrentRoom("templo");
}
