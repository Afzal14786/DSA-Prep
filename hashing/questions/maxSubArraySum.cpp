#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max sum = " << maxSubArraySum(nums) << endl;
    return 0;
}