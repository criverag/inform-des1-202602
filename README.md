# inform-des1-202602

Repositorio para dar seguimiento al desarrolo del desafío 1 del curso de informática 2.

# Desafío 1 Informática 2

Este desafío consiste en diseñar e implementar el juego Sweet Crush, aplicando conceptos de operadores
a nivel de bits (bitwise) y gestión de memoria dinámica, bajo restricciones estrictas de programación
estructurada.

## **Momento 1**: 

Informe preliminar.

El día 11 de septiembre (11:59 pm), para adjuntar la evidencia del proceso de análisis y
diseño de la solución. (Informe preliminar: Contextualización, Análisis, Diseño).

## Avances

- Detectar y eliminar combinaciones horizontales y verticales.
  
- Nuevo modulo combinaciones.h/.cpp: deteccion de rachas de 3+ fichas
  iguales por fila y por columna, marcado temporal con arreglo auxiliar
  y eliminacion de las fichas marcadas.
  
- 'main.cpp': se invoca 'procesarCombinaciones()' tras cada eliminacion
  manual exitosa y se amplian los contadores de estado del juego
  (combinaciones detectadas, fichas eliminadas totales).

## Porcentaje de Avance Estimado

Progreso: 50%
[████████████████████--------------------]
