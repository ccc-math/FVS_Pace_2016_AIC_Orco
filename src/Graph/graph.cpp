#include "graph.hpp"
Graph::Graph(int vertices) {
        numVertices = vertices;
        
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
        adjList.resize(vertices,std::list<int>());
    };


void Graph::addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
            adjList[u].push_front(v);
            adjList[v].push_front(u);
        } else {
            std::cout << "Invalid vertex!" << std::endl; //Error
        }
    };

void Graph::removeEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            if(adjMatrix[u][v]==1 && adjMatrix[v][u]==1){
                adjMatrix[u][v] = 0;
                adjList[u].remove(u);
            }
                a
        } else {
            std::cout << "Invalid vertex!" << std::endl;
        }
    };

 bool Graph::hasEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            return adjMatrix[u][v] == 1;
        }
        return false;
    };

void Graph::printGraph_console() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    };

int Graph::vertexCount() {
        return numVertices;
    };

    // Clear the graph by resetting the adjacency matrix
void Graph::clearGraph() {
    adjMatrix.assign(numVertices, std::vector<int>(numVertices, 0));
};