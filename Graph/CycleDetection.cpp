#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int V;
    vector<list<int>> listAdj;
    bool isUndirected;

    void dfsHelper(int node, vector<bool> &visited) {
        cout << node << " ";
        visited[node] = true;

        for (int n : listAdj[node]) {
            if (!visited[n]) {
                dfsHelper(n, visited);
            }
        }
    }

    bool cycleUndirectedHelper(int source, int parent, vector<bool> &visited) {
        visited[source] = true;

        for (int neighbour : listAdj[source]) {
            if (!visited[neighbour]) {
                if (cycleUndirectedHelper(neighbour, source, visited)) return true;  // cycle exist
            } else {
                if (neighbour != parent) return true;   // cycle exist 
            }
        }

        return false;
    }

    bool directedCycleHelper(int source, vector<bool> &visited, vector<bool> &recPath) {
        visited[source] = true;
        recPath[source] = true;

        for (int neighbour : listAdj[source]) {
            if (!visited[neighbour]) {
                if (directedCycleHelper(neighbour, visited, recPath)) return true;
            } else {
                if (recPath[neighbour]) return true;    // means the cycle exist
            }
        }

        recPath[source] = false;
        return false;
    }

public:
    Graph(int V, bool isUndirected = true) :  V(V), isUndirected(isUndirected), listAdj(V) {
        listAdj.resize(V);
    }

    // addEdge
    void addEdge(int u, int v) {
        listAdj[u].push_back(v);
        if (isUndirected && u != v) {
            listAdj[v].push_back(u);
        }
    }

    // print the graph
    void printGraph() {
        cout << "List Adjecency : \n";
        for (int i = 0; i < V; ++i) {
            cout << "vertex " << i << " -> ";
            for (int neighbour : listAdj[i]) {
                cout  << neighbour << " ";
            }
            cout << endl;
        }
    }

    void dfs() {
        vector<bool> visited(V, false);
        dfsHelper(0, visited);
        cout << endl;
    }

    //check the cycle exist or not using dfs
    bool isCycleUndirected() {
        vector<bool> visited(V, false);
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                if (cycleUndirectedHelper(i, -1, visited)) return true;
            }
        }
        return false;
    }

    bool isCycleDirected() {
        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                if (directedCycleHelper(i, visited, recPath)) return true;
            }
        }

        return false;
    }
};

int main() {
    Graph graph(5);     // undirected graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    graph.printGraph();
    cout << "\n---------------- DFS TRAVERSAL ----------------\n";
    graph.dfs();
    cout << (graph.isCycleUndirected() ? "Cycle Exist" : "Cycle Not Exist") << endl;

    // directed graph
    Graph d_graph(4, false);
    d_graph.addEdge(1,0);
    d_graph.addEdge(0,2);
    d_graph.addEdge(2,3);
    d_graph.addEdge(3,0);  // cycle exist here
    cout << "\n---------------- DFS TRAVERSAL (Directed Graph) ----------------\n";
    d_graph.printGraph();
    cout << (d_graph.isCycleDirected() ? "Cycle Exist" : "Cycle Not Exist") << endl;
    return 0;
}