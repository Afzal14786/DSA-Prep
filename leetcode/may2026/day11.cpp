// Question Link : https://leetcode.com/problems/separate-the-digits-in-an-array/?envType=daily-question&envId=2026-05-11

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int x : nums) {
            string s = to_string(x);
            for (char ch : s) {
                res.push_back(ch - '0');
            }
        }

        return res;
    }
};
