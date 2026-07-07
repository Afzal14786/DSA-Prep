// Question Link : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/?envType=daily-question&envId=2026-07-07

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // improved solution
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, place = 1;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                x = digit * place + x;
                place *= 10;
                sum += digit;
            }
            n /= 10;
        }

        return sum * x;
    }
};

class Solution {
public:
    // initial thought 
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        string temp = "";
        string temp1 = to_string(n);
        for (char ch : temp1) {
            if (ch != '0') {
                temp.push_back(ch);
            }
        }

        long long sum = 0;
        for (char ch : temp) {
            sum += ch - '0';
        }

        int digits = std::stoi(temp);
        return digits * sum;
    }
};
