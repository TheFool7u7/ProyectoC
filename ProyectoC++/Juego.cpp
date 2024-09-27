#include "Juego.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <atomic> // Para usar std::atomic<bool>

// Constructor del Juego
Juego::Juego() : nivelActual(1), tiempoNivel(1000000) , nivelFinalizado(false) {
    tablero = new Tablero(20, 20);  // Crear un tablero de 10x10
    jugador = new Jugador(2, 2, tablero);  // Posición inicial del jugador
}
void Juego::manejarTemporizador() {
    auto inicio = std::chrono::steady_clock::now();
    while (true) {
        // Salir del bucle si el nivel ha finalizado
        if (nivelFinalizado.load()) {
            break;
        }

        auto ahora = std::chrono::steady_clock::now();
        auto tiempoTranscurrido = std::chrono::duration_cast<std::chrono::seconds>(ahora - inicio).count();
        int tiempoRestante = tiempoNivel - tiempoTranscurrido;


        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Iniciar el juego
void Juego::iniciarJuego() {
    cargarSiguienteNivel();
    std::thread temporizador(&Juego::manejarTemporizador, this);

    temporizador.detach();  // Separar el hilo para que se ejecute en segundo plano

    while (true) {
        // Esperar a que el usuario presione una tecla sin bloquear la ejecución
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
    // Cargar el tablero guardado desde el archivo dado
    tablero->cargarNivel(archivo);

    // Buscar la posición del jugador en el tablero cargado
    int filaJugador, columnaJugador;
    if (tablero->encontrarPosicionJugador(filaJugador, columnaJugador)) {
        jugador = new Jugador(filaJugador, columnaJugador, tablero);
    }
    else {
        // Manejar el caso donde no se encuentra el jugador ('@') en el nivel
        std::cout << "Error: No se encontró al jugador ('@') en el nivel." << std::endl;
        jugador = new Jugador(1, 1, tablero); // Posición por defecto si hay error
    }

    // Imprimir el tablero cargado
    tablero->imprimir();

    // Continuar el juego después de cargar
    while (true) {
        if (_kbhit()) {  // Verifica si se ha presionado una tecla
            char direccion = _getch();  // Lee la tecla presionada
            if (direccion == 'g') {  // Si se presiona 'g', guardar partida y salir
                tablero->guardarPartida("partida_guardada.txt");
                std::cout << "Partida guardada. Saliendo..." << std::endl;
                break;  // Salir del bucle
            }
            else if (direccion == 'r') {  // Si se presiona 'r', reiniciar nivel
                tablero->reiniciarNivel();
            }
            else {  // Mover al jugador en la dirección especificada
                jugador->mover(direccion);
                tablero->imprimir();
                verificarVictoria();  // Verifica si se ha ganado la partida
            }
        }
    }
}

// Verificar si el jugador ha ganado el nivel
void Juego::verificarVictoria() {
    Nodo* fila = tablero->obtenerNodo(0, 0);
    while (fila) {
        Nodo* actual = fila;
        while (actual) {
            if (actual->simbolo == '$') return;  // Aún hay cajas sin colocar
            actual = actual->derecha;
        }
        fila = fila->abajo;
    }
    nivelFinalizado.store(true);
    std::cout << "¡Nivel completado!" << std::endl;

    // Preguntar si quiere ver los movimientos
    char respuesta;
    std::cout << "¿Quieres ver los movimientos usados para completar el nivel? (S/N): ";
    std::cin >> respuesta;
    if (toupper(respuesta) == 'S') {
        mostrarMovimientos();
        std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
        _getch();  // Esperar a que el usuario presione una tecla
    }

    cargarSiguienteNivel();
}

void Juego::mostrarMovimientos() const {
    const std::vector<char>& movimientos = jugador->obtenerMovimientos();
    std::cout << "Movimientos usados para completar el nivel: ";
    for (char movimiento : movimientos) {
        std::cout << movimiento << " ";
    }
    std::cout << std::endl;

    // Calcular y mostrar el tiempo total utilizando inicioNivel
    auto fin = std::chrono::steady_clock::now();
    auto tiempoTotal = std::chrono::duration_cast<std::chrono::seconds>(fin - inicioNivel).count();
    std::cout << "Tiempo total: " << tiempoTotal << " segundos" << std::endl;

}

// Cargar el siguiente nivel
void Juego::cargarSiguienteNivel() {

    if (nivelActual > 5) {
        std::cout << "¡Felicidades! Has completado todos los niveles." << std::endl;
        exit(0);
    }

    std::string archivoNivel = "nivel" + std::to_string(nivelActual) + ".txt";
    tablero->cargarNivel(archivoNivel);

    int filaJugador, columnaJugador;
    if (tablero->encontrarPosicionJugador(filaJugador, columnaJugador)) {
        jugador = new Jugador(filaJugador, columnaJugador, tablero);
        
    }
    else {
        std::cout << "Error: No se encontró al jugador ('@') en el nivel." << std::endl;
        jugador = new Jugador(1, 1, tablero); // Posición por defecto si hay error
    }


    inicioNivel = std::chrono::steady_clock::now();  // Registrar el tiempo de inicio del nuevo nivel

    tablero->imprimir();
    nivelActual++;

}