// Question Link : https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2026-07-13

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        queue<int> q;
        for (int i = 1; i <= 8; ++i) {
            q.push(i);
        }

        while (!q.empty()) {
            int num = q.front();
            q.pop();

            if (num >= low && num <= high) {
                ans.push_back(num);
            }

            if (num > high) break;

            int last_digit = num % 10;
            last_digit += 1;  // increase 1;
            if (last_digit > 9) continue;
            num = (num * 10) + last_digit;

            q.push(num);
        }

        return ans;
    }
};
