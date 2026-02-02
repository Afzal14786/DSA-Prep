
/**
  * Question Link : https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/?envType=daily-question&envId=2026-02-02
*/

#include <iostream>
#include <multiset>
#include <vector>

using namespace std;

class Solution {
public:
    class OrderedSet {
    public:
        multiset<int> low;
        multiset<int> high;

        int dist;
        int k;

    public:
        long long windowSum;
        OrderedSet(int dist, int k) {
            windowSum = 0;
            this->dist = dist;
            this->k = k;
        }

        void rebalance() {
            while (high.size() > 0 && low.size() < k - 1) {
                auto it = high.begin();
                low.insert(*it);
                windowSum += (*it);
                high.erase(it);
            }

            while (low.size() > k - 1) {
                auto it = low.rbegin();
                high.insert(*it);
                windowSum -= (*it);
                low.erase(low.find(*it));
            }
        }

        void Insert(int x) {
            if (high.size() > 0 && *(high.begin()) <= x) {
                high.insert(x);
            } else {
                low.insert(x);
                windowSum += x;
            }

            rebalance();
        }

        void Delete(int x) {
            if (low.find(x) != low.end()) {
                low.erase(low.find(x));
                windowSum -= x;
            } else {
                high.erase(high.find(x));
            }
            rebalance();
        }
    };
    long long minimumCost(vector<int>& nums, int k, int dist) {

        long long ans = 1e18;
        int n = nums.size();

        OrderedSet s(dist, k);
        for (int i = 1; i < n; i++) {
            s.Insert(nums[i]);

            if (i - dist - 1 > 0) {
                s.Delete(nums[i - dist - 1]);
            }
            if (s.low.size() == k - 1) {
                ans = min(ans, s.windowSum + nums[0]);
            }

            
        }

        return ans;
    }
};
