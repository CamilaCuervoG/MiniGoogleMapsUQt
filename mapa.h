#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ListaSimple.h"
#include "ListaDoble.h"
#include "ListaCircular.h"
#include "ArbolBinario.h"
#include "Grafo.h"
#include "historial.h"

class Mapa {
private:
    Grafo grafo;                          // Grafo del campus
    ArbolBinario arbolLugares;            // Árbol de lugares (orden alfabético)
    ListaCircular<std::string> cafeteria; // Cafetería: 4 comidas + papelería
    Historial historial;                  // Historial de rutas
    ListaSimple<std::string> edificios;    // Lista simple de edificios
    Structures::ListaDoble<std::string> zonasLibres;  // Lista doble de zonas libres

public:
    // Constructor
    Mapa(int numNodos) : grafo(numNodos) {}

    ~Mapa();  // Declaración del destructor

    // -------------------
    // GRAFOS
    // -------------------


    void setNombreNodo(int nodo, const std::string& nombre) {
        grafo.setNombre(nodo, nombre);
        arbolLugares.insertar(nombre); // También lo guardamos en árbol
    }

    void agregarConexion(int origen, int destino, int distancia) {
        grafo.agregarConexion(origen, destino, distancia);
    }

    void mostrarMapa() const {
        grafo.mostrarGrafo();
    }

    std::vector<int> calcularRuta(int origen, int destino) {
        auto ruta = grafo.dijkstra(origen, destino);
        if (!ruta.empty()) {
            historial.agregar(grafo.getNombre(origen), grafo.getNombre(destino));
        }
        return ruta;
    }

    void mostrarRuta(const std::vector<int>& ruta) const {
        grafo.mostrarRuta(ruta);
    }

    void recorrerDFS(int inicio) const {
        grafo.DFS(inicio);
    }

    std::string getNombreNodo(int nodo) const {
        return grafo.getNombre(nodo);
    }


    // -------------------
    // ARBOL DE LUGARES
    // -------------------
    void mostrarLugaresOrdenados() const {
        arbolLugares.mostrarInOrden();
    }

    void buscarLugar(const std::string& nombre) const {
        arbolLugares.buscar(nombre);
    }

    // -------------------
    // LISTAS SIMPLES / DOBLES / CIRCULARES
    // -------------------
    void agregarEdificio(const std::string& nombre) {
        edificios.insertar(nombre);
    }

    void mostrarEdificios() const {
        edificios.mostrar();
    }

    void agregarZonaLibre(const std::string& nombre) {
        zonasLibres.agregar(nombre);
    }

    void mostrarZonasLibres() const {
        zonasLibres.mostrarAdelante();
    }

    void agregarLocalCafeteria(const std::string& nombre) {
        cafeteria.insertar(nombre);
    }

    void mostrarCafeteria() const {
        cafeteria.mostrar();
    }

    // -------------------
    // HISTORIAL
    // -------------------
    void mostrarHistorial() const {
        historial.mostrar();
    }

    std::vector<std::string> getHistorial() const {
        return historial.getRegistros();
    }
};
