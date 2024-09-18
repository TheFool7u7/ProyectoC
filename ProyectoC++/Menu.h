// Menu.h
#ifndef MENU_H
#define MENU_H

#include "Juego.h"

class Menu {
public:
    // Mostrar el menú principal del juego
    void mostrarMenu();

    // Seleccionar la opción del menú
    void seleccionarOpcion(int opcion, Juego& juego);
};

#endif // MENU_H
