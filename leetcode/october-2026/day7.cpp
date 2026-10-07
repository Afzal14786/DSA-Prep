// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/remove-invalid-parentheses/description/?envType=daily-question&envId=2026-10-07

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        forward(s, res, 0, 0);

        return res;
    }

private:
    void forward(string s, auto& res, int li, int lj) {
        int bal = 0;

        for (int i = li; i < s.length(); i++) {
            bal += (s[i] == '(') - (s[i] == ')');

            if (bal >= 0) continue;

            for (int j = lj; j <= i; j++)
                if (s[j] == ')' && (j == lj || s[j - 1] != ')'))
                    forward(s.substr(0, j) + s.substr(j + 1), res, i, j);

            return;
        }

        backward(s, res, s.length() - 1, s.length() - 1);
    }

    void backward(string s, auto& res, int ri, int rj) {
        int bal = 0;

        for (int i = ri; i >= 0; i--) {
            bal += (s[i] == ')') - (s[i] == '(');

            if (bal >= 0) continue;

            for (int j = rj; j >= i; j--)
                if (s[j] == '(' && (j == rj || s[j + 1] != '('))
                    backward(s.substr(0, j) + s.substr(j + 1), res, i - 1,
                             j - 1);

            return;
        }

        res.push_back(s);
    }
};

