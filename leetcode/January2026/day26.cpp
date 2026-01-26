/**
 * Minimum Absolute Difference
 * Question Link : https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26
 * Solution Link : 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return {};
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            int curr_diff = abs(arr[i+1] - arr[i]);
            if (curr_diff < min_diff) {
                min_diff = curr_diff;
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            } else if (curr_diff == min_diff) ans.push_back({arr[i], arr[i+1]});
        }
        return ans;
    }
};