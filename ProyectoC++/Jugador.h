// Jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H

#include "Tablero.h"

class Jugador {
private:
    int posX, posY;         // Posici�n actual del jugador
    Tablero* tablero;       // Puntero al tablero en el que juega el jugador

public:
    bool puedeMoverCaja(int nuevaX, int nuevaY);
    bool estaEnPunto();
    // Constructor del Jugador
    Jugador(int x, int y, Tablero* tablero);

    // Mover el jugador en la direcci�n especificada
    void mover(char direccion);

private:
    // Verificar si el jugador puede moverse a una nueva posici�n
    bool puedeMover(int nuevaX, int nuevaY);
};

#endif // JUGADOR_H
