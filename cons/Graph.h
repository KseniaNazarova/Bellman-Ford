#ifndef BELLMAN_FORD_GRAPH_H
#define BELLMAN_FORD_GRAPH_H
#include <limits.h>
#include <iostream>
#include <fstream>
#include <vector>

#define BUF_SIZE 3
using namespace std;
struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    Edge *edges;    // ребра
    int numV; // число вершин
    int numE; // число ребер
    vector<int> dist;
    vector<int> path;
    void setEdges(char *);
public:
    Graph(int, int, char *);
    void showPath();
    int getShortPathBF();
};

#endif //BELLMAN_FORD_GRAPH_H
