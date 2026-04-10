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

/**
 * Subsequences where sum is K
 */

void subsequencesWhereSumIsK(int idx, int currSum, int K, vector<int> nums, vector<int> &temp) {
    int n = nums.size();
    if (idx >= n) {
        if (currSum == K) {
            for (auto n : temp) {
                cout << n << " ";
            }
            cout << endl;
        }
        return;
    }
    temp.push_back(nums[idx]);
    currSum += nums[idx];
    subsequencesWhereSumIsK(idx+1, currSum, K, nums, temp);
    temp.pop_back();
    currSum -= nums[idx];

    subsequencesWhereSumIsK(idx+1, currSum, K, nums, temp);
}

/**
 * Printing only one subsequence whose sum == K
 */

bool printOneSubsequence(int idx, int currSum, int K, vector<int> nums, vector<int> &temp) {
    int n = nums.size();
    if (idx == n) {
        if (currSum == K) {
            for (auto it : temp) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    temp.push_back(nums[idx]);
    currSum += nums[idx];
    if (printOneSubsequence(idx+1, currSum, K, nums, temp)) return true;
    temp.pop_back();
    currSum -= nums[idx];

    if (printOneSubsequence(idx+1, currSum, K, nums, temp)) return true;
    return false;
}

int countSubsequences(int idx, int currSum, int K, vector<int> nums) {
    int n = nums.size();
    int count = 0;
    if (n == idx) {
        if (currSum == K) return 1;
        return 0;
    }

    currSum += nums[idx];
    int x = countSubsequences(idx+1, currSum, K, nums);
    currSum -= nums[idx];

    int y = countSubsequences(idx+1, currSum, K, nums);
    return x + y;
}

int main() {
    vector<int> nums = {1,2,1};
    vector<int> ans;
    cout << "Total Subsequences : " << countSubsequences(0, 0, 2, nums) << endl;
    return 0;
}