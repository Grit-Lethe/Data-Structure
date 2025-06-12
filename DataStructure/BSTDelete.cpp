#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* FindMin(Node* root);

Node* Delete(Node* root, int data){
    if (root == NULL){
        return root;
    }
    else if (data < root->data){
        root->left = Delete(root->left, data);
    }
    else if (data > root->data){
        root->right = Delete(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            // return root;
        }
        else if (root->left == NULL){
            struct Node *temp = root;
            root = root->right;
            delete temp;
            // return root;
        }
        else if (root->right == NULL){
            struct Node *temp = root;
            root = root->left;
            delete temp;
            // return root;
        }
        else {
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
            // return root;
        }
    }
    return root;
}

Node* FindMin(Node *root){
    if (root == NULL){
        cout << "Error: Empty Tree" << endl;
        return 0;
    }
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* GetNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data){
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

int main(){
    Node* root;
    root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);
    cout << "Inorder: " << endl;
    Inorder(root);
    cout << " " << endl;
    root = Delete(root, 4);
    Inorder(root);
    cout << endl;
    system("pause");
    return 0;
}
