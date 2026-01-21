/**
 * Construct The Minimum Bitwise Array II
 * Question Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/?envType=daily-question&envId=2026-01-21
 * Solution Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/submissions/1892016344/?envType=daily-question&envId=2026-01-21
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> arr;
        for(int i: nums) {

            if(i==2){
                arr.push_back(-1);
                continue;
            }
            int val =i;

            int ans =0;
            int d=0;
            while((val&(1<<d))!=0) {
                d++;
            }

            val -= (1<<(d-1));
            arr.push_back(val);
        }
        return arr;
    }
};