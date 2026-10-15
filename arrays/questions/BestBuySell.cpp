#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// time complexity : O(n)
// space complexity : O(n)
int bestBuyAndSell(vector<int> &nums) {
    int maxProfit = 0;
    int currPrice = 0;
    int bestBuy[nums.size()];
    bestBuy[0] = INT_MAX;

    for (int i = 1; i < nums.size(); ++i) {
        bestBuy[i] = min(bestBuy[i-1], nums[i-1]);
    }

    for (int i = 0; i < nums.size(); ++i) {
        currPrice = nums[i] - bestBuy[i];
        maxProfit = max(maxProfit, currPrice);
    }

    return maxProfit;
}

// time complexity for this code is : O(n) but 
// space complexity for this code is : O(1).
int bestBuyAndSell2(vector<int> &nums) {
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < nums.size(); ++i) {
        minPrice = min(minPrice, nums[i]);

        // calculate the current price if we buy at low price and sell today
        int currProfit = nums[i] - minPrice;

        maxProfit = max(maxProfit, currProfit);
    }

    return 0;
}

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    cout << bestBuyAndSell(nums) << endl;
    return 0;
}