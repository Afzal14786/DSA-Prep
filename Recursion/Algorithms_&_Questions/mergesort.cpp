/**
 * Understanding Merge Sort Using Recursion
 */

#include <iostream>
#include <vector>

class Sorting {
    std::vector<int> nums;

public:
    Sorting(std::vector<int> &vec) : nums(vec) {}

    void MergeSort(int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        MergeSort(low, mid);
        MergeSort(mid+1, high);

        Merge(low, mid, high);
    }

    void Merge(int low, int mid, int high) {
        std::vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; ++i) nums[i] = temp[i-low];
    }

    void displayArr() {
        for (int x : nums) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};


int main() {
    std::vector<int> nums = {5,7,8,5,2,1,6,4,9,3,2,1,5,4,5,1,2,78,45,12,20,0,3,5,65};
    Sorting S(nums);
    std::cout << "Sorting Before : " << std::endl;
    S.displayArr();

    S.MergeSort(0, nums.size()-1);
    std::cout << "After Sorting : ";
    S.displayArr();
    
    return 0;
}