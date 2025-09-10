#include <iostream>
#include <vector>
using namespace std;

#include "./BST.h"


int main() {
    cout << "This is the BST (Binary Search Tree's Entry Point)" << endl;
    bst<int> bs;
    vector<int> keys = {50, 30, 70, 20, 40, 60, 80};
    
    for (int key : keys) {
        bs.insert(key);
    }

    cout << "Try to insert a duplicate value : " << endl;
    bs.insert(30);

    bs.preorder();
    bs.inorder();
    bs.postorder();
    bs.levelorder();

    cout << "\n\nNumber of nodes present in the tree : " << bs.count() << endl;
    cout << "Current height off of the tree is : " << bs.height() << endl;
    cout << "Sum of all the keys = " << bs.sum() << endl;
    bool res = bs.search(20);

    cout << "Searching key is = " << (res ? "Oh Yes, Found" : "No, Not Found")  << endl;
    
    return 0;
}