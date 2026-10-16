#include <iostream>
using namespace std;

#include "./DoublyLinkedListImplement.h"

int main() {
    cout << "\n------------Implement Insertion In DLL----------------------\n";
    Doubly_LL<int> D_list;
    D_list.push_front(10);
    D_list.push_front(20);
    D_list.push_front(30);
    D_list.push_front(40);
    D_list.push_back(50);   // work fine

    cout << "Older List : ";
    D_list.Display_D_LL();

    cout << "Size of the list is : " << D_list.DoublyListSize() << endl;

    D_list.insert(500, 4);
    cout << "List After inserting new element at given positon : ";
    D_list.Display_D_LL();
    cout << "Size of the list is : " << D_list.DoublyListSize() << endl;

    cout << "\n------------Implement Deletion In DLL----------------------\n\n";
    // D_list.pop_front();
    // D_list.pop_back();
    D_list.deleteDNode(0);
    D_list.front();
    D_list.back();
    return 0;
}