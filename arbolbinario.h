#pragma once
#include <iostream>
#include <string>

// =========================================================
//                  Nodo del Árbol Binario
// =========================================================
class NodoArbol {
public:
    std::string nombre;      // Ej: "Cafetería", "Edificio A"
    NodoArbol* izquierda;
    NodoArbol* derecha;

    explicit NodoArbol(const std::string& n)
        : nombre(n), izquierda(nullptr), derecha(nullptr) {}
};

// =========================================================
//                       Árbol Binario
// =========================================================
class ArbolBinario {
private:
    NodoArbol* raiz;

    // ------------ Inserción recursiva ------------
    void insertarRecursivo(NodoArbol*& nodo, const std::string& nombre) {
        if (!nodo) {
            nodo = new NodoArbol(nombre);
            return;
        }

        if (nombre < nodo->nombre)
            insertarRecursivo(nodo->izquierda, nombre);
        else if (nombre > nodo->nombre)
            insertarRecursivo(nodo->derecha, nombre);
        // Si es igual: no insertar duplicados
    }

    // ------------ Recorrido InOrden ------------
    void inOrdenRecursivo(NodoArbol* nodo) const {
        if (!nodo) return;

        inOrdenRecursivo(nodo->izquierda);
        std::cout << nodo->nombre << "\n";
        inOrdenRecursivo(nodo->derecha);
    }

    // ------------ Búsqueda recursiva ------------
    NodoArbol* buscarRecursivo(NodoArbol* nodo, const std::string& nombre) const {
        if (!nodo || nodo->nombre == nombre)
            return nodo;

        if (nombre < nodo->nombre)
            return buscarRecursivo(nodo->izquierda, nombre);

        return buscarRecursivo(nodo->derecha, nombre);
    }

    // ------------ Liberar memoria ------------
    void destruir(NodoArbol* nodo) {
        if (!nodo) return;

        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }

public:

    ArbolBinario() : raiz(nullptr) {}

    ~ArbolBinario() {
        destruir(raiz);
    }

    // ------------ API pública ------------

    void insertar(const std::string& nombre) {
        insertarRecursivo(raiz, nombre);
    }

    void mostrarInOrden() const {
        std::cout << "\n--- Lugares del Campus (ordenados) ---\n";
        inOrdenRecursivo(raiz);
    }

    void buscar(const std::string& nombre) const {
        NodoArbol* resultado = buscarRecursivo(raiz, nombre);

        if (resultado)
            std::cout << "Lugar encontrado: " << resultado->nombre << "\n";
        else
            std::cout << "Lugar no encontrado.\n";
    }
};
