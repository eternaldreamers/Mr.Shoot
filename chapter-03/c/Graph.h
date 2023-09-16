#ifndef GRAFO_H
#define GRAFO_H

#include <bitset>
#include <vector>

class Graph {
private:
    static const int MAXN = 1000;
    const int n = 10;
    std::bitset<8> matriz[MAXN][MAXN];

public:
    Graph();
    void create();
    void delNodes(double porcentaje);
    static const std::vector<std::pair<int, int>> desplacement;
    std::bitset<8> getConexiones(int x, int y) const;
};

#endif
