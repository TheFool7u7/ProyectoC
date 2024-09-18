// Nodo.h
#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    char simbolo;           // Representa el contenido del nodo (@, $, #, etc.)
    Nodo* arriba;           // Puntero al nodo de arriba
    Nodo* abajo;            // Puntero al nodo de abajo
    Nodo* izquierda;        // Puntero al nodo a la izquierda
    Nodo* derecha;          // Puntero al nodo a la derecha

    // Constructor de Nodo
    Nodo(char simbolo);
};

#endif // NODO_H
