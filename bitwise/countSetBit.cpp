#include <iostream>
using namespace std;

void countSetBit(int num) {
    int count = 0;
    while (num > 0) {
        int lastDigit = num & 1;
        count += lastDigit;
        num = num >> 1;
    }

    cout << "No Of Set Bits : " << count << endl;
}

int main() {
    countSetBit(10);
    return 0;
}