/**
    This is the simplest algorithm for searchin where each element is compared with it's adjucent and at the end the heaviest element is sort
*/

#include <iostream>
#include <vector>
using namespace std;

void printArr(int *nums, int n) {
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

void printVecor(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

void BubbleSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
            }
        }
    }

    printVecor(nums);
}

void BubbleSort2(int *nums, int n) {
    for (int i = 0; i < n-1; ++i) {
        int flag = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j] , nums[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Given Array is already sorted.\n";
            return;
        }
    }


}

int main() {

    vector<int> numsVector = {10,2,4,1,45,23};
    int nums[] = {1,2,3,5,4,6,8,7};
    
    cout << "Array Before Sorting : \n";
    printArr(nums, 8);
    // printVecor(numsVector);


    cout << "\nArray After Sorting The Element's :\n";
    
    BubbleSort2(nums, 8);
    // BubbleSort(numsVector);

    printArr(nums, 8);
    return 0;
}