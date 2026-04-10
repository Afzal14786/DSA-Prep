// Question Link : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/?envType=daily-question&envId=2026-04-10

#include <iostream>
#include <vector>
#include <algorithm>

struct custom {
    int i, j, k;
    custom(int i, int j, int k) : i(i), j(j), k(k){}
};

class Solution {
public:
    int minimumDistance(std::vector<int>& nums) {
        int n = nums.size();
        int min_dist = 1e9;
        if (n < 3) return -1;
        
        std::vector<custom> temp;

        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) temp.push_back({i,j,k});
                }
            }
        }

        for (auto cust : temp) {
            min_dist = std::min(min_dist, abs(cust.i - cust.j) + abs(cust.j - cust.k) + abs(cust.k - cust.i));
        }
        return (min_dist == 1e9) ? -1 : min_dist;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1,1,2,3,2,1,2};
    std::cout << "Minimum Distance : " << s.minimumDistance(nums) << std::endl;

    return 0;
}