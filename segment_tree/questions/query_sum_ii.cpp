
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1

class Solution {
  public:

    void build_tree(int left, int right, vector<int> &segTree, int curr_idx, int arr[]) {
        // base case
        if (left == right) {
            segTree[curr_idx] = arr[left];
            return;
        }

        // compute mid
        int mid = left + (right - left) / 2;

        // now go left and right
        build_tree(left, mid, segTree, 2*curr_idx + 1, arr);
        build_tree(mid+1, right, segTree, 2*curr_idx + 2, arr);

        // now compute 
        segTree[curr_idx] = segTree[2 * curr_idx + 1] + segTree[2 * curr_idx + 2];
    }

    int query_tree(int start, int end, int curr_idx, int left, int right, vector<int> &segTree) {
        int mid = left + (right -left) / 2;

        if (left > end || right < start) return 0;
        else if (left >= start && right <= end) return segTree[curr_idx];
        else return query_tree(start, end, 2*curr_idx+1, left, mid, segTree) + query_tree(start, end, 2*curr_idx + 2, mid+1, right, segTree);
    }

    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        // code here
        vector<int> segTree(4*n);

        build_tree(0, n-1, segTree, 0, arr);
        vector<int> res;

        for (int i = 0; i < 2 * q; i += 2) {
            int start = queries[i]   - 1;
            int end   = queries[i+1] - 1;

            res.push_back(query_tree(start, end, 0, 0, n-1, segTree));
        }

        return res;
    }
}; 