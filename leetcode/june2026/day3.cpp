// Question Link : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/?envType=daily-question&envId=2026-06-03

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculateFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minimum = 1e9;

        for (int i = 0; i < landStartTime.size(); ++i) {
            minimum = min(minimum, landStartTime[i] + landDuration[i]);
        }

        int ans = 1e9;

        for (int i = 0; i < waterStartTime.size(); ++i) {
            ans = min(ans, max(minimum, waterStartTime[i]) + waterDuration[i]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(calculateFinishTime(landStartTime, landDuration, waterStartTime, waterDuration), calculateFinishTime(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};