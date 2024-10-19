#ifndef MULTIGRAPH_H
#define MULTIGRAPH_H


#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include "Graph/graph.hpp"

class Edge{
private:
    int unode;
    int vnode;
    int weight;  // number of parallel edges

public:
    // Constructor
    Edge(int u, int v, int w);

    // Methods
    bool isAdjacent(int vertex);
    void printEdge(); 

    // getters and setters
    int getU();
    int getV();
    int getWeight(); 
    //void setWeight(int weight);
    void incrWeight();  // weight++
    void dicrWeight();  // weight--
};


struct Node{
    Edge edge;
    Node* next;

    Node(Edge e) : edge(e), next(NULL) {} 
};

class EdgeLinkedList{
private:
    Node* head;

public:
    // Constructor
    EdgeLinkedList();

    // Methods
    void push_front(Edge e);
    void deleteEdge(int u, int v);
    Node* findEdge(int u, int v);
    void printEdgeList();

    // getters and setters
    Node* getHead();
    //void setHead(Edge edge);
};


class Multigraph {
private:
    int numVertices;                          // Number of vertices
    std::vector<int> selfLoops;               // list of self loops
    std::map<int , EdgeLinkedList> adjList;   // adjacency list

public:
    ///////////////////
    ///////////////////
    //  constructors 
    ///////////////////
    ///////////////////
    Multigraph(int vertices);
    Multigraph(Graph G);
    Multigraph(Multigraph& MG);
    Multigraph(std::string filename);

    ///////////////////
    ///////////////////
    //    methods
    ///////////////////
    ///////////////////
    void printMultigraph();
    void disconnectVertex(int v);
    std::vector<int> simpleKernel(); // reduce the multi graph and return a list of vertices that must be in the MFVS 


    ///////////////////
    ///////////////////
    //getters & setters 
    ///////////////////
    ///////////////////
    int getNumVertices();                   
    std::vector<int> getSelfLoops();        
    EdgeLinkedList getIncidentEdges(int u);       
    std::map<int , EdgeLinkedList> getAdjList();
};


#endif

