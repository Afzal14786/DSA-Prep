#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int V;
    vector<list<int>> listAdj;
    bool isUndirected;

    void allPathHelper(int source, int destination, vector<bool> &visited, string &paths) {
        // this is the dfs approach for solving this problem
        if (source == destination) {
            cout << paths << destination << " ";
            cout << endl;
            return;
        }

        visited[source] = true;
        paths += to_string(source);

        for (int neighbour : listAdj[source]) {
            if (!visited[neighbour]) {
                allPathHelper(neighbour, destination, visited, paths);
            }
        }

        paths = paths.substr(0, paths.size()-1);
        visited[source] = false;
    }

public:

    Graph(int V, bool isUndirected = true) : V(V), isUndirected(true), listAdj(V) {
        listAdj.resize(V);
    }

    void addEdge(int u, int v) {
        listAdj[u].push_back(v);
        if (!isUndirected) {
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

    void allPaths(int source, int destination) {
        vector<bool> visited(V, false);
        string paths = "";
        allPathHelper(source, destination, visited, paths);
    }
};

int main() {
    Graph graph(6, false);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    cout << "\n----------------- The Graph -----------------\n";
    graph.printGraph();
    cout << "\n..........................Printing All The Paths..........................\n";
    graph.allPaths(5, 1);
    return 0;
}