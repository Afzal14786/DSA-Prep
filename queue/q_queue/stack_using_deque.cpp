#include <iostream>
#include <deque>
using namespace std;

class Stack {
    deque<int> deq;

    public:
        void push(int data) {   // in stack we always push into the top means in deque it will be push_back()
            deq.push_back(data);
        }

        void pop() {    // in stack we can always pop from top so in deque it will be pop_back
            deq.pop_back();
        }

        int top() { // in stack we can use always top in deque it will become back()
            return deq.back();
        }

        bool isEmpty() {
            return deq.empty();
        }

        void display() {
            while (!deq.empty()) {
                cout << top() << " ";
                pop();
            }
            cout << endl;
        }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();   // deleting from stack
    cout << "Top Element Of The Stack Is : " << st.top() << endl;
    cout << "Stack Using Deque : ";
    st.display();

    return 0;
}