#include "combinaciones.h"

// Una posicion solo cuenta para una combinacion si contiene una ficha
// "normal" (0 a 5). ESTADO_VACIO y ESTADO_ESPECIAL nunca forman parte
// de una combinacion.
bool esFichaNormal(unsigned char valor)
{
    return valor < CANTIDAD_TIPOS_FICHA;
}

int detectarCombinacionesHorizontales(unsigned char* tablero, int filas, int columnas, bool* marcas)
{
    int combinacionesEncontradas = 0;

    for (int f = 0; f < filas; f++) {
        int c = 0;
        while (c < columnas) {
            int posicionInicio = f * columnas + c;
            unsigned char valorActual = obtenerFicha(tablero, posicionInicio);

            // Las posiciones vacias o especiales no inician racha; se avanza.
            if (!esFichaNormal(valorActual)) {
                c++;
                continue;
            }

            // Se mide cuantas posiciones consecutivas, a la derecha,
            // tienen exactamente el mismo valor de ficha.
            int longitud = 1;
            while (c + longitud < columnas) {
                int posicionSiguiente = f * columnas + (c + longitud);
                if (obtenerFicha(tablero, posicionSiguiente) != valorActual) {
                    break;
                }
                longitud++;
            }

            // Si la racha tiene 3 o mas posiciones, es una combinacion valida.
            if (longitud >= 3) {
                combinacionesEncontradas++;
                for (int i = 0; i < longitud; i++) {
                    marcas[f * columnas + (c + i)] = true;
                }
            }

            // Se salta toda la racha ya evaluada (evita reevaluar posiciones).
            c += longitud;
        }
    }

    return combinacionesEncontradas;
}

int detectarCombinacionesVerticales(unsigned char* tablero, int filas, int columnas, bool* marcas)
{
    int combinacionesEncontradas = 0;

    for (int c = 0; c < columnas; c++) {
        int f = 0;
        while (f < filas) {
            int posicionInicio = f * columnas + c;
            unsigned char valorActual = obtenerFicha(tablero, posicionInicio);

            if (!esFichaNormal(valorActual)) {
                f++;
                continue;
            }

            int longitud = 1;
            while (f + longitud < filas) {
                int posicionSiguiente = (f + longitud) * columnas + c;
                if (obtenerFicha(tablero, posicionSiguiente) != valorActual) {
                    break;
                }
                longitud++;
            }

            if (longitud >= 3) {
                combinacionesEncontradas++;
                for (int i = 0; i < longitud; i++) {
                    marcas[(f + i) * columnas + c] = true;
                }
            }

            f += longitud;
        }
    }

    return combinacionesEncontradas;
}

int eliminarFichasMarcadas(unsigned char* tablero, int filas, int columnas, bool* marcas)
{
    int totalPosiciones = filas * columnas;
    int fichasEliminadas = 0;

    for (int p = 0; p < totalPosiciones; p++) {
        if (marcas[p]) {
            asignarFicha(tablero, p, ESTADO_VACIO);
            fichasEliminadas++;
        }
    }

    return fichasEliminadas;
}

bool procesarCombinaciones(unsigned char* tablero, int filas, int columnas,
                            int& combinacionesDetectadas, int& fichasEliminadas)
{
    int totalPosiciones = filas * columnas;

    // Arreglo auxiliar temporal: una bandera por cada posicion logica del
    // tablero (no por byte). Se usa solo para coordinar la deteccion
    // horizontal/vertical antes de eliminar, y se libera antes de salir.
    bool* marcas = new bool[totalPosiciones];
    for (int i = 0; i < totalPosiciones; i++) {
        marcas[i] = false;
    }

    int combosHorizontales = detectarCombinacionesHorizontales(tablero, filas, columnas, marcas);
    int combosVerticales = detectarCombinacionesVerticales(tablero, filas, columnas, marcas);

    combinacionesDetectadas = combosHorizontales + combosVerticales;
    fichasEliminadas = eliminarFichasMarcadas(tablero, filas, columnas, marcas);

    delete[] marcas;
    marcas = nullptr;

    return fichasEliminadas > 0;
}
