#include "Algo/precomputations.hpp"
using namespace std;
// NOTE : the union find structure is just a vector yet, maybe it should be a class !!!!!!!!!!!!!!!!!!!!!!!

void recDisconnectDegreeOneVertices(Graph &G, int v){
	vector<int> neighbours = G.getNeighbours(v);
	if(neighbours.size() == 1){
		int neighbour = neighbours[0];
		G.disconnectVertex(v);
		recDisconnectDegreeOneVertices(G, neighbour);
	}
}

void simple_kernel(Graph &G, vector<int>&FVS){
	/*
	It will do modifications on G and FVS
	*/
	for(int v : G.getSelfLoops()){
		G.disconnectVertex(v);
		FVS.push_back(v);
	}
	for(int v = 0; v < G.getNumVertices(); v++){
		vector<int> neighbours = G.getNeighbours(v);
		if(neighbours.size() == 0){
			continue;
		}
		else if(neighbours.size() == 1){
			recDisconnectDegreeOneVertices(G, v);
		}
		else if(neighbours.size() == 2){
			// We need to deal with multi edges, to discuss
			continue;
		}
		else{
			continue;
		}
	}
	
};




