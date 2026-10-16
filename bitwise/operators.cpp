#include <iostream>
using namespace std;

int main() {
    cout << "Bitwise AND (&) Operator : " << (3 & 5) << endl;
    cout << "Bitwise OR (|) Operator : " << (3 | 5) << endl;
    cout << "Bitwise XOR (^) Operator : " << (3 ^ 5) << endl;
    cout << "2's Complement (~) : " << ~4 << endl;

    // Left Shift Operator //
    // It is used to shift the given number's bit by given positions
    // 7 is the number and it is shifted by 2 position in left
    // Left shift formula = num * (2 ^ position);
    cout << "Left Shift Operator (<<) : " << (7 << 2) << endl;

    // Right Shift Operator
    // Just shift he guevn number's bit right side by given position
    // Formula => num / 2 ^ position
    cout << "Right Shift Operator (>>) : " << (7 >> 2) << endl;
    return 0;
}