// Question Link : https://leetcode.com/problems/palindrome-partitioning-ii/

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool palindrome(std::string &str, int startingIdx, int endIdx) {
        while (startingIdx < endIdx) {
            if (str[startingIdx++] != str[endIdx--]) return false;
        }
        return true;
    }

    int solve(int idx, std::string &srt, int count) {
        int min_cuts = 1e9;
        
    }

    int minCut(std::string s) {
        
    }
};