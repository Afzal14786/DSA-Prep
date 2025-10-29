#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int V;  // no of vertices
    vector<list<int>> listAdd;
    bool isUndirected;

public:

    Graph(int V, bool isUndirected = true) : V(V), isUndirected(true), listAdd(V) {
        listAdd.resize(V);
    }

    void calcIndegree(vector<int> &indegree) {
        for (int i = 0; i < V; ++i) {
            for (int n : listAdd[i]) {
                indegree[n]++;
            }
        }
    }

    void addEdge(int u, int v);
    void printGraph();
    void kahnsAlgorithm();
};

void Graph::addEdge(int u, int v) {
    listAdd[u].push_back(v);

    if (!isUndirected && u != v) {
        listAdd[v].push_back(u);
    }
}

void Graph::printGraph() {
    cout << "List Adjecency : \n";
    for (int i = 0; i < V; ++i) {
        cout << "vertex " << i << " -> ";
        for (int n : listAdd[i]) {
            cout << n << " ";
        }
        cout << endl;
    }
}

void Graph::kahnsAlgorithm() {
    vector<int> indegree(V, 0);
    calcIndegree(indegree);
    queue<int> q;

    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for (int i = 0; i < V; ++i) {
            for (int N : listAdd[curr]) {
                indegree[N]--;
                if (indegree[N] == 0) {
                    q.push(N);
                }
            }
        }
    }

    cout << endl;
}

int main() {
    Graph graph(6);

    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);


    cout << "\n--------------- DAG (Directed Acyclic Graph) ---------------\n";
    graph.printGraph();

    cout << "\n--------------- Kahn's Algorithm (Topological Sorting) ---------------\n";
    graph.kahnsAlgorithm();
    return 0;
}