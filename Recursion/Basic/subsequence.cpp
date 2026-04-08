#include <iostream>
#include <vector>

using namespace std;

void printAllSubsequences(int idx, vector<int> &T, vector<int> nums) {
    int n = nums.size();
    if (idx >= n) {
        // print the array
        for (auto n : T) {
            cout << n << " ";
        }
        if (T.size() == 0) {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    // now choose
    T.push_back(nums[idx]);
    printAllSubsequences(idx+1, T, nums);
    T.pop_back();

    // now not choose
    printAllSubsequences(idx+1, T, nums);
}



int main() {
    vector<int> nums = {3,1,2};
    vector<int> ans;
    printAllSubsequences(0, ans, nums);
    return 0;
}