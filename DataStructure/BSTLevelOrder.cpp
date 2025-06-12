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

void LevelOrder(Node* root){
    if (root == NULL){
        return;
    }
    else{
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()){
            Node* current = Q.front();
            cout << current->data << " ";
            if (current->left != NULL) Q.push(current->left);
            if (current->right != NULL) Q.push(current->right);
            Q.pop();
        }
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
    LevelOrder(root);
    cout << "Ending" << endl;
    system("pause");
    return 0;
}
