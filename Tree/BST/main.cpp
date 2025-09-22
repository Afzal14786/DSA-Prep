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

    // cout << "----------------------- Performing Deletion On BST -----------------------\n";
    // cout << "Enter a key that you want to delete : ";
    // int key;
    // cin >> key;
    // cout << "The new head element = " << bs.delete_key(key) << " after deletion.\n";

    // cout << "The tree after deleting the key " << key << endl;
    // bs.inorder();

    // cout << "------------------------- Performing In Range Function -------------------------\n";
    // int start, end;
    // cout << "Enter the value of start & end : ";
    // cin >> start >> end;
    // bs.printInRange(start, end);

    cout << "------------------------------ Performing All Paths Function ------------------------------\n";
    bs.printAllPaths();

    cout << "\n---------------- Check Kr Rahe Hai Valid BST hai ya nahi ----------------\n";
    if (bs.validate_bst() == 1) {
        cout << "Ha bhai haa, BST valid hai! Congratulation.\n";
    } else {
        cout << "Nahi bhai, BST valid nhi hai, uffs!\n";
    }
    
    return 0;
}