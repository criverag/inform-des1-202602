#include "tablero.h"
#include <cstdlib> // rand()

int calcularBytesNecesarios(int filas, int columnas)
{
    int totalBits = BITS_POR_FICHA * filas * columnas;

    // Redondeo hacia arriba: si sobran bits que no completan un byte,
    // igual se necesita un byte adicional para almacenarlos.
    int totalBytes = (totalBits + 7) / 8;

    return totalBytes;
}

unsigned char* crearTablero(int filas, int columnas)
{
    int bytesNecesarios = calcularBytesNecesarios(filas, columnas);

    // Memoria dinamica: el tablero se representa como un arreglo de
    // bytes (unsigned char) reservado en tiempo de ejecucion, cuyo
    // tamano depende de las dimensiones indicadas por el usuario.
    unsigned char* tablero = new unsigned char[bytesNecesarios];

    // Se inicializa todo el bloque en 0 para no trabajar con memoria
    // sin inicializar (0 corresponde al codigo de la Ficha A, pero de
    // todas formas el tablero se llena enseguida en llenarTableroAleatorio).
    for (int i = 0; i < bytesNecesarios; i++) {
        tablero[i] = 0;
    }

    return tablero;
}

void liberarTablero(unsigned char* tablero)
{
    // Libera la memoria reservada con "new[]" en crearTablero().
    delete[] tablero;
}

unsigned char obtenerFicha(unsigned char* tablero, int posicion)
{
    unsigned char valor = 0;

    // Bit global (dentro de la secuencia continua) donde inicia la ficha.
    int bitInicial = posicion * BITS_POR_FICHA;

    // Se recorren los 3 bits de la ficha, del mas significativo al
    // menos significativo, y se van "armando" dentro de "valor".
    for (int i = 0; i < BITS_POR_FICHA; i++) {
        int bitGlobal = bitInicial + i;

        // A que byte del arreglo pertenece este bit, y en que posicion
        // (0 a 7, contada desde el bit mas significativo) esta dentro
        // de ese byte.
        int indiceByte = bitGlobal / 8;
        int posicionEnByte = bitGlobal % 8;

        // Mascara con un unico 1 en la posicion que interesa leer.
        unsigned char mascara = 1 << (7 - posicionEnByte);

        // Operador & para extraer ese bit especifico del byte.
        // (Se usa if/else en lugar del operador ternario "?:" para
        // mantener el codigo dentro de las estructuras de control
        // vistas en el curso.)
        unsigned char bit;
        if (tablero[indiceByte] & mascara) {
            bit = 1;
        } else {
            bit = 0;
        }

        // Se desplaza "valor" un bit a la izquierda (<<) y se agrega
        // el nuevo bit leido con un OR (|) en la posicion menos
        // significativa.
        valor = (valor << 1) | bit;
    }

    return valor;
}

void asignarFicha(unsigned char* tablero, int posicion, unsigned char valor)
{
    int bitInicial = posicion * BITS_POR_FICHA;

    for (int i = 0; i < BITS_POR_FICHA; i++) {
        int bitGlobal = bitInicial + i;
        int indiceByte = bitGlobal / 8;
        int posicionEnByte = bitGlobal % 8;

        unsigned char mascara = 1 << (7 - posicionEnByte);

        // Se extrae, de "valor", el bit que corresponde a esta
        // iteracion (empezando por el mas significativo de los 3).
        unsigned char bit = (valor >> (BITS_POR_FICHA - 1 - i)) & 1;

        if (bit == 1) {
            // Enciende el bit correspondiente usando OR con la mascara.
            tablero[indiceByte] = tablero[indiceByte] | mascara;
        } else {
            // Apaga el bit correspondiente usando AND con la mascara
            // negada (~mascara tiene un 0 unicamente en esa posicion).
            tablero[indiceByte] = tablero[indiceByte] & (~mascara);
        }
    }
}

void llenarTableroAleatorio(unsigned char* tablero, int filas, int columnas)
{
    int totalPosiciones = filas * columnas;

    for (int p = 0; p < totalPosiciones; p++) {
        // Distribucion uniforme entre los 6 tipos de ficha (0 a 5).
        unsigned char ficha = rand() % CANTIDAD_TIPOS_FICHA;
        asignarFicha(tablero, p, ficha);
    }
}
