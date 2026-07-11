// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <random>
#include <iomanip>
using namespace std;

class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    // No path compression – worst-case O(n) for deep chains
    int find(int x) {
        if (x == parent[x]) return x;
        return find(parent[x]);  // recursion can be deep
    }

    void unite(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent != y_parent)
            parent[x_parent] = y_parent;  // always attach to y's root
    }
};

// Helper to print test results with alignment
void printResult(const string& name, bool passed) {
    cout << (passed ? "[✓] " : "[✗] ") << name << "\n";
}

int main() {
    cout << "========== DSU (BASIC) TEST SUITE ==========\n\n";

    // ------------------- CORRECTNESS TESTS -------------------
    cout << "--- Correctness Tests ---\n";

    // 1. Basic unions and separate components
    {
        DSU dsu(5);
        dsu.unite(0, 1);
        dsu.unite(2, 3);
        bool ok = true;
        ok &= (dsu.find(0) == dsu.find(1));
        ok &= (dsu.find(2) == dsu.find(3));
        ok &= (dsu.find(0) != dsu.find(2));
        ok &= (dsu.find(4) == 4);
        printResult("Basic union 0-1, 2-3", ok);
    }

    // 2. Connecting two components
    {
        DSU dsu(6);
        dsu.unite(0, 1);
        dsu.unite(2, 3);
        dsu.unite(1, 2);   // merges components
        bool ok = true;
        ok &= (dsu.find(0) == dsu.find(3));
        ok &= (dsu.find(0) != dsu.find(4));
        printResult("Merge components via 1-2", ok);
    }

    // 3. Union with self (no change)
    {
        DSU dsu(3);
        dsu.unite(1, 1);
        bool ok = (dsu.find(1) == 1);
        printResult("Union self (1,1)", ok);
    }

    // 4. Repeated union (idempotent)
    {
        DSU dsu(4);
        dsu.unite(0, 1);
        dsu.unite(0, 1);   // should be no-op
        bool ok = (dsu.find(0) == dsu.find(1));
        printResult("Repeated union (0,1)", ok);
    }

    // 5. Chain of unions (all become one component)
    {
        DSU dsu(6);
        for (int i = 0; i < 5; ++i) dsu.unite(i, i+1);
        int root = dsu.find(0);
        bool ok = true;
        for (int i = 1; i < 6; ++i) ok &= (dsu.find(i) == root);
        printResult("Chain 0-1-2-3-4-5 all connected", ok);
    }

    // 6. Mixed unions with multiple components
    {
        DSU dsu(7);
        dsu.unite(0, 2);
        dsu.unite(4, 6);
        dsu.unite(2, 5);
        dsu.unite(1, 3);
        dsu.unite(5, 6);   // merges {0,2,5,4,6} and {1,3} remains separate
        bool ok = true;
        ok &= (dsu.find(0) == dsu.find(6));
        ok &= (dsu.find(1) == dsu.find(3));
        ok &= (dsu.find(0) != dsu.find(1));
        printResult("Complex mixed unions", ok);
    }

    // 7. Verify that find always returns the root (no cycles)
    {
        DSU dsu(8);
        dsu.unite(0, 1);
        dsu.unite(2, 3);
        dsu.unite(1, 2);   // 0->1->2->3? actually parent[1]=2, parent[2]=3, parent[3]=3
        // Check each element's root is consistent
        int root0 = dsu.find(0);
        int root1 = dsu.find(1);
        int root2 = dsu.find(2);
        int root3 = dsu.find(3);
        bool ok = (root0 == root1 && root1 == root2 && root2 == root3);
        // Also check that root is a self-parent
        ok &= (dsu.find(root0) == root0);
        printResult("Consistent roots after chain", ok);
    }

    // 8. Large number of unions (size 100) with random connections
    {
        const int N = 100;
        DSU dsu(N);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, N-1);
        // Perform many random unions
        for (int i = 0; i < N * 5; ++i) {
            int a = dist(gen), b = dist(gen);
            dsu.unite(a, b);
        }
        // Verify that each element's root is a valid parent (no out-of-bounds)
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            int r = dsu.find(i);
            if (r < 0 || r >= N) { ok = false; break; }
        }
        printResult("Random unions (N=100) – no invalid roots", ok);
    }

    // 9. Edge case: N=0 (should not happen, but test it)
    {
        DSU dsu(0);
        // No operations possible, but constructor should not crash
        bool ok = true;
        printResult("Construction with N=0", ok);
    }

    // 10. Edge case: Single element
    {
        DSU dsu(1);
        bool ok = (dsu.find(0) == 0);
        dsu.unite(0, 0); // no-op
        ok &= (dsu.find(0) == 0);
        printResult("Single element operations", ok);
    }

    // ------------------- PERFORMANCE TESTS -------------------
    cout << "\n--- Performance Tests (time in milliseconds) ---\n";
    cout << fixed << setprecision(2);

    // Test sizes (keep moderate to avoid stack overflow due to deep recursion)
    const vector<int> SIZES = {1000, 5000, 10000};
    const int OPS_MULTIPLIER = 5;   // number of operations = N * multiplier

    random_device rd;
    mt19937 gen(rd());

    for (int N : SIZES) {
        cout << "\nN = " << N << "\n";

        // 1. Chain creation and find (worst-case)
        {
            DSU dsu(N);
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < N-1; ++i) dsu.unite(i, i+1);  // creates a deep chain
            auto mid = chrono::high_resolution_clock::now();
            // Now find the last element (which will recurse N times)
            int root = dsu.find(N-1);
            auto end = chrono::high_resolution_clock::now();
            double buildTime = chrono::duration<double, milli>(mid - start).count();
            double findTime = chrono::duration<double, milli>(end - mid).count();
            cout << "  Chain build: " << buildTime << " ms, find(last): " << findTime << " ms (root=" << root << ")\n";
        }

        // 2. Random unions only
        {
            DSU dsu(N);
            uniform_int_distribution<> dist(0, N-1);
            int ops = N * OPS_MULTIPLIER;
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < ops; ++i) {
                int a = dist(gen), b = dist(gen);
                dsu.unite(a, b);
            }
            auto end = chrono::high_resolution_clock::now();
            double time = chrono::duration<double, milli>(end - start).count();
            cout << "  " << ops << " random unions: " << time << " ms  (" << (time/ops) << " ms/op)\n";
        }

        // 3. Random finds only (after random unions)
        {
            DSU dsu(N);
            uniform_int_distribution<> dist(0, N-1);
            // First perform some unions to create structure
            for (int i = 0; i < N; ++i) dsu.unite(dist(gen), dist(gen));
            int ops = N * OPS_MULTIPLIER;
            auto start = chrono::high_resolution_clock::now();
            volatile int dummy = 0; // prevent optimisation
            for (int i = 0; i < ops; ++i) {
                dummy += dsu.find(dist(gen));
            }
            auto end = chrono::high_resolution_clock::now();
            double time = chrono::duration<double, milli>(end - start).count();
            cout << "  " << ops << " random finds: " << time << " ms  (" << (time/ops) << " ms/op)\n";
            (void)dummy;
        }

        // 4. Mixed (half unions, half finds)
        {
            DSU dsu(N);
            uniform_int_distribution<> dist(0, N-1);
            int ops = N * OPS_MULTIPLIER;
            auto start = chrono::high_resolution_clock::now();
            volatile int dummy = 0;
            for (int i = 0; i < ops; ++i) {
                if (i % 2 == 0) {
                    int a = dist(gen), b = dist(gen);
                    dsu.unite(a, b);
                } else {
                    dummy += dsu.find(dist(gen));
                }
            }
            auto end = chrono::high_resolution_clock::now();
            double time = chrono::duration<double, milli>(end - start).count();
            cout << "  " << ops << " mixed ops (half union, half find): " << time << " ms  (" << (time/ops) << " ms/op)\n";
            (void)dummy;
        }
    }

    cout << "\n========== ALL TESTS COMPLETED ==========\n";
    return 0;
}