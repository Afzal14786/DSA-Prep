// Question Link : https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n, '0');
        for (int i = 0; i < n; i++)
            ans[i] = nums[i][i] == '0' ? '1' : '0';
        return ans;
    }
};
