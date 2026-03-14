// Question Link : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2026-03-14

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int sz = pow(2, n - 1);
        if (3 * sz < k) return "";

        string res = "";
        if (k <= sz){ res += 'a'; }
        else if (k <= 2*sz){ res += 'b'; k -= sz; }
        else { res += 'c'; k -= 2*sz; }

        string opts[] = {"bc", "ac", "ab"};
        for (int i = 1; i < n; i++) {
            sz /= 2;
            string& ch = opts[res.back() - 'a'];
            if (k <= sz) res += ch[0];
            else { res += ch[1]; k -= sz; }
        }
        return res;
    }
};
