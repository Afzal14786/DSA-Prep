// Question Link : https://leetcode.com/problems/complement-of-base-10-integer/?envType=daily-question&envId=2026-03-11

#include <iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int bits = log2(n) + 1;
        int mask = (1<<bits) - 1;
        return n ^ mask;
    }
};
