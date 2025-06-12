#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if (top == MAX_SIZE -1){
        printf("ERROR: Stack Overflow\n");
        return;
    }
    top++;
    A[top] = x;
    //A[++top] = x;
}

void Pop(){
    if (top == -1){
        printf("ERROR: No Element to Pop\n");
        return;
    }
    top--;
}

int Top(){
    return A[top];
}

void Print(){
    int i;
    printf("Stack: \n");
    for (i=0; i<=top; i++){
        printf(" %d ", A[i]);
    }
    printf("\n");
}

bool IsEmpty(){
    if (top == -1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Push(2);
    Push(5);
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();
    int a = Top();
    printf("Top of Stack: %d\n", a);
    system("pause");
    return 0;
}