// Question Link : https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/?envType=daily-question&envId=2026-03-13

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1, high = 1e16;
        while (low < high) {
            long long mid = (low + high) >> 1;
            long long total = 0;
            for (int i = 0; i < workerTimes.size() && total < mountainHeight; ++i) {
                total += (long long)(sqrt((double)mid / workerTimes[i] * 2 + 0.25) - 0.5);
            }

            if (total >= mountainHeight) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
