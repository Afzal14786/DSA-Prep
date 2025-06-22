#include <iostream>
#include <vector>
using namespace std;

// approach 1.

// time complexity is : (n^3)
void printSubArr(vector<int> &nums) {
    int n = nums.size();
    cout << "Total No Of Sub Arrays are : " << n * (n+1)/2 << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int k = i; k <= j; ++k) {
                cout << nums[k];
            }
            cout << ", ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> nums= {1,2,3,4,5};
    printSubArr(nums);

    return 0;
}