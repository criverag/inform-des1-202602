#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "visualizacion.h"
#include "interaccion.h"
#include "combinaciones.h"
using namespace std;



int main()
{
    // Semilla para los numeros aleatorios (distinta en cada ejecucion).
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

    // ------------------------------------------------------------
    // El jugador puede seleccionar posiciones del tablero y eliminar
    // la ficha correspondiente. Despues de cada eliminacion valida,
    // se revisa si se formaron combinaciones horizontales o verticales
    // de 3 o mas fichas iguales, y de ser asi, se eliminan tambien.
    //
    // Todavia NO se reorganiza el tablero (caida de fichas + relleno)
    // ni se procesan cascadas: eso se aborda en un proximo avance.
    // ------------------------------------------------------------
    int contadorEliminaciones = 0;
    int contadorFichasEliminadasTotal = 0;
    int contadorCombinacionesTotal = 0;
    bool continuarJugando = true;

    while (continuarJugando) {
        int filaSeleccionada = 0;
        int columnaSeleccionada = 0;

        cout << "\n--- Seleccionar ficha a eliminar ---\n";
        cout << "Ingrese la fila (0 a " << (filas - 1)
             << "), o -1 para terminar: ";
        cin >> filaSeleccionada;

        if (filaSeleccionada == -1) {
            continuarJugando = false;
        } else {
            cout << "Ingrese la columna (0 a " << (columnas - 1) << "): ";
            cin >> columnaSeleccionada;

            bool eliminada = eliminarFicha(tablero, filas, columnas,
                                            filaSeleccionada, columnaSeleccionada);

            if (eliminada) {
                contadorEliminaciones++;
                contadorFichasEliminadasTotal++;
                cout << "Ficha eliminada en (" << filaSeleccionada << ", "
                     << columnaSeleccionada << ").\n";
                mostrarTableroFichas(tablero, filas, columnas);
                mostrarTableroBinario(tablero, filas, columnas);

                // Tras la eliminacion manual, se revisa si se formaron
                // combinaciones de 3 o mas fichas iguales.
                int combinacionesEnEsteMovimiento = 0;
                int fichasEnEsteMovimiento = 0;
                bool huboCombinacion = procesarCombinaciones(tablero, filas, columnas,
                                                               combinacionesEnEsteMovimiento,
                                                               fichasEnEsteMovimiento);

                if (huboCombinacion) {
                    contadorCombinacionesTotal += combinacionesEnEsteMovimiento;
                    contadorFichasEliminadasTotal += fichasEnEsteMovimiento;

                    cout << "\nSe detectaron " << combinacionesEnEsteMovimiento
                         << " combinacion(es); se eliminaron " << fichasEnEsteMovimiento
                         << " ficha(s) adicionales.\n";
                    mostrarTableroFichas(tablero, filas, columnas);
                    mostrarTableroBinario(tablero, filas, columnas);
                } else {
                    cout << "\nNo se formaron combinaciones tras esta eliminacion.\n";
                }
            } else {
                cout << "No se pudo eliminar: la posicion esta fuera del "
                     << "tablero o ya se encuentra vacia.\n";
            }
        }
    }

    cout << "\n--- Resumen de la partida ---\n";
    cout << "Eliminaciones realizadas por el jugador: " << contadorEliminaciones << endl;
    cout << "Combinaciones detectadas: " << contadorCombinacionesTotal << endl;
    cout << "Total de fichas eliminadas (manual + combinaciones): "
         << contadorFichasEliminadasTotal << endl;

    // Se libera la memoria dinamica reservada para el tablero.
    liberarTablero(tablero);
    tablero = nullptr;

    return 0;
}
