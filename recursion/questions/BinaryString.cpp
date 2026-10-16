#include <iostream>
#include <string>
using namespace std;

void BinaryString(int n, const int lastDIgit = 0, const string ans = "") {
    
    if (n == 0 || n < 0) {
        (n==0) ? cout << ans << endl : cout << "There is  no binary string for given n = " << n << endl;
        return;
    }

    if (lastDIgit != 1) {
        BinaryString(n-1, 0, ans+'0');
        BinaryString(n-1, 1, ans+'1');
    } else {
        BinaryString(n-1, 0, ans+'0');
    }
}

void BinaryString2(int n, const string ans = "") {
    if (n == 0 || n < 0) {
        (n==0) ? cout << ans << endl : cout << "There is  no binary string for given n = " << n << endl;
        return;
    }

    if (ans.size()-1 != 1) {
        BinaryString(n-1, 0, ans+'0');
        BinaryString(n-1, 1, ans+'1');
    } else {
        BinaryString(n-1, 0, ans+'0');
    }
}

int main() {
    cout << "Binary String Are : \n";
    BinaryString2(2);
    return 0;
}