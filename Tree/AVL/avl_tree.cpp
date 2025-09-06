#include <iostream>
#include <vector>
using namespace std;

class Node {
    Node *left;
    Node *right;
    int data;
    int height; // this will calculate the height of node
    friend class AVL;

public:
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1; // start from 0
    }

    ~Node() {
        // de-allocating
    }
};

class AVL {
    Node *root;

    int getHeight(Node *node) {
        return node ? node->height : 0;
    }

    int Height(Node *curr) {
        return 1 + max(getHeight(curr->left), getHeight(curr->right));
    }

    int Balance_Factor(Node *curr) {
        int hl = curr && curr->left ? curr->left->height : 0;
        int hr = curr && curr->right ? curr->right->height : 0;

        return hl - hr;
    }

    Node *recursiveInsert(Node *current, int key) {
        // check if the currect is null or not
        if (current == nullptr) {
            return new Node(key);
        }

        // check the left and right data of current
        if (key < current->data) {
            current->left = recursiveInsert(current->left, key);
        }
        else {
            current->right = recursiveInsert(current->right, key);
        }

        // now let calculate the height of the node after insertion
        current->height = Height(current);
        // now check the balance factor and perform the rotations
        // get the balance factor
        int balance_factor = Balance_Factor(current);

        if (balance_factor > 1) {
            if (Balance_Factor(current->left) >= 0) {
                return LL_Rotation(current);
            } else {
                return LR_Rotation(current);
            }
        } else if (balance_factor < -1) {
            if (Balance_Factor(current->right) <= 0) {
                return RR_Rotation(current);
            } else {
                return RL_Rotation(current);
            }
        }
        
        return current;
    }

    Node *LL_Rotation(Node *current) {
        Node *PL = current->left;
        Node *PLR = PL->right;

        PL->right = current;
        current->left = PLR;

        current->height = Height(current);
        PL->height = Height(PL);

        return PL;
    }

    Node *LR_Rotation(Node *current) {
        Node *PL = current->left;
        Node *PLR = PL->right;

        PL->right = PLR->left;
        current->left = PLR->right;

        PLR->right = current;
        PLR->left = PL;

        current->height = Height(current);
        PL->height = Height(PL);
        PLR->height = Height(PLR);

        return PLR;
    }

    Node *RR_Rotation(Node *current) {
        Node *PR = current->right;
        Node *PRL = PR->left;

        PR->left = current;
        current->right = PRL;

        current->height = Height(current);
        PR->height = Height(PR);

        return PR;
    }

    Node *RL_Rotation(Node *current) {
        Node *PR = current->right;
        Node *PLR = PR->left;

        PR->left = PLR->right;
        current->right = PLR->left;

        PLR->right = PR;
        PLR->left = current;

        current->height = Height(current);
        PR->height = Height(PR);
        PLR->height = Height(PLR);

        return PLR;
    }

    void PRE_ORDER_TRAVERSAL(Node *current) {
        if (current == nullptr) {
            return; // do nothing, just eat 5 star 😂
        }
        // visit -> left -> right
        cout << current->data << " ";
        PRE_ORDER_TRAVERSAL(current->left);
        PRE_ORDER_TRAVERSAL(current->right);
    }

    void INORDER_TRAVERSAL(Node *current) {
        if (current == nullptr) {
            return; // do nothing, just eat 5 star 😂
        }

        // left - visit - right
        INORDER_TRAVERSAL(current->left);
        cout << current->data << " ";
        INORDER_TRAVERSAL(current->right);
    }

    void POST_ORDER_TRAVERSAL(Node *current) {
        if (current == nullptr) {
            return; // do nothing, just eat 5 star 😂
        }

        POST_ORDER_TRAVERSAL(current->left);
        POST_ORDER_TRAVERSAL(current->right);
        cout << current->data << " ";
    }

public:
    AVL() {
        root = nullptr;
    }

    void insert(int key) {
        root = recursiveInsert(root, key);
    }

    void pre_order_traversal() {
        cout << "Pre Order Traversal : ";
        PRE_ORDER_TRAVERSAL(root);
        cout << endl;
    }

    void inorder_traversal() {
        cout << "Inorder Traversal : ";
        INORDER_TRAVERSAL(root);
        cout << endl;
    }

    void post_order_traversal() {
        cout << "Post Order Traversal : ";
        POST_ORDER_TRAVERSAL(root);
        cout << endl;
    }
};

int main() {
    AVL avl;
    vector<int> keys = {10, 20, 30, 40, 50};
    for (int i = 0; i < keys.size(); ++i) {
        avl.insert(keys[i]);
    }
    
    // now let perform the traversal
    avl.pre_order_traversal();
    avl.post_order_traversal();
    avl.inorder_traversal();
    return 0;
}