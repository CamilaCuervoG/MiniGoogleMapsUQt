#include "Mapa.h"

// Agregar una zona y su bloque asociado
void Mapa::agregarZona(const std::string& zona, const std::string& bloque) {

    zonasBloques[zona] = bloque; // Guarda en el mapa la relación zona → bloque
}

// Buscar el bloque al que pertenece una zona
std::string Mapa::buscarZona(const std::string& zona) const {
    // Busca la zona en el contenedor
    auto it = zonasBloques.find(zona);

    // Si existe, devuelve el bloque
    if (it != zonasBloques.end())
        return it->second;

    // Si no existe, devuelve string vacío
    return "";
}

// Destructor
Mapa::~Mapa() {
    // No se requiere liberar memoria manualmente porque
    // los contenedores STL administran su propia memoria.
}

