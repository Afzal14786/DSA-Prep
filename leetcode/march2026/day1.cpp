// Question Link : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {

        int ans = 0;
        for (char c : n) {
            ans = max(ans, c - '0');
        }

        return ans;
    }
};
