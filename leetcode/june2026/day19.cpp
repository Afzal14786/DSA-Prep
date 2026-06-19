// Question Link : https://leetcode.com/problems/find-the-highest-altitude/?envType=daily-question&envId=2026-06-19

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_height = 0, curr_height = 0;
        for (const auto &g : gain) {
            curr_height += g;
            max_height = max(curr_height, max_height);
        }
        return max_height;
    }
};

