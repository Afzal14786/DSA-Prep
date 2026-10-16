#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;
    vector<list<int>> listAdj;
    bool isUndirected;
    // topologoical Sorting Helper --- Bolte Apne Ko Bhai 
    void topologicalSortingHelper(int source, vector<bool> &visited, stack<int> &st) {
        visited[source] = true;

        for (int neighbour : listAdj[source]) {
            if (!visited[neighbour]) {
                topologicalSortingHelper(neighbour, visited, st);
            }
        }

        st.push(source);
    }

public:
    Graph(int V, bool isUndirected = true) : V(V), isUndirected(true), listAdj(V) {
        listAdj.resize(V);
    }

    void addEdge(int u, int v) {
        listAdj[u].push_back(v);
        if (!isUndirected && u != v) {
            listAdj[v].push_back(u);
        }
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "List Adjecency : " << i << " -> ";
            for (int neighbour : listAdj[i]) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    void topologicalSorting() {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortingHelper(i, visited, st);
            }
        }

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }
};

int main() {
    Graph graph(6, false);

    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    
    cout << "\n------------ Printing All The Graphs ------------\n";
    graph.printGraph();
    cout << "\n------------ Topological Sorting ------------\n";
    graph.topologicalSorting();

    return 0;
}