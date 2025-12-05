#pragma once
#include <string>
#include <vector>

class Bloque {
private:
    std::string nombre;
    std::vector<std::string> espacios;
    std::string imagen;   // ruta de la imagen
    std::vector<int> pisos; // piso de cada espacio

public:
    Bloque(const std::string& nombreBloque, const std::string& rutaImagen = "")
        : nombre(nombreBloque), imagen(rutaImagen) {}

    std::string getNombre() const { return nombre; }
    const std::vector<std::string>& getEspacios() const { return espacios; }
    const std::vector<int>& getPisos() const { return pisos; }
    std::string getImagen() const { return imagen; }

    void agregarEspacio(const std::string& esp, int piso = 1) {
        espacios.push_back(esp);
        pisos.push_back(piso);
    }
};
