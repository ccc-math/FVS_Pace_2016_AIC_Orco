#include "Graph/multigraph.hpp"
using namespace std;

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// Methods for the Edge class
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

Edge::Edge(int u, int v, int w){
    unode = u;
    vnode = v;
    weight = w;
};

bool Edge::isAdjacent(int vertex){
    return unode == vertex || vnode == vertex;
};
void Edge::printEdge(){
    cout << weight << "  #  (" << unode << ", " << vnode << ")" << endl;
}; 
int Edge::getU(){
    return unode;
};
int Edge::getV(){
    return vnode;
};
int Edge::getWeight(){
    return weight;
};
/*
void Edge::setWeight(int weight){
    weight = weight;
};
*/
void Edge::incrWeight(){  // weight++
    weight++;
};  
void Edge::dicrWeight(){// weight--
    if(weight >= 1){
        weight--;
    }
    else{
        std::cout << "forbidden negative weigth on edge "; //Error
        printEdge();
        exit ( EXIT_FAILURE );
    }
};  


///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// Methods for EdgeLinkedList class
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


    // Constructor
    EdgeLinkedList::EdgeLinkedList(){
        head = NULL;
    };

    // Methods
    void EdgeLinkedList::push_front(Edge e){
        Node* newNode = new Node(e);
        newNode->next = head;
        head = newNode;
    };

    void EdgeLinkedList::deleteEdge(int u, int v){
        Node* node = head;
        if(node != NULL){
            if(node->edge.isAdjacent(u) && node->edge.isAdjacent(v)){
                //delete node->edge;
                head = node->next;
            }
            else{
                Node* nextNode = node->next;
                bool flag = true;
                while(nextNode != NULL && flag){
                    if(nextNode->edge.isAdjacent(u) && nextNode->edge.isAdjacent(v)){
                        //delete nextNode->edge;
                        node->next = nextNode->next;
                        flag = false;
                    }
                    else{
                        node = nextNode;
                    }
                }
                if(flag){
                    std::cout << "edge " << u << " " << v << " not in edgelist" << std::endl;
                    exit ( EXIT_FAILURE );
                }
            }
        }
        else{
            std::cout << "edgelist is empty" << std::endl;
            exit (EXIT_FAILURE);
        }
    };

    // returns the edge u v from a list of edges
    Node* EdgeLinkedList::findEdge(int u, int v){
        Node* node = head;
        while(node != NULL){
            if(node->edge.isAdjacent(u) && node->edge.isAdjacent(v)){
                return node;
            }
            else{
                node = node->next;
            }
        }
        std::cout << "edge " << u << " " << v << " not in edgelist" << std::endl;
        exit ( EXIT_FAILURE );
    };

    void EdgeLinkedList::printEdgeList(){
        Node* node = head;
        while(node != NULL){
            //std::cout << node << std::endl;
            //std::cout << node->next << std::endl;
            std::cout << "          ";
            node->edge.printEdge();
            node = node->next;
        }
        std::cout << "          ~~" << std::endl;
    };

    // getters and setters
    Node* EdgeLinkedList::getHead(){
        return head;
    };
    //void EdgeLinkedList::setHead(Edge edge);



///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// Methods for the multigraph class
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

///////////////////
///////////////////
// Constructor 
///////////////////
///////////////////

Multigraph::Multigraph(int vertices){
    numVertices = vertices;                    
    selfLoops = {};         
    for(int i = 0; i < numVertices; i++){
        EdgeLinkedList EL;
        adjList[i] = EL;
    }

};
// Constructor from graph
Multigraph::Multigraph(Graph G){
    numVertices = G.getNumVertices();                    
    selfLoops = G.getSelfLoops();           
    adjList.clear();
    // Init with empty linked lists
    for(int i = 0; i < numVertices; i++){
        EdgeLinkedList EL;
        adjList[i] = EL;
    }
    // Then we add the edges
    for(int i = 0; i < numVertices; i++){
        vector<int> nei = G.getNeighbours(i);
        for(int j = 0; j < nei.size(); j++){
            Edge e = Edge(i, nei[j], 1);
            adjList[i].push_front(e);
        }
    }
};

Multigraph::Multigraph(Multigraph& MG){
    numVertices = MG.getNumVertices();
    selfLoops = MG.getSelfLoops();
    adjList = MG.getAdjList();
};


// Constructor from PACE challenge file
Multigraph::Multigraph(std::string filename){
    return;
};

///////////////////
///////////////////
//    Methods
///////////////////
///////////////////


void Multigraph::printMultigraph(){
    std::cout << "print multigraph" << std::endl;

    for(int i = 0; i < numVertices; i++){
        if(adjList.count(i)>0){
            std::cout << i << std::endl;
            adjList[i].printEdgeList();
        }
    }
};







///////////////////
///////////////////
//getters & setters 
///////////////////
///////////////////

int Multigraph::getNumVertices(){
    return numVertices;
};                   
std::vector<int> Multigraph::getSelfLoops(){
    return selfLoops;
};        
EdgeLinkedList Multigraph::getIncidentEdges(int u){
    return adjList[u];
};       
std::map<int, EdgeLinkedList> Multigraph::getAdjList(){
    return adjList;
};