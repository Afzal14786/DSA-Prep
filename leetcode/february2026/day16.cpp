// Question Link : https://leetcode.com/problems/reverse-bits/description/?envType=daily-question&envId=2026-02-16

#include <iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int rev = 0;
        for (int i = 0; i < 32; ++i) {
            rev = (rev << 1) | ((n >> i) & 1);
        }
        return rev;
    }
};
