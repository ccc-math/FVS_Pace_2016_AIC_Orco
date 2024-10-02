#include "graph.hpp"
using namespace std;


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


// Probably hella bugged, to discuss
Graph Graph::fromFile(string filename){
    // Open filename
    ifstream inputFile(filename);

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        cerr << "Error opening the file! " << filename << endl;
    }

    vector<vector<int>> edges = {}; // the set of all edges (needed to find the number of edges which is not given in the instance files for some reasons)
    int size = -1;
    string line;
    // Read a new line until EOF
    while (getline(inputFile, line)) {
        // Split the line 
        string node1 = "";
        string node2 = "";
        cpt = 0;
        while(line[i] != " "){
            node1 = node1 + line[i];
            cpt++;
        }
        cpt++;
        while(cpt < line.size()){
            node2 = node2 + line[cpt];
            cpt++;
        }
        int n1 = int(node1);
        int n2 = int(node2);
        if(max(n1, n2) > size){
            size = max(n1, n2);
        } 
        edges.push_back({n1, n2});
    }
    // Close the file
    inputFile.close();
    // We now construct the graph
    Graph G = Graph(size);
    for(int i = 0; i < edges.size(); i++){
        G.addEdge(edges[i][0] - 1, edges[i][1] - 1); // Note: names int the instance files start from 1, but our indices start from 0
    } 
    return G;
};