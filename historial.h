#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ListaDoble.h"

class Historial {
private:
    Structures::ListaDoble<std::string> rutas;   // Lista doble que almacena texto de rutas

public:
    // Agregar registro al historial
    void agregar(const std::string& origen, const std::string& destino) {
        std::string registro = "Ruta: " + origen + " -> " + destino;
        rutas.agregar(registro);
    }

    // Mostrar historial completo en consola
    void mostrar() const {
        if (rutas.vacia()) {
            std::cout << "El historial está vacío." << std::endl;
            return;
        }

        std::cout << "=== HISTORIAL DE RUTAS ===" << std::endl;
        rutas.mostrarAdelante();
    }

    // Devuelve los registros como vector<string> para usar en Qt
    std::vector<std::string> getRegistros() const {
        std::vector<std::string> registros;

        // Necesitamos acceder a la cabeza de la lista doble
        auto actual = rutas.getCabeza();  // <<--- ListaDoble debe tener método getCabeza()
        while (actual) {
            registros.push_back(actual->dato);
            actual = actual->siguiente;
        }

        return registros;
    }
};

