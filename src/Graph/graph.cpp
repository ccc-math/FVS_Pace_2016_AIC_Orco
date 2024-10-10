#include "Graph/graph.hpp"
using namespace std;


Graph::Graph(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
        adjList.resize(vertices, {}); // graph with no edge
};


Graph::Graph(std::string filename){
    // Open filename
    ifstream file;
    file.open(filename);
    // Check if the file is successfully opened
    if (!file.is_open()) {
        cerr << "Error opening the file! " << filename << endl;
        exit ( EXIT_FAILURE );
    }

    vector<vector<int>> edges = {}; // the set of all edges (needed to find the number of edges which is not given in the instance files for some reasons)
    int size = -1;
    string line;
    // Read a new line until EOF
    while (getline(file, line)) {
        //std::cout<<"oi"<<std::endl;
        // Split the line 
        std::string node1 = "";
        std::string node2 = "";
        int cpt = 0;

        while(line[cpt] != ' '){
            node1 = node1 + line[cpt];
            cpt++;
        }
        cpt++;
        while(cpt < line.size()){
            node2 = node2 + line[cpt];
            cpt++;
        }
        int n1 = stoi(node1);
        int n2 = stoi(node2);
        if(max(n1, n2) > size){
            size = max(n1, n2);
        } 
        edges.push_back({n1, n2});
    }
    // Close the file
    file.close();
    // We now construct the graph
    size = size + 1;
    numVertices = size;
    adjMatrix.resize(size, std::vector<int>(size, 0));
    adjList.resize(size, {});
    for(int i = 0; i < edges.size(); i++){
        this->addEdge(edges[i][0], edges[i][1]); // Note: names int the instance files start from 1, but our indices start from 0
    } 
    
};


void Graph::addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        } else {
            std::cout << "Invalid vertex!" << std::endl; //Error
            exit ( EXIT_FAILURE );
        }
    };

/*
void Graph::removeEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            if(adjMatrix[u][v]==1 && adjMatrix[v][u]==1){
                adjMatrix[u][v] = 0;
                adjList[u].remove(v);
                adjList[v].remove(u);
            }
        
        } else {
            std::cout << "Invalid vertex!" << std::endl;
            exit ( EXIT_FAILURE );
        }
    };
*/
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


int Graph::getNumVertices(){
    return this->numVertices;
};


std::vector<int> Graph::getNeighbours(int v){
    return this->adjList[v];
}


