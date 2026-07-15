// Question Link : https://leetcode.com/problems/gcd-of-odd-and-even-sums/?envType=daily-question&envId=2026-07-15

// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        for (int i = 1; i <= n; ++i) {
            sumOdd += (2 * i) - 1;
            sumEven += (2 * i);
        }

        return gcd(sumOdd, sumEven);
    }
};

int main() {
    Solution s;
    cout << s.gcdOfOddEvenSums(4) << endl;
    return 0;
}