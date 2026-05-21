// Question Link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2026-05-21
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for (int x : arr1) {
            while (!st.count(x) && x > 0) {
                st.insert(x);
                x /= 10;
            }
        }

        int res = 0;

        for (int x : arr2) {
            while (!st.count(x) && x > 0) {
                x /= 10;
            }
            if (x > 0) {
                res = max(res, static_cast<int>(log10(x) + 1));
            }
        }

        return res;
    }
};
