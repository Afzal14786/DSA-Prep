#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;


class Graph {
    int V;
    vector<list<int>> adj;  // vector of listAdjecency

    // dfs helper
    void dfsHelper(int node, vector<bool> &visited) {
        cout << node << " ";
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfsHelper(neighbour, visited);
            }
        }
    }

    // bfs helper
    void bfsHelper(int node, vector<bool> &visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int neighbour : adj[curr]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
            
        }
    }

public:
    Graph(int V) : V(V), adj() {
        adj.resize(V);
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    void printGraph() {
        cout << "List Adjecency : \n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " -> ";
            for (int neighbour : adj[i]) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    void dfs() {
        vector<bool> visited(V, false);
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                dfsHelper(i, visited);
                cout << endl;
            }
        }
    }

    void bfs() {
        vector<bool> visited(V, false);
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                bfsHelper(i, visited);
                cout << endl;
            }
        }
    }

};

int main() {
    Graph graph(10);
    graph.addEdge(0, 2);
    graph.addEdge(2, 5);
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(3, 7);
    graph.addEdge(3, 8);

    graph.printGraph();
    cout << "\n---------------- DFS TRAVERSAL IN DIFFERENT COMPONENTS ----------------\n";
    graph.dfs();
    cout << "\n---------------- BFS TRAVERSAL IN DIFFERENT COMPONENTS ----------------\n";
    graph.bfs();
    return 0;
}