// رَبِّ زِدْنِي عِلْمًا
// رَبِّ زِدْنِي عِلْمًا
#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <random>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);  // path compression
    }

    void unite(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        // Union by rank – update parent, not rank!
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

void printTestResult(const string& testName, bool passed) {
    cout << (passed ? "[PASS]" : "[FAIL]") << " " << testName << "\n";
}

int main() {
    cout << "========== DSU TEST SUITE ==========\n\n";

    // ---------- CORRECTNESS TESTS ----------
    cout << "--- Correctness Tests ---\n";

    // Test 1: Basic unions
    {
        DSU dsu(5);
        dsu.unite(0, 1);
        dsu.unite(2, 3);
        bool t1 = (dsu.find(0) == dsu.find(1));
        bool t2 = (dsu.find(2) == dsu.find(3));
        bool t3 = (dsu.find(0) != dsu.find(2));
        bool t4 = (dsu.find(4) == 4);
        printTestResult("Basic union 0-1, 2-3", t1 && t2 && t3 && t4);
    }

    // Test 2: Connecting components
    {
        DSU dsu(6);
        dsu.unite(0, 1);
        dsu.unite(2, 3);
        dsu.unite(1, 2);
        bool t1 = (dsu.find(0) == dsu.find(3));
        bool t2 = (dsu.find(0) != dsu.find(4));
        printTestResult("Connect components via 1-2", t1 && t2);
    }

    // Test 3: Union self
    {
        DSU dsu(3);
        dsu.unite(1, 1);
        bool t = (dsu.find(1) == 1);
        printTestResult("Union self (1,1)", t);
    }

    // Test 4: Repeated union
    {
        DSU dsu(4);
        dsu.unite(0, 1);
        dsu.unite(0, 1);
        bool t = (dsu.find(0) == dsu.find(1));
        printTestResult("Repeated union (0,1)", t);
    }

    // Test 5: Long chain
    {
        DSU dsu(6);
        for (int i = 0; i < 5; ++i) dsu.unite(i, i+1);
        int root = dsu.find(0);
        bool allSame = true;
        for (int i = 1; i < 6; ++i) {
            if (dsu.find(i) != root) { allSame = false; break; }
        }
        printTestResult("Chain 0-1-2-3-4-5 all connected", allSame);
    }

    // Test 6: Mixed unions
    {
        DSU dsu(7);
        dsu.unite(0, 2);
        dsu.unite(4, 6);
        dsu.unite(2, 5);
        dsu.unite(1, 3);
        dsu.unite(5, 6);
        bool t1 = (dsu.find(0) == dsu.find(6));
        bool t2 = (dsu.find(1) == dsu.find(3));
        bool t3 = (dsu.find(0) != dsu.find(1));
        printTestResult("Mixed unions with multiple components", t1 && t2 && t3);
    }

    // ---------- PERFORMANCE TESTS ----------
    cout << "\n--- Performance Tests ---\n";

    const int SIZES[] = { 10000, 100000, 1000000 };
    const int OPERATIONS_MULTIPLIER = 10;

    random_device rd;
    mt19937 gen(rd());

    for (int N : SIZES) {
        cout << "\nTesting N = " << N << "\n";

        DSU dsu(N);
        uniform_int_distribution<> dist(0, N-1);
        int ops = N * OPERATIONS_MULTIPLIER;

        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < ops; ++i) {
            int a = dist(gen), b = dist(gen);
            dsu.unite(a, b);
        }
        auto end = chrono::high_resolution_clock::now();
        auto unionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "  " << ops << " random unions: " << unionTime << " ms\n";

        start = chrono::high_resolution_clock::now();
        int sum = 0;
        for (int i = 0; i < ops; ++i) {
            sum += dsu.find(dist(gen));
        }
        end = chrono::high_resolution_clock::now();
        auto findTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "  " << ops << " random finds: " << findTime << " ms\n";

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < ops; ++i) {
            if (i % 2 == 0) {
                int a = dist(gen), b = dist(gen);
                dsu.unite(a, b);
            } else {
                sum += dsu.find(dist(gen));
            }
        }
        end = chrono::high_resolution_clock::now();
        auto mixedTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "  " << ops << " mixed ops (half union, half find): " << mixedTime << " ms\n";

        (void)sum;
    }

    cout << "\n========== ALL TESTS COMPLETED ==========\n";
    return 0;
}