#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int V;
    vector<list<int>> listAdj;
    bool isUndirected;

    bool helperBipartite(int source, vector<bool> &visited, vector<int> &color) {
        queue<int> q;
        // puch the source into the queue
        q.push(source);
        visited[source] = true;
        color[source] = 0;  // for the first node, it is blue baby

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbour : listAdj[curr]) {
                if (!visited[neighbour]) {
                    // 1. pahle visit to karo bhai 
                    visited[neighbour] = true;
                    // fir color bhi to lagao you naughty
                    color[neighbour] = !color[curr];  // color lagawo lekin opposite, like musalman color 
                    q.push(neighbour);      // fir lagado garibo ko line me 
                } else {
                    if (color[neighbour] == color[curr]) return false;
                }
            }
        }

        return true;
    }

public:

    Graph(int V, bool isUndirected = true) :  V(V), isUndirected(isUndirected), listAdj(V) {
        listAdj.resize(V);
    }

    void addEdge(int u, int v) {
        listAdj[u].push_back(v);
        if (isUndirected && u != v) {
            listAdj[v].push_back(u);
        }
    }

    void printGraph() {
        cout << "List Adjecency : \n";
        for (int i = 0; i < V; ++i) {
            cout << "vertex " << i << " -> ";
            for (int neighbour : listAdj[i]) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    bool isBipartite() {

        vector<bool> visited(V, false);
        vector<int> colors(V, -1);
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                if(helperBipartite(i, visited, colors)) return true;
            }
        }

        return false;
    }
};

int main() {

    cout << "\n----------------- Bipartite Graph -----------------\n";
    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    cout << "\n-------- Printing The Graph --------\n";
    graph.printGraph();
    cout << "Kia Graph Bipartite Graph Hai ? " << (graph.isBipartite() ? "Haa Bipartite Graph hai" : "Nahi Bipartite Graph nhi hai") << endl;
 
    return 0;
}