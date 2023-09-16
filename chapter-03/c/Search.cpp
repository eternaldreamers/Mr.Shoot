#include "Search.h"
#include <queue>
#include <stack>
#include <set>

std::vector<std::pair<int, int>> Search::BFS(const Graph& grafo, std::pair<int, int> start) {
    std::vector<std::pair<int, int>> resultado;
    std::set<std::pair<int, int>> visitados;
    std::queue<std::pair<int, int>> cola;

    cola.push(start);

    while (!cola.empty()) {
        std::pair<int, int> actual = cola.front();
        cola.pop();

        if (visitados.find(actual) != visitados.end()) {
            continue;
        }

        resultado.push_back(actual);
        visitados.insert(actual);

        std::bitset<8> conexiones = grafo.getConexiones(actual.first, actual.second);
        for (int i = 0; i < 8; ++i) {
            if (conexiones[i]) {
                std::pair<int, int> vecino = {actual.first + Graph::desplacement[i].first, actual.second + Graph::desplacement[i].second};
                if (visitados.find(vecino) == visitados.end()) {
                    cola.push(vecino);
                }
            }
        }
    }

    return resultado;
}

std::vector<std::pair<int, int>> Search::DFS(const Graph& grafo, std::pair<int, int> start) {
    std::vector<std::pair<int, int>> resultado;
    std::set<std::pair<int, int>> visitados;
    std::stack<std::pair<int, int>> pila;

    pila.push(start);

    while (!pila.empty()) {
        std::pair<int, int> actual = pila.top();
        pila.pop();

        if (visitados.find(actual) != visitados.end()) {
            continue;
        }

        resultado.push_back(actual);
        visitados.insert(actual);

        std::bitset<8> conexiones = grafo.getConexiones(actual.first, actual.second);
        for (int i = 0; i < 8; ++i) {
            if (conexiones[i]) {
                std::pair<int, int> vecino = {actual.first + Graph::desplacement[i].first, actual.second + Graph::desplacement[i].second};
                if (visitados.find(vecino) == visitados.end()) {
                    pila.push(vecino);
                }
            }
        }
    }

    return resultado;
}
