#include <iostream>
using namespace std;

void TOH(int x, char Sourse, char Temp, char Destination) {
    static int totalCalls = 0;
    if (x > 0) {
        totalCalls++;
        TOH(x-1, Sourse, Destination, Temp);
        cout << "Move from " << Sourse << " to " << Destination << ".\n";
        TOH(x-1, Temp, Sourse, Destination);
    }
}

int main() {
    TOH(3, 'A', 'B', 'C');
    return 0;
}