#ifndef TABLERO_H
#define TABLERO_H

#include "Nodo.h"
#include <string>

class Tablero {
public:
    int filas, columnas;
    Nodo* inicio;  // Nodo inicial del tablero
    std::string archivoNivel;  // Nombre del archivo del nivel

    // Constructor
    Tablero(int filas, int columnas);

    // Métodos del Tablero
    void construirTablero();
    void imprimir();
    void cargarNivel(std::string archivo);
    void guardarNivel(std::string archivo);
    Nodo* obtenerNodo(int fila, int columna);
    bool encontrarPosicionJugador(int& filaJugador, int& columnaJugador);
    void reiniciarNivel(); // Método para reiniciar el nivel
    void guardarPartida(std::string archivo);
    void limpiarTablero(); // Método para limpiar el tablero
};

#endif // TABLERO_H