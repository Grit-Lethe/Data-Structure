#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// struct Node* head;
void Insert(struct Node** head, int x);
void Print(struct Node* head);

void Insert(struct Node** head, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *head;
    // temp->next = NULL;
    // if (head!=NULL){
    //     temp->next = head;
    // }
    *head = temp;
    //return head;
}

void Print(struct Node* head){
    // struct Node* temp = head;
    printf("List is: ");
    while (head!=NULL){
        printf(" %d", head->data);
        head = head->next;

    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
    system("pause");
    return 0;
}
