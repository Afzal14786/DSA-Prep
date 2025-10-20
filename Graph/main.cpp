#include <iostream>
#include <vector>
#include <list>

using namespace std;

/**
 * @brief Implememtation Of Unordered Unweighted Graph
 */

class Graph {
    int V;      // total no of vertices
    list<int>* l;    // store the list of neighbours

    public:
        Graph(int V) {
            this->V = V;
            l = new list<int>[V];   // a list of sive V
        }

        void addEdge(int u, int v) {
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void printGraph() {
            for (int u = 0; u < V; ++u) {
                list<int> neighbour = l[u];
                cout << u << " : ";
                for (int v : neighbour) {
                    cout << v << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(2,3);

    cout << "Printing The Graph : \n";
    graph.printGraph();
    return 0;
}