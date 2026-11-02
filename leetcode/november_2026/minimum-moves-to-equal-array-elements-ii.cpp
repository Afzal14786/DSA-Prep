// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/?envType=daily-question&envId=2026-11-02

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        int moves = 0;
        while (i < j) {
            // just compute the distace
            moves += (nums[j] - nums[i]);
            i++;
            j--;
        }

        return moves;
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        int _mid = n / 2;
        for(int i=0; i < _mid; i++){  // this loop is traversing till half of the array which is faster then above solution
            steps += nums[n-1-i] - nums[i]; //Adding difference
        }
        return steps;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();