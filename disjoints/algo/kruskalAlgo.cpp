#include <iostream>
#include <vector>
#include <functional>

using namespace std;


// kruskal's algo

class Edge {
    public:
        int u;
        int v;
        int wt;

        Edge(int u, int v, int wt) : u(u), v(v), wt(wt) {}

};

class Graph {
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;

    Graph(int V) : V(V), par(V), rank(V, 0) {
        for (int i = 0; i < V; ++i) {
            par[i] = i;
        }
    }

    void add_edge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    int find_set(int x) {
        if (x == par[x]) return x;
        return par[x] = find_set(par[x]);
    }

    void union_set(int a, int b) {
        int x = find_set(a);  // parent of a
        int y = find_set(b); // parent of b

        if (x != y) {
            if (rank[x] > rank[y]) par[y] = x;
            else if (rank[x] < rank[y]) par[x] = y;
            else {
                par[y] = x;
                rank[x]++;
            }
        }
    }

    // kruskal's algo

    int kruskal() {
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});
        int ans = 0;

        for (int i = 0; i < edges.size(); ++i) {
            auto e = edges[i];

            int x = find_set(e.u);  // parent of u
            int y = find_set(e.v);  // parent of v

            if (x != y) {   // means there is not cycle
                union_set(x, y);
                ans += e.wt;
            }
        }

        return ans;
    }
};

int main() {
    Graph graph(4);
    graph.add_edge(0, 1, 10);
    graph.add_edge(0, 2, 15);
    graph.add_edge(0, 3, 30);
    graph.add_edge(1, 3, 40);
    graph.add_edge(2, 3, 50);

    cout << "The Minimum Weight Of The Graph Is : " << graph.kruskal() << endl;

    return 0;
}
