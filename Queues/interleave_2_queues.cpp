#include <iostream>
#include <queue>
using namespace std;

/**
 * @brief We have a queue and we have to interleave 2 halves of a queue of size even
 * @example Orignal Queue = 1 2 3 4 5 6 7 8 9 10
 * o/p : [1 6 2 7 3 8 4 9 5 10]
 */

void interleave_2_queue(queue<int> &Queue) {
    int queue_size = Queue.size();
    // take 2 extra queue
    queue<int> first;
    queue<int> answer;

    // run q loop in the Parameter queue till queue_size/2

    while (Queue.size() != queue_size/2) {
        first.push(Queue.front());
        Queue.pop();
    }

    // now again run a loop in both in the first and Parameter Queue from start till null and add the element in the answer queue
    while (!first.empty() && !Queue.empty()) {
        answer.push(first.front());
        first.pop();
        answer.push(Queue.front());
        Queue.pop();
    }


    //now print the answer
    while (!answer.empty()) {
        cout << answer.front() << " ";
        answer.pop();
    }

    cout << endl;
}


/**
 * Approach 2 : Using One Single Extra Queue
 * 
 */

void Approach2(queue<int> &orignalQue) {
    queue<int> first;
    int queue_size = orignalQue.size();

    while (orignalQue.size() != queue_size/2) {
        first.push(orignalQue.front());
        orignalQue.pop();
    }

    while (!first.empty()) {
        orignalQue.push(first.front());
        first.pop();

        orignalQue.push(orignalQue.front());
        orignalQue.pop();
    }

    // print 
    cout << "The Interleave Queue is : ";
    while (!orignalQue.empty()) {
        cout << orignalQue.front() << " ";
        orignalQue.pop();
    }
    cout << endl;
}

int main() {
    queue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);
    Queue.push(6);
    Queue.push(7);
    Queue.push(8);
    Queue.push(9);
    Queue.push(10);

    Approach2(Queue);

    return 0;
}