// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/?envType=daily-question&envId=2026-11-03

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int _max = nums[n-1], moves = 0;
        for (int i = n-1; i >= 0; --i) moves += abs(nums[i] - _max);
        return moves;
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int _max = 0, sum = 0;
        for (int x : nums) {
            _max = max(_max, x);
            sum += x;
        }

        return nums.size() * _max - sum;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();