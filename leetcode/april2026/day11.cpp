// Question Link : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/?envType=daily-question&envId=2026-04-11

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Time Complexity For this solution is O(N^2)
 */
// class Solution {
// public:
//     int minimumDistance(std::vector<int>& nums) {
//         int ans = 1e9;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             bool flag = false;
//             for (int j = i+1; j < n; ++j) {
//                 if (nums[i] == nums[j]) {
//                     if (flag) {
//                         ans = std::min(ans, j-i);
//                         break;
//                     } else {
//                         flag = true;
//                     }
//                 }
//             }
//         }

//         return (ans == 1e9) ? -1 : ans * 2;
//     }
// };

/**
 * Time Compexity : O(N)
 * Space Compexity: O(N) In order to storing the data for manipulating
 */
class Solution {
public:
    int minimumDistance(std::vector<int>& nums) {
        int ans = 1e9;
        int n = nums.size();
        std::vector<int> position(n+1, -1);
        std::vector<int> distance(n, 1e9);

        for (int i = 0; i < n; ++i) {
            if (position[nums[i]] != -1) {
                distance[i] = (i - position[nums[i]]);
                ans = std::min(ans, distance[i] + distance[position[nums[i]]]);
            }
            position[nums[i]] = i;
        }

        return (ans == 1e9) ? -1 : 2 * ans;
    }
};

int main() {
    std::vector<int> nums = {1,1,2,3,2,1,2};
    Solution s;

    std::cout << "Minimum Distance : " << std::endl;
    std::cout << s.minimumDistance(nums) << std::endl;

    return 0;
}