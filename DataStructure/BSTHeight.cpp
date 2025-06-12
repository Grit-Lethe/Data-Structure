#include <iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int FindHeight(BstNode* root){
    if (root == NULL){
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

BstNode* Insert(BstNode* root, int data){
    if (root == NULL){
        root = GetNewNode(data);
        return root;
    }
    else if (root->data <= data){
        root->right = Insert(root->right, data);
    }
    else {
        root->left = Insert(root->left, data);
    }
    return root;
}
