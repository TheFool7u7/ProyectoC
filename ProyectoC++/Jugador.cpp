#include "Jugador.h"
#include <iostream>

// Constructor del Jugador
Jugador::Jugador(int x, int y, Tablero* tablero) : posX(x), posY(y), tablero(tablero) {}

// Mover el jugador en la dirección especificada
void Jugador::mover(char direccion) {
    direccion = toupper(direccion);  // Convertir la dirección a mayúsculas

    if (direccion == 'R') {
        tablero->reiniciarNivel();
        tablero->imprimir();  // Volver a imprimir el tablero
        std::cout << "Nivel reiniciado" << std::endl;
        return;
    }

    if (direccion == 'G') {
        tablero->guardarPartida("partida_guardada.txt");
        std::cout << "Partida guardada. Saliendo..." << std::endl;
        exit(0);
    }

    int nuevaX = posX;
    int nuevaY = posY;

    // Definir el movimiento según la dirección
    switch (direccion) {
    case 'W': nuevaX--; break;  // Mover hacia arriba
    case 'S': nuevaX++; break;  // Mover hacia abajo
    case 'A': nuevaY--; break;  // Mover hacia la izquierda
    case 'D': nuevaY++; break;  // Mover hacia la derecha
    default:
        std::cout << "Tecla inválida. Use W, A, S o D para moverse." << std::endl;
        return;
    }

    // Verificar si el movimiento es posible
    if (puedeMover(nuevaX, nuevaY)) {
        Nodo* nodoActual = tablero->obtenerNodo(posX, posY);  // Nodo donde está el jugador actualmente
        Nodo* nodoNuevo = tablero->obtenerNodo(nuevaX, nuevaY);  // Nodo a donde se mueve el jugador

        // Restaurar el símbolo original del nodo anterior
        if (nodoActual->esPunto) {
            nodoActual->simbolo = '.';  // Si era un punto, restaurarlo
        }
        else {
            nodoActual->simbolo = ' ';  // Si no, dejarlo vacío
        }

        // Actualizar la posición del jugador
        posX = nuevaX;
        posY = nuevaY;

        // Colocar el jugador en el nuevo nodo
        nodoNuevo->simbolo = '@';

        // Imprimir el tablero actualizado
        tablero->imprimir();
    }
    else {
        std::cout << "Movimiento no permitido hacia (" << nuevaX << ", " << nuevaY << ")" << std::endl;
    }
}

// Verificar si el jugador puede moverse a una nueva posición
bool Jugador::puedeMover(int nuevaX, int nuevaY) {
    if (nuevaX < 0 || nuevaX >= tablero->filas || nuevaY < 0 || nuevaY >= tablero->columnas) {
        std::cout << "Movimiento fuera de los límites del tablero" << std::endl;
        return false;  // Movimiento fuera del tablero
    }

    Nodo* destino = tablero->obtenerNodo(nuevaX, nuevaY);

    if (destino->simbolo == '#' || destino->simbolo == '!') {
        std::cout << "Movimiento bloqueado en (" << nuevaX << ", " << nuevaY << ")" << std::endl;
        return false;  // Movimiento bloqueado por una pared o una caja colocada
    }

    if (destino->simbolo == '$') {
        // Intentar mover una caja
        int cajaNuevaX = nuevaX + (nuevaX - posX);  // Calcular la nueva posición de la caja
        int cajaNuevaY = nuevaY + (nuevaY - posY);

        if (puedeMoverCaja(cajaNuevaX, cajaNuevaY)) {
            Nodo* cajaDestino = tablero->obtenerNodo(cajaNuevaX, cajaNuevaY);

            if (cajaDestino->simbolo == '.') {
                cajaDestino->simbolo = '!';  // Caja colocada en un punto
            }
            else {
                cajaDestino->simbolo = '$';  // Caja movida a un espacio vacío
            }

            destino->simbolo = '@';  // Mover al jugador a la posición de la caja
            return true;
        }
        else {
            return false;  // Movimiento de la caja no permitido
        }
    }

    return true;  // Movimiento permitido
}

// Verificar si una caja puede ser movida a una nueva posición
bool Jugador::puedeMoverCaja(int nuevaX, int nuevaY) {
    if (nuevaX < 0 || nuevaX >= tablero->filas || nuevaY < 0 || nuevaY >= tablero->columnas) {
        return false;  // Movimiento de la caja fuera del tablero
    }

    Nodo* cajaDestino = tablero->obtenerNodo(nuevaX, nuevaY);

    if (cajaDestino->simbolo == '#' || cajaDestino->simbolo == '$' || cajaDestino->simbolo == '!') {
        return false;  // Movimiento de la caja bloqueado
    }

    return true;  // Movimiento de la caja permitido
}