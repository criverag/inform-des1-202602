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


SOURCES += \
    main.cpp \
    tablero.cpp \
    visualizacion.cpp \
    interaccion.cpp

HEADERS += \
    tablero.h \
    visualizacion.h \
    interaccion.h