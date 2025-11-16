#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Disjoint {
public:
    int n;
    vector<int> parents;
    vector<int> ranks;

    Disjoint(int n) : n(n), parents(n), ranks(n, 0) {
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }

    int find_set(int x) {
        if (x != parents[x])
            parents[x] = find_set(parents[x]);  // known as path compressions
        return parents[x];
    }

    void union_set(int a, int b) {
        int x = find_set(a);
        int y = find_set(b);

        if (x != y) {
            if (ranks[x] < ranks[y]) {
                parents[x] = y;
            } else if (ranks[x] > ranks[y]) {
                parents[y] = x;
            } else {
                parents[y] = x;
                ranks[x]++;
            }
        }
    }
};

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

    int kruskal() { // t.c = eloge
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});        // t.c = eloge
        int ans = 0;
        int count = 0;
        for (int i = 0; i < edges.size() && count < V - 1; ++i) {       // 
            auto e = edges[i];

            int x = find_set(e.u);  // parent of u
            int y = find_set(e.v);  // parent of v

            if (x != y) {   // means there is not cycle
                union_set(x, y);
                ans += e.wt;
                count++;
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
