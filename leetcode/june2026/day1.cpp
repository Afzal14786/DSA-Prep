// Question Link : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/?envType=daily-question&envId=2026-06-01

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        sort(cost.begin(), cost.end(), greater<int>());
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 3 != 2) total += cost[i];
        }

        return total;
    }
};