#include "visualizacion.h"
#include <iostream>
using namespace std;


char caracterFicha(unsigned char valor)
{
    switch (valor) {
        case FICHA_A: return 'A';
        case FICHA_B: return 'B';
        case FICHA_C: return 'C';
        case FICHA_D: return 'D';
        case FICHA_E: return 'E';
        case FICHA_F: return 'F';
        case ESTADO_VACIO: return '.';
        default: return '?';
    }
}

void mostrarTableroFichas(unsigned char* tablero, int filas, int columnas)
{
    cout << "\nTablero (formato fichas):\n";

    int posicion = 0;
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            unsigned char valor = obtenerFicha(tablero, posicion);
            cout << caracterFicha(valor) << " ";
            posicion++;
        }
        cout << endl;
    }
}

void mostrarTableroBinario(unsigned char* tablero, int filas, int columnas)
{
    int bytesTotales = calcularBytesNecesarios(filas, columnas);

    cout << "\nTablero (formato binario, byte por byte, tal como esta en memoria):\n";

    for (int i = 0; i < bytesTotales; i++) {

        for (int b = 7; b >= 0; b--) {
            unsigned char bit = (tablero[i] >> b) & 1;
            // Se usa static_cast en lugar de un cast estilo C (int)bit,
            // que es la forma propia de C++ para convertir tipos.
            cout << static_cast<int>(bit);
        }
        cout << " ";
    }
    cout << endl;
}
