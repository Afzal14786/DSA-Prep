// Question Link : https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool palindrome(std::string &str, int startIdx, int endIdx) {
        while (startIdx < endIdx) {
            if (str[startIdx++] != str[endIdx]) return false;
        }
        return true;
    }
    
    void solve(int idx, std::string str, std::vector<std::string> &path, std::vector<std::vector<std::string>> &ans) {
        if (idx == str.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < str.size(); ++i) {
            if (palindrome(str, idx, i)) {
                path.push_back(str.substr(idx, i-idx+1));
                solve(i+1, str, path, ans);
                path.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> path;
        solve(0, s, path, ans);
        return ans;
    }
};