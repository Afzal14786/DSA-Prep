// Question Link : https://leetcode.com/problems/number-of-unique-xor-triplets-i/description/?envType=daily-question&envId=2026-07-23
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2) return n;
        int ans = 1;
        while (ans <= n) ans *= 2;

        return ans;
    }
};
