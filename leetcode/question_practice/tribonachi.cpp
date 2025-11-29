#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int n) {
    vector<int> dp(n+1, -1);
    int a = 0, b = 1, c = 1;

    if (n == 0) return 0;

    for (int i = 3; i <= n; ++i) {
        int curr = a + b + c;
        a = b;
        b = c;
        c = curr;
    }

    return c;
}

int main() {

    return 0;
}