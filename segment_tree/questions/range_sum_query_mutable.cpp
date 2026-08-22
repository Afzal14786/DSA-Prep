
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    vector<int> segment_tree;

    void build_tree(int curr_idx, int left, int right, vector<int> &nums) {
        // base case 
        if (left == right) {
            segment_tree[curr_idx] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        build_tree(2 * curr_idx + 1, left, mid, nums);
        build_tree(2 * curr_idx + 2, mid + 1, right, nums);

        segment_tree[curr_idx] = segment_tree[2 * curr_idx + 1] + segment_tree[2 * curr_idx + 2];
    }

    /**
     * this is the method used to update the segment tree
     */

    void update_segment_tree(int index, int val, int curr_idx, int left, int right) {
        // base case
        if (left == right) {
            segment_tree[curr_idx] = val;
            return;
        }

        // now go into left and right or waha ja ke check kro 
        int mid = left + (right - left) / 2;
        if (index <= mid) {  // means the value is in the left side 
            update_segment_tree(index, val, 2 * curr_idx + 1, left, mid);
        } else {
            update_segment_tree(index, val, 2 * curr_idx + 2, mid + 1, right);
        }

        // now returning ke time tum yaha uppar wale values ko bhi update krte hue backtrack kro --- samjhe 
        segment_tree[curr_idx] = segment_tree[2 * curr_idx + 1] + segment_tree[2 * curr_idx + 2];
    }

    /**
     * this function will return the sum within a range
     * @return int
     */

    int range_sum_query(int start, int end, int curr_idx, int left, int right) {
        // jb start or end bilkul apne aukaat ke bahar ho
        if (left > end || right < start) return 0;
        if (left >= start && right <= end) return segment_tree[curr_idx];  // matlab  bhai within the range hai 
        else {
            int mid = left + (right - left) / 2;
            return range_sum_query(start, end, 2 * curr_idx + 1, left, mid) + range_sum_query(start, end, 2 * curr_idx + 2, mid + 1, right);
        }
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();  // size of the passed nums
        segment_tree.resize(4*n);
        // now build the tree
        build_tree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        // yaha hum update krenge value ko diye hue particular index me 
        update_segment_tree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return range_sum_query(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */