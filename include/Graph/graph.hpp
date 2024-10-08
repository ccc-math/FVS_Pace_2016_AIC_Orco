#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;  // Adjacency matrix
    int numVertices;                          // Number of vertices
    std::vector<std::vector<int>> adjList;    // Adjacence 

public:
    // Constructor
    Graph(int vertices);

    // Add an edge between vertex u and vertex v
    void addEdge(int u, int v);

    // Remove an edge between vertex u and vertex v
    //void removeEdge(int u, int v);

    // Check if an edge exists between vertex u and vertex v
    bool hasEdge(int u, int v) ;

    // Print the adjacency matrix
    void printGraph_console();

    // Get the number of vertices
    int vertexCount();

    // Clear the graph by resetting the adjacency matrix
    void clearGraph();

    // Read a graph from a PACE Challenge file 
    Graph(std::string filename);

    // Getter 
    int getNumVertices();
    std::vector<int> getNeighbours(int v);
};

