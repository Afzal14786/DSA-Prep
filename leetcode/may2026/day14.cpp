// Question Link https://leetcode.com/problems/check-if-array-is-good/?envType=daily-question&envId=2026-05-14
//
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        bitset<201> seen;
        bool dup = 0;

        for (auto& num : nums) {
            if (num > n) return false;

            if (seen.test(num)) {
                if (num < n || dup) return false;
                dup |= 1;
                continue;
            }

            seen.set(num);
        }

        return true;
    }
};
