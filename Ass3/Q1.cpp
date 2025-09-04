#include <iostream>
#define MAX_SIZE 10

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int data) {
        if (isFull()) {
            std::cout << "Stack is full. Push operation failed.\n";
            return;
        }
        arr[++top] = data;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Pop operation failed.\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Peek operation failed.\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, data;

    while (true) {
        std::cout << "\nStack Operations Menu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Display\n";
        std::cout << "5. Check if Empty\n";
        std::cout << "6. Check if Full\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter data to push: ";
                std::cin >> data;
                s.push(data);
                break;
            case 2:
                data = s.pop();
                if (data != -1) {
                    std::cout << "Popped element: " << data << "\n";
                }
                break;
            case 3:
                data = s.peek();
                if (data != -1) {
                    std::cout << "Top element: " << data << "\n";
                }
                break;
            case 4:
                s.display();
                break;
            case 5:
                if (s.isEmpty()) {
                    std::cout << "Stack is empty.\n";
                } else {
                    std::cout << "Stack is not empty.\n";
                }
                break;
            case 6:
                if (s.isFull()) {
                    std::cout << "Stack is full.\n";
                } else {
                    std::cout << "Stack is not full.\n";
                }
                break;
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
