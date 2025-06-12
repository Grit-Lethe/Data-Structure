#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void Reverse(struct Node* p){
    if (p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

void Insert(struct Node** head, int data){
    struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL){
        *head = temp;
    }
    else{
        struct Node* temp1 = *head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    // return head;
}

void Print(struct Node* p){
    if (p == NULL){
        printf("\n");
        return;
    }
    printf(" %d ", p->data);
    Print(p->next);
}

int main(){
    head = NULL;
    Insert(&head, 2);
    Insert(&head, 5);
    Insert(&head, 3);
    Insert(&head, 7);
    Print(head);
    Reverse(head);
    Print(head);
    system("pause");
    return 0;
}
