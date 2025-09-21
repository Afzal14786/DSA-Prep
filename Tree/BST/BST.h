#ifndef BST
#define BST

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "./Node.h"

template <typename T>
class bst {
    Node<T> *root;
    // all the other supportive funceris, like 
    /**
     * All the function that help a public functions to work, reside here
     * 
     * e.g :    
     * 
     *      All Tree Traversal Using Recursive Approach And Iterative Appraoch
     *      Recursive Insert 
     *      Delete the tree
     */

    void deleteTree(Node<T> *node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    Node<T> * recursiveInsert(Node<T> *current, T key) {
        if (current == nullptr) {
            return new Node<T>(key);
        }

        // this check will prevent to insert duplicate values
        if (key == current->key) {
            return current;
        }

        if (key < current->key) {
            current->left = recursiveInsert(current->left, key);
        } else {
            current->right = recursiveInsert(current->right, key);
        }

        return current;
    }

    void inorder_traversal(Node<T> *current) {
        if (current != nullptr) {
            inorder_traversal(current->left);
            std::cout << current->key << " ";
            inorder_traversal(current->right);
        }
    }

    void preorder_traversal(Node<T> *current) {
        if (current != nullptr) {
            std::cout << current->key << " ";
            preorder_traversal(current->left);
            preorder_traversal(current->right);
        }
    }

    void postorder_traversal(Node<T> *current) {
        if (current != nullptr) {
            postorder_traversal(current->left);
            postorder_traversal(current->right);
            std::cout << current->key << " ";
        }
    }

    /**
     * using iterative appraoch we are solving this 
     */
    void levelorder_traversal(Node<T> *current) {
        
        if (current == nullptr) {
            std::cout << "there is no element in the tree.\n";
            return;
        }

        std::queue<Node<T> *> que;
        que.push(current);

        while (!que.empty()) {
            Node<T> *temp = que.front();
            que.pop();

            std::cout << temp->key << " ";

            if (temp->left) {
                que.push(temp->left);
            }

            if (temp->right) {
                que.push(temp->right);
            }
        }

    }

    int count_helper(Node<T> *current);
    int height_helper(Node<T> *current);
    int sum_helper(Node<T> *current);
    bool search_helper(Node<T> *current, T key);
    Node<T>* delete_helper(Node<T> *root, T key);
    Node<T>* inorder_successor(Node<T>* node);
    std::vector<T> printInRange_helper(Node<T> *root, int start, int end);

    public:
        bst() {
            root = nullptr;
        }

        /**
         * All the helper functions, reside here
         *      
         *      TREE TRAVERSALS
         * 1. Inorder
         * 2. Preorder
         * 3. Post Order
         * 4. Level Order
         * 
         */

        void inorder() {
            std::cout << "Inorder Tree Traversal : ";
            inorder_traversal(root);
            std::cout << std::endl;
        }

        void preorder() {
            std::cout << "Preorder Tree Traversal : ";
            preorder_traversal(root);
            std::cout << std::endl;
        }

        void postorder() {
            std::cout << "Postorder Tree Traversal : ";
            postorder_traversal(root);
            std::cout << std::endl;
        }

        void levelorder() {
            std::cout << "Levelorder Tree Traversal : ";
            levelorder_traversal(root);
            std::cout << std::endl;
        }

        /**
         * all the public working functions, reside here
         * 
         * 1. Insert
         * 2. Search
         * 3. Delete
         * 4. Height
         * 5. Count
         * 6. Sum
         * 7. Duplicate
         */

        void insert(T key) {
            root = recursiveInsert(root, key);
        }

        bool search(T value);
        T delete_key(T key);
        int height();
        int count();
        int sum();
        void printInRange(int start, int end);

        ~bst() {
            // removing the space occupied
            deleteTree(root);
        }
};

#include "operations/search.cpp"
#include "operations/height.cpp"
#include "operations/delete_key.cpp"
#include "operations/sum.cpp"
#include "operations/count.cpp"
#include "operations/printInRange.cpp"

#endif
