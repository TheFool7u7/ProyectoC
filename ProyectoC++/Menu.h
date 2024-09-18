// Menu.h
#ifndef MENU_H
#define MENU_H

#include "Juego.h"

class Menu {
public:
    // Mostrar el men� principal del juego
    void mostrarMenu();

    // Seleccionar la opci�n del men�
    void seleccionarOpcion(int opcion, Juego& juego);
};

#endif // MENU_H
