// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

struct node {
    int max_elem;
    int min_elem;
    node() : max_elem(0), min_elem(0) {}
    node(int max_elem, int min_elem) {
        this->max_elem = max_elem;
        this->min_elem = min_elem;
    }
};

class Lazy_Propagation {
private:
    vector<int> nums, lazy;
    vector<node> segment_tree;  // every node store <max_elem, min_eleme>

    void build_tree(int curr_idx, int left, int right) {
        // base case
        if (left == right) {
            // every element itself minimum and maximum
            segment_tree[curr_idx].max_elem = nums[left];
            segment_tree[curr_idx].min_elem = nums[left];
            return;
        }

        // now go in the left and right
        int mid = left + (right - left) / 2;
        build_tree(2 * curr_idx + 1, left, mid);
        build_tree(2 * curr_idx + 2, mid + 1, right);

        // now update the min and max
        segment_tree[curr_idx].min_elem = min(segment_tree[2 * curr_idx + 1].min_elem, segment_tree[2 * curr_idx + 2].min_elem);
        segment_tree[curr_idx].max_elem = max(segment_tree[2 * curr_idx + 1].max_elem, segment_tree[2 * curr_idx + 2].max_elem);
    }

    void propagate(int idx, int left, int right) {
        if (lazy[idx] == 0) return;
        int val = lazy[idx];

        segment_tree[idx].min_elem += val;
        segment_tree[idx].max_elem += val;

        if (left != right) {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }

        lazy[idx] = 0;
    }

    void update_range(int start, int end, int curr_idx, int left, int right, int val) {
        // propagation
        propagate(curr_idx, left, right);
        if (start > right || end < left) return;

        if (left >= start && right <= end) {
            lazy[curr_idx] += val;
            propagate(curr_idx, left, right);
            return;
        }

        int mid = left + (right - left) / 2;
        update_range(start, end, 2 * curr_idx + 1, left, mid, val);
        update_range(start, end, 2 * curr_idx + 2, mid + 1, right, val);

        segment_tree[curr_idx].min_elem = min(segment_tree[2 * curr_idx + 1].min_elem, segment_tree[2 * curr_idx + 2].min_elem);
        segment_tree[curr_idx].max_elem = max(segment_tree[2 * curr_idx + 1].max_elem, segment_tree[2 * curr_idx + 2].max_elem);
    }

public:
    Lazy_Propagation(vector<int> &nums) : nums(nums) {
        int n = nums.size();
        segment_tree.resize(4 * n);
        lazy.resize(4 * n, 0);  // initially everything 0
        build_tree(0, 0, n-1);
    }

    void update(int start, int end, int val) {
        update_range(start, end, 0, 0, nums.size() - 1, val);
    }

    int get_min() {
        return segment_tree[0].min_elem;
    }

    int get_max() {
        return segment_tree[0].max_elem;
    }
};

void print_arr(const vector<int> &arr) {
    cout << "current array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {

    vector<int> nums = {1, 3, 5, 7, 9, 11};

    Lazy_Propagation st(nums);

    print_arr(nums);

    cout << "Initial array:\n";
    cout << "Min = " << st.get_min() << '\n';
    cout << "Max = " << st.get_max() << '\n';

    // Add 10 to indices [1, 4]
    cout << "Adding 10 from [1, 4]\n";
    st.update(1, 4, 10);
    
    cout << "\nAfter adding 10 to range [1, 4]:\n";
    cout << "Min = " << st.get_min() << '\n';
    cout << "Max = " << st.get_max() << '\n';

    // Add 5 to indices [0, 2]
    st.update(0, 2, 5);

    cout << "\nAfter adding 5 to range [0, 2]:\n";
    cout << "Min = " << st.get_min() << '\n';
    cout << "Max = " << st.get_max() << '\n';

    return 0;
}
