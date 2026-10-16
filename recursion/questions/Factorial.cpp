#include <iostream>
using namespace std;

int fact(int n) {
    if (n == 1) {
        return n;
    } else {
        return n * fact(n-1);
    }
}


// printing number from n to 1

void printReverse(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    printReverse(n-1);
}

// first N, sum

int SumN(int n) {
    if (n == 0) {
        return 0;
    }

    return SumN(n-1) + n;
}

int main() {
    cout << "Factorial Is : " << fact(5) << endl;
    // printReverse(5);
    cout << "Sum Of N Natural Number Is : " << SumN(5) << endl;
    return 0;
}