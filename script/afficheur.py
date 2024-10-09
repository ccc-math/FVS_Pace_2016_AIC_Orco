"""
IN : fichier .graph et un fichier avec un sommet par ligne qui sont ceux à garder

OUT : Un PNG qui donne le graphes avec une couleur différente pour ceux qui sont retirés/conservés
"""

import matplotlib.pyplot as plt
import networkx as nx

def getCardGraph(filename):
    """ Take a .graph file and return the number of vertices """
    k = 0
    with open(filename + '.graph', 'r') as f:
        for ligne in f:
            l = ligne.split()
            if k < int(l[0]):
                k = int(l[0])
    return k


def createGraph(filename):
    """ Take a .graph file and return the associated graph as in the networkx class """
    G = nx.Graph()
    for i in range(getCardGraph(filename)+1):
        G.add_node(i)

    with open(filename + '.graph', 'r') as f:
        for ligne in f:
            l = ligne.split()
            G.add_edge(int(l[0]), int(l[1]))
    return G

# Prob better way to do this as a function
def coloring(G, pos, sol):
    """ Take a graph G and the solution of the FVS and colors the removed vetices and edges """
    colorV, colorE = [], []
    with open(sol + '.solution', 'r') as f:
        for ligne in f:
            if ligne !='\n':
                colorV.append(int(ligne))
    nx.draw_networkx_nodes(G, pos, nodelist=colorV, node_color='red', node_size=50)
    
    for edge in G.edges():
        if (edge[0] in colorV) or (edge[1] in colorV):
            colorE.append(edge)
    nx.draw_networkx_edges(G, pos, edgelist=colorE, edge_color='red')
    return colorV, colorE

filename = '002'

G = createGraph(filename)
sol = 'sol'

print(G)
print('nodes :')
print(G.nodes())
print('edges')
print(G.edges())

pos = nx.kamada_kawai_layout(G)

nx.draw_networkx_nodes(G, pos, node_size=50)
nx.draw_networkx_edges(G, pos, edge_color='blue')
removedV, removedE = coloring(G, pos, sol)
#nx.draw_networkx_labels(G, pos)

plt.tight_layout()
plt.show()

# Doesn't work as intended...
# plt.savefig(filename + '.png')


"""
-> Add a second png with only the remaining solution
"""
solV, solE = [], []
for v in G.nodes():
    if not v in removedV:
        solV.append(v)
for e in G.edges():
    if not e in removedE:
        solE.append(e)

nx.draw_networkx_nodes(G, pos, nodelist=solV, node_color='blue', node_size=50)
nx.draw_networkx_edges(G, pos, edgelist=solE, edge_color='blue')
plt.tight_layout()
plt.show()