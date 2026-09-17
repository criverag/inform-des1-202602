#ifndef TABLERO_H
#define TABLERO_H

const int BITS_POR_FICHA = 3;

// Codigos posibles para cada posicion del tablero (3 bits -> 0 a 7).
const unsigned char FICHA_A = 0;
const unsigned char FICHA_B = 1;
const unsigned char FICHA_C = 2;
const unsigned char FICHA_D = 3;
const unsigned char FICHA_E = 4;
const unsigned char FICHA_F = 5;
const unsigned char ESTADO_VACIO = 6;     // Posicion sin ficha (tras una eliminacion)
const unsigned char ESTADO_ESPECIAL = 7;  // Reservado para un uso futuro

// Cantidad de tipos de ficha "normales" (para el llenado aleatorio).
const int CANTIDAD_TIPOS_FICHA = 6;

// Calcula la cantidad minima de bytes necesarios para almacenar un
// tablero de "filas" x "columnas" posiciones, usando 3 bits por
// posicion (redondeando siempre hacia arriba).
int calcularBytesNecesarios(int filas, int columnas);

// Reserva dinamicamente la memoria necesaria para el tablero

unsigned char* crearTablero(int filas, int columnas);

// Libera la memoria dinamica reservada para el tablero (usando delete[]).
void liberarTablero(unsigned char* tablero);


unsigned char obtenerFicha(unsigned char* tablero, int posicion);


void asignarFicha(unsigned char* tablero, int posicion, unsigned char valor);


void llenarTableroAleatorio(unsigned char* tablero, int filas, int columnas);

#endif // TABLERO_H
