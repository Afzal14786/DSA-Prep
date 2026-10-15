#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * @brief This is the first approach for solving this question
 * In this solution we will be first sort the array and they we'll get the third highest element from end.
 * by default sort function sort the array in ascending order
 * so from last the third element will be [n-3] because the array is sorted in ascending order
 */

int thirdHighestElement1(vector<int> &nums) {
    // base call
    if (nums.size() == 0) {
        return -1;
    }

    sort(nums.begin(), nums.end());
    return nums[nums.size() - 3];
}


/**
 * @brief This is the second approach for solving this question
 * In this approach we have three different loops and each loops calculate the highest element
 * @example first loop will find first highest element
 * second loop will find second highest element & 
 * third loop will find third highest element
 */

int thirdLargestElement2(vector<int> &nums) {
    // base case
    if (nums.size() == 0) {
        return -1;
    }

    // calculate the first heighest element
    int first = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > first) {
            first = nums[i];
        }
    }

    // calculate the second highest element
    int second = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > second && nums[i] < first) {
            second = nums[i];
        }
    }

    // calculate the third highest element
    int third = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > third && nums[i] < second) {
            third = nums[i];
        }
    }

    return third;   // finally found the third highest element

}

/**
 * This is the third approach we are solving
 * @brief Time complexity for following code in O(n) and space complexity is : O(1)
 */
int thirdLargestElement(vector<int> &arr) {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    // check the base 
    if (arr.size() == 0) {
        // means the array is empty, there is no such elements
        return -1;
    }

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third) {
            third = arr[i];
        }
    }
    return third;
}

int main() {
    vector<int> arr = {1, 14, 2, 16, 10, 20};
    cout << "Third Largest Element :" << thirdLargestElement(arr) << endl;
    cout << "Third Largest Element :" << thirdLargestElement2(arr) << endl;
    cout << "Third Largest Element :" << thirdHighestElement1(arr) << endl;
    return 0;
}
