#include<bits/stdc++.h>
using namespace std;

class bst {
public:
    int data;
    bst *right;
    bst *left;
    bst(int x) : data(x), left(nullptr), right(nullptr) {}
};

bst* insert(bst* root, int data) {
    if (!root) return new bst(data);
    if (data > root->data) root->right = insert(root->right, data);
    else root->left = insert(root->left, data);
    return root;
}

void inorder(bst* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    bst* root = nullptr;
    vector<int> values = {30, 13, 12, 54, 90, 15};
    for (int val : values) root = insert(root, val);
    inorder(root);
}
