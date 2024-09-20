// Jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H

#include "Tablero.h"
#include <vector>

class Jugador {
private:
    int posX, posY;         // Posici�n actual del jugador
    Tablero* tablero;       // Puntero al tablero en el que juega el jugador
    std::vector<char> movimientos; // Vector para almacenar los movimientos


public:
    bool puedeMoverCaja(int nuevaX, int nuevaY);
    bool estaEnPunto();
    // Constructor del Jugador
    Jugador(int x, int y, Tablero* tablero);

    // Mover el jugador en la direcci�n especificada
    void mover(char direccion);

    const std::vector<char>& obtenerMovimientos() const { return movimientos; }

    // Verificar si el jugador puede moverse a una nueva posici�n
    bool puedeMover(int nuevaX, int nuevaY);
};

#endif // JUGADOR_H
