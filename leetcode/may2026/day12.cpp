// Question Link : https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/?envType=daily-question&envId=2026-05-12

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for (auto &task : tasks) {
            int actual_energy = task[0];
            int minimum_energy = task[1];

            if (minimum_energy > mid) return false;

            mid -= actual_energy;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int left = 0, right = 1e9 + 7;
        int res = 1e9+7;
        auto lambda = [](auto &task1, auto &task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(tasks.begin(), tasks.end(), lambda);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(tasks, mid)) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
};