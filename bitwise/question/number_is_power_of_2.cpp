// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

bool number_is_power_of_2(int N) {
    return ((N & N-1) == 0);
}

int main() {
    cout << number_is_power_of_2(16) << '\n';
    return 0;
}