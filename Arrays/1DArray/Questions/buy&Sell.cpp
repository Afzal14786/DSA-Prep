#include <iostream>
#include <climits>
using namespace std;

/**
 * Time Complexity : O(n)
 * Leet Code Question Link :  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 */

int buy_sell_tock(int *prices, int n) {
    int bestBuy[n];
    bestBuy[0] = INT_MAX;
    int maxProfit = 0;
    int currPrice = 0;

    for (int i = 1; i < n; ++i) {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }

    for (int i = 0; i < n; ++i) {
        currPrice = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currPrice);
    }

    return maxProfit;
}


// using this login we can save our auxilary space and can solve in O(1) space complexity 
int buy_sell_stock2(int *prices, int size) {
    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 0; i < size; ++i) {
        int currPrice = prices[i];
        int currProfit = currPrice - minPrice;

        maxProfit = max(maxProfit, currProfit);
        minPrice = min(currPrice, minPrice);
    }

    return maxProfit;
}

int main() {
    int prices[] = {7,1,5,3,6,4};
    int size = sizeof(prices) / sizeof(int);

    cout << "Maximum Profit = " << buy_sell_stock2(prices, size) << endl;

    return 0;
}