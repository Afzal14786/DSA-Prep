#include <iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *queue;

public:
    Queue(int size)
    {
        this->size = size;
        queue = new int[this->size];
        front = rear = 0;
    }

    ~Queue()
    {
        delete[] queue;
    }

    void enQueue(int data)
    {
        // Condition for a full queue
        if ((rear + 1) % size == front)
        {
            cout << "Queue is Full.\n";
            return;
        }
        else
        {
            rear = (rear + 1) % size;
            queue[rear] = data;
        }
    }

    int deQueue()
    {
        int ans = -1;
        if (front == rear)
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            front = (front + 1) % size;
            ans = queue[front];
        }
        return ans;
    }

    void display()
    {
        if (front == rear)
        {
            cout << "Queue is empty.\n";
            return;
        }

        int i = (front + 1) % size;

        while (i != (rear + 1) % size)
        {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1(6);
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    q1.enQueue(50);
    
    q1.display();
    
    cout << q1.deQueue() << endl;
    q1.enQueue(60);

    q1.display();
    return 0;
}