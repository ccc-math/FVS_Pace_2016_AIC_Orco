#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include "Graph/graph.hpp"
#include "Algo/greedy.hpp"
int main() {
    
    Graph G("../data/instances_maison/testGreedyFvs.graph");
    G.printGraph_console();
    std::vector<int> FVS = greedy(G);
    for(int i = 0; i < FVS.size(); i++){
        std::cout << FVS[i] << std::endl;
    }

    Graph H("../data/instances_maison/testGreedyFvs2.graph");
    H.printGraph_console();
    std::vector<int> FVS2 = greedy(H);
    for(int i = 0; i < FVS2.size(); i++){
        std::cout << FVS2[i] << std::endl;
    }
    return 0;
}