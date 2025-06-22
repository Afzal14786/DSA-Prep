#include <iostream>
// #include <bitmask>
using namespace std;

// way 1
void evenOrOdd(int num) {
    if (!(num & 1)) {
        cout << "Even\n";
    } else {
        cout << "Odd\n";
    }
}

int getIthBit(int num, int pos) {
    int mask = (1 << pos);
    if (!(num & mask)) {
        return 0;       // means the ith bit is zero;
    } else {
        return 1;       // means the ith bit is one.
    }
}

int setIthBit (int num, int pos) {
    int mask = (1 << pos);
    return (num | mask);
}

int clearIthBit(int num, int pos) {
    int mask = ~(1 << pos);
    return (num & mask);
}

bool powerOf2(int num) {
    if (!(num & (num-1))) {
        return true;
    } else {
        return false;
    }
}

void updateIthBit(int num, int pos, int val) {
    int mask = ~(1 << pos);
    num = (num & mask);    // clear the ith bit first
    num = num | (val << pos);     // update the num with value 

    cout << num << endl;
}

// clear last i bit .
void clearLastIbit(int num, int pos) {
    int mask = ((~0) << pos);
    num = num & mask;
    cout << num << endl;
}
// count set bits

int countSetBits(int num) {
    int count = 0;

    while (num > 0) {
        int lastDigit = num & 1;
        count += lastDigit;

        num = num >> 1;         // right shift the num bit
    }

    return count;
}

int main() {
    int num = 9;
    // evenOrOdd(num);
    // cout << getIthBit(num, 2) << endl;
    // cout << setIthBit(9, 2) << endl;
    // cout << clearIthBit(6, 1) << endl;

    // cout << powerOf2(2) << endl;        // 1    true
    // cout << powerOf2(4) << endl;        // 1    true
    // cout << powerOf2(3) << endl;        // 0    false
    // cout << powerOf2(5) << endl;        // 0    false

    // updateIthBit(7,2,0);
    // clearLastIbit(15,2);

    cout << countSetBits(10) << endl;
    return 0;
}