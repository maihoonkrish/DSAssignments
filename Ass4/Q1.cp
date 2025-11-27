#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() { return (front == -1); }

    bool isFull() { return (rear == MAX - 1); }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is FULL\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = val;
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) cout << "Queue empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;

    while (true) {
        cout << "\n----- SIMPLE QUEUE MENU -----\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid\n";
        }
    }
}

