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
    Grafo grafo;                                     // Grafo donde guardo toda la estructura del campus
    std::vector<Bloque> bloques;                     // Lista de bloques físicos del mapa
    std::map<std::string, std::string> zonasBloques; // Relación zona → bloque

public:
    // Constructor: creo el grafo validando que numNodos sea mínimo 1
    Mapa(int numNodos)
        : grafo(numNodos > 0 ? numNodos : 1)
    {
        qDebug() << "Mapa creado con numNodos =" << numNodos;

        // Si numNodos es inválido aviso y creo un grafo básico
        if (numNodos <= 0) {
            qDebug() << "Advertencia: numNodos <= 0, se creó un grafo con 1 nodo.";
        }
    }

    ~Mapa();  // Destructor declarado (definido en el .cpp)

    // Retorno cuántos nodos tiene el grafo
    int getCantidadNodos() const {
        return grafo.getNumNodos();  // usa el método de Grafo
    }

    // Le asigno un nombre a un nodo específico
    void setNombreNodo(int nodo, const std::string& nombre) {
        grafo.setNombre(nodo, nombre);
    }

    // Agrego una conexión entre dos nodos con su distancia
    void agregarConexion(int origen, int destino, int distancia) {
        grafo.agregarConexion(origen, destino, distancia);
    }

    // Imprimo toda la estructura del grafo
    void mostrarMapa() const {
        grafo.mostrarGrafo();
    }

    // Calculo la ruta más corta usando Dijkstra
    std::vector<int> calcularRuta(int origen, int destino) {
        auto ruta = grafo.dijkstra(origen, destino);
        return ruta;
    }

    // Muestro una ruta ya calculada usando un stream (stdout, archivo, etc.)
    void mostrarRuta(const std::vector<int>& ruta, std::ostream& os) const {
        grafo.mostrarRuta(ruta, os); // ahora pasa el stream
    }

    // Ejecuto un recorrido DFS desde un nodo inicial
    void recorrerDFS(int inicio, std::ostream& os) const {
        grafo.DFS(inicio, os);
    }

    // Recupero el nombre de un nodo del grafo
    std::string getNombreNodo(int nodo) const {
        return grafo.getNombre(nodo);
    }

    // BLOQUES

    // Agrego un bloque al vector de bloques
    void agregarBloque(const Bloque& b) { bloques.push_back(b); }

     // Devuelvo la lista completa de bloques
    const std::vector<Bloque>& getBloques() const { return bloques; }

    // ZONAS → BLOQUES

    // Asocio una zona con un bloque
    void agregarZona(const std::string& zona, const std::string& bloque);

    // Busco qué bloque pertenece a una zona dada
    std::string buscarZona(const std::string& zona) const;
};
