#include <iostream>
using namespace std;

// ------------------------ NODE CLASS ------------------------
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ------------------------ LINKED LIST CLASS ------------------------
class LinkedList {
    Node* head;

public:
    LinkedList() { head = NULL; }

    // (a) INSERT AT BEGIN
    void insertBegin(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    // (b) INSERT AT END
    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
    }

    // (c) INSERT AFTER A VALUE
    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != target) temp = temp->next;

        if (temp == NULL) {
            cout << "Target value not found.\n";
            return;
        }
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // INSERT BEFORE A VALUE
    void insertBefore(int target, int val) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        if (head->data == target) {  // before first node
            insertBegin(val);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != target)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Target not found.\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // (d) DELETE FROM BEGIN
    void deleteBegin() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) DELETE FROM END
    void deleteEnd() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // (f) DELETE SPECIFIC VALUE
    void deleteValue(int val) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        if (head->data == val) {
            deleteBegin();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Value not found.\n";
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    // (g) SEARCH
    void search(int val) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Found at position: " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Not found.\n";
    }

    // (h) DISPLAY LIST
    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List empty.\n";
            return;
        }
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // COUNT OCCURRENCES + DELETE ALL
    void deleteAllOccurrences(int key) {
        int count = 0;

        while (head != NULL && head->data == key) {
            deleteBegin();
            count++;
        }
        Node* temp = head;

        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == key) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                count++;
            } else {
                temp = temp->next;
            }
        }

        cout << "Count: " << count << endl;
    }

    // FIND MIDDLE OF LINKED LIST
    void findMiddle() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle: " << slow->data << endl;
    }

    // REVERSE LINKED LIST
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

// -------------------------------------------------------------

int main() {
    LinkedList ll;
    int choice, val, target;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1 Insert at Beginning\n";
        cout << "2 Insert at End\n";
        cout << "3 Insert After a Value\n";
        cout << "4 Insert Before a Value\n";
        cout << "5 Delete from Beginning\n";
        cout << "6 Delete from End\n";
        cout << "7
