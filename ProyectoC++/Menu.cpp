// Menu.cpp
#include "Menu.h"
#include <iostream>

// Mostrar el men� principal del juego
void Menu::mostrarMenu() {
    std::cout << "1. Nuevo Juego" << std::endl;
    std::cout << "2. Cargar Partida" << std::endl;
    std::cout << "3. Salir" << std::endl;
}

// Seleccionar la opci�n del men�
void Menu::seleccionarOpcion(int opcion, Juego& juego) {
    switch (opcion) {
    case 1:
        juego.iniciarJuego();
        break;
    case 2:
        juego.cargarJuego("partida_guardada.txt");  // Carga la �ltima partida guardada
        break;
    case 3:
        std::cout << "Saliendo del juego..." << std::endl;
        exit(0);
    default:
        std::cout << "Opci�n inv�lida." << std::endl;
    }
}
