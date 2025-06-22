#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Approach 1   => time complexity : O(n) and space complexity is O(n)
 */

int WaterTrap(vector<int> &nums) {

    int totalWaterTrap = 0;
    
    if (nums.size() < 2 || nums.size() == 0) {
        return totalWaterTrap;
    }

    
    int leftMax[nums.size()], rightMax[nums.size()];
    

    // calculate the left max bar's value
    leftMax[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        leftMax[i] = max(leftMax[i-1], nums[i-1]);
    }

    // calculating the right max bar
    rightMax[nums.size()-1] = nums[nums.size()-1];
    for (int j = nums.size() - 2; j >= 0; --j) {
        rightMax[j] = max(rightMax[j+1], nums[j+1]);
    }

    for (int i = 0; i < nums.size(); ++i) {
        int currWater = min(leftMax[i], rightMax[i]) - nums[i];

        if (currWater > 0) {
            totalWaterTrap += currWater;
        }
    }

    return totalWaterTrap;
}

// Approach 2 for solving the question using constant space .

int WaterTrap2(vector<int> &nums) {
    int totalWaterTrap = 0;
    int start = 0, end = nums.size()-1;

    int leftMaxBar = 0, rightMaxBar = 0;

    while (start < end) {
        if (nums[start] < nums[end]) {
            if (nums[start] > leftMaxBar) {
                leftMaxBar = nums[start];
            } else {
                totalWaterTrap += leftMaxBar - nums[start];
            }

            ++start;
        } else {
            if (nums[end] >= rightMaxBar) {
                rightMaxBar = nums[end];
            } else {
                totalWaterTrap += rightMaxBar - nums[end];
            }
            --end;
        }
    }

    return totalWaterTrap;
}

int main() {
    vector<int> heights = {4,2,0,6,3,2,5};
    cout << "Total Water Trap : " << WaterTrap(heights) << endl;
    cout << "Total Water Trap : " << WaterTrap2(heights) << endl;

    return 0;
}