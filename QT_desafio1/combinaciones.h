#ifndef COMBINACIONES_H
#define COMBINACIONES_H

#include "tablero.h"

// Recorre el tablero por filas y marca (en "marcas") las posiciones que
// forman parte de una racha horizontal de 3 o mas fichas iguales.
// "marcas" debe ser un arreglo de tamano filas*columnas, ya reservado
// por quien llama esta funcion.
// Retorna la cantidad de combinaciones horizontales encontradas.
int detectarCombinacionesHorizontales(unsigned char* tablero, int filas, int columnas, bool* marcas);

// Igual que la anterior, pero recorriendo por columnas (sentido vertical).
int detectarCombinacionesVerticales(unsigned char* tablero, int filas, int columnas, bool* marcas);

// Recorre "marcas" y, por cada posicion marcada como true, vacia la ficha
// correspondiente en el tablero (ESTADO_VACIO).
// Retorna la cantidad de fichas que realmente fueron eliminadas.
int eliminarFichasMarcadas(unsigned char* tablero, int filas, int columnas, bool* marcas);

// Funcion principal del modulo: detecta combinaciones horizontales y
// verticales, elimina las fichas involucradas, y reporta por referencia
// cuantas combinaciones y cuantas fichas fueron eliminadas.
// Retorna true si se elimino al menos una ficha por combinacion.
bool procesarCombinaciones(unsigned char* tablero, int filas, int columnas,
                            int& combinacionesDetectadas, int& fichasEliminadas);

#endif // COMBINACIONES_H
