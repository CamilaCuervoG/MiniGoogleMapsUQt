#include "Mapa.h"

void Mapa::agregarZona(const std::string& zona, const std::string& bloque) {
    zonasBloques[zona] = bloque; // asigna el bloque correspondiente a la zona
}

std::string Mapa::buscarZona(const std::string& zona) const {
    auto it = zonasBloques.find(zona);
    if (it != zonasBloques.end())
        return it->second;
    return "";
}

// Destructor
Mapa::~Mapa() {
    // No se requiere liberar memoria manualmente
}

