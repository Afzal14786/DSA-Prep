// Question Link : https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Question Link : https://www.naukri.com/code360/problems/count-inversions_615?interviewProblemRedirection=true&search=count%20inversion

#include <iostream>
#include <vector>

class Solution {
  public:
    int merge(std::vector<int> &nums, int low, int mid, int high) {
        int count = 0;
        int left = low, right = mid+1;
        std::vector<int> temp;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else {
                temp.push_back(nums[right++]);
                count += (mid-left+1);
            }
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        // now transforming into nums
        for (int i = low; i <= high; ++i) nums[i] = temp[i-low];
        return count;
    }

    int mergeSort(std::vector<int> &nums, int low, int high) {
        int count = 0;
        if (low >= high) return count;
        int mid = low + (high - low) / 2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);

        count += merge(nums, low, mid, high);

        return count;
    }

    int inversionCount(std::vector<int> &arr) {
        // Code Here
        // brute force solution
        // int count = 0;
        // int n = arr.size();
        // for (int i = 0; i < n-1; ++i) {
        //     for (int j = i+1; j < n; ++j) {
        //         if (arr[i] > arr[j]) count++;
        //     }
        // }
        // return count;
        
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
    }
};