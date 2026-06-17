// Question Link : https://leetcode.com/problems/process-string-with-special-operations-ii/description/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (auto ch : s) {
            if (islower(ch)) len++;
            else if (ch == '*' && len > 0) len--;
            else if (ch == '#') len *= 2;
        }

        if (k >= len) return '.';

        for (int i = s.size()-1; i >=0; --i) {
            char ch = s[i];

            if (islower(ch)) {
                if (k == len - 1) return ch;
                len--;
            }
            else if (ch == '*') len++;
            else if (ch == '#') {
                len /= 2;
                if (k >= len) k -= len;
            } else if (ch == '%') {
                k = len - 1 - k;
            }
        }
        return '.';
    }
};

int main() {
    string str = "qud#y";
    int k = 6;

    Solution s;
    cout << "Character is : " << s.processStr(str, k) << endl;
    return 0;
}