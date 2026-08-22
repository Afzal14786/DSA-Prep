// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/?envType=daily-question&envId=2026-08-22

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        for (int x = n; x > 0; x /= 10) {
            const int rem = x % 10;
            sum += rem;
            product *= rem;
        }

        return n % (sum + product) == 0;
    }
};

class Solution {
public:

    pair<int, int> sum_product(int n) {
        int sum = 0, product = 1;

        for (int i = n; i > 0; i /= 10) {
            const int rem = i % 10;
            sum += rem;
            product *= rem;
        }

        return {sum, product};
    }

    bool checkDivisibility(int n) {
        int orignal_n = n;
        auto response = sum_product(n);

        int ans = response.first + response.second;
        return (orignal_n % (ans)) == 0;
    }
};