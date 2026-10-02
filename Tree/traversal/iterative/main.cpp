// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * Tree Traversal Using Iterative Approach
 */

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left  = nullptr;
        this->right = nullptr;
    }
};

class Tree {
public:
    Tree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insert_recursive(root, data);
    }

    void preorder() {
        cout << "Iterative Preorder Traversal : \n";
        iterative_preorder(root);
        cout << "\n ------ Preorder Traversal Ends --------\n";
    }

    void inorder() {
        cout << "Inorder Traversal : \n";
        iterative_inorder(root);
        cout << "\n ----- Inorder Traversal Ends -----\n";
    }

    void level_order() {
        cout << "Level Order Traversal : \n";
        iterative_levelorder(root);
        cout << "\n ----- Level Order Traversal Ends -----\n";
    }

    void postorder() {
        cout << "Postorder Traversal : \n";
        iterative_postorder(root);
        cout << "\n ----- Postorder Traversal Ends -----\n";
    }

private:
    Node *root;
    Node *insert_recursive(Node *curr_node, int data) {
        if (curr_node == nullptr) {
            // meaning enter a new node 
            return new Node(data);
        }

        if (data < curr_node->data) {
            curr_node->left = insert_recursive(curr_node->left, data);
        } else {
            curr_node->right = insert_recursive(curr_node->right, data);
        }

        return curr_node;
    }
    
    void iterative_preorder(Node *curr) {
        /**
         * As we know the recursive steps is
         *      1. Visit the node
         *      2. Go to the left child
         *      3. Go to the right child
         * 
         * Similary in iterative approach it would be doing but we are maintaining a stack where stack is going to hold the node
         * the approahc is 
         *      1. Visit the node
         *      2. Push the current node into the stack and go left
         *      3. if left node is null then pop the top node from stack, and move right
         * 
         * repeate this until current node become null or stack is empty
         */
        stack<Node*> st;
        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                cout << curr->data << " ";
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
    }

    void iterative_inorder(Node *curr_node) {
        stack<Node*> st;

        while (curr_node != nullptr || !st.empty()) {
            if (curr_node) {
                st.push(curr_node);
                curr_node = curr_node->left;
            } else {
                curr_node = st.top();
                cout << curr_node->data << " ";
                st.pop();
                curr_node = curr_node->right;
            }
        }
    }

    // using one stack
    void iterative_postorder(Node *curr_node) {
        stack<Node*> st;
        while (curr_node || !st.empty()) {
            // we know go left and left first untill u hit the null
            if (curr_node) {
                st.push(curr_node);
                curr_node = curr_node->left;
            } else {
                Node *temp = st.top()->right;
                if (temp == nullptr) { // means top node's does not having any right child
                    // if the top node's right child is null means this is the leaf node having 0 childrens
                    temp = st.top();
                    st.pop();  // since there is no children so popped it out from stack 
                    cout << temp->data << " ";  // printing the value
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        cout << temp->data << " ";
                    }
                } else {
                    // means this is having a right child
                    curr_node = temp;
                }
            }
        }
    }

    void iterative_levelorder(Node *root) {
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node *temp = q.front();
            q.pop();
            // printing the data
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
};

int main() {
    Tree tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(5);
    tree.insert(4);
    tree.insert(9);
    tree.insert(7);
    tree.insert(6);

    tree.preorder();
    tree.inorder();
    tree.level_order();
    tree.postorder();
    return 0;
}