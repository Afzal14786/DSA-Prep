// Question Link : https://leetcode.com/problems/sorted-gcd-pair-queries/description/?envType=daily-question&envId=2026-07-17
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end());
        vector<long long> freq(maxElem + 1, 0);

        for (int x : nums) {
            freq[x]++;    
        }

        vector<long long> countDivisors(maxElem+1, 0);

        for (int g = 1; g <= maxElem; g++) {
            for (int x = g; x <= maxElem; x += g) {
                countDivisors[g] += freq[x];
            }
        }

        vector<long long> exact(maxElem + 1, 0);
        for (int g = maxElem; g >= 1; --g) {
            exact[g] = countDivisors[g] * (countDivisors[g] - 1) / 2;
            for (int m = 2 * g; m <= maxElem; m += g) {
                exact[g] -= exact[m];
            }
        }

        vector<long long> prefix(maxElem + 1, 0);

        for (int g = 1; g <= maxElem; ++g) {
            prefix[g] = prefix[g-1] + exact[g];
        }

        vector<int> ans;
        for (long long query : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), query + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};