// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : www.geeksforgeeks.org/problems/range-minimum-query/1

class Solution {
  public:

    void build_tree(int left, int right, int curr_idx, vector<int> &segment_tree, vector<int> &nums) {
        if (left == right) {
            segment_tree[curr_idx] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        build_tree(left, mid, 2 * curr_idx + 1, segment_tree, nums);
        build_tree(mid+1, right, 2 * curr_idx + 2, segment_tree, nums);

        segment_tree[curr_idx] = min(segment_tree[2 * curr_idx + 1], segment_tree[2 * curr_idx + 2]);
    }

    // now query and return the min value withing the range

    int query_tree(int start, int end, int curr_idx, int left, int right, vector<int> &segment_tree) {
        if (left > end || right < start) return INT_MAX;
        else if (left >= start && right <= end) return segment_tree[curr_idx];
        else {
            int mid = left + (right - left) / 2;
            int left_min  = query_tree(start, end, 2 * curr_idx + 1, left, mid, segment_tree);
            int right_min = query_tree(start, end, 2 * curr_idx + 2, mid + 1, right, segment_tree);
            return min(left_min, right_min);
        }
    }
    
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        vector<int> segment_tree(4*n, INT_MAX);

        build_tree(0, n-1, 0, segment_tree, arr);
        vector<int> ans;

        for (auto &que : queries) {
            int start = que[0];
            int end   = que[1];

            ans.push_back(query_tree(start, end, 0, 0, n-1, segment_tree));
        }

        return ans;
    }
};