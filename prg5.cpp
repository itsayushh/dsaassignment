#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int x){
        this->data=x;
        this->right=NULL;
        this->left=NULL;
    }
};

void preorder(Node *node){
    if(node==NULL) return;
    else {
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}
void inorder(Node *node){
    if(node==NULL) return;
    else {
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}
void postorder(Node *node){
    if(node==NULL) return;
    else {
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
}



int main(){
}