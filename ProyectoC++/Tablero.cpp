// Tablero.cpp
#include "Tablero.h"
#include <iostream>
#include <fstream>

// Constructor del Tablero
Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    inicio = new Nodo(' ');  // Nodo inicial vacío
    construirTablero();
}

// Construir el tablero con nodos enlazados
void Tablero::construirTablero() {
    Nodo* actual = inicio;
    Nodo* filaAnterior = nullptr;

    for (int i = 0; i < filas; ++i) {
        Nodo* inicioFila = actual;

        for (int j = 0; j < columnas; ++j) {
            if (j != 0) {
                actual->derecha = new Nodo(' ');
                actual->derecha->izquierda = actual;
                actual = actual->derecha;
            }

            if (filaAnterior != nullptr) {
                filaAnterior->abajo = actual;
                actual->arriba = filaAnterior;
                filaAnterior = filaAnterior->derecha;
            }
        }

        filaAnterior = inicioFila;
        if (i < filas - 1) {
            actual = new Nodo(' ');
            inicioFila->abajo = actual;
        }
    }
}

// Imprimir el tablero en consola
void Tablero::imprimir() {
    Nodo* fila = inicio;
    while (fila) {
        Nodo* actual = fila;
        while (actual) {
            std::cout << actual->simbolo << " ";
            actual = actual->derecha;
        }
        std::cout << std::endl;
        fila = fila->abajo;
    }
}

// Cargar un nivel desde un archivo
void Tablero::cargarNivel(std::string archivo) {
    std::ifstream archivoNivel(archivo);
    if (!archivoNivel.is_open()) {
        std::cout << "Error al abrir el archivo del nivel" << std::endl;
        return;
    }

    Nodo* fila = inicio;
    std::string linea;
    while (getline(archivoNivel, linea) && fila) {
        Nodo* actual = fila;
        for (char c : linea) {
            actual->simbolo = c;
            if (c == '.' || c == '!') {  // Punto de destino o caja colocada en un punto
                actual->esPunto = true;
            }
            actual = actual->derecha;
        }
        fila = fila->abajo;
    }
    archivoNivel.close();
}

// Guardar el nivel en un archivo
void Tablero::guardarNivel(std::string archivo) {
    std::ofstream archivoNivel(archivo);
    Nodo* fila = inicio;
    while (fila) {
        Nodo* actual = fila;
        while (actual) {
            archivoNivel << actual->simbolo;
            actual = actual->derecha;
        }
        archivoNivel << std::endl;
        fila = fila->abajo;
    }
    archivoNivel.close();
}

// Obtener un nodo en una posición específica del tablero
Nodo* Tablero::obtenerNodo(int fila, int columna) {
    Nodo* actual = inicio;
    for (int i = 0; i < fila && actual; ++i) {
        actual = actual->abajo;
    }
    for (int j = 0; j < columna && actual; ++j) {
        actual = actual->derecha;
    }
    return actual;
}

// Función para encontrar la posición inicial del jugador ('@')
bool Tablero::encontrarPosicionJugador(int& filaJugador, int& columnaJugador) {
    Nodo* fila = inicio;
    int filaActual = 0;
    while (fila) {
        Nodo* actual = fila;
        int columnaActual = 0;
        while (actual) {
            if (actual->simbolo == '@') {
                filaJugador = filaActual;
                columnaJugador = columnaActual;
                return true; // Jugador encontrado
            }
            actual = actual->derecha;
            columnaActual++;
        }
        fila = fila->abajo;
        filaActual++;
    }
    return false; // Jugador no encontrado
}
