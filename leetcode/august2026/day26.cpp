// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/?envType=daily-question&envId=2026-08-26

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;

        string ans = "";
        for (int right = 0; right < n; ++right) {
            if (s[right] == '1')
                ones++;
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {
                while (s[left] == '0')
                    left++;

                int r = right;
                while (r >= left && s[r] == '0')
                    r--;

                string curr = s.substr(left, r - left + 1);

                if (ans.empty() ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};