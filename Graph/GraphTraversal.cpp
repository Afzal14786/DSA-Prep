#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;      // total no of vertices
    vector<list<int>> listAdjeceny;

    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;       // mark the node as visited
        cout << node << " ";        // and print the node
        for (int neighbour : listAdjeceny[node]) {
            if (!visited[neighbour]) {
                DFSUtil(neighbour, visited);        // internally it uses stack data structure
            }
        }
    }

    public:
        Graph(int V) {
            this->V = V;
            listAdjeceny.resize(V);
        }

        void addEdge(int u, int v, bool directed = false) {
            listAdjeceny[u].push_back(v);
            if (!directed) {    // check if it is directed graph or not
                listAdjeceny[v].push_back(u);   // uni-directional
            }
        }

        // now print all the edges
        void printGraph() {
            cout << "List Adjecency : \n";
            for (int i  = 0; i < V; ++i) {
                cout << "Vexte : " << i << " -> ";
                for (int neighbour : listAdjeceny[i]) {
                    cout << neighbour << " ";
                }
                cout << endl;

            }
        }

        void BFS(int start) {
            cout << "Breadth First Search (BFS) : ";
            vector<bool> visited(V, false); // initally all the values are false and the size if `V`
            queue<int> q;

            // push the starting value into the queue and mark it as visited
            q.push(start);  
            visited[start] = true;

            // now navigate to the start's neighbout
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                cout << current << " ";
                for (int neighbour : listAdjeceny[current]) {
                    if (!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
            cout << endl;
        }

        void DFS(int start) {
            cout << "Depth First Search (DFS): ";
            vector<bool> visited(V, false);
            DFSUtil(start, visited);
            cout << endl;
        }
};

int main() {
    Graph graph(5);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();
    graph.BFS(0);       // 0 1 4 2 3
    graph.DFS(0);       // 0,1,2,3,4
    return 0;
}
