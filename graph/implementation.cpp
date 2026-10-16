#include <bits/stdc++.h>
using namespace std;

/**
 * @description 
 *
 * This is the implementation of graph using adjacency matrix
 * Using this method it takes 
 *  * O(V^2) space
 *  * And for traversing in the neighbout as well it is costly, it takes O(V) time.
 *  This method waste a lots of space, in the sparse matrix most of cells are fills with zeros(0), means there is no connection
 * */

class Graph {
private:
    int size;  // size of the matrix or say size of the edge
    vector<vector<int>> adjacencyMatrix;  // this is the matrix which holds the connection relation between nodes
    vector<vector<int>> edgeList;   // this is the edgelist which contains the graph and it's connection | non - connected graph
    
    // forming the adjaency matrix and maintaining the connection between edges
    void formMatrix() {
        for (int i = 0; i < edgeList.size(); ++i) {
            int a = edgeList[i][0];
            int b = edgeList[i][1];

            adjacencyMatrix[a][b] = 1;
            adjacencyMatrix[b][a] = 1;
        }
    }

public:

    // initialize the constructor
    Graph(int sz, vector<vector<int>> edgeList): size(sz), edgeList(edgeList), adjacencyMatrix(size, vector<int>(size, 0)) {
        formMatrix();
    }

    // now printing the graph
    void printGraph() {
        for (int i = 1; i < size; ++i) {
            cout << "Node: " << i << "'s Neighbours: [";
            for (int j = 1; j < size; ++j) {
                if (adjacencyMatrix[i][j] == 1) {
                    cout << j << "->";
                }
            }
            cout << "]" << endl;
        }
    }

    // now also let see what exactly inside adjacency matrix
    void insideAdjanceyMatrix() {
        for (int i = 0; i < size; ++i) {
            cout << i << "'th row [ ";
            for (int j = 0; j < size; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << "]" << endl;
        }
    }
};

/**
 * Graph Implementation using edgeList
 * Here we are using list, instead of matrix
 * list is efficient compare to matrix
 * it takes less amout of time as well as storage
 * it takes 
 *      * O(V) space 
 *      * O(degree) Time for traversing through all the neighbour
 */

class BetterGraph {
private:
    int size;
    vector<vector<int>> edgeList;
    unordered_map<int, list<int>> adjacecnyList;
    
    void formAdjacencyList() {
        for (int i = 0; i < size; ++i) {
            int a = edgeList[i][0];
            int b = edgeList[i][1];

            adjacecnyList[a].push_back(b);
            adjacecnyList[b].push_back(a);
        }
    }

public:
    BetterGraph(int size, vector<vector<int>> edgeList) : size(size), edgeList(edgeList) {
        formAdjacencyList();
    }

    void printGraph() {
        for (auto x : adjacecnyList) {
            cout << x.first << "'th Neighbours : [";
            for (int node : x.second) {
                cout << node << "->";
            }
            cout << "]" << endl;
        }
    }
};

vector<vector<int>> generateDenseGraph(int numNodes, int densityFactor) {
    vector<vector<int>> edgeList;
    
    // Step 1: Guarantee every node is connected (Creates a spanning path)
    // This ensures there are absolutely ZERO isolated nodes.
    for (int i = 1; i < numNodes; ++i) {
        edgeList.push_back({i, i + 1});
    }
    
    // Step 2: Add extra connections to make it dense.
    // densityFactor determines how many forward connections each node gets.
    // E.g., if densityFactor is 5, Node 1 connects to 3, 4, 5, and 6.
    for (int i = 1; i <= numNodes; ++i) {
        for (int step = 2; step <= densityFactor; ++step) {
            if (i + step <= numNodes) {
                edgeList.push_back({i, i + step});
            }
        }
    }
    
    return edgeList;
}

int main() {
    int totalNodes = 50;
    
    // Density factor of 10 means each node connects to the next 10 consecutive nodes.
    // This will generate around 400+ edges for 50 nodes.
    int densityFactor = 10; 

    vector<vector<int>> edgeList = generateDenseGraph(totalNodes, densityFactor);
    cout << "Total edges generated: " << edgeList.size() << "\n";
    
    int size = edgeList.size();
    // cout << "\n ------------------- Using Adjacency Matrix --------------------\n";
    // Graph graph(size+1, edgeList);

    // graph.printGraph();
    // cout << "\n----------------- Inside Adjacency Matrix -------------------------\n";
    // graph.insideAdjanceyMatrix();
    
    cout << "\n ------------------- Using Adjacency List -----------------\n";
    BetterGraph better_graph(size, edgeList);

    better_graph.printGraph();
    return 0;
}


