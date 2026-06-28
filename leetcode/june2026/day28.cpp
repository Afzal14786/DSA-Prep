// Question Link : https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/?envType=daily-question&envId=2026-06-28
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n + 1, 0);

        for (int x : arr) {
            cnt[min(x, n)]++;
        }

        int val = 0;

        for (int i = 1; i <= n; i++) {
            val = min(i, val + cnt[i]);
        }

        return val;
    }
};
