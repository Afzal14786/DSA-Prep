// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> segTree;
    vector<int> nums;

    void build_tree(int idx, int left, int right) {
        // Base case: leaf node
        if (left == right) {
            segTree[idx] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        
        // Build left child (2*idx + 1) and right child (2*idx + 2)
        build_tree(2 * idx + 1, left, mid);
        build_tree(2 * idx + 2, mid + 1, right);

        // Merge step (Sum Query Segment Tree)
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

public:
    // Constructor initializes data and triggers the tree build
    SegmentTree(const vector<int>& input_nums) {
        nums = input_nums;
        n = nums.size();
        
        if (n > 0) {
            // Allocate 4 * n space and initialize elements to 0
            segTree.resize(4 * n, 0);
            // Start building from the root index 0, spanning range [0, n-1]
            build_tree(0, 0, n - 1);
        }
    }

    void update_segTree(int idx, int val, int i, int left, int right) {
        if (left == right) {
            segTree[i] = val;
            return;
        }

        int mid = left + (right - left) / 2;
        if (idx <= mid) { // go left
            update_segTree(idx, val, 2*i + 1, left, mid);
        } else {
            update_segTree(idx, val, 2*i + 2, mid+1, right);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int query(int start, int end, int idx, int left, int right) {

        int mid = left + (right - left) / 2;
        // first case
        if (left > end || right < start) return 0;
        else if (left >= start && right <= end) return segTree[idx];
        else {
            // just return the sum of left and right values
            return query(start, end, 2*idx + 1, left, mid) + query(start, end, 2 * idx + 2, mid + 1, right); 
        }
    }

    // Helper function to print tree contents for debugging
    void printTree() {
        cout << "Segment Tree Array: ";
        for (int i = 0; i < 4 * n; ++i) {
            cout << segTree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};
    
    // Create and build the segment tree
    SegmentTree st(data);
    
    st.printTree();
    
    return 0;
}
