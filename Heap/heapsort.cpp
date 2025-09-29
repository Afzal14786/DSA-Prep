#include <iostream>
#include <vector>
using namespace std;

void heapify(int i, vector<int>&nums, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maximumI = i;

    if (left < n && nums[left] > nums[maximumI]) {
        maximumI = left;
    }

    if (right < n && nums[right] > nums[maximumI]) {
        maximumI = right;
    }

    if (maximumI != i) {
        swap(nums[i], nums[maximumI]);
        heapify(maximumI, nums, n);
    }
}

void heapSort(vector<int> &nums) {
    int n = nums.size();

    for (int i = n/2-1; i>=0; --i) {
        heapify(i, nums, n);
    }

    // step 2
    for (int i = n-1; i >= 0; --i) {
        swap(nums[0], nums[i]);
        heapify(0, nums, i);
    }
}

int main() {
    vector<int> arr = {1,4,2,5,3};
    heapSort(arr);

    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}