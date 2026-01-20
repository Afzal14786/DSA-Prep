/**
 * Construct The Minimum Bitwise Array I
 * Question Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/?envType=daily-question&envId=2026-01-20
 * Solution Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/submissions/1890837785/?envType=daily-question&envId=2026-01-20
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i: nums) {
            bool flag = false;
            for(int j=1;j<=i-1;j++){
                if((j|(j+1))==i){
                    ans.push_back(j);
                    flag = true;
                    break;
                }
            }

            if(!flag){
                ans.push_back(-1);
            }
        }

        return ans;
    }
};