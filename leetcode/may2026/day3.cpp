// question link : https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2026-05-03

#include <iostream>
#include <string>
#include <algorithm>
// brute force solution
class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        int n = s.size();
	for (int i = 1; i <= n; ++i) {
		std::rotate(s.begin(), s.begin()+1, s.end());
		if (s == goal) return true;
	}

	return false;
    }
};

class Solution2 {
public:
    bool rotateString(std::string s, std::string goal) {
        int m = s.length();
        int n = goal.length();
        
        if(m == n && (s+s).find(goal) != string::npos)
            return true;
        
        return false;
    }
};
