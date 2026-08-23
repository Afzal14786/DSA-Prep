
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sum-game/description/?envType=daily-question&envId=2026-08-23

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int left_known_sum = 0, right_known_sum = 0;
        int left_qn_mark_cnt = 0, right_qn_mark_cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (num[i] == '?') {
                if (i < n / 2) {
                    left_qn_mark_cnt++;
                } else {
                    right_qn_mark_cnt++;
                }
            } else {
                if (i < n/2) {
                    left_known_sum += num[i] - '0';
                } else {
                    right_known_sum += num[i] - '0';
                }
            }
        }

        int total_qn_mark = left_qn_mark_cnt + right_qn_mark_cnt;
        if (total_qn_mark % 2 == 1) return true; // alice always wins

        int LEFT    = 2 * left_known_sum + 9 * left_qn_mark_cnt;
        int RIGHT   = 2 * right_known_sum + 9 * right_qn_mark_cnt;

        return (LEFT == RIGHT) ? false : true;
    }
};