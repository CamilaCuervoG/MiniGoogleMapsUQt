#include "mapa.h"

// La mayoría de la lógica ya está implementada en Mapa.h
// Dado que usamos objetos que manejan su propia memoria (Grafo, Árbol, Listas, Historial),
// no es estrictamente necesario un destructor adicional.
// Si en el futuro agregas punteros manuales, aquí podrías liberar memoria.

Mapa::~Mapa() {
    // Destructor vacío, no requiere limpieza manual
}
