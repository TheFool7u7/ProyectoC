#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include <stack>
#include <chrono>
#include <thread>
#include <atomic> 


class Juego {
private:
    Tablero* tablero;                   // Puntero al tablero actual
    Jugador* jugador;                   // Puntero al jugador
    std::stack<Nodo*> cajasColocadas;   // Pila de cajas colocadas correctamente
    int nivelActual;                    // Número del nivel actual
    int tiempoNivel;    
    std::chrono::steady_clock::time_point inicioNivel; // Tiempo límite para el nivel actual en segundos
    std::atomic<bool> nivelFinalizado;

public:
    // Constructor del Juego
    Juego();

    // Iniciar el juego
    void iniciarJuego();

    // Cargar un juego guardado desde un archivo
    void cargarJuego(const std::string& archivo);

    // Verificar si el jugador ha ganado el nivel
    void verificarVictoria();

    // Cargar el siguiente nivel
    void cargarSiguienteNivel();

    // Mostrar los movimientos realizados
    void mostrarMovimientos() const;

    // Manejar el temporizador del nivel
    void manejarTemporizador();
};

#endif // JUEGO_H