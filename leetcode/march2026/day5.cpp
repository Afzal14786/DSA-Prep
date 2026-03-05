// Question Link : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2026-03-05

#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n, c = 0, j = 0;
        for(n = 0; n < s.size(); n++, j ^= 1) {
            if(s[n] - '0' == j) c++;
        }
        return min(c, n - c);
    }
};
