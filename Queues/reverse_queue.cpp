#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse_queue(queue<int> &Queue) {
    stack<int> st;

    while (!Queue.empty()) {
        st.push(Queue.front());
        Queue.pop();
    }

    while (!st.empty()) {
        Queue.push(st.top());
        st.pop();
    }

    // now print the queue 
    cout << "Reverse Queue Is : ";
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }

    cout << endl;
}

int main() {
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);

    reverse_queue(Q);
    return 0;
}

