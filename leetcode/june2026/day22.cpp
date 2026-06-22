// Question Link : https://leetcode.com/problems/maximum-number-of-balloons/?envType=daily-question&envId=2026-06-22
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(5, 0);
        string s = "balon";
        for (char ch : text) {
            for (int i = 0; i < s.size(); ++i) {
                freq[i] += !(ch ^ s[i]);
            }
        }

        return min({freq[0], freq[1], freq[2] >> 1, freq[3] >> 1, freq[4]});
    }
};

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        for (char ch : text) {
            switch (ch) {
                case 'b': b++; break;
                case 'a': a++; break;
                case 'l': l++; break;
                case 'o': o++; break;
                case 'n': n++; break;
            }
        }

        return min({b, a, l/2, o/2, n});
    }
};
