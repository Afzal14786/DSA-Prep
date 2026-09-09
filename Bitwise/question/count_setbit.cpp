// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

int count_setbit(int n) {
    int count = 0;
    while (n > 1) {
        // checking for odd
        count += n & 1;
        n >>= 1;
    }

    return (n == 1) ? count + 1 : count;
}

int main() {
    
    return 0;
}