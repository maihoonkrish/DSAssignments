#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void travPreorder(Node* node){

    if(node == NULL)
    return;
    
    cout<< node->data<<" "<<endl;
    
    travPreorder(node->left);
    
    travPreorder(node->right);
};

int main(){
    Node* root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(200);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    cout<<"Preorder Traversal: "<<endl;
    travPreorder(root);
    return 0;
}