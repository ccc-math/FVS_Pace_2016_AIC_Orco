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

    int EdgeLinkedList::deleteEdge(int u, int v){
        /*
        delete an edge and return its multiplicity (0 if no edge)
        */
        Node* node = head;
        if(node != NULL){ 
            if(node->edge.isAdjacent(u) && node->edge.isAdjacent(v)){
                head = node->next;
                int res = node->edge.getWeight();
                //delete node;
                return res;
            }
            else{
                Node* nextNode = node->next;
                while(nextNode != NULL){
                    if(nextNode->edge.isAdjacent(u) && nextNode->edge.isAdjacent(v)){
                        node->next = nextNode->next;
                        int res = nextNode->edge.getWeight();
                        //delete nextNode;
                        return res;
                    }
                    else{
                        node = nextNode;
                        nextNode = nextNode->next;
                    }
                }
            }
        }
        return 0;
    };

    void EdgeLinkedList::addEdge(int u, int v){    // NOTE : à recoder ça a l'air horrible
        Node* node = head;
        if(node == NULL){
            std::cout << "1 \n";
            Edge e(u, v, 1);
            Node* newNode = new Node(e);
            head = newNode;
        }
        else{
            if(node->edge.isAdjacent(u) && node->edge.isAdjacent(v)){
                node->edge.incrWeight();
                    return;
            }
            else{
                while(node->next != NULL){
                    std::cout << "é \n";
                    node->edge.printEdge();
                    if(node->edge.isAdjacent(u) && node->edge.isAdjacent(v)){
                        node->edge.incrWeight();
                        return;
                    }
                    else{
                        node = node->next;
                    }
                }
            }
            if(node->edge.isAdjacent(u) && node->edge.isAdjacent(v)){
                node->edge.incrWeight();
                    return;
            }
            std::cout << "2 \n";
            Edge e(u, v, 1);
            Node* newNode = new Node(e);
            node->next = newNode;         
        }
    }


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


void Multigraph::deleteVertex(int u){
    /*
    delete the vertex u in the graph
    -> delete u from the set of vertices
    -> delete every edge adjacent to u
    -> delete the self loop uu if it exists
    */
    while(adjList[u].getHead() != NULL){
        Edge e = adjList[u].getHead()->edge;
        int nei = e.getU();
        if(nei == u){
            nei = e.getV();
        }
        adjList[nei].deleteEdge(nei, u);
        adjList[u].deleteEdge(u, nei);
    }
    adjList.erase(u);
    for(int i = 0; i < selfLoops.size(); i++){
        if(selfLoops[i] == u){
            swap(selfLoops[i], selfLoops[selfLoops.size() - 1]);
            selfLoops.pop_back();
        }
    }
};


void Multigraph::addEdge(int u, int v){
    /*
    add the edge uv, or increase its multiplicity if uv already exists

    NOTE : can be made faster by looking for uv int the edgelist of u/v with the lowest degree
    */
    std::cout << "a\n";
    adjList[u].addEdge(u, v);
    std::cout << "b\n";
    adjList[v].addEdge(u, v);


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