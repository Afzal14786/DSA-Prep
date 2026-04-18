// Question Link : https://leetcode.com/problems/mirror-distance-of-an-integer/description/?envType=daily-question&envId=2026-04-18

#include <iostream>

class Solution {
public:
    int getReverse(int n) {
        int rev = 0;
        while (n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }

        return rev;
    }

    int mirrorDistance(int n) {
        int reverse_num = getReverse(n);
        return abs(reverse_num - n);
    }
};