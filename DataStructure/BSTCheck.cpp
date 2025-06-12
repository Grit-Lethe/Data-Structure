#include <iostream>
#include <queue>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

bool SubtreeLesser(Node* root, int value){
    if (root == NULL){
        return true;
    }
    else if (root->data <= value
             && SubtreeLesser(root->left, value)
             && SubtreeLesser(root->right, value)){
        return true;
    }
    else {
        return false;
    }
}

bool SubtreeGreater(Node* root, int value){
    if (root == NULL){
        return true;
    }
    else if (root->data > value
             && SubtreeGreater(root->left, value)
             && SubtreeGreater(root->right, value)){
        return true;
    }
    else {
        return false;
    }
}

bool IsBST(Node* root){
    if (root == NULL) return true;
    if (SubtreeLesser(root->left, root->data) 
       && SubtreeGreater(root->right, root->data)
       && IsBST(root->left) && (IsBST(root->right))){
        return true;
    }
    else {
        return false;
    }
}

bool IBST(Node* root, int minValue, int maxValue){
    if (root == NULL){
        return true;
    }
    else if (root->data > minValue
             && root->data <= maxValue
             && IBST(root->left, minValue, root->data)
             && IBST(root->right, root->data, maxValue)){
        return true;
    }
    else {
        return false;
    }
}

bool IBSTMain(Node* root){
    return IBST(root, INT_MAX, INT_MIN);
}
