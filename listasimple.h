#pragma once
#include <QDebug>

/*
 *  NodoSimple
 *  -------------------------
 *  Representa un nodo de una lista simplemente enlazada.
 *  Contiene un dato genérico y un puntero al siguiente nodo.
 */
template <typename T>
class NodoSimple {
public:
    T dato;                    // Valor almacenado
    NodoSimple<T>* siguiente;  // Puntero al siguiente nodo

    // Constructor
    explicit NodoSimple(T valor)
        : dato(valor), siguiente(nullptr) {}

    // Destructor
    ~NodoSimple() = default;
};

/*
 *  ListaSimple
 *  -------------------------
 *  Implementa una lista simplemente enlazada.
 *  Permite insertar elementos y recorrerlos para mostrarlos.
 */
template <typename T>
class ListaSimple {
private:
    NodoSimple<T>* cabeza;   // Puntero al primer nodo

public:
    // Constructor: inicializa la lista vacía
    ListaSimple() : cabeza(nullptr) {}

    // Destructor: libera memoria de todos los nodos
    ~ListaSimple() {
        NodoSimple<T>* temp = cabeza;
        while (temp != nullptr) {
            NodoSimple<T>* borrar = temp;
            temp = temp->siguiente;
            delete borrar;
        }
    }

    /*
    * insertar(T valor)
    * -------------------------
    * Inserta un nuevo nodo al final de la lista.
    */
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

    /*
    * mostrar()
    * -------------------------
    * Imprime los elementos de la lista en la consola de Qt
    */
    void mostrar() const {
        if (!cabeza) {
            qDebug() << "La lista está vacía.";
            return;
        }

        qDebug() << "Elementos en la lista:";
        NodoSimple<T>* temp = cabeza;

        while (temp != nullptr) {
            qDebug() << " -" << temp->dato;
            temp = temp->siguiente;
        }
    }
};
