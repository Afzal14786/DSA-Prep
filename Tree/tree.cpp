#include <iostream>
using namespace std;

class Node {
    int data;
    Node *left_child;
    Node *right_child;
    friend class BinaryTree;
    public:
        Node(int data) {
            this->data = data;
            left_child = nullptr;
            right_child = nullptr;
        }
};

class BinaryTree {
    Node *root;

    Node *recursiveInsert(Node *currentNode, int data) {
        if (currentNode == nullptr) {
            return new Node(data);
        }

        if (data < currentNode->data) {
            currentNode->left_child = recursiveInsert(currentNode->left_child, data);
        } else {
            currentNode->right_child = recursiveInsert(currentNode->right_child, data);
        }

        return currentNode;
    }

    public:
        BinaryTree() {
            root = nullptr;
        }

        void insert(int data) {
            root = recursiveInsert(root, data);
        }

        void pre_order_traversal(Node *node) {
            if (node != nullptr) {
                cout << node->data << " ";
                pre_order_traversal(node->left_child);
                pre_order_traversal(node->right_child);
            }
        }

        void inorder_traversal(Node *node) {
            if (node != nullptr) {
                inorder_traversal(node->left_child);
                cout << node->data << " ";
                inorder_traversal(node->right_child);
            }
        }

        void post_order_traversal(Node *node) {
            if (node != nullptr) {
                post_order_traversal(node->left_child);
                post_order_traversal(node->right_child);
                cout << node->data << " ";
            }
        }

        void printTree_inorder() {
            inorder_traversal(root);
            cout << endl;
        }

        void printTree_preOrder() {
            pre_order_traversal(root);
            cout << endl;
        }

        void printTree_post_order() {
            post_order_traversal(root);
            cout << endl;
        }

        ~BinaryTree(){}
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);

    cout << "Pre Order Tree Traversal : ";
    tree.printTree_preOrder();

    cout << "Inorder Tree Traversal : ";
    tree.printTree_inorder();

    cout << "Post Order Tree Traversal : ";
    tree.printTree_post_order();
    return 0;
}