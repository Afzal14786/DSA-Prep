#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// approach 1.
// time complexity :  O(n^3)

int subArrSum1(vector<int> &nums) {
    int maxSum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int currSum = 0;
            for (int k = i; k <= j; ++k) {
                currSum += nums[k];
            }

            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

// approach 2   => Better then approach 1
// time complexity : O(n^2)

int subArrSum2(vector<int> &nums) {
    int maxSum = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int currSum = 0;
        for (int j = i; j < n; ++j) {
            currSum += nums[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

// approach 3   => Best optimize solution
// time complexity : O(n)

int subArrSum3(vector<int> &nums) {
    int currSum = 0, maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); ++i)  {
        currSum += nums[i];

        if (currSum < 0) {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

// dsl  450689  12 04 2003  

int main() {
    vector<int> nums= {2,-3,6,-5,4,2};

    cout << subArrSum1(nums) << endl;
    cout << subArrSum2(nums) << endl;
    cout << "Using Kadan's Algorithms : " << subArrSum3(nums) << endl;

    return 0;
}