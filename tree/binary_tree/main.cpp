#include <iostream>
using namespace std;

#include "./binarytree.h"

int main() {
    btree<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);

    tree.inorder();
    tree.preOrder();
    tree.postOrder();

    return 0;
}
