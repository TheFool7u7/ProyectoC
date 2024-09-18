#include "Menu.h"
#include <iostream>

int main() {
    Juego juego;
    Menu menu;
    int opcion;

    while (true) {
        menu.mostrarMenu();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        menu.seleccionarOpcion(opcion, juego);
    }

    return 0;
}
