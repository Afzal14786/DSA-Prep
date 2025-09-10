#ifndef NODE_BST
#define NODE_BST

/**
 * This a NODE class for BST (Binary Search Tree)
 */

template <typename T>
class Node {
    public:
        Node<T> *left;
        Node<T> *right;
        int height;
        T key;

        Node(T key) {
            this->key = key;
            left = nullptr;
            right = nullptr;
            height = 0;
        }

        ~Node() {
            delete left;
            delete right;
        }
};

#endif