#include <iostream>
#include <queue>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Preorder(Node* root){
    if (root == NULL){
        return;
    }
    else{
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(Node* root){
    if (root == NULL){
        return;
    }
    else{
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Postorder(Node* root){
    if (root == NULL){
        return;
    }
    else{
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

Node* Insert(Node* root, char data){
    if (root == NULL){
        root = GetNewNode(data);
        return root;
    }
    else if (data <= root->data){
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

int main(){
    Node* root;
    root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'A');
    root = Insert(root, 'Z');
    root = Insert(root, 'B');
    root = Insert(root, 'G');
    root = Insert(root, 'P');
    Preorder(root);
    cout << " Preorder Ending" << endl;
    Inorder(root);
    cout << " Inorder Ending" << endl;
    Postorder(root);
    cout << " Postorder Ending" << endl;
    system("pause");
    return 0;
}
