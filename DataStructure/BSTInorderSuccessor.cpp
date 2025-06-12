#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* Find(struct Node* root, int data){
    if (root == NULL){
        return NULL;
    }
    else if (data == root->data){
        return root;
    }
    else if (data < root->data){
        return Find(root->left, data);
    }
    else{
        return Find(root->right, data);
    }
}

struct Node* FindMin(struct Node* root){
    if (root == NULL){
        return NULL;
    }
    else {
        while (root->left != NULL){
            root = root->left;
        }
        return root;
    }
}

struct Node* Getsuccessor(struct Node* root, int data){
    struct Node* current = Find(root, data);
    if (current == NULL){
        return NULL;
    }
    else if (current->right != NULL){
        // struct Node* temp = current->right;
        // while (temp->left != NULL){
        //     temp = temp->left;
        return FindMin(current->right);
    }
    else {
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        while (ancestor != current){
            if (current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
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
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    cout << "The Tree is: " << endl;
    Inorder(root);
    cout << endl;
    int number;
    struct Node* successor;
    cout << "Select Node:" << endl;
    cin >> number;
    successor = Getsuccessor(root, number);
    cout << "The Successor is: " << successor->data << endl;
    system("pause");
    return 0;
}
