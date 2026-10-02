
#include <iostream>

#include "travel_tree.h"

int main() {
    TravelTree tree;
    tree.insert_data(10);
    tree.insert_data(20);
    tree.insert_data(30);
    tree.insert_data(40);
    tree.insert_data(50);
    tree.insert_data(60);
    tree.insert_data(70);
    tree.insert_data(80);
    
    std::cout << "Preorder Traversal : ";
    tree.postorder();

    std::cout << "\n";
    std::cout << "Postorder Traversal : ";
    tree.postorder();

    std::cout << "\n";
    std::cout << "Inorder Traversal : ";
    tree.inorder();


    std::cout << "\n";
    tree.display();
    return 0;
}