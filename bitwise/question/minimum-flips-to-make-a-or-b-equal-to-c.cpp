// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// approach one
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a != 0 || b != 0 || c != 0) {
            if ((c & 1) == 1) {
                // get the right most bit
                if ((a & 1) == 0 && (b & 1) == 0) flips++;
            } else {
                if ((a & 1) == 1) flips++;
                if ((b & 1) == 1) flips++;

                // flips += ((a & 1) == 1) + ((b & 1) == 1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};

// another approach 

int count_setbit(int n) {
    int count = 0;
    while (n != 0) {
        n = n & (n-1);
        count++;
    }

    return count;
}

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = ((a | b) ^ c);
        return __builtin_popcount(res) + __builtin_popcount((a & b) & res);
    }
};