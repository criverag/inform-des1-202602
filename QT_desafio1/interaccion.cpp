#include "interaccion.h"

bool posicionValida(int fila, int columna, int filas, int columnas)
{
    if (fila < 0 || fila >= filas) {
        return false;
    }
    if (columna < 0 || columna >= columnas) {
        return false;
    }
    return true;
}

bool eliminarFicha(unsigned char* tablero, int filas, int columnas, int fila, int columna)
{
    // Primero se valida que la posicion exista dentro del tablero.
    if (!posicionValida(fila, columna, filas, columnas)) {
        return false;
    }

    // Se traduce (fila, columna) a la posicion logica correspondiente,
    // igual que en tablero.cpp: posicion = fila * columnas + columna.
    int posicion = fila * columnas + columna;

    // No tiene sentido "eliminar" una posicion que ya esta vacia.
    if (obtenerFicha(tablero, posicion) == ESTADO_VACIO) {
        return false;
    }


    asignarFicha(tablero, posicion, ESTADO_VACIO);

    return true;
}
