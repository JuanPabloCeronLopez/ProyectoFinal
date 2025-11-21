#ifndef VIDEOJUEGO_PROYECTO_FINALPOO_ROOMMANAGER_H
#define VIDEOJUEGO_PROYECTO_FINALPOO_ROOMMANAGER_H

#include <string>
#include <map>
#include "Habitacion.h"

// Subclases de las habitaciones
class TemploDelAmanecer;
class BosqueEsmeralda;
class MontanaDelOlvido;

class RoomManager {
private:
    std::map<std::string, Habitacion*> rooms;
    Habitacion* currentRoom;

public:
    RoomManager();
    ~RoomManager();

    void addRoom(const std::string& id, Habitacion* room);

    void setCurrentRoom(const std::string& id);
    Habitacion* getCurrentRoom();

    void printCurrentRoom();

    // Carga el mapa por defecto
    void loadDefaultRooms();
};

#endif
