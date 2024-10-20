#include "Algo/greedy.hpp"
using namespace std;
// NOTE : the union find structure is just a vector yet, maybe it should be a class !!!!!!!!!!!!!!!!!!!!!!!



int findSet(vector<int> &disjointSet, int i){
	/*
	A class is a tree
	disjointSet[i] = i iff i is the root of a tree i.e. the representant if its class
	if disjointSet[i] = -1 then i is not stored in any class
	if disjointSet[i] != i the the representant of the class of i is findSet(disjointset, disjointset[i])
	*/
	if(disjointSet[i] == -1){
		cerr << "Element in no set " << endl;
        exit ( EXIT_FAILURE );
	}
	if(disjointSet[i] == i){
		return i;
	}
	else{
		int repr = findSet(disjointSet, disjointSet[i]); // the representent of i
		disjointSet[i] = repr; // Path Compression to flatten the tree             NOTE : we might need to decrease the height here, to check
		return repr;
	}
}


void unionSet(vector<int> &disjointSet, vector<int> &height, int i, int j){
	/*
	A class is a tree
	to identify the class of i and the class of j, we just have to modify disjointSet[repr[i]] or disjointSet[repr[j]]
	we add a small optimization to limit the height of the final tree
	*/
	int irepr = findSet(disjointSet, i);
	int jrepr = findSet(disjointSet, j);
	if(irepr != jrepr){
		if(height[irepr] < height[jrepr]){ // we put irepr under jrepr
			disjointSet[irepr] = jrepr;
			height[irepr] = -1;
		}
		else if(height[irepr] > height[jrepr]){ // we put irepr under jrepr
			disjointSet[jrepr] = irepr;
			height[jrepr] = -1;
		}
		else{
			disjointSet[jrepr] = irepr;
			height[irepr] = height[irepr] + 1;
		}
	}
}



std::vector<int> greedy(Graph &G){
	/*
	
	G MUST HAVE NO SELF LOOP

	*/
	vector<int> FVS = {};
	vector<int>disjointSet = vector<int>(G.getNumVertices(), -1); // at the beginning, no class
	vector<int>height = vector<int>(G.getNumVertices(), 0); 
	
	for(int i = 0; i < G.getNumVertices(); i++){
		set<int> colorsInNeighbourhood;
		//vector<int>colorsInNeighbourhood = {}; 			// we store the colored neighbour of i        NOTE: should be better with a set data structure
		bool flag = true; 								// stopping contidion
		// we look at the neighbours of i
		for(int j = 0; j < G.getNeighbours(i).size() && flag; j++){
			int neighbour = G.getNeighbours(i)[j];
			// if the neighbour has been colored :
			if(disjointSet[neighbour] >= 0){
				int neighbour_color = findSet(disjointSet, neighbour);
				// we check if we've already stored its color
				if(colorsInNeighbourhood.count(neighbour_color) != 0){
					flag = false;                           		// in which case we stop
					FVS.push_back(i);
				}
				colorsInNeighbourhood.insert(neighbour_color);
			}
		}
		// if i is not in the FVS, we have to update the color classes
		if(flag){
			disjointSet[i] = i;
			height[i] = 1;
			// if i connects its neighbours trees
			for(auto color : colorsInNeighbourhood){
				unionSet(disjointSet, height, color, i);
			}
		}
	}
	return FVS;
};



