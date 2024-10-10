#ifndef GREEDY_H
#define GREEDY_H

#include "Graph/graph.hpp" 
#include <iostream>
#include <utility>
#include <vector>
#include <set>


// auxillary functions
void unionSet(std::vector<int> &disjointSet, std::vector<int> &height, int i, int j);
int findSet(std::vector<int> &disjointSet, int i);

// first version of a greedy algorthm
std::vector<int> greedy(Graph &G);



#endif