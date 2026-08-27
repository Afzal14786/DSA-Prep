// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Optimal Solution

class Optimal {
private:
    int n;
    vector<int> segment_tree;

    void update_range(int idx, int val, int root_idx, int l, int r) {
        // in the root
        if (l == r) {
            segment_tree[root_idx] = val;
            return;
        }

        // now in the left or rigt
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            update_range(idx, val, 2 * root_idx + 1, l, mid);
        else update_range(idx, val, 2 * root_idx + 2, mid + 1, r);

        segment_tree[root_idx] = max(segment_tree[2 * root_idx + 1], segment_tree[2 * root_idx + 2]);
    }

    int query_range(int start, int end, int root_idx, int l, int r) {
        // now check complete out of bound 
        if (l > end || r < start) return 0;
        if (l >= start && r <= end) return segment_tree[root_idx];

        // othewise query in left and right 
        int mid = l + (r - l) / 2;
        int left_max = query_range(start, end, 2 * root_idx + 1, l, mid);
        int right_max = query_range(start, end, 2 * root_idx + 2, mid + 1, r);

        return max(left_max, right_max);
    }

public:
    Optimal(int n) : n(n) {
        segment_tree.resize(4*n, 0);  // initially all zero 
    }

    // here root idx always start from 0 and l also start from 0
    // and r = n-1 which is passed in the parameter
    // now update and query function
    void update(int idx, int val, int root_idx, int l, int r) {
        update_range(idx, val, 0, 0, n-1);
    }

    // here root idx always start from 0 and l also start from 0
    // and r = n-1 which is passed in the parameter
    int query(int start, int end, int root_idx, int l, int r) {
        return query_range(start, end, 0, 0, n-1);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = 50001; // required size for the query 
        Optimal optimal_sol(n);

        set<int> st;
        st.insert(0); // this is always an obstacial 

        vector<bool> ans;

        for (auto &q : queries) {
            if (q[0] == 1) { // this is the type 1 query and need to perform updatation on segment tree
                int x = q[1];
                // upper bound of x
                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? *it : -1;
                int pre = *prev(it);

                // now update
                optimal_sol.update(x, x - pre, 0, 0, n-1);
                if (nxt != -1) optimal_sol.update(nxt, nxt - x, 0, 0, n-1);
                st.insert(x);  // insert the obtical
            } else { // query type 2
                int x = q[1];
                int sz = q[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);
                // we pass here 
                // (starting always from 0, to prev, n-1)
                // n-1 is the last range
                int max_gap = optimal_sol.query(0, pre, 0, 0, n-1);
                int best = max(max_gap, x - pre);
                ans.push_back(best >= sz);
            }
        }


        return ans;
    }
};

// brute force soluiton 
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;
        set<int> st;  // ordered set to store the opticals

        for (auto &query : queries) {
            if (query[0] == 1) {  // type 1 query
                st.insert(query[1]);  // store the opticals
            } else { // type 2 query
                int x = query[1];
                int sz = query[2];
                int prev = 0;

                bool found = false;

                for (int curr : st) {
                    if (curr > x) break;
                    if (curr - prev >= sz) {
                        found = true;
                        break;
                    }

                    prev = curr;
                }

                if (!found) {
                    found = (x - prev >= sz);
                }

                res.push_back(found);
            }
        }

        return res;
    }
};