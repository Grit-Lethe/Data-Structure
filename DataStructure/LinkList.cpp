#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *link;
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> link;
    }
    cout << " NULL " << endl;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head -> link;
        delete temp;
    }
}

int main() {
    Node* A;
    A = NULL;
    // Node* temp = (Node*)malloc(sizeof(Node));
    Node* temp = new Node();
    // (*temp).data = 2;
    // (*temp).link = NULL;
    temp -> data = 2;
    temp -> link = NULL;
    A = temp;
    temp = new Node();
    temp -> data = 4;
    temp -> link = NULL;
    Node* temp1 = A;
    while (temp1 -> link != NULL) {
        temp1 = temp1 -> link;
    }
    temp1 -> link = temp;
    cout << "链表内容：";
    printList(A);
    freeList(A);
    system("pause");
    return 0;
}
