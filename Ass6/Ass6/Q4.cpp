#include <iostream>
using namespace std;

class Node{
public:
    char data;
    Node* next;
    Node* prev;

    Node(char v){
        data = v;
        next = prev = NULL;
    }
};

Node* insertEnd(Node* head, char val){
    Node* n = new Node(val);
    if(head == NULL) return n;

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;

    return head;
}

bool isPalindrome(Node* head){
    if(head == NULL) return true;

    Node* left = head;
    Node* right = head;

    // move right pointer to end
    while(right->next != NULL)
        right = right->next;

    // compare from both ends
    while(left != right && right->next != left){
        if(left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main(){
    Node* head = NULL;

    // Example 1: Palindrome
    head = insertEnd(head, 'R');
    head = insertEnd(head, 'A');
    head = insertEnd(head, 'D');
    head = insertEnd(head, 'A');
    head = insertEnd(head, 'R');

    if(isPalindrome(head))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
