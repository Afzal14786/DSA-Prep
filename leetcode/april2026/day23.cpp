// Question Link : https://leetcode.com/problems/sum-of-distances/?envType=daily-question&envId=2026-04-23

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    typedef long long ll;

    std::vector<long long> distance(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, ll> indexSum;
        std::unordered_map<int, ll> indexCount;
        std::vector<ll> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];

            ans[i] += freq * i - sum;
            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        indexCount.clear();
        indexSum.clear();

        for (int i = n-1; i >= 0; --i) {
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];

            ans[i] += sum - freq * i;
            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        return ans;
    }
};