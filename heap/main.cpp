#include <iostream>
#include <vector>

using namespace std;

/**
 * Important functions
 * 
 *      1. push()       O(logn)
 *      2. pop()        O(logn)
 *      3. top()        O(1)
 */

class Heap {
    vector<int> cbt;
    void heapify(int i) {

        if (i > cbt.size()) {
            return;
        }

        int left = 2*i + 1;
        int right = 2*i + 2;
        int maxIdx = i;

        if (left < cbt.size() && cbt[left] > cbt[maxIdx]) {
            maxIdx = left;
        }

        if (right < cbt.size() && cbt[right] > cbt[maxIdx]) {
            maxIdx = right;
        }

        swap(cbt[i], cbt[maxIdx]);

        if (maxIdx != i) {
            heapify(maxIdx);
        }
    }
    
    public:

        void push(int val) {
            cbt.push_back(val);
            int x = cbt.size()-1;
            int parent = (x-1)/2;

            while (parent >= 0 && cbt[x] > cbt[parent]) {
                swap(cbt[x], cbt[parent]);
                x = parent;
                parent = (x-1)/2;
            }
        }

        void pop() {
            swap(cbt[0], cbt[cbt.size() - 1]);
            cbt.pop_back();

            // now fix the heap -> heapify
            heapify(0);

        }

        int top() {
            return cbt[0];
        }

        bool isEmpty() {
            return cbt.size() == 0;
        }

};

int main() {
    Heap h1;
    
    h1.push(9);
    h1.push(4);
    h1.push(8);
    h1.push(1);
    h1.push(2);
    h1.push(5);

    while (!h1.isEmpty()) {
        cout << "top = " << h1.top() << endl;
        h1.pop();
    }

    return 0;
}