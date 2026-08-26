// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // brute force solution
        int n = nums.size();
        vector<int> cum_sum(n, 0);
        int max_len = 0;
        unordered_map<int, int> mpp;
        
        for (int r = 0; r < n; ++r) {
            int val = (nums[r] % 2 == 0) ? 1 : -1;
            int prev = -1;

            if (mpp.count(nums[r])) prev = mpp[nums[r]];

            if (prev != -1) {
                for (int l = 0; l <= prev; ++l) {
                    cum_sum[l] -= val;
                }
            }

            for (int l = 0; l <= r; ++l) cum_sum[l] += val;

            for (int l = 0; l <= r; ++l) {
                if (cum_sum[l] == 0) {
                    max_len = max(max_len, r - l + 1);
                    break;;
                }
            }

            mpp[nums[r]] = r;
        }

        return max_len;
    }
};

// optimal solution 

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

    int left_most_zero_range(int curr_idx, int left, int right) {
        propagate(curr_idx, left, right);

        if (segment_tree[curr_idx].min_elem > 0 || segment_tree[curr_idx].max_elem < 0) return -1;  // means zero does not exist here
        if (left == right) { // in the lead node
            return left;
        }

        int mid = left + (right - left) / 2;
        int _left_res   = left_most_zero_range(2 * curr_idx + 1, left, mid);
        if (_left_res != -1) return _left_res;

        return left_most_zero_range(2 * curr_idx + 2, mid + 1, right);
    }

public:
    Lazy_Propagation(int n) {
        segment_tree.resize(4 * n);
        lazy.resize(4 * n, 0);  // initially everything 0
    }

    void update(int start, int end, int curr_idx, int  left, int right, int val) {
        update_range(start, end, curr_idx, left, right, val);
    }

    int left_most_zero(int curr_idx, int left, int right) {
        return left_most_zero_range(curr_idx, left, right);
    }
};