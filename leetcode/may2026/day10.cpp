// Question Link : https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/?envType=daily-question&envId=2026-05-10

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            if (dp[i] == -1) continue;
            for (int j = i+1; j < n; ++j) {
                long long diff = 1LL * nums[j] - nums[i];
                if (-target <= diff && diff <= target) dp[j] = max(dp[j], dp[i]+1);
            }
        }

        return dp[n-1];
    }
};


class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, -1);
    }

    // update position with maximum value
    void update(int node, int start, int end, int idx, int val) {

        if(start == end) {
            tree[node] = max(tree[node], val);
            return;
        }

        int mid = (start + end) / 2;

        if(idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = max(tree[2 * node],
                         tree[2 * node + 1]);
    }

    // range maximum query
    int query(int node, int start, int end,
              int l, int r) {

        // no overlap
        if(r < start || end < l)
            return -1;

        // complete overlap
        if(l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        return max(
            query(2 * node, start, mid, l, r),
            query(2 * node + 1, mid + 1, end, l, r)
        );
    }
};

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        // coordinate compression
        vector<int> vals = nums;

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()),
                   vals.end());

        int m = vals.size();

        SegmentTree seg(m);

        vector<int> dp(n, -1);

        // starting index
        dp[0] = 0;

        // update value of nums[0]
        int pos0 = lower_bound(vals.begin(), vals.end(),nums[0]) - vals.begin();

        seg.update(1, 0, m - 1, pos0, 0);

        for(int j = 1; j < n; j++) {

            long long leftVal = 1LL * nums[j] - target;
            long long rightVal = 1LL * nums[j] + target;

            // compressed range
            int left =
                lower_bound(vals.begin(), vals.end(),leftVal) - vals.begin();

            int right =
                upper_bound(vals.begin(),vals.end(),rightVal) - vals.begin() - 1;

            if(left <= right) {

                int best =
                    seg.query(1, 0, m - 1, left, right);

                if(best != -1) {
                    dp[j] = best + 1;
                }
            }

            // update current value
            if(dp[j] != -1) {

                int pos =
                    lower_bound(vals.begin(),vals.end(),nums[j]) - vals.begin();

                seg.update(1, 0, m - 1, pos, dp[j]);
            }
        }

        return dp[n - 1];
    }
};