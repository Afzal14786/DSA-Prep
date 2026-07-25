// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-product-of-two-digits/description/?envType=daily-question&envId=2026-07-25

class Solution {
public:
    int maxProduct(int n) {
        int first_max = 0, second_max = 0;
        while (n > 0) {
            int lastDigit = n % 10;
            if (lastDigit >= first_max) {
                second_max = first_max;
                first_max = lastDigit;
            } else if (lastDigit > second_max) {
                second_max = lastDigit;
            }

            n /= 10;
        }

        return first_max * second_max;
    }
};
