// Menu.cpp
#include "Menu.h"
#include <iostream>

// Mostrar el menú principal del juego
void Menu::mostrarMenu() {
	const std::string RESET = "\033[0m"; // Restablece el color por defecto
	const std::string CYAN = "\033[36m"; // Cyan
	const std::string AMARILLO = "\033[33m"; // Amarillo
	const std::string MAGENTA = "\033[35m"; // Magenta

	std::cout << CYAN << "          -----++++------++++-                                                                        -------..." << RESET << std::endl;
	std::cout << CYAN << "          -.---++##+-.---++##+                                                                        --+++-.---" << RESET << std::endl;
	std::cout << CYAN << "          -.-..++++--.-..++++-                                                                        --++------" << RESET << std::endl;
	std::cout << CYAN << "          --.-------++-+-                                                                                  ++++-" << RESET << std::endl;
	std::cout << CYAN << "          -.--.-.---++##+                                                                                  ##+--" << RESET << std::endl;
	std::cout << CYAN << "          -.--..-.-.----.                                                                                  .---." << RESET << std::endl;
	std::cout << CYAN << "          ++++------        " << RESET; std::cout << AMARILLO << ":'######:::'#######::'##:::'##::'#######::'########:::::'###::::'##::: ##:" << RESET << std::endl;
	std::cout << CYAN << "          ##+----+#+        " << RESET; std::cout << AMARILLO << "'##... ##:'##.... ##: ##::'##::'##.... ##: ##.... ##:::'## ##::: ###:: ##:" << RESET << std::endl;
	std::cout << CYAN << "          -+---             " << RESET; std::cout << AMARILLO << " ##:::..:: ##:::: ##: ##:'##::: ##:::: ##: ##:::: ##::'##:. ##:: ####: ##:" << RESET << std::endl;
	std::cout << CYAN << "          -----             " << RESET; std::cout << AMARILLO << ". ######:: ##:::: ##: #####:::: ##:::: ##: ########::'##:::. ##: ## ## ##:" << RESET << std::endl;
	std::cout << CYAN << "          -.++-             " << RESET; std::cout << AMARILLO << ":..... ##: ##:::: ##: ##. ##::: ##:::: ##: ##.... ##: #########: ##. ####:" << RESET << std::endl;
	std::cout << CYAN << "                            " << RESET; std::cout << AMARILLO << "'##::: ##: ##:::: ##: ##:. ##:: ##:::: ##: ##:::: ##: ##.... ##: ##:. ###:" << RESET << std::endl;
	std::cout << CYAN << "                            " << RESET; std::cout << AMARILLO << ". ######::. #######:: ##::. ##:. #######:: ########:: ##:::: ##: ##::. ##:" << RESET << std::endl;
	std::cout << CYAN << "                            " << RESET; std::cout << AMARILLO << ":......::::.......:::..::::..:::.......:::........:::..:::::..::..::::..::" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << MAGENTA << "                                                         1 JUEGO NUEVO" << RESET << std::endl;
	std::cout << CYAN << "                            __________________________________________________________________________" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << MAGENTA << "                                                         2 CARGAR JUEGO" << RESET << std::endl;
	std::cout << CYAN << "                            __________________________________________________________________________" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << MAGENTA << "                                                            3 SALIR" << RESET << std::endl;

}

// Seleccionar la opción del menú
void Menu::seleccionarOpcion(int opcion, Juego& juego) {

	switch (opcion) {
	case 1:
		juego.iniciarJuego();
		break;
	case 2:
		juego.cargarJuego("partida_guardada.txt");  // Carga la última partida guardada
		break;
	case 3:
		std::cout << "Saliendo del juego..." << std::endl;
		exit(0);
	default:
		std::cout << "Opción inválida." << std::endl;
	}
}
