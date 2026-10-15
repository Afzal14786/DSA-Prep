#include <iostream>
#include <climits>
using namespace std;

int trap(int *heights, int size) {
    int leftMax[10000], rightMax[10000];

    leftMax[0] = heights[0];
    rightMax[size-1] = heights[size-1];

    // calculate the left max and right max
    for (int i = 1; i < size; ++i) {
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
    }

    for (int i = size - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
    }

    int waterTrap = 0;
    for (int i = 0; i < size; ++i) {
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];

        if (currWater > 0) {
            waterTrap += currWater;
        }
    }

    return waterTrap;
}

/**
 * Without using any extra space we solve this issue having O(1) space complexity and O(n) time complexity
 * 
 */
int trap2(int *heights, int size) {
    int waterTrap = 0;
    int start = 0, end = size-1;
    int leftMax = 0, rightMax = 0;

    while (start < end) {
        if (heights[start] < heights[end]) {
            if (heights[start] > leftMax) {
                leftMax = heights[start];
            } else {
                waterTrap += leftMax - heights[start];
            }
            ++start;
        } else {
            if (heights[end] >= rightMax) {
                rightMax = heights[end];
            } else {
                waterTrap += rightMax - heights[end];
            }rightMaxBar
            --end;
        }
    }

    return waterTrap;
}

int main() {
    int heights[] = {4,2,0,6,3,2,5};
    int size = sizeof(heights)/ sizeof(int);
    // cout << trap(heights,size) << endl;  // 11
    cout << trap2(heights, size) << endl;
    return 0;
}