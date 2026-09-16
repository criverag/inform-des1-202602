#ifndef TABLERO_H
#define TABLERO_H

// ============================================================
// Modulo: Tablero
//
// Contiene las funciones responsables de:
//   - Calcular cuanta memoria necesita el tablero.
//   - Reservar y liberar esa memoria en forma dinamica.
//   - Leer y escribir cada ficha manipulando directamente los bits.
//   - Generar el llenado inicial aleatorio del tablero.
//
// REPRESENTACION DEL TABLERO (obligatoria segun el desafio):
// Cada ficha ocupa EXACTAMENTE 3 bits. El tablero se guarda como
// una secuencia CONTINUA de bits (sin rellenar para alinear cada
// ficha a un byte), empaquetada dentro de un arreglo dinamico de
// tipo "unsigned char" (bytes).
//
// El primer bit de la secuencia corresponde al bit mas significativo
// (bit 7) del primer byte, y los bits siguientes se van ubicando uno
// despues de otro, incluso si eso significa que una ficha queda
// repartida entre dos bytes consecutivos (ver Figuras 2 y 3 del
// documento del desafio).
// ============================================================

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
// (usando new) y la deja inicializada en cero. Devuelve el
// puntero al bloque de memoria reservado.
unsigned char* crearTablero(int filas, int columnas);

// Libera la memoria dinamica reservada para el tablero (usando delete[]).
void liberarTablero(unsigned char* tablero);

// Obtiene el valor (0 a 7) almacenado en la posicion logica indicada.
// La posicion logica recorre el tablero fila por fila, de izquierda a
// derecha, comenzando en 0 (posicion = fila * columnas + columna).
unsigned char obtenerFicha(unsigned char* tablero, int posicion);

// Asigna un valor (0 a 7) a la posicion logica indicada, modificando
// unicamente los 3 bits que le corresponden dentro del tablero.
void asignarFicha(unsigned char* tablero, int posicion, unsigned char valor);

// Llena todas las posiciones del tablero con fichas aleatorias
// (tipos 0 a 5), siguiendo una distribucion uniforme.
void llenarTableroAleatorio(unsigned char* tablero, int filas, int columnas);

#endif // TABLERO_H
