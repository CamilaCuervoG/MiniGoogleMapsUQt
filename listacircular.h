#pragma once
#include <iostream>
#include <stdexcept>  // std::runtime_error

// ===============================================================
// NODO CIRCULAR
// ===============================================================
template <typename T>
class NodoCircular {
public:
    T dato;
    NodoCircular<T>* siguiente;

    explicit NodoCircular(const T& valor)
        : dato(valor), siguiente(nullptr) {}
};

// ===============================================================
// LISTA CIRCULAR SIMPLEMENTE ENLAZADA
// ===============================================================
template <typename T>
class ListaCircular {
private:
    NodoCircular<T>* cabeza;

public:

    ListaCircular() : cabeza(nullptr) {}

    // ------------------ Destructor ------------------
    ~ListaCircular() {
        if (!cabeza) return;

        NodoCircular<T>* actual = cabeza->siguiente;

        // Eliminamos todos los nodos que no son la cabeza
        while (actual != cabeza) {
            NodoCircular<T>* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }

        delete cabeza;   // eliminar última (cabeza)
        cabeza = nullptr;
    }

    // ------------------ Insertar ------------------
    void insertar(const T& valor) {
        NodoCircular<T>* nuevo = new NodoCircular<T>(valor);

        if (!cabeza) {
            cabeza = nuevo;
            cabeza->siguiente = cabeza;
            return;
        }

        // Buscar el último nodo
        NodoCircular<T>* temp = cabeza;
        while (temp->siguiente != cabeza) {
            temp = temp->siguiente;
        }

        temp->siguiente = nuevo;
        nuevo->siguiente = cabeza;
    }

    // ------------------ Mostrar ------------------
    void mostrar() const {
        if (!cabeza) {
            std::cout << "La lista está vacía.\n";
            return;
        }

        NodoCircular<T>* temp = cabeza;
        std::cout << "Lista circular: ";

        do {
            std::cout << temp->dato << " -> ";
            temp = temp->siguiente;
        } while (temp != cabeza);

        std::cout << "(regresa al inicio)" << std::endl;
    }

    // ------------------ Buscar ------------------
    bool buscar(const T& valor) const {
        if (!cabeza) return false;

        NodoCircular<T>* temp = cabeza;

        do {
            if (temp->dato == valor)
                return true;

            temp = temp->siguiente;
        } while (temp != cabeza);

        return false;
    }

    // ------------------ Obtener siguiente ------------------
    T siguiente(const T& actual) const {
        if (!cabeza)
            throw std::runtime_error("Lista vacía");

        NodoCircular<T>* temp = cabeza;

        do {
            if (temp->dato == actual)
                return temp->siguiente->dato;

            temp = temp->siguiente;

        } while (temp != cabeza);

        throw std::runtime_error("Elemento no encontrado");
    }

    // ------------------ Obtener anterior ------------------
    T anterior(const T& actual) const {
        if (!cabeza)
            throw std::runtime_error("Lista vacía");

        NodoCircular<T>* temp = cabeza;

        do {
            if (temp->siguiente->dato == actual)
                return temp->dato;

            temp = temp->siguiente;

        } while (temp != cabeza);

        throw std::runtime_error("Elemento no encontrado");
    }
};
