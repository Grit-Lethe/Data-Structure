#include <iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

int FindMin(BstNode* root){
    if (root == NULL){
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    // BstNode* current = root;
    while (root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int FindMax(BstNode* root){
    if (root == NULL){
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    else if (root->right == NULL){
        return root->data;
    }
    return FindMax(root->right);
}
