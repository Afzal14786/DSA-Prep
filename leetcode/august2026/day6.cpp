
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-divisible-digit-product-i/?envType=daily-question&envId=2026-08-06

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int product = 1;
            int cpy = n;
            while (cpy) {
                int last_digit = cpy % 10;
                product = product * last_digit;
                cpy = cpy / 10;
            }

            if (product % t == 0) return n;
            n++;
        }

        return 1;
    }
};

int main() {
    
    return 0;
}