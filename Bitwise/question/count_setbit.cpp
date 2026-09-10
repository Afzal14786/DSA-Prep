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

// another way of doing this 

int count_setbit_2(int n) {
    int count = 0;
    while (n != 0) {
        n = n & (n-1);
        count++;
    }

    return count;
}

int main() {
    int n = 84;
    cout << count_setbit_2(n) << '\n';
    cout << count_setbit(n) << '\n';
    return 0;
}