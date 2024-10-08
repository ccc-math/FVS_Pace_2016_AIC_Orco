#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include "Graph/graph.hpp"
#include "Algo/greedy.hpp"
#include "Algo/precomputations.hpp"
int main() {
    
    Graph G("../data/instances_maison/2.graph");
    G.printGraph_console();
    std::vector<int> FVS = greedy(G);
    for(int i = 0; i < FVS.size(); i++){
        std::cout << FVS[i] << std::endl;
    }
    
    return 0;
};