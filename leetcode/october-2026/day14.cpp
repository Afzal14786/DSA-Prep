// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/?envType=daily-question&envId=2026-10-14

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       int nines = sum / 9;
       int reman = sum % 9;

       string ans(nines, '9');
       if (reman > 0) {
           ans.push_back(reman + '0');
       }

       ans.append(num - ans.length(), '0');
       return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
