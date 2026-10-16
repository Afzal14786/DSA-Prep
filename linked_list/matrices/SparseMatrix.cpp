#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int column;
        int data;
        Node *next;

        Node(int column, int data) {
            this->column = column;
            this->data = data;
            this->next = nullptr;
        }
};


// now let create a sparse matrix
// as input it will take an 2D array or vector
vector<Node*> createSparseMatrix(const vector<vector<int>> &matrix) {
    // now check the size of the matrix 
    // row size and column
    int row = matrix.size();
    // check if the row == 0 means the 2D array is empty
    if (row == 0) {
        return {};
    }

    int cols = matrix[0].size();

    // now we have to create an array of Nodes
    vector<Node*> sparse(row, nullptr);

    for (int i = 0; i < row; ++i) {
        Node *lastNode = nullptr;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                Node *newNode = new Node(j, matrix[i][j]);

                if (sparse[i] == nullptr) {
                    sparse[i] = newNode;
                    lastNode = newNode;
                } else {
                    lastNode->next = newNode;
                    lastNode = newNode;
                }
            }
        }
    }

    return sparse;
}

// now displaying a matrix
void printMatrix(const vector<Node*> &sparseMatrix) {
    int row = sparseMatrix.size();
    cout << "Sparse Matrix Representation : \n";
    for (int i = 0; i < row; ++i) {
        cout << "Row: " << i << ": ";
        Node *temp = sparseMatrix[i];
        if (temp == nullptr) {
            cout << "-> empty";
        }
        while (temp != nullptr) {
            cout << "[Col: " << temp->column << ", Val: " << temp->data << " ]";
            if (temp->next != nullptr) {
                cout << " -> ";
            } else {
                cout << " -> empty";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    
}


int main() {
    vector<vector<int>> matrix = {
        {0,0,0,0,7,0,0},
        {0,4,0,1,0,0,0},
        {0,0,5,0,0,0,9},
        {0,1,0,0,3,0,0},
        {1,0,0,0,0,0,0},
        {0,2,0,8,0,9,0},
    };

    vector<Node*> spMatrix = createSparseMatrix(matrix);
    printMatrix(spMatrix);

    // avoid memory lead
    for (Node *node : spMatrix) {
        Node *temp = node;
        while (temp != nullptr) {
            Node *toDeleted = temp;
            temp = temp->next;
            delete toDeleted;
        }
    }
    return 0;
} 