// Question Link : https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=daily-question&envId=2026-07-18
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max_elem = 0;
        int min_elem = INT_MAX;

        for (int x : nums) {
            max_elem = max(max_elem, x);
            min_elem = min(min_elem, x);
        }

        return gcd(max_elem, min_elem);
    }
};
