#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v; left = right = NULL; }
};

// Check BST using inorder traversal
bool isBSTUtil(Node* root, Node* &prev){
    if(root == NULL) return true;

    if(!isBSTUtil(root->left, prev)) return false;

    if(prev != NULL && root->data <= prev->data) return false;

    prev = root;

    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root){
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}

// Simple insert for testing
Node* insert(Node* root, int val){
    if(root == NULL) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main(){
    Node* root = NULL;

    // A BST
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);

    if(isBST(root)) cout << "Tree is BST\n";
    else cout << "Tree is NOT BST\n";

    return 0;
}
