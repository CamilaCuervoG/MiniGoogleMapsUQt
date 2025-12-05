#pragma once
#include <QDebug>

template <typename T>
class NodoSimple {
public:
    T dato;
    NodoSimple<T>* siguiente;

    explicit NodoSimple(T valor)
        : dato(valor), siguiente(nullptr) {}
    ~NodoSimple() = default;
};

template <typename T>
class ListaSimple {
private:
    NodoSimple<T>* cabeza;

public:
    ListaSimple() : cabeza(nullptr) {}
    ~ListaSimple() {
        NodoSimple<T>* temp = cabeza;
        while (temp != nullptr) {
            NodoSimple<T>* borrar = temp;
            temp = temp->siguiente;
            delete borrar;
        }
    }

    void insertar(T valor) {
        NodoSimple<T>* nuevo = new NodoSimple<T>(valor);
        if (!cabeza) {
            cabeza = nuevo;
            return;
        }
        NodoSimple<T>* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }

    void mostrar() const {
        if (!cabeza) {
            qDebug() << "La lista está vacía.";
            return;
        }
        NodoSimple<T>* temp = cabeza;
        while (temp != nullptr) {
            qDebug() << temp->dato;
            temp = temp->siguiente;
        }
    }

    // Método público para acceder a la cabeza
    NodoSimple<T>* getCabeza() const { return cabeza; }
};

