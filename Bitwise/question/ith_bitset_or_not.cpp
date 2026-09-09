// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * Check if the ith bit set or not
 * @param N given the decimal number
 * @param i check the ith bit is set or not
 * @return {bool} trur if set otherwise false
 */

 // using left shift
bool is_bitset(int N, int i) {
    return ((N & (1 << i)) != 0);
}


// using right shift
bool is__bitset(int N, int i) {
    return (((N >> i) & 1) == 1);
}

int main() {
    int N = 13, i = 1;
    cout << is__bitset(N, i) << '\n'; // true -- 1
    cout << is_bitset(N, i) << '\n';  // true -- 1
    return 0;
}