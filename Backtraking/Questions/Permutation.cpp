#include <iostream>
#include <string>

using namespace std;

// time complexity = O(n!)
// space complexity : O(n)
void Permutation(string str, string ans) {
    int n = str.size();
    if (n == 0) {
        cout << ans << endl;
        return;
    } else {
        for (int i = 0; i < n; ++i) {
            char ch = str[i];
            string nextStr = str.substr(0,i) + str.substr(i+1, n-i-1);
            Permutation(nextStr, ans + ch);
        }
    }
}

int main() {
    string str = "abc";
    string ans = "";

    Permutation(str, ans);
    return 0;
}