#include <string.h>
#include <stdlib.h>
#include "Graph.h"

Graph::Graph(int v, int e, char *file) {
    numV = v;
    numE = e;
    dist = vector<int>(numV);
    path = vector<int>(numV);
    edges = new Edge[numE * sizeof(struct Edge)];
    setEdges(file);
}

void Graph::setEdges(char *file) {
    ifstream f(file);
    char buf[BUF_SIZE];
    for (int i = 0, k = 0; !f.eof() && i < numV; ++i)
        for (int j = 0; !f.eof() && j < numV; ++j){
            f>>buf;
            if(!strcmp(buf, "*") || i == j)
                continue;
            edges[k++] = {i, j, atoi(buf)};
        }
    f.close();
}

void Graph::showPath() {
    for (int i = 0, j = 0; j < numV - 1; j++) {
        cout<<i<<" -> "<<path[i]<<" ("<<dist[path[i]]<<")"<<endl;
        i = path[i];
    }
}

int Graph::getShortPathBF() {
    for (int i = 0; i < numV; ++i)
        dist[i] = INT_MAX;
    dist[0] = 0;

    for (int i = 0; i < numV - 1; ++i)
        for (int j = 0; j < numE; ++j)
            if (dist[edges[j].src] != INT_MAX && dist[edges[j].dest] > dist[edges[j].src] + edges[j].weight){
                dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
                path[edges[j].src] = edges[j].dest;
            }

    for (int i = 0; i < numE; ++i)
        if (dist[edges[i].src] != INT_MAX && dist[edges[i].src] + edges[i].weight < dist[edges[i].dest])
            return -1;  // Отрицательный цикл в графе

    return 0;
}


