#pragma once
#include <QDebug>

template <typename T>
class NodoSimple {
public:
    T dato;
    NodoSimple<T>* siguiente;

    // Constructor: inicializo el nodo con el valor y dejo el puntero siguiente en null
    explicit NodoSimple(T valor)
        : dato(valor), siguiente(nullptr) {}
    ~NodoSimple() = default; // No necesito lógica extra al destruir un nodo
};

template <typename T>
class ListaSimple {
private:
    NodoSimple<T>* cabeza; // Puntero al primer nodo de la lista

public:
    // Constructor: inicio la lista vacía
    ListaSimple() : cabeza(nullptr) {}

    // Destructor: recorro toda la lista liberando cada nodo
    ~ListaSimple() {
        NodoSimple<T>* temp = cabeza;
        while (temp != nullptr) {
            NodoSimple<T>* borrar = temp;
            temp = temp->siguiente;
            delete borrar; // elimino nodo por nodo
        }
    }

    // Inserto un nuevo nodo al final de la lista
    void insertar(T valor) {
        NodoSimple<T>* nuevo = new NodoSimple<T>(valor);

        // Si la lista está vacía, el nuevo nodo es la cabeza
        if (!cabeza) {
            cabeza = nuevo;
            return;
        }

        // Recorro hasta el último nodo
        NodoSimple<T>* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }

        // Enlazo el nuevo nodo al final
        temp->siguiente = nuevo;
    }

    // Muestro todos los elementos de la lista usando qDebug
    void mostrar() const {
        if (!cabeza) {
            qDebug() << "La lista está vacía.";
            return;
        }
        NodoSimple<T>* temp = cabeza;
        while (temp != nullptr) {
            qDebug() << temp->dato; // imprimo el dato del nodo actual
            temp = temp->siguiente; // avanzo al siguiente
        }
    }

    // Método para obtener la cabeza de la lista (por si necesito recorrerla afuera)
    NodoSimple<T>* getCabeza() const { return cabeza; }
};

