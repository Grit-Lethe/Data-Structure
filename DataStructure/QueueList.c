#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x){
    struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

void Dequeue(){
    struct Node* temp = front;
    if (front == NULL){
        printf("Error: Queue is Empty\n");
        return;
    }
    else if (front == rear){
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);
}

void Print(){
    struct Node* temp = front;
    printf("Queue: ");
    if (temp == NULL){
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Front(){
    if (front == NULL){
        printf("Error: Queue is empty\n");
        return;
    }
    else{
        printf("Front: %d\n", front->data);
    }
}

int main(){
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Print();
    Dequeue();
    Print();
    Dequeue();
    Print();
    Front();
    Dequeue();
    Print();
    system("pause");
    return 0;
}
