// #include <iostream>

//

// // desaparecer nodos

// int main() {
//     // Generate Data
//     vector<vector<int>> data;

//     int rows = 5;
//     int cols = 5;

//     for (int i = 0; i < rows; i++) {
//         vector<int> row;
//         for (int j = 1; j <= cols; j++) {
//             row.push_back(i * cols + j);
//         }
//         data.push_back(row);
//     }

//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             cout << data[i][j] << " ";
//         }
//         cout << endl;
//     }

//     // Generate connections

//     // Find  graph

//     return 0;
// }

#include <cstdlib>
#include <fstream>
#include <graphviz/gvc.h>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  string text;
  int *self;
  int *child;
};

int randomNumber(int min, int max) {
  random_device rd;
  mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(min, max);

  return dist(mt);
}

// int getClose(int curr, ) {}

int main() {
  GVC_t *gvc = gvContext();
  Agraph_t *graph = agopen((char *)"G", Agstrictdirected, NULL);

  // --- BEGIN --

  vector<vector<Node>> data;

  int rows = 5;
  int cols = 5;

  int limitConnections = 8;
  // limite 8 conexiones

  for (int i = 0; i < rows; i++) {
    vector<Node> row;
    for (int j = 0; j < cols; j++) {
      int *value = new int(i * cols + j + 1);
      Node node = {.text = to_string(*value), .self = value, .child = NULL};

      row.push_back(node);
    }
    data.push_back(row);
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int conLimit = randomNumber(1, limitConnections);
    //   int y = randomNumber(1, rows - 1);

      for (int k = 0; k < conLimit;) {
        int y = randomNumber(1, 4);
        
        // if (!y) continue;



        cout << y << endl;
        k++;
      }

    //   cout << data[i][j].text << " " << x << " " << y << endl;

      // data[i][j].child = data[x][y].self;
      // Agnode_t *nodeH = agnode(graph, (char *)data[i][j].text.c_str(), 1);
      // Agnode_t *nodeT = agnode(graph, (char *)data[x][y].text.c_str(), 1);
      // Agedge_t *edge = agedge(graph, nodeT, nodeH, NULL, 1);

      // cout << *data[i][j].self << " ";
      // cout << *data[x][y].self << " ";
      // cout << data[x][y].text << " ";
      // cout << x << " " << y << endl;
    }
    // cout << endl;
  }

  //   Agnode_t *node1 = agnode(graph, (char *)"Node 1", 1);
  //   Agnode_t *node2 = agnode(graph, (char *)"Node 2", 1);

  //   Agedge_t *edge = agedge(graph, node1, node2, NULL, 1);

  // --- END --

  FILE *dotFile = fopen("graph.dot", "w");
  agwrite(graph, dotFile);
  fclose(dotFile);

  std::system("dot -Tpng -o graph.png graph.dot");

  gvFreeLayout(gvc, graph);
  agclose(graph);
  gvFreeContext(gvc);

  std::cout << "Grafo generado" << std::endl;

  return 0;
}
