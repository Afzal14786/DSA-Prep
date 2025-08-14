#include <iostream>
using namespace std;

#include "./LinkedList.h"

/**
 * run following command for executing the program : 
 * g++ -. main.cpp -o program && ./program
 */

int main() {
    List<int> list;

    /***
     * @brief Adding Some Data Form A LinkedList
     */

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.push_back(100);
    list.push_back(60);
    list.push_front(1);
    list.insert(200, 5);

    cout << "List Before Cycle : ";
    list.DisplayList();

    // let make the list cycle 
    list.makeCycle();

    // now check cycle exist or not first
    // list.isCycle(); // now cycle exist

    // now remove the cycle 
    list.removeCycle();
    return 0;
}
