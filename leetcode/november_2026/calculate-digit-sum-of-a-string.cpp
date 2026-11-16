// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/?envType=daily-question&envId=2026-11-16

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next = "";
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                for (int j = i; j < s.length() && j < i + k; j++) {
                    sum += s[j] - '0';
                }
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();