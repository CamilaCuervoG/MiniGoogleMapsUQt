#include "Mapa.h"

// Destructor
Mapa::~Mapa() {
    // No se requiere liberar memoria manualmente
}

// ------------------------------------
//  ZONAS → BLOQUES
// ------------------------------------

void Mapa::agregarZona(const std::string& zona, const std::string& bloque) {
    zonasBloques[zona] = bloque;
}

std::string Mapa::buscarZona(const std::string& zona) const {
    auto it = zonasBloques.find(zona);
    if (it != zonasBloques.end()) {
        return it->second;
    }
    return "Zona no encontrada";
}
