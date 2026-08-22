
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Range_Max_Min_Query_Index {
private:
    /**
     * @param n                 the number of values passed in the nums array from user
     * @param segment_tree      segment tree that contains the maximum values within the ranges
     */
    int n;
    vector<int> segment_tree, nums;

    void build_tree(int curr_idx, int left, int right, vector<int> &nums) {
        // base case bhai
        if (left == right) {
            segment_tree[curr_idx] = left;
            return;
        }

        int mid = left + (right - left) / 2;
        build_tree(2 * curr_idx + 1, left, mid, nums);
        build_tree(2 * curr_idx + 2, mid + 1, right, nums);

        int left_idx    =   segment_tree[2 * curr_idx + 1];
        int right_idx   =   segment_tree[2 * curr_idx + 2];

        segment_tree[curr_idx] = (nums[left_idx] <= nums[right_idx]) ? left_idx : right_idx;
    }

    /**
     * @funtion -- ye function index return krega minimum values ka diye hue given range me
     * @param start         starting range
     * @param end           ending range
     * @param curr_idx      current index, starting from root `0`
     * @param left          starting from 0
     * @param right         ending at n-1
     * @param nums          array of values
     */
    int query_minimum_index(int start, int end, int curr_idx, int left, int right, vector<int> &nums) {
        // bilkul apne aukaat ke bahar ka hai ye to 
        if (start > right || end < left) return -1;
        if (start >= left && end <= right) return segment_tree[curr_idx];
        
        int mid = left + (right - left) / 2;
        int left_idx    =    query_minimum_index(start, end, 2 * curr_idx + 1, left, mid, nums);
        int right_idx   =    query_minimum_index(start, end, 2 * curr_idx + 2, mid + 1, right, nums);

        if (left_idx == -1)     return right_idx;
        if (right_idx == -1)    return left_idx;

        return (nums[left_idx] <= nums[right_idx]) ? left_idx : right_idx;
    }

    int query_maximum_index(int start, int end, int curr_idx, int left, int right, vector<int> &nums) {
        if (start > right || end < left) return -1;
        if (start >= left && end <= right) return segment_tree[curr_idx];

        int mid = left + (right - left) / 2;
        int left_idx    =     query_maximum_index(start, end, 2 * curr_idx + 1, left, mid, nums);
        int right_idx   =     query_maximum_index(start, end, 2 * curr_idx + 2, mid + 1, right, nums);

        if (left_idx == -1) return right_idx;
        if (right_idx == -1) return left_idx;

        return (nums[left_idx] >= nums[right_idx]) ? left_idx : right_idx;
    }

public:

    Range_Max_Min_Query_Index(vector<int> &nums): nums(nums) {
        n = nums.size();
        segment_tree.resize(4*n);
        // now build the tree
        build_tree(0, 0, n-1, nums);
    }

    int min_query(int start, int end) {
        return query_minimum_index(start, end, 0, 0, n-1, nums);
    }

    int max_query(int start, int end) {
        return query_maximum_index(start, end, 0, 0, n-1, nums);
    }
};