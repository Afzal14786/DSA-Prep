// Question Link : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/submissions/1928089919/?envType=daily-question&envId=2026-02-23

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if ((n - k + 1) < (1 << k)) {
            return false;
        }

        unordered_map<string, int> mp;

        for (int i = 0; i <= n - k; i++) {
            string t = s.substr(i, k);
            mp[t]++;
            if(mp.size() == (1 << k)){
                return true;
            }
        }

        return false;
    }
};
