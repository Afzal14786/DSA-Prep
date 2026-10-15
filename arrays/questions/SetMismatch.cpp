/**
    * You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
    
    * You are given an integer array nums representing the data status of this set after the error.
    * Find the number that occurs twice and the number that is missing and return them in the form of an array.
    * 
    * Example 1:

        Input: nums = [1,2,2,4]
        Output: [2,3]
        
    Example 2:

        Input: nums = [1,1]
        Output: [1,2]
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    unordered_set<int> seen;
    int duplicate = -1;

    long long currSum = 0;

    for (int num : nums) {
        if (seen.count(num)){
            duplicate = num;
        }
        seen.insert(num);
        currSum += num;
    }

    int n = nums.size();
    long long expected_sum = (long long)n * (n+1)/2;
    int missing = static_cast<int> (expected_sum - (currSum - duplicate));

    return {duplicate, missing};
}

int main() {
    vector<int> nums = {2,2};
    vector<int> ans = findErrorNums(nums);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}