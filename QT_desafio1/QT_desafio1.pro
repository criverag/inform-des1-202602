#TEMPLATE = app
#CONFIG += console c++17
#CONFIG -= app_bundle
#CONFIG -= qt

#SOURCES += \
#        main.cpp


####################

QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# Avance 1: por ahora el proyecto no utiliza clases de Qt, solo C++
# estandar (cin/cout, punteros, memoria dinamica, arreglos y
# operadores de bits). Se usa igualmente la infraestructura de Qt
# Creator (.pro) porque asi lo exige el desafio.

SOURCES += \
    main.cpp \
    tablero.cpp \
    visualizacion.cpp

HEADERS += \
    tablero.h \
    visualizacion.h