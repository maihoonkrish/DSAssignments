#include <iostream>
using namespace std;

#define MAX 10

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (rear + 1) % MAX == front; }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Circular Queue FULL\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = val;
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue EMPTY\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";

        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void peek() {
        if (isEmpty()) cout << "Empty queue\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    while (true) {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1 Enqueue\n2 Dequeue\n3 Peek\n4 Display\n5 Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: return 0;
        }
    }
}
