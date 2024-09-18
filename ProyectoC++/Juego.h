// Juego.h
#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include <stack>

class Juego {
private:
    Tablero* tablero;                   // Puntero al tablero actual
    Jugador* jugador;                   // Puntero al jugador
    std::stack<Nodo*> cajasColocadas;   // Pila de cajas colocadas correctamente
    int nivelActual;                    // Número del nivel actual

public:
    // Constructor del Juego
    Juego();

    // Iniciar el juego
    void iniciarJuego();

    // Cargar un juego guardado desde un archivo
    void cargarJuego(const std::string& archivo);

    // Verificar si el jugador ha ganado el nivel
    void verificarVictoria();
};

#endif // JUEGO_H
