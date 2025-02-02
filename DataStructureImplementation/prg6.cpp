#include<bits/stdc++.h>
using namespace std;

class bst{
public:
    int data;
    bst *right;
    bst *left;
    bst(int x){
        this->data=x;
        this->left=this->right=NULL;
    }
};

bst *insert(bst *root,int data){
    if(!root){
        bst *newnode = new bst(data);
        return newnode;
    }
    if(data>root->data){
        root->right=insert(root->right,data);
    }
    else{
        root->left=insert(root->left,data);
    }
    return root;
}

void inorder(bst *node){
    if(node==NULL) return;
    else {
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}

int main(){
    cout<<"Enter BST: "<<"\n";
    bst *root=NULL;
    root=insert(root,30);
    root=insert(root,13);
    root=insert(root,12);
    root=insert(root,54);
    root=insert(root,90);
    root=insert(root,15);
    inorder(root);


}