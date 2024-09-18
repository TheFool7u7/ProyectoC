// Menu.cpp
#include "Menu.h"
#include <iostream>

// Mostrar el menú principal del juego
void Menu::mostrarMenu() {
    std::cout << "1. Nuevo Juego" << std::endl;
    std::cout << "2. Cargar Partida" << std::endl;
    std::cout << "3. Salir" << std::endl;
}

// Seleccionar la opción del menú
void Menu::seleccionarOpcion(int opcion, Juego& juego) {
    switch (opcion) {
    case 1:
        juego.iniciarJuego();
        break;
    case 2: {
        std::string archivo;
        std::cout << "Ingrese el nombre del archivo: ";
        std::cin >> archivo;
        juego.cargarJuego(archivo);
        break;
    }
    case 3:
        std::cout << "Saliendo del juego..." << std::endl;
        exit(0);
    default:
        std::cout << "Opción inválida." << std::endl;
    }
}
