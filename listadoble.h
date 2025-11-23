#pragma once
#include <iostream>
#include <string>

namespace Structures {

// ----------------------- NODO DOBLEMENTE ENLAZADO -----------------------
template <typename T>
class NodoDoble {
public:
    T dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    explicit NodoDoble(const T& d)
        : dato(d), siguiente(nullptr), anterior(nullptr) {}
    ~NodoDoble() = default;
};

// ----------------------- LISTA DOBLEMENTE ENLAZADA -----------------------
template <typename T>
class ListaDoble {
private:
    NodoDoble<T>* cabeza;
    NodoDoble<T>* cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    ~ListaDoble() {
        NodoDoble<T>* actual = cabeza;
        while (actual) {
            NodoDoble<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        cabeza = nullptr;
        cola = nullptr;
    }

    void agregar(const T& valor) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(valor);
        if (!cabeza) {
            cabeza = nuevo;
            cola = nuevo;
        } else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    void mostrarAdelante() const {
        NodoDoble<T>* actual = cabeza;
        std::cout << "Lista (inicio → fin): ";
        while (actual) {
            std::cout << actual->dato;
            if (actual->siguiente) std::cout << " <-> ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    void mostrarAtras() const {
        NodoDoble<T>* actual = cola;
        std::cout << "Lista (fin → inicio): ";
        while (actual) {
            std::cout << actual->dato;
            if (actual->anterior) std::cout << " <-> ";
            actual = actual->anterior;
        }
        std::cout << std::endl;
    }

    bool vacia() const {
        return cabeza == nullptr;
    }

    // ------------------ NUEVO: obtener cabeza ------------------
    NodoDoble<T>* getCabeza() const {
        return cabeza;
    }
};

} // namespace Structures

