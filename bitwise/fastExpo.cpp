#include <iostream>
using namespace std;

void fastExpo(int x, int n) {
    int ans = 1;

    while (n > 0) {
        int lastDigit = n & 1;
        if (lastDigit) {
            ans *= x;
        }
        x *= x;

        n = n >> 1;
    }

    cout << "Ans : " << ans << endl;
}

int main() {

    fastExpo(5, 3);
    return 0;
}