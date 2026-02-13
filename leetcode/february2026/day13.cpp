// Question Link : https://leetcode.com/problems/longest-balanced-substring-ii/?envType=daily-question&envId=2026-02-13

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    void solve(string& s, char x, char y, int& maxi) {
        int n = s.size(), sum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == x)
                sum += 1;
            else if (s[i] == y)
                sum -= 1;
            else {
                mpp.clear();
                mpp[0] = i;
                sum = 0;
                continue;
            }

            if (mpp.find(sum) != mpp.end())
                maxi = max(maxi, i - mpp[sum]);
            else
                mpp[sum] = i;
        }
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 1, len = 1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1])
                len++;
            else {
                maxi = max(maxi, len);
                len = 1;
            }
        }
        maxi = max(maxi, len);

        solve(s, 'a', 'b', maxi);
        solve(s, 'b', 'c', maxi);
        solve(s, 'a', 'c', maxi);

        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        vector<int> count(3, 0);
        for (int i = 0; i < n; ++i) {
            count[s[i] - 'a']++;
            int count_ab = count[0] - count[1], count_ac = count[0] - count[2];
            if (mp.find({count_ab, count_ac}) != mp.end())
                maxi = max(maxi, i - mp[{count_ab, count_ac}]);
            else
                mp[{count_ab, count_ac}] = i;
        }

        return maxi;
    }
};
