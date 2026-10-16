// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/?envType=daily-question&envId=2026-10-16

#include <bits/stdc++.h>
using namespace std;

/**
 * Optimal Solution
 * @time complexity : O(nlogn)
 * @space complexity : O(4*n)
 */


class Solution {
private:
    typedef long long ll;
    const int MOD = 1e9 + 7;

    vector<ll> sq_sum_seg_tree;
    vector<ll> sum_seg_tree;
    vector<ll> lazy_tree;
    int n;

    void lazy_addition(int i, int l, int r, int val) {
        int childs = r - l + 1;
        sq_sum_seg_tree[i] += 2 * val * sum_seg_tree[i] + childs * val * val;
        sum_seg_tree[i]    += (childs * val);
    }

    void update_range(int start, int end, int i, int l, int r, int val) {
        
        /**
         * lazy propagation
         */

        if (lazy_tree[i] != 0) {
            // means update in the child
            lazy_addition(i, l, r, lazy_tree[i]);
            if (l != r) {
                lazy_tree[2 * i + 1] += lazy_tree[i];
                lazy_tree[2 * i + 2] += lazy_tree[i];
            }
            lazy_tree[i] = 0;
        }

        // out of range
        if (l > end || r < start || l > r) return;
        
        // within range
        if (l >= start && r <= end) {
            // call the function
            lazy_addition(i, l, r, val);
            if (l != r) {
                lazy_tree[2 * i + 1] += val;
                lazy_tree[2 * i + 2] += val;
            }
            return;
        }

        int mid = l + (r - l) / 2;
        update_range(start, end, 2 * i + 1, l, mid, val);
        update_range(start, end, 2 * i + 2, mid + 1, r, val);
        sum_seg_tree[i]     = sum_seg_tree[2 * i + 1] + sum_seg_tree[2 * i + 2];
        sq_sum_seg_tree[i]  = sq_sum_seg_tree[2 * i + 1] + sq_sum_seg_tree[2 * i + 2];
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sq_sum_seg_tree.assign(4*n, 0);
        sum_seg_tree.assign(4*n, 0);
        lazy_tree.assign(4*n, 0);
        
        ll result = 0;
        vector<int> last_seen_idx(100001, -1);

        for (int i = 0; i < n; ++i) {
            int start = last_seen_idx[nums[i]] + 1;
            int end = i;

            /**
             * update within the range
             */
            update_range(start, end, 0, 0, n-1, 1);
            result = (result + sq_sum_seg_tree[0]) % MOD;
            last_seen_idx[nums[i]] = i;
        }

        return result;
    }
};

 /** ----------------------------------- ----------------------------------- ----------------------------------- -----------------------------------  */

/**
 * brute force solution
 * @time complexity : O(n^2)
 * @space complexity : O(n)
 * 
 * @details but this will solution will give us TLE because the constraints are :
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 */
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> st;
            for (int j = i; j < n; ++j) {
                st.insert(nums[j]);
                int distince = st.size();
                res += distince * distince;
            }
        }
        return res;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();