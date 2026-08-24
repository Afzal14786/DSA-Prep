// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/

class Solution {
public:

    void build_segment_tree(int curr_idx, int left, int right, int segment_tree[], vector<int> &heights) {
        // base case
        if (left == right) {
            segment_tree[curr_idx] = left;
            return;
        }

        // now go left and right
        int mid = left + (right - left) / 2;
        build_segment_tree(2 * curr_idx + 1, left, mid, segment_tree, heights);
        build_segment_tree(2 * curr_idx + 2, mid + 1, right, segment_tree, heights);

        int left_idx = segment_tree[2 * curr_idx + 1];
        int right_idx = segment_tree[2 * curr_idx + 2];

        segment_tree[curr_idx] = (heights[left_idx] >= heights[right_idx]) ? left_idx : right_idx;
    }

    int * construct_segment_tree(vector<int> &heights, int n) {
        int *segment_tree = new int[4 * n];
        build_segment_tree(0, 0, n-1, segment_tree, heights);
        return segment_tree;
    }

    int _query_range(int start, int end, int curr_idx, int left, int right, int segment_tree[], vector<int> &heights) {
        // now it is completely out of range
        if (left > end || right < start) return -1;
        if (left >= start && right <= end) return segment_tree[curr_idx];

        // now look in the left and right
        int mid = left + (right - left) / 2;
        int left_idx = _query_range(start, end, 2 * curr_idx + 1, left, mid, segment_tree, heights);
        int right_idx = _query_range(start, end, 2 * curr_idx + 2, mid + 1, right, segment_tree, heights);

        if (left_idx == -1) return right_idx;
        if (right_idx == -1) return left_idx;

        return (heights[left_idx] >= heights[right_idx]) ? left_idx : right_idx;
    }

    int RMIQ(int segment_tree[], vector<int> &heights, int n, int start, int end) {
        return _query_range(start, end, 0, 0, n-1, segment_tree, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int *segment_tree = construct_segment_tree(heights, n);

        vector<int> res;

        for (auto &query : queries) {
            int min_idx = min(query[0], query[1]);
            int max_idx = max(query[0], query[1]);
            int threshold = max(heights[min_idx], heights[max_idx]);

            if (min_idx == max_idx || heights[max_idx] > heights[min_idx]) {
                res.push_back(max_idx);
                continue;
            }

            int low = max_idx + 1, high = n - 1;
            int ans_idx = INT_MAX;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int _idx = RMIQ(segment_tree, heights, n, low, mid);
                if (heights[_idx] > threshold) {
                    ans_idx = min(ans_idx, _idx);
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (ans_idx == INT_MAX) res.push_back(-1);
            else res.push_back(ans_idx);
        }

        return res;
    }
};