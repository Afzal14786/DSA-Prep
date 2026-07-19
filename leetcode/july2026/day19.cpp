// Question Link : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_seen(26);

        for (int i = 0; i < s.size(); ++i) {
            last_seen[s[i] - 'a'] = i;
        }

        vector<bool> in_stack(26, false);
        string st;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (in_stack[ch - 'a'])
                continue;
            while (!st.empty() && st.back() > ch && last_seen[st.back() - 'a'] > i) {
                in_stack[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            in_stack[ch - 'a'] = true;
        }
        return st;
    }
};
