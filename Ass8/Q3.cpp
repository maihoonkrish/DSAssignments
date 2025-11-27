#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data = v;
        left = right = NULL;
    }
};

// ------------------------------ INSERT ------------------------------
Node* insert(Node* root, int val){
    if(root == NULL) return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// ------------------------------ MIN VALUE ---------------------------
Node* minNode(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

// ------------------------------ DELETE ------------------------------
Node* deleteNode(Node* root, int key){
    if(root == NULL) return NULL;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else{
        // leaf
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // one child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // two children
        Node* m = minNode(root->right);
        root->data = m->data;
        root->right = deleteNode(root->right, m->data);
    }
    return root;
}

// ------------------------------ MAX DEPTH ---------------------------
int maxDepth(Node* root){
    if(root == NULL) return 0;
    int L = maxDepth(root->left);
    int R = maxDepth(root->right);
    return 1 + (L > R ? L : R);
}

// ------------------------------ MIN DEPTH ---------------------------
int minDepth(Node* root){
    if(root == NULL) return 0;

    int L = minDepth(root->left);
    int R = minDepth(root->right);

    if(root->left == NULL) return 1 + R;
    if(root->right == NULL) return 1 + L;

    return 1 + (L < R ? L : R);
}

// ------------------------------ MAIN -------------------------------
int main(){
    Node* root = NULL;

    int arr[] = {20, 10, 5, 15, 30, 25, 40};
    for(int x : arr)
        root = insert(root, x);

    cout << "Max depth = " << maxDepth(root) << endl;
    cout << "Min depth = " << minDepth(root) << endl;

    root = deleteNode(root, 10);
    cout << "After deleting 10, Max depth = " << maxDepth(root) << endl;

    return 0;
}
