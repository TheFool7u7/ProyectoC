// Juego.cpp
#include "Juego.h"
#include <iostream>
#include <fstream>
#include <conio.h>

// Constructor del Juego
Juego::Juego() : nivelActual(1) {
    tablero = new Tablero(10, 10);  // Crear un tablero de 10x10
    jugador = new Jugador(2, 2, tablero);  // Posici�n inicial del jugador
}

// Iniciar el juego
void Juego::iniciarJuego() {
    tablero->cargarNivel("nivel1.txt");

    int filaJugador, columnaJugador;
    if (tablero->encontrarPosicionJugador(filaJugador, columnaJugador)) {
        jugador = new Jugador(filaJugador, columnaJugador, tablero);
    }
    else {
        // Manejar el caso donde no se encuentra el jugador en el nivel (opcional)
        std::cout << "Error: No se encontr� al jugador ('@') en el nivel." << std::endl;
        jugador = new Jugador(1, 1, tablero); // Posici�n por defecto si hay error
    }

    tablero->imprimir();


    while (true) {
        // Esperar a que el usuario presione una tecla sin bloquear la ejecuci�n
        if (_kbhit()) {
            char direccion = _getch(); // Leer la tecla presionada sin mostrar en pantalla
            jugador->mover(direccion);
            tablero->imprimir();
            verificarVictoria();
        }
    }
}

// Cargar un juego guardado desde un archivo
void Juego::cargarJuego(const std::string& archivo) {
    tablero->cargarNivel(archivo);  // Cargar el nivel desde el archivo dado

    int filaJugador, columnaJugador;
    if (tablero->encontrarPosicionJugador(filaJugador, columnaJugador)) {
        jugador = new Jugador(filaJugador, columnaJugador, tablero);
    }
    else {
        // Manejar el caso donde no se encuentra el jugador (opcional)
        std::cout << "Error: No se encontr� al jugador ('@') en el nivel." << std::endl;
        jugador = new Jugador(1, 1, tablero); // Posici�n por defecto si hay error
    }

    tablero->imprimir();            // Imprimir el tablero cargado

    // Continuar el juego despu�s de cargar
    while (true) {
        if (_kbhit()) {
            char direccion = _getch();
            jugador->mover(direccion);
            tablero->imprimir();
            verificarVictoria();
        }
    }
}

// Verificar si el jugador ha ganado el nivel
void Juego::verificarVictoria() {
    Nodo* fila = tablero->obtenerNodo(0, 0);
    while (fila) {
        Nodo* actual = fila;
        while (actual) {
            if (actual->simbolo == '$') return;  // A�n hay cajas sin colocar
            actual = actual->derecha;
        }
        fila = fila->abajo;
    }
    std::cout << "�Nivel completado!" << std::endl;
}
