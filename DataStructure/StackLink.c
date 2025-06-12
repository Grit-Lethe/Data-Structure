#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x){
    struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop(){
    struct Node* temp;
    if (top == NULL){
        printf("ERROR: No Element to Pop\n");
        return;
    }
    temp = top;
    top = top->link;
    free(temp);
}

void Print(){
    struct Node* temp = top;
    printf("Stack: \n");
    while (temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    Push(2);
    Push(5);
    Push(7);
    Print();
    Pop();
    Print();
    system("pause");
    return 0;
}