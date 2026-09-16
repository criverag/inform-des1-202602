#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "visualizacion.h"
using namespace std;

// ============================================================
// Sweet Crush - Avance 1
//
// En este avance el programa unicamente:
//   1) Pide al usuario las dimensiones del tablero.
//   2) Reserva dinamicamente la memoria necesaria (representacion
//      compacta de 3 bits por ficha).
//   3) Llena el tablero con fichas aleatorias (6 tipos posibles).
//   4) Muestra el tablero en formato de fichas y en formato binario.
//   5) Libera la memoria antes de terminar.
//
// Todavia NO se implementa: seleccionar/eliminar fichas, detectar
// combinaciones, aplicar gravedad, agregar/eliminar filas o columnas,
// cascadas ni puntuacion. Esas funcionalidades se agregaran en los
// proximos avances.
// ============================================================

int main()
{
    // Semilla para los numeros aleatorios (distinta en cada ejecucion).
    // time(0) se convierte automaticamente al tipo que espera srand(),
    // por lo que no se necesita ningun cast explicito.
    srand(time(0));

    int filas = 0;
    int columnas = 0;

    // Se solicitan las dimensiones y se valida que sean positivas.
    do {
        cout << "Ingrese el numero de filas del tablero: ";
        cin >> filas;
        cout << "Ingrese el numero de columnas del tablero: ";
        cin >> columnas;

        if (filas <= 0 || columnas <= 0) {
            cout << "Las dimensiones deben ser numeros positivos. Intente de nuevo.\n";
        }
    } while (filas <= 0 || columnas <= 0);

    // Se crea el tablero reservando memoria dinamica.
    unsigned char* tablero = crearTablero(filas, columnas);

    // Se llena el tablero con fichas aleatorias (distribucion uniforme).
    llenarTableroAleatorio(tablero, filas, columnas);

    // Se muestra el estado inicial del tablero en los dos formatos.
    mostrarTableroFichas(tablero, filas, columnas);
    mostrarTableroBinario(tablero, filas, columnas);

    cout << "\nBytes reservados para este tablero: "
         << calcularBytesNecesarios(filas, columnas) << endl;

    // --- Funcionalidades pendientes para proximos avances ---
    // - Seleccionar y eliminar una ficha indicada por el jugador.
    // - Detectar combinaciones horizontales y verticales (3 o mas).
    // - Aplicar gravedad para que las fichas caigan (sin generar
    //   fichas nuevas, segun la modificacion indicada del juego).
    // - Agregar/eliminar filas y columnas en posiciones intermedias.
    // - Redimensionar realmente la memoria fisica del tablero.
    // - Procesar cascadas.
    // - Llevar el estado del juego (eliminaciones, puntuacion, etc.).

    // Se libera la memoria dinamica reservada para el tablero.
    liberarTablero(tablero);
    tablero = nullptr;

    return 0;
}