#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Graph/graph.hpp"
#include "Graph/multigraph.hpp"
#include "Algo/greedy.hpp"
#include "Algo/precomputations.hpp"
int main() {
    
    /*
    Graph G("../data/instances_maison/3.graph");
    G.printGraph_console();

    std::vector<int> FVS;
    std::vector<int> FVS2;
    simple_kernel(G, FVS);
    FVS2 = greedy(G);
    for(int i = 0; i < FVS.size(); i++){
        std::cout << FVS[i] << std::endl;
    }
    for(int i = 0; i < FVS2.size(); i++){
        std::cout << FVS2[i] << std::endl;
    }
    std::cout << " " << std::endl;
    G.printGraph_console();
    
    Multigraph MG(G);
    MG.printMultigraph();
    */
    
    EdgeLinkedList EL;
    EL.printEdgeList();

    std::cout << std::endl;

    Edge E1(1, 2, 10);
    EL.push_front(E1);
    EL.printEdgeList();

    std::cout << std::endl;

    Edge E2(3, 4, 20);
    EL.push_front(E2);
    EL.printEdgeList();

    std::cout << std::endl;
    
    Node* N = EL.findEdge(1, 2);
    N->edge.incrWeight();
    EL.printEdgeList();

    std::cout << std::endl;
    
    int edgeweight = EL.deleteEdge(1,2);
    std::cout<< edgeweight << std::endl;
    std::cout<< EL.deleteEdge(5, 6) << std::endl;
    EL.printEdgeList();

    std::cout << std::endl;

    Graph G("../data/instances_maison/3.graph");
    Multigraph MG(G);
    MG.printMultigraph();

    std::cout << std::endl;
    
    MG.deleteVertex(0);
    MG.deleteVertex(1);
    MG.deleteVertex(2);
    MG.deleteVertex(3);
    MG.deleteVertex(4);
    MG.deleteVertex(5);
    MG.deleteVertex(10);
    MG.printMultigraph();

    std::cout << std::endl;

    //MG.addEdge(8, 9);
    MG.addEdge(6, 9);
    MG.addEdge(6, 9);
    MG.addEdge(9, 6);
    MG.addEdge(9, 6);
    MG.addEdge(9, 6);
    MG.printMultigraph();





    return 0;
};