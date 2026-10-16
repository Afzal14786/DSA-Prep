#include <iostream>
using namespace std;


// #include "LinkedList/SinglyLinkedList/Question/LinkedList.h"
#include "LinkedList.h"

/**
 * @brief For compiling this file run followinf command
 * run the command form /DSA/Stack
 * g++ -I.. -I../LinkedList/SinglyLinkedList/Question Stack__LL.cpp -o program && ./program
 */

int main() {
    List<int> stack;

    stack.push_front(10);
    stack.push_front(20);
    stack.push_front(30);
    stack.push_front(40);
    stack.push_front(50);

    stack.DisplayList();

    cout << "Top Value : " << stack.front() << endl;
    cout << "Popped value : " << stack.pop_front() << endl;
    return 0;
}