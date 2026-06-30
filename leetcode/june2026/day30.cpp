// Question Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2026-06-30

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<int> seen_last(3, -1);
        for (int i = 0; i < n; ++i) {
            seen_last[s[i] - 'a'] = i;
            if (seen_last[0] != -1 && seen_last[1] != -1 && seen_last[2] != -1) {
                count += (1 + min(seen_last[0], min(seen_last[1], seen_last[2])));
            }
        }
        return count;
    }
};
