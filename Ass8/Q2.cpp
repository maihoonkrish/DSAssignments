#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v){
        data = v;
        left = right = NULL;
    }
};

// ----------------------------------------------------
// INSERT (Helper for creating BST)
// ----------------------------------------------------
Node* insert(Node* root, int val){
    if(root == NULL) return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// ----------------------------------------------------
// (a) SEARCH — RECURSIVE
// ----------------------------------------------------
Node* searchRec(Node* root, int key){
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return searchRec(root->left, key);

    return searchRec(root->right, key);
}

// ----------------------------------------------------
// (a) SEARCH — NON-RECURSIVE
// ----------------------------------------------------
Node* searchNonRec(Node* root, int key){
    while(root != NULL){
        if(root->data == key) return root;

        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// ----------------------------------------------------
// (b) MAXIMUM ELEMENT IN BST
// ----------------------------------------------------
Node* findMax(Node* root){
    if(root == NULL) return NULL;
    while(root->right != NULL)
        root = root->right;
    return root;
}

// ----------------------------------------------------
// (c) MINIMUM ELEMENT IN BST
// ----------------------------------------------------
Node* findMin(Node* root){
    if(root == NULL) return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

// ----------------------------------------------------
// (d) IN-ORDER SUCCESSOR
// ----------------------------------------------------
Node* inorderSuccessor(Node* root, int key){
    Node* target = searchRec(root, key);
    if(target == NULL) return NULL;

    // Case 1: right subtree exists
    if(target->right != NULL){
        return findMin(target->right);
    }

    // Case 2: no right subtree — go to ancestor
    Node* succ = NULL;
    Node* temp = root;

    while(temp != NULL){
        if(key < temp->data){
            succ = temp;
            temp = temp->left;
        }
        else if(key > temp->data){
            temp = temp->right;
        }
        else break;
    }
    return succ;
}

// ----------------------------------------------------
// (e) IN-ORDER PREDECESSOR
// ----------------------------------------------------
Node* inorderPredecessor(Node* root, int key){
    Node* target = searchRec(root, key);
    if(target == NULL) return NULL;

    // Case 1: left subtree exists
    if(target->left != NULL){
        return findMax(target->left);
    }

    // Case 2: no left subtree
    Node* pred = NULL;
    Node* temp = root;

    while(temp != NULL){
        if(key > temp->data){
            pred = temp;
            temp = temp->right;
        }
        else if(key < temp->data){
            temp = temp->left;
        }
        else break;
    }
    return pred;
}

// ----------------------------------------------------
// MAIN
// ----------------------------------------------------
int main(){
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for(int x : arr)
        root = insert(root, x);

    cout << "Max = " << findMax(root)->data << endl;
    cout << "Min = " << findMin(root)->data << endl;

    Node* s = searchNonRec(root, 40);
    if(s) cout << "40 Found\n";
    else cout << "40 Not Found\n";

    Node* succ = inorderSuccessor(root, 40);
    if(succ) cout << "Successor of 40 = " << succ->data << endl;

    Node* pred = inorderPredecessor(root, 40);
    if(pred) cout << "Predecessor of 40 = " << pred->data << endl;

    return 0;
}
