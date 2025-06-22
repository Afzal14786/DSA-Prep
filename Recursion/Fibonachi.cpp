#include <iostream>
using namespace std;

int fiboNachi(int num) {
    if (num == 0 || num == 1) {
        return num;
    }

    return fiboNachi(num - 2) + fiboNachi(num - 1);
}

int globalArray[20] = {-1};

int impRoveFibo (int num) {

    if (num == 0 || num == 1) {
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
    return 0;
}