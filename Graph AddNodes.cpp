#include<iostream>
using namespace std;
class GraphNode {
private:
    int id;
    static const int MAX_NEIGHBORS = 100;
    int neighbors[MAX_NEIGHBORS];
    int numNeighbors;

public:
    GraphNode() {}

    GraphNode(int nodeId) : id(nodeId), numNeighbors(0) {}


    void addNeighbor(int neighborId) {
        neighbors[numNeighbors++] = neighborId;
    }


    int getID() const {
        return id;
    }


    const int* getNeighbors() const {
        return neighbors;
    }


    int getNumNeighbors() const {
        return numNeighbors;
    }
};

class Graph {
private:
    static const int MAX_NODES = 100;
    GraphNode nodes[MAX_NODES];
    int numNodes;



    GraphNode* findNode(int nodeId) {
        for (int i = 0; i < numNodes; ++i) {
            if (nodes[i].getID() == nodeId) {
                return &nodes[i];
            }
        }
        return nullptr;
    }

public:

    Graph() : numNodes(0) {}


    void addNode(int nodeId) {
        if (numNodes < MAX_NODES) {
            nodes[numNodes++] = GraphNode(nodeId);
        }
        else {
            cout << "Exceeded the maximum number of nodes." << endl;
        }
    }


    void addEdge(int fromNodeId, int toNodeId) {

        GraphNode* fromNode = findNode(fromNodeId);
        GraphNode* toNode = findNode(toNodeId);


        if (fromNode && toNode) {
            fromNode->addNeighbor(toNodeId);
        }
        else {
            cout << "Node not found." << endl;
        }
    }


    void printGraph() const {
        cout << "Graph adjacency list:" << endl;
        for (int i = 0; i < numNodes; ++i) {
            cout << "Node " << nodes[i].getID() << ": ";
            for (int j = 0; j < nodes[i].getNumNeighbors(); ++j) {
                cout << nodes[i].getNeighbors()[j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    Graph graph;


    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);


    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(4, 2);
    graph.addEdge(1, 2);
    graph.addEdge(4, 0);


    graph.printGraph();

    return 0;
}