#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> pairSum(vector<int> &nums, int target) {
    int start = 0, end = nums.size()-1;

    while (start < end) {
        if (nums[start] + nums[end] == target) {
            nums.push_back(start);
            nums.push_back(end);
            return nums;
        } else if (nums[start]+nums[end] > target) {
            end--;
        } else {
            start++;
        }
    }
    return nums;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int start = 0, end = numbers.size()-1;
    
    while (start < end) {
        long long currSum = (long long)numbers[start]+numbers[end];

        if (currSum == target) {
            return {start+1, end+1};
        } else if (currSum > target) {
            end--;
        } else {
            start++;
        }
    }
    return {};
}

// this is for unsorted array 
vector<int> twoSum1(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; nums.size(); ++i) {
        int compliment = target - nums[i];

        if (numMap.count(compliment)) {
            return {numMap[compliment], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> vec = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum1(vec, target);

    cout << ans[0] << "," << ans[1] << endl;
    return 0;
}