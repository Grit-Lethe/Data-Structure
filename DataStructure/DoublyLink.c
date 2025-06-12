#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void InsertAtHead(int x){
    struct Node* newNode = GetNewNode(x);
    if (head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x){
    struct Node* newNode = GetNewNode(x);
    if (head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Print(){
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint(){
    struct Node* temp = head;
    if (temp == NULL){
        return;
    }
    while (temp->next != NULL){
        temp = temp->next;
    }
    printf("Reverse: ");
    while (temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}


int main(){
    head = NULL;
    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtHead(3);
    InsertAtHead(4);
    Print();
    InsertAtTail(5);
    InsertAtTail(7);
    InsertAtTail(8);
    InsertAtTail(9);
    Print();
    ReversePrint();
    system("pause");
    return 0;
}
