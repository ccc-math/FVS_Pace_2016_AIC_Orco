#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include "Graph/graph.hpp"
#include "Algo/greedy.hpp"
#include "Algo/precomputations.hpp"
int main() {
    
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
    return 0;
};