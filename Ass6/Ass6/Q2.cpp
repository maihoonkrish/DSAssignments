#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int v){
        data = v;
        next = NULL;
    }
};

Node* insertLast(Node* head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        n->next = n;
        return head;
    }
    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
    return head;
}

void displayCircular(Node* head){
    if(head == NULL) return;

    Node* temp = head;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);

    cout << head->data;  // repeat first node
    cout << endl;
}

int main(){
    Node* head = NULL;

    head = insertLast(head, 20);
    head = insertLast(head, 100);
    head = insertLast(head, 40);
    head = insertLast(head, 80);
    head = insertLast(head, 60);

    displayCircular(head);

    return 0;
}
