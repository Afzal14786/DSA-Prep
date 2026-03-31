// QUestion Link : https://leetcode.com/problems/lexicographically-smallest-generated-string/?envType=daily-question&envId=2026-03-31

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        vector<char> res(n + m - 1, '?');
        vector<bool> fix(n + m - 1, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (res[i + j] == '?' || res[i + j] == str2[j]) {
                        res[i + j] = str2[j];
                        fix[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '?') res[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {

                bool same = true;
                for (int j = 0; j < m; j++) {
                    if (res[i + j] != str2[j]) {
                        same = false;
                        break;
                    }
                }

                if (same) {
                    bool changed = false;

                    for (int j = m - 1; j >= 0 && !changed; j--) {
                        if (!fix[i + j]) {
                            for (char ch = 'a'; ch <= 'z'; ch++) {
                                if (ch != str2[j]) {
                                    res[i + j] = ch;
                                    changed = true;
                                    break;
                                }
                            }
                        }
                    }

                    if (!changed) return "";
                }
            }
        }

        return string(res.begin(), res.end());
    }
};
