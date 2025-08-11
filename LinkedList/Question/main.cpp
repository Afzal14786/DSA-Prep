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
    list.insert(200, 5);

    cout << "List Before Merge : ";
    list.DisplayList();


    list.mergeSort();
    cout << "List After Merge : ";
    list.DisplayList();
    return 0;
}