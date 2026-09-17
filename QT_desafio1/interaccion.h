#ifndef INTERACCION_H
#define INTERACCION_H

#include "tablero.h"



// Indica si la posicion (fila, columna) esta dentro de los limites
// del tablero de "filas" x "columnas".
bool posicionValida(int fila, int columna, int filas, int columnas);


bool eliminarFicha(unsigned char* tablero, int filas, int columnas, int fila, int columna);

#endif // INTERACCION_H
