// Question Link : https://leetcode.com/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') ans.push_back(ch);
            if (ch == '*') {
                if (ans.empty()) continue;
                ans.pop_back();
            }
            if (ch == '#') {
                if (ans.empty()) continue;
                ans.append(ans);
            }
            if (ch == '%') {
                if (ans.empty()) continue;
                reverse(ans.begin(), ans.end());
            }
        }

        return ans;
    }
};

int main() {
    string str = "*%";
    Solution s;
    cout << "Output string is : " << s.processStr(str) << endl;
}

