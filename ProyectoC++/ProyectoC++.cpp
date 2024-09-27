#include "Menu.h"
#include <iostream>
#include "Intro.h"

int main() {
    Intro intro;
    Juego juego;
    Menu menu;
    int opcion;

    while (true) {
        /*intro.mostrarIntro();*/
        menu.mostrarMenu();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        menu.seleccionarOpcion(opcion, juego);
    }

    return 0;
}
