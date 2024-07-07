#include<iostream>
using namespace std;

class Graph {
private:
    int n;  
    bool** adjmatrix;

public:
    Graph(int vertices) {
        n = vertices;
        adjmatrix = new bool* [n];
        for (int i = 0; i < n; i++) {
            adjmatrix[i] = new bool[n];
            for (int j = 0; j < n; j++) {
                adjmatrix[i][j] = false;
            }
        }
    }
    void addEdge(int from, int to) {
        adjmatrix[from][to] = true;
        adjmatrix[to][from] = true;
    }

    void addVertex() {
        bool** newMatrix = new bool* [n + 1];
        for (int i = 0; i < n + 1; i++) {
            newMatrix[i] = new bool[n + 1];
            for (int j = 0; j < n + 1; j++) {
                newMatrix[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                newMatrix[i][j] = adjmatrix[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            delete[] adjmatrix[i];
        }
        delete[] adjmatrix;
        adjmatrix = newMatrix;
        n++;
    }

    void printGraph() {
        for (int i = 0; i < n; i++) {
            cout << "adj list for vertex " << i << ": ";
            for (int j = 0; j < n; j++) {
                if (adjmatrix[i][j]) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Graph myGraph(5);  
    myGraph.addEdge(0, 1);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 3);
    myGraph.addVertex(); 
    myGraph.addEdge(3, 4);
    myGraph.printGraph();

    return 0;
}
