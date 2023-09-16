#include "Graph.h"
#include "Search.h"
#include <iostream>

void printGraph(const Graph& grafo, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << (grafo.getConexiones(i, j).none() ? '0' : '1') << " ";
        }
        std::cout << "\n";
    }
}

void printRes(const std::vector<std::pair<int, int>>& visitedNodes) {
    std::cout << "Nodos visitados: ";
    for (const auto& nodo : visitedNodes) {
        std::cout << "(" << nodo.first << "," << nodo.second << ") ";
    }
    std::cout << "\n";
}

int main() {
    int n = 10;

    Graph graph;
    graph.create();

    std::cout << "Grafo original:\n";
    printGraph(graph, n);

    double porcentaje = 0.2;
    graph.delNodes(porcentaje);

    std::cout << "\nGrafo después de eliminar nodos:\n";
    printGraph(graph, n);

    auto bfsResult = Search::BFS(graph, {2, 2});
    std::cout << "\nResultado BFS desde (2,2):\n";
    printRes(bfsResult);

    auto dfsResult = Search::DFS(graph, {2, 2});
    std::cout << "\nResultado DFS desde (2,2):\n";
    printRes(dfsResult);

    return 0;
}
