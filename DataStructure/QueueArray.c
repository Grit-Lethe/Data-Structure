#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 50

typedef struct Queue{
    int A[MAX_SIZE];
    int front, rear;
} Queue;

Queue* CreateQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool IsEmpty(Queue* q){
    return (q->front == -1 && q->rear == -1);
}

bool IsFull(Queue* q){
    return (q->rear + 1) % MAX_SIZE == q->front ? true : false;
}

void Enqueue(Queue* q, int x){
    printf("Enqueuing %d\n", x);
    if (IsFull(q)){
        printf("Error: Queue is Full\n");
        return;
    }
    if (IsEmpty(q)){
        q->front = q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->A[q->rear] = x;
}

void Dequeue(Queue* q){
    printf("Dequeuing\n");
    if (IsEmpty(q)){
        printf("Error: Queue is Empty\n");
        return;
    }
    else if (q->front == q->rear){
        q->rear = q->front = -1;
    }
    else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
}

int Front(Queue* q){
    if (q->front == -1){
        printf("Error: Queue is Empty\n");
        return -1;
    }
    else {
        return q->A[q->front];
    }
}

void Print(Queue* q){
    int count = (q->rear + MAX_SIZE - q->front) % MAX_SIZE + 1;
    printf("Queue:\n");
    for (int i=0; i<count; i++){
        int index = (q->front + i) % MAX_SIZE;
        printf("%d ", q->A[index]);
    }
    printf("\n");
}

int main(){
    Queue* q = CreateQueue();
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    Print(q);
    Dequeue(q);
    Print(q);
    printf("Front: %d\n", Front(q));
    Dequeue(q);
    Dequeue(q);
    Dequeue(q); // Error: Queue is Empty
    system("pause");
    return 0;
}
