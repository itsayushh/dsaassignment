#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    Node(int x) {
        data = x;
        right = nullptr;
        left = nullptr;
    }
};

void preorder(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " "; 
    preorder(node->left);      
    preorder(node->right);     
}
void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);       
    cout << node->data << " "; 
    inorder(node->right);      
}
void postorder(Node* node) {
    if (node == nullptr) return;
    postorder(node->left);     
    postorder(node->right);    
    cout << node->data << " "; 
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    delete root;
    return 0;
}
