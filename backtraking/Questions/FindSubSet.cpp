#include <iostream>
#include <string.h>
using namespace std;



void Subset(string str, string ans) {
    int n = str.size();
    if (n == 0) {
        // print the subset
        cout << ans << endl;
        return;
    }

    char ch = str[0];
    // call for yes choise
    Subset(str.substr(1, n-1), ans+ch);

    // call for no
    Subset(str.substr(1, n-1), ans);

}

int main() {
    string ans = "";
    Subset("abc", ans);
    return 0;
}