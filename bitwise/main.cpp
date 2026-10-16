// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include <bitset>
using namespace std;


int main() {
    int a = 5;
    cout << bitset<32>(a) << endl;
    cout << bitset<32>(~a) << endl;

    // check if the bit is on or off
    int x;
    cin >> x;
    //left shift
    if (a & (1 << x)) {
        cout << "ON\n";
    } else {
        cout << "OFF\n";
    }

    // another way 
    // right shift
    if ((a >> x) & 1) cout << "ON\n";
    else cout << "OFF\n";

    // check given x even or off
    if (x & 1) cout << "ODD\n";
    else cout << "EVEN\n";

    return 0;
}
