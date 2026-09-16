#ifndef VISUALIZACION_H
#define VISUALIZACION_H

#include "tablero.h"

// Muestra el tablero en pantalla usando un caracter representativo
// para cada tipo de ficha (formato "fichas", pensado para el jugador).
void mostrarTableroFichas(unsigned char* tablero, int filas, int columnas);

// Muestra el contenido fisico del tablero en formato binario, byte
// por byte, tal como esta almacenado realmente en memoria. Sirve
// para comprobar que la representacion compacta de bits funciona
// correctamente.
void mostrarTableroBinario(unsigned char* tablero, int filas, int columnas);

#endif // VISUALIZACION_H
