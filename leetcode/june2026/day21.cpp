// Question Link https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        if (costs.empty()) return 0;
        sort(costs.begin(), costs.end());
        int count = 0;
        for (const auto &cs : costs) {
            if (coins >= cs) {
                coins -= cs;
                count++;
            }
        }

        return count;
    }
};

// with time complexity : O(N)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost = *max_element(costs.begin(), costs.end());
        vector<int> freq(max_cost+1, 0);

        for (const auto c : costs) freq[c]++;

        int count = 0;

        for (int price = 1; price <= max_cost; ++price) {
            if (freq[price] == 0) continue;
            if (coins >= (long long)freq[price] * price) {
                coins -= price * freq[price];
                count += freq[price];
            } else {
                int buy = coins / price;
                count += buy;
                break;
            }
        }

        return count;
    }
};
