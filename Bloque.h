#pragma once
#include <string>
#include <vector>

class Bloque {
private:
    std::string nombre;                // Nombre del bloque (ej. "Administrativo")
    std::vector<std::string> espacios; // Lista de espacios dentro del bloque (aulas, oficinas…)
    std::string imagen;                // ruta de la imagen
    std::vector<int> pisos;            // piso de cada espacio

public:
    // Constructor: inicializo el bloque con su nombre y opcionalmente su imagen
    Bloque(const std::string& nombreBloque, const std::string& rutaImagen = "")
        : nombre(nombreBloque), imagen(rutaImagen) {}

    // Getters: devuelvo la info del bloque sin permitir modificaciones
    std::string getNombre() const { return nombre; }
    const std::vector<std::string>& getEspacios() const { return espacios; }
    const std::vector<int>& getPisos() const { return pisos; }
    std::string getImagen() const { return imagen; }

    // Agrego un nuevo espacio y su piso a las listas correspondientes
    void agregarEspacio(const std::string& esp, int piso = 1) {
        espacios.push_back(esp); // nombre del espacio
        pisos.push_back(piso);   // piso donde está ubicado
    }
};
