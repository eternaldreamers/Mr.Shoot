#include "Graph.h"
#include <unordered_set>
#include <random>
#include <iostream>

const std::vector<std::pair<int, int>> Graph::desplacement = {
    {-1, -1},
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0}
};

void Graph::create() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int d = 0; d < desplacement.size(); ++d) {
                int ni = i + desplacement[d].first;
                int nj = j + desplacement[d].second;

                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    matriz[i][j].set(d);
                }
            }
        }
    }
}

void Graph::delNodes(double porcentaje) {
    int total_nodes = n * n;
    int nodos_to_eliminated = static_cast<int>(total_nodes * porcentaje);

    std::unordered_set<int> deleted;
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int rank = total_nodes - nodos_to_eliminated; rank < total_nodes; ++rank) {
        int idx = std::uniform_int_distribution<>(0, rank)(gen);
        auto it = deleted.find(idx);
        if (it != deleted.end()) {
            deleted.insert(rank);
        } else {
            deleted.insert(idx);
        }
    }

    for (int val : deleted) {
        int x = val / n;
        int y = val % n;
        
        matriz[x][y].reset();
        
        for (int d = 0; d < desplacement.size(); ++d) {
            int xi = x + desplacement[d].first;
            int yi = y + desplacement[d].second;

            if (xi >= 0 && xi < n && yi >= 0 && yi < n) {
                matriz[xi][yi].reset(d);
            }
        }
    }
}

std::bitset<8> Graph::getConexiones(int x, int y) const {
    return matriz[x][y];
}
