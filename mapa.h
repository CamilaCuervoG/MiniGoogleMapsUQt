#pragma once
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "Grafo.h"
#include "Bloque.h"
#include <QDebug>

class Mapa {
private:
    Grafo grafo; // Grafo del campus
    std::vector<Bloque> bloques;
    std::map<std::string, std::string> zonasBloques;
public:
    Mapa(int numNodos)
        : grafo(numNodos > 0 ? numNodos : 1)
    {
        qDebug() << "Mapa creado con numNodos =" << numNodos;
        if (numNodos <= 0) {
            qDebug() << "Advertencia: numNodos <= 0, se creó un grafo con 1 nodo.";
        }
    }

    ~Mapa();  // Declaración del destructor

    int getCantidadNodos() const {
        return grafo.getNumNodos();  // usa el método de Grafo
    }

    void setNombreNodo(int nodo, const std::string& nombre) {
        grafo.setNombre(nodo, nombre);
    }

    void agregarConexion(int origen, int destino, int distancia) {
        grafo.agregarConexion(origen, destino, distancia);
    }

    void mostrarMapa() const {
        grafo.mostrarGrafo();
    }

    std::vector<int> calcularRuta(int origen, int destino) {
        auto ruta = grafo.dijkstra(origen, destino);
        return ruta;
    }

    void mostrarRuta(const std::vector<int>& ruta, std::ostream& os) const {
        grafo.mostrarRuta(ruta, os); // ahora pasa el stream
    }

    void recorrerDFS(int inicio, std::ostream& os) const {
        grafo.DFS(inicio, os);
    }

    std::string getNombreNodo(int nodo) const {
        return grafo.getNombre(nodo);
    }

    // -------------------------
    // BLOQUES
    // -------------------------

    void agregarBloque(const Bloque& b) { bloques.push_back(b); }
    const std::vector<Bloque>& getBloques() const { return bloques; }

    // -------------------------
    // ZONAS → BLOQUES
    // -------------------------
    void agregarZona(const std::string& zona, const std::string& bloque);
    std::string buscarZona(const std::string& zona) const;
};
