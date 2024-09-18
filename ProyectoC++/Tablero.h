// Tablero.h
#ifndef TABLERO_H
#define TABLERO_H

#include "Nodo.h"
#include <string>

class Tablero {

public:

    Nodo* inicio;           // Puntero al primer nodo del tablero
    int filas, columnas;    // Dimensiones del tablero

    // Constructor del Tablero
    Tablero(int filas, int columnas);

    // Imprimir el tablero en la consola
    void imprimir();

    // Cargar un nivel desde un archivo .txt
    void cargarNivel(std::string archivo);

    // Guardar el nivel actual en un archivo .txt
    void guardarNivel(std::string archivo);

    // Obtener un nodo en una posición específica del tablero
    Nodo* obtenerNodo(int fila, int columna);
    // Método para construir el tablero utilizando una lista enlazada
    void construirTablero();
    bool encontrarPosicionJugador(int& filaJugador, int& columnaJugador);
};

#endif // TABLERO_H
