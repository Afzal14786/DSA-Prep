// Question Link : https://leetcode.com/problems/add-binary/?envType=daily-question&envId=2026-02-15

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < max(a.length(), b.length()); i++) {
            int digitA = i < a.length() ? a[i] - '0' : 0;
            int digitB = i < b.length() ? b[i] - '0' : 0;

            int total = digitA + digitB + carry;
            char c = (total % 2) + '0';
            res += c;
            carry = total / 2;
        }

        if (carry) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
