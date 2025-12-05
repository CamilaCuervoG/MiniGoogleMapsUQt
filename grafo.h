#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm> // Para std::reverse

// ================================
// Clase Grafo para representar un mapa de nodos y conexiones
// ================================
class Grafo {
private:
    int numNodos; // Cantidad de nodos en el grafo

    // Nombres de los lugares correspondientes a cada nodo
    std::vector<std::string> nombres;

    // Lista de adyacencia: cada nodo tiene una lista de pares (vecino, distancia en metros)
    std::vector<std::list<std::pair<int, int>>> adyacencia;

public:

    // Constructor: inicializa número de nodos, nombres vacíos y listas de adyacencia
    explicit Grafo(int n)
        : numNodos(n), nombres(n), adyacencia(n) {}

    // ================================
    // Configuración de nodos y conexiones
    // ================================

    // Asignar nombre a un nodo específico
    void setNombre(int nodo, const std::string& nombre) {
        if (nodo < 0 || nodo >= numNodos) {
            std::cout << "Error: nodo fuera de rango.\n";
            return;
        }
        nombres[nodo] = nombre;
    }

    // Agregar conexión bidireccional entre nodos con distancia
    void agregarConexion(int origen, int destino, int distancia) {
        if (origen < 0 || origen >= numNodos ||
            destino < 0 || destino >= numNodos) {
            std::cout << "Error: conexion invalida.\n";
            return;
        }

        adyacencia[origen].push_back({ destino, distancia });
        adyacencia[destino].push_back({ origen, distancia });
    }

    // ================================
    // Mostrar grafo completo en consola
    // ================================
    void mostrarGrafo() const {
        std::cout << "\n===== MAPA DEL CAMPUS =====\n";
        for (int i = 0; i < numNodos; i++) {
            std::cout << "[" << i << "] " << nombres[i] << " -> ";

            for (const auto& vecino : adyacencia[i]) {
                std::cout << "("
                          << nombres[vecino.first] << ", "
                          << vecino.second << "m) ";
            }
            std::cout << std::endl;
        }
    }

    // ================================
    // Accesores
    // ================================
    const std::list<std::pair<int, int>>& getVecinos(int nodo) const {
        return adyacencia[nodo]; // Retorna vecinos y distancias de un nodo
    }

    std::string getNombre(int nodo) const {
        return nombres[nodo]; // Retorna el nombre de un nodo
    }

    int getNumNodos() const {
        return numNodos; // Retorna cantidad de nodos
    }

    // ================================
    // DFS (Recorrido en profundidad)
    // ================================
    void dfsUtil(int nodo, std::vector<bool>& visitado, std::ostream& os) const {
        visitado[nodo] = true;
        os << getNombre(nodo) << " -> ";

        for (const auto& vecino : adyacencia[nodo]) {
            if (!visitado[vecino.first]) {
                dfsUtil(vecino.first, visitado, os); // Llamada recursiva
            }
        }
    }

    // Inicia DFS desde un nodo dado y escribe recorrido
    void DFS(int inicio, std::ostream& os) const {
        if (inicio < 0 || inicio >= numNodos) {
            os << "Nodo inválido.\n";
            return;
        }

        std::vector<bool> visitado(numNodos, false);
        os << "Recorrido DFS desde " << getNombre(inicio) << ": \n\n";
        dfsUtil(inicio, visitado, os);
        os << "\n";
    }

    // ================================
    // DIJKSTRA (Ruta más corta)
    // ================================
    std::vector<int> dijkstra(int origen, int destino) const {
        if (origen < 0 || origen >= numNodos ||
            destino < 0 || destino >= numNodos) {
            std::cout << "Error: nodos inválidos.\n";
            return {};
        }

        const int INF = 1e9;

        std::vector<int> dist(numNodos, INF);    // Distancias iniciales
        std::vector<int> padre(numNodos, -1);    // Para reconstruir ruta
        std::vector<bool> visitado(numNodos, false);

        dist[origen] = 0;

        // Algoritmo principal
        for (int i = 0; i < numNodos; i++) {
            int u = -1;

            // Seleccionar nodo no visitado con distancia mínima
            for (int j = 0; j < numNodos; j++) {
                if (!visitado[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            if (dist[u] == INF) break; // Nodo inaccesible
            visitado[u] = true;

            // Actualizar distancias a vecinos
            for (const auto& vecino : adyacencia[u]) {
                int v = vecino.first;
                int peso = vecino.second;

                if (dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    padre[v] = u;
                }
            }
        }

        // Reconstruir ruta desde destino hasta origen
        std::vector<int> ruta;
        for (int actual = destino; actual != -1; actual = padre[actual]) {
            ruta.push_back(actual);
        }
        std::reverse(ruta.begin(), ruta.end());
        return ruta;
    }

    // Mostrar ruta encontrada en consola
    void mostrarRuta(const std::vector<int>& ruta, std::ostream& os) const {
        if (ruta.empty()) {
            os << "No existe una ruta.\n";
            return;
        }

        os << "Ruta encontrada: \n\n";
        for (size_t i = 0; i < ruta.size(); i++) {
            os << getNombre(ruta[i]);
            if (i + 1 < ruta.size()) os << " -> ";
        }
        os << '\n';
    }
};
