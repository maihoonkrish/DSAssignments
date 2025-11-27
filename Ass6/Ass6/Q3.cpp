#include <iostream>
using namespace std;

// ================= DOUBLY LINKED LIST =================

class DNode{
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int v){
        data = v;
        next = prev = NULL;
    }
};

int sizeDLL(DNode* head){
    int count = 0;
    DNode* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

DNode* insertEndDLL(DNode* head, int val){
    DNode* n = new DNode(val);
    if(head == NULL) return n;

    DNode* temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp->next = n;
    n->prev = temp;

    return head;
}

// ================= CIRCULAR LINKED LIST =================

class CNode{
public:
    int data;
    CNode* next;

    CNode(int v){
        data = v;
        next = NULL;
    }
};

CNode* insertEndCLL(CNode* head, int val){
    CNode* n = new CNode(val);
    if(head == NULL){
        head = n;
        n->next = n;
        return head;
    }
    CNode* temp = head;
    while(temp->next != head) temp = temp->next;

    temp->next = n;
    n->next = head;
    return head;
}

int sizeCLL(CNode* head){
    if(head == NULL) return 0;

    int count = 0;
    CNode* temp = head;
    do{
        count++;
        temp = temp->next;
    } while(temp != head);

    return count;
}

// ================= MAIN =================

int main(){
    // DLL
    DNode* headDLL = NULL;
    headDLL = insertEndDLL(headDLL, 10);
    headDLL = insertEndDLL(headDLL, 20);
    headDLL = insertEndDLL(headDLL, 30);

    cout << "Size of Doubly Linked List = " << sizeDLL(headDLL) << endl;

    // CLL
    CNode* headCLL = NULL;
    headCLL = insertEndCLL(headCLL, 5);
    headCLL = insertEndCLL(headCLL, 15);
    headCLL = insertEndCLL(headCLL, 25);

    cout << "Size of Circular Linked List = " << sizeCLL(headCLL) << endl;

    return 0;
}
