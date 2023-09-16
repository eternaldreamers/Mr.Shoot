#ifndef SEARCH_H
#define SEARCH_H

#include "Graph.h"
#include <vector>
#include <utility>

class Search {
public:
    static std::vector<std::pair<int, int>> BFS(const Graph& grafo, std::pair<int, int> start);
    static std::vector<std::pair<int, int>> DFS(const Graph& grafo, std::pair<int, int> start);
};

#endif
