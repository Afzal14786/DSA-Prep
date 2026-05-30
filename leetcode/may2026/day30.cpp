// Question Link : https://leetcode.com/problems/block-placement-queries/description/?envType=daily-question&envId=2026-05-30
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        set<int> st;

        for (auto &query : queries) {
            if (query[0] == 1) {
                st.insert(query[1]);  // insert the value x
            } else {
                int x = query[1];
                int sz = query[2];

                int prev = 0;
                bool found = false;

                for (int currPoint : st) {
                    if (currPoint > x) break;

                    if (currPoint - prev >= sz) {
                        found = true;
                        break;
                    }

                    prev = currPoint;
                }

                if (!found) {
                    found = (x - prev >= sz);
                }

                ans.push_back(found);
            }
        }

        return ans;
    }
};

// Question Link :) https://leetcode.com/problems/block-placement-queries/description/?envType=daily-question&envId=2026-05-30
//  Better Approach :) Using Segment Tree


#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int n = 50000;
    vector<int> segmentTree;

    void constructSegmentTree() {
        segmentTree.resize(4 * n, 0);
    }

    void updateSegmentTree(int idx, int val, int i, int l, int r) {

        if (l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            updateSegmentTree(idx, val, 2*i+1, l, mid);
        } else {
            updateSegmentTree(idx, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }

    int querySegTree(int start, int end, int i, int l, int r) {
        if (l > end || r < start) return 0;

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        return max(querySegTree(start, end, 2*i+1, l, mid), querySegTree(start, end, 2*i+2, mid+1, r));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        constructSegmentTree();
        set<int> st;
        st.insert(0);

        vector<bool> ans;

        for (auto &query : queries) {
            if (query[0] == 1) {
                int x = query[1];
                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? *it : -1;
                int pre = *prev(it);

                updateSegmentTree(x, x-pre, 0, 0, n-1);
                updateSegmentTree(nxt, nxt-x, 0, 0, n-1);
                st.insert(x);
            } else {
                int x = query[1];
                int sz = query[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int maxGap = querySegTree(0, pre, 0, 0, n-1);
                int best = max(maxGap, x-pre);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};
