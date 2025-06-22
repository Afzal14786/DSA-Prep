#include <iostream>
#include <limits>
#include <climits>
using namespace std;

/***
 * Revision Questions
 *  1. Find Max Profix
 *  2. Max Sub Array Sum
 *  3. Max Profix (Best Time To Buy And Sell Stock)
 *  4. Sorting Algorithms
 *   
 */

 // the logic is correct and time complexity is O(n^3)
int brute_force(int *nums, int size) {
    int maxSum = INT_MIN;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            int currSum = 0;
            for (int k = i; k < j; ++k) {
                currSum += nums[k];
            }
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int optimize_solution(int *nums, int n) {
    int maxSum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int currSum = 0;
        for (int j = i; j < n; ++j) {
            currSum += nums[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int kadans_algorithm(int *nums, int n) {
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; ++i) {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int max_profit(int *prices, int n) {
    int maxProfit = 0, currProfit = 0;
    int bestBuy[n];
    bestBuy[0] = INT_MAX;
    // calculate the best buying price 
    for (int i = 1; i < n; ++i) {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }

    // calculating the currProfit and max profit
    for (int i = 0; i < n; ++i) {
        currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }

    return maxProfit;
}

int optimize_maxProfit(int *prices, int n) {
    int currPrice = 0, maxProfit = 0;

    for (int i = 0; i < n; ++i) {

    }

    return maxProfit;
}

int waterTrap(int *heights, int size) {
    int waterTrap = 0, currWater = 0;
    int leftMax[size], rightMax[size];
    leftMax[0] = heights[0];
    rightMax[size-1] = heights[size-1];

    for (int i = 1; i < size; ++i) {
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
    }

    for (int i = size-2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
    }

    for (int i = 0; i < size; ++i) {
        currWater = min(leftMax[i], rightMax[i]) - heights[i];
        if (currWater > 0) {
            waterTrap += currWater;
        }
    }

    return waterTrap;
}



int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(nums)/sizeof(int);

    // cout << kadans_algorithm(nums, size) << endl;

    int prices[] = {7,6,4,3,1};
    int n = sizeof(prices)/sizeof(int);
    // cout << max_profit(prices, n) << endl;

    int heights[] = {4,2,0,6,3,2,5};
    int heightSize = sizeof(heights)/sizeof(int);

    cout << waterTrap(heights, heightSize) << endl;
    return 0;
}