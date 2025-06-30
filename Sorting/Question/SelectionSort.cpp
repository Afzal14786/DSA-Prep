#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int> &nums) {
    int n = nums.size();
    int k;
    for (int i = 0; i < n; ++i) {
        for (int j = k = i; j < n; ++j) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        swap(nums[i], nums[k]);
    }
}

void printArr(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {50,70,60,90,40,80,10,20,30};
    cout << "Array before sorting it :\n";
    printArr(nums);

    cout << "Array after sorting using selection sort:\n";
    SelectionSort(nums);
    printArr(nums);
    return 0;
}