#include <iostream>
#include <vector>
using namespace std;

int fiboNachi(int num) {
    if (num == 0 || num == 1) {
        return num;
    }

    return fiboNachi(num - 2) + fiboNachi(num - 1);
}

// Fibonacci Series Using A Global Array Known As  "Memoization".


int impRoveFibo (int num) {

    int globalArray[num+1];
    for (int i = 0; i < num+1; ++i) {
        globalArray[i] = -1;
    }

    if (num <= 1) {
        globalArray[num] = num;
        return num;
    } else {
        if (globalArray[num - 2] == -1) {
            globalArray[num - 2] = impRoveFibo(num - 2);
        }

        if (globalArray[num - 1] == -1) {
            globalArray[num - 1] = impRoveFibo(num - 1);
        }

        return globalArray[num - 2] + globalArray[num - 1];
    }
}

int main() {
    cout << fiboNachi(5) << endl;   // 5
    cout << impRoveFibo(5) << endl;
    return 0;
}