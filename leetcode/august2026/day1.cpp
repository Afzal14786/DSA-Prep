// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01

class Solution {
public:
    int t[23][23];
    int solve(int i, int j, vector<int> &nums) {
        if (i > j) return 0;
        if (i == j) return nums[i];
        // every index having two option so 
        // 2 ^ n
        if (t[i][j] != -1) return t[i][j];
        int take_i = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));
        int take_j = nums[j] + min(solve(i, j-2, nums), solve(i+1, j-1, nums));

        return t[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        int total_sum = 0;
        for (int x : nums) total_sum += x;

        int player1 = solve(0, n-1, nums);
        int player2 = total_sum - player1;

        return player1 >= player2;
    }
};

// another way of solving 

class Solution {
public:
    int t[23][23];
    int solve(int i, int j, vector<int> &nums) {
        if (i > j) return 0;
        if (i == j) return nums[i];
        if (t[i][j] != -1) return t[i][j];
        int take_i = nums[i] - solve(i + 1, j, nums);
        int take_j = nums[j] - solve(i, j-1, nums);
        return t[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        
        return solve(0, n-1, nums) >= 0;
    }
};