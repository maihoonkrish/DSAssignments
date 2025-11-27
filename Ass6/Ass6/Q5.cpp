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

// Function to check if linked list is circular
bool isCircular(Node* head){
    if(head == NULL) return false;  // empty list is NOT circular

    Node* temp = head->next;

    while(temp != NULL && temp != head)
        temp = temp->next;

    if(temp == head)
        return true;    // came back to head → circular
    else
        return false;   // reached NULL → not circular
}

int main(){
    // Example 1: Circular Linked List
    Node* head1 = new Node(10);
    Node* second1 = new Node(20);
    Node* third1 = new Node(30);

    head1->next = second1;
    second1->next = third1;
    third1->next = head1;   // making it circular

    cout << "List 1 is ";
    if(isCircular(head1)) cout << "Circular\n";
    else cout << "Not Circular\n";


    // Example 2: Normal Linked List
    Node* head2 = new Node(5);
    Node* second2 = new Node(15);

    head2->next = second2;
    second2->next = NULL;   // NOT circular

    cout << "List 2 is ";
    if(isCircular(head2)) cout << "Circular\n";
    else cout << "Not Circular\n";

    return 0;
}
