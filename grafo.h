#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm> // para std::reverse

class Grafo {
private:
    int numNodos;

    // Nombre de cada lugar
    std::vector<std::string> nombres;

    // Lista de adyacencia: cada nodo tiene lista de pares (vecino, distancia)
    std::vector<std::list<std::pair<int, int>>> adyacencia;

public:

    explicit Grafo(int n)
        : numNodos(n), nombres(n), adyacencia(n) {}

    // Asignar nombre a un nodo
    void setNombre(int nodo, const std::string& nombre) {
        if (nodo < 0 || nodo >= numNodos) {
            std::cout << "Error: nodo fuera de rango.\n";
            return;
        }
        nombres[nodo] = nombre;
    }

    // Agregar conexión bidireccional
    void agregarConexion(int origen, int destino, int distancia) {
        if (origen < 0 || origen >= numNodos ||
            destino < 0 || destino >= numNodos) {
            std::cout << "Error: conexion invalida.\n";
            return;
        }

        adyacencia[origen].push_back({ destino, distancia });
        adyacencia[destino].push_back({ origen, distancia });
    }

    // Mostrar grafo completo
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

    // Obtener vecinos (para DFS o búsquedas)
    const std::list<std::pair<int, int>>& getVecinos(int nodo) const {
        return adyacencia[nodo];
    }

    std::string getNombre(int nodo) const {
        return nombres[nodo];
    }

    int getNumNodos() const {
        return numNodos;
    }

    // DFS recursivo que escribe en un stream
    void dfsUtil(int nodo, std::vector<bool>& visitado, std::ostream& os) const {
        visitado[nodo] = true;
        os << getNombre(nodo) << " -> ";

        for (const auto& vecino : adyacencia[nodo]) {
            if (!visitado[vecino.first]) {
                dfsUtil(vecino.first, visitado, os);
            }
        }
    }

    // DFS completo que escribe en un stream
    void DFS(int inicio, std::ostream& os) const {
        if (inicio < 0 || inicio >= numNodos) {
            os << "Nodo inválido.\n";
            return;
        }

        std::vector<bool> visitado(numNodos, false);
        os << "Recorrido DFS desde " << getNombre(inicio) << ": ";
        dfsUtil(inicio, visitado, os);
        os << "\n";
    }


    // DIJKSTRA
    std::vector<int> dijkstra(int origen, int destino) const {
        if (origen < 0 || origen >= numNodos ||
            destino < 0 || destino >= numNodos) {
            std::cout << "Error: nodos inválidos.\n";
            return {};
        }

        const int INF = 1e9;

        std::vector<int> dist(numNodos, INF);
        std::vector<int> padre(numNodos, -1);
        std::vector<bool> visitado(numNodos, false);

        dist[origen] = 0;

        for (int i = 0; i < numNodos; i++) {
            int u = -1;

            for (int j = 0; j < numNodos; j++) {
                if (!visitado[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            if (dist[u] == INF) break;

            visitado[u] = true;

            for (const auto& vecino : adyacencia[u]) {
                int v = vecino.first;
                int peso = vecino.second;

                if (dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    padre[v] = u;
                }
            }
        }

        // Reconstruir ruta final
        std::vector<int> ruta;
        for (int actual = destino; actual != -1; actual = padre[actual]) {
            ruta.push_back(actual);
        }

        std::reverse(ruta.begin(), ruta.end());
        return ruta;
    }

    void mostrarRuta(const std::vector<int>& ruta, std::ostream& os) const {
        if (ruta.empty()) {
            os << "No existe una ruta.\n";
            return;
        }

        os << "Ruta encontrada: ";
        for (size_t i = 0; i < ruta.size(); i++) {
            os << getNombre(ruta[i]);
            if (i + 1 < ruta.size()) os << " -> ";
        }
        os << '\n';
    }
};
