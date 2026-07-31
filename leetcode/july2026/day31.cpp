// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2026-07-31

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq_map(26, 0);
        for (auto &ch : word) freq_map[ch - 'a']++;

        // now sort the frequency in decending order
        sort(freq_map.begin(), freq_map.end(), greater<int>());

        // now traverse of the array and compute the answer
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            int freq = freq_map[i];
            int press = (i/8) + 1;
            ans += (freq * press);
        }

        return ans;
    }
};