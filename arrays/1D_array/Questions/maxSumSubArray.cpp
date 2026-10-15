#include <iostream>
#include <climits>
using namespace std;

// Leetcode Problem Link : https://leetcode.com/problems/maximum-subarray/description/

// Brute Force Approach             Approach 1


/**
 * In this approach Time Complexity Is : O(n^3);

 */

int maxSum_SubArray(int *arr, int size) {
    int maxSum = INT_MIN;

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            int currSum = 0;
            for (int k = i; k <= j; ++k) {
                // now calculating the current Sum in this step
                currSum += arr[k];
            }
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

// Approach 2       -> Try to Optimize the Algorithm

/**
 * Time Complexity : O(n^2)
 */
int maxSum_SubArray2(int *arr, int size) {
    int maxSum = INT_MIN;
    for (int i = 0; i < size; ++i) {
        int currSum = 0;
        for (int j = i; j < size; ++j) {
            currSum += arr[j];
            maxSum = max(currSum, maxSum);
        }
    }

    return maxSum;
}

// Kadane's Algorithm

int kadanesAlgo (int *arr, int size) {
    int maxSum = INT_MIN, currSum = 0;

    for (int i = 0; i < size; ++i) {
        currSum += arr[i];
        if (currSum <  0) {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {

    int arr[] = {2,3,-2,4};
    int length =  sizeof(arr) / sizeof(int);

    // printing the maxSum_SubArray(arr, length){} function     -> Approach 1.
    // Time Complexity : O(n^3)
    // cout << "Maximum Sum In The Sub Array Is : " << maxSum_SubArray(arr, length) << endl;

    // printing the maxSum_SubArray(arr, length){} function     -> Approach 2.
    // Time Complexity : O(n^2)
    // cout << "Maximum Sum In The Sub Array Is : " << maxSum_SubArray2(arr, length) << endl;
    cout << "Maximum Sum In The Sub Array Is : " << kadanesAlgo(arr,length) << endl;
    return 0;
}