#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Graph/graph.hpp"

int main() {
    
    std::cout<<"test"<<std::endl;

    Graph a(5);
    a.printGraph_console();
    a.addEdge(1,2);
    a.printGraph_console();
    if(a.hasEdge(1,2)){
        std::cout<<"oui"<<std::endl;
    };
    if(a.hasEdge(1,3)){
        std::cout<<"non"<<std::endl;
    };
    a.clearGraph();
    a.printGraph_console();
    Graph b("../data/hidden/1.graph");
    b.printGraph_console();


    return 0;
}