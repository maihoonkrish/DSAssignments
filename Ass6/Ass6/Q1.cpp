#include <iostream>
using namespace std;

// =====================================================
//                 CIRCULAR LINKED LIST
// =====================================================
class CNode {
public:
    int data;
    CNode* next;
    CNode(int val){ data = val; next = NULL; }
};

class CircularLL {
public:
    CNode* head;

    CircularLL(){ head = NULL; }

    // Insert at beginning
    void insertFirst(int val){
        CNode* n = new CNode(val);
        if(head == NULL){
            head = n;
            n->next = n;
            return;
        }
        CNode* temp = head;
        while(temp->next != head) temp = temp->next;
        n->next = head;
        temp->next = n;
        head = n;
    }

    // Insert at last
    void insertLast(int val){
        if(head == NULL){ insertFirst(val); return; }
        CNode* temp = head;
        CNode* n = new CNode(val);
        while(temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    // Insert after a given key
    void insertAfter(int key, int val){
        if(head == NULL) return;
        CNode* temp = head;
        do{
            if(temp->data == key){
                CNode* n = new CNode(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        }while(temp != head);
    }

    // Insert before a given key
    void insertBefore(int key, int val){
        if(head == NULL) return;

        if(head->data == key){ insertFirst(val); return; }

        CNode* temp = head;
        do{
            if(temp->next->data == key){
                CNode* n = new CNode(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        }while(temp != head);
    }

    // Delete a node
    void deleteNode(int key){
        if(head == NULL) return;

        CNode* curr = head;
        CNode* prev = NULL;

        // delete head
        if(head->data == key){
            while(curr->next != head) curr = curr->next;
            if(curr == head){ delete head; head = NULL; return; }
            curr->next = head->next;
            CNode* t = head;
            head = head->next;
            delete t;
            return;
        }

        // delete non-head node
        curr = head->next;
        prev = head;
        while(curr != head){
            if(curr->data == key){
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Search a node
    void search(int key){
        if(head == NULL){ cout<<"Not Found\n"; return; }
        CNode* temp = head;
        int pos = 1;
        do{
            if(temp->data == key){
                cout<<"Found at position "<<pos<<endl;
                return;
            }
            temp = temp->next;
            pos++;
        }while(temp != head);

        cout<<"Not Found\n";
    }

    // Display Circular LL
    void display(){
        if(head == NULL){ cout<<"List empty\n"; return; }
        CNode* temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != head);
        cout<<head->data<<" (repeat)\n";
    }
};

// =====================================================
//                     DOUBLY LINKED LIST
// =====================================================
class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val){ data = val; next = prev = NULL; }
};

class DoublyLL {
public:
    DNode* head;

    DoublyLL(){ head = NULL; }

    // Insert at beginning
    void insertFirst(int val){
        DNode* n = new DNode(val);
        if(head == NULL){ head = n; return; }
        n->next = head;
        head->prev = n;
        head = n;
    }

    // Insert at end
    void insertLast(int val){
        if(head == NULL){ insertFirst(val); return; }
        DNode* temp = head;
        while(temp->next != NULL) temp = temp->next;
        DNode* n = new DNode(val);
        temp->next = n;
        n->prev = temp;
    }

    // Insert after a key
    void insertAfter(int key, int val){
        DNode* temp = head;
        while(temp){
            if(temp->data == key){
                DNode* n = new DNode(val);
                n->next = temp->next;
                if(temp->next) temp->next->prev = n;
                temp->next = n;
                n->prev = temp;
                return;
            }
            temp = temp->next;
        }
    }

    // Insert before a key
    void insertBefore(int key, int val){
        if(head == NULL) return;
        if(head->data == key){ insertFirst(val); return; }

        DNode* temp = head;
        while(temp){
            if(temp->data == key){
                DNode* n = new DNode(val);
                n->next = temp;
                n->prev = temp->prev;
                temp->prev->next = n;
                temp->prev = n;
                return;
            }
            temp = temp->next;
        }
    }

    // Delete a specific node
    void deleteNode(int key){
        if(head == NULL) return;

        DNode* temp = head;

        // deleting head
        if(head->data == key){
            head = head->next;
            if(head) head->prev = NULL;
            delete temp;
            return;
        }

        while(temp){
            if(temp->data == key){
                if(temp->next) temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    // Search node
    void search(int key){
        DNode* temp = head;
        int pos = 1;
        while(temp){
            if(temp->data == key){
                cout<<"Found at position "<<pos<<endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout<<"Not Found\n";
    }

    // Display DLL
    void display(){
        if(head == NULL){ cout<<"Empty\n"; return; }
        DNode* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


// =====================================================
//                     MAIN FUNCTION
// =====================================================
int main(){
    CircularLL cll;
    DoublyLL dll;

    // Example operations (you can replace with menu)
    cll.insertFirst(10);
    cll.insertLast(20);
    cll.insertAfter(10, 15);
    cll.insertBefore(20, 18);
    cll.display();
    cll.search(15);
    cll.deleteNode(18);
    cll.display();

    cout << "\nDoubly Linked List:\n";
    dll.insertFirst(50);
    dll.insertLast(60);
    dll.insertAfter(50, 55);
    dll.insertBefore(60, 58);
    dll.display();
    dll.search(55);
    dll.deleteNode(58);
    dll.display();

    return 0;
}
