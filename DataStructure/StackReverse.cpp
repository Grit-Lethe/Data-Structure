#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

// class Stack{
//     private:
//         char A[101];
//         int top;
//     public:
//         void Push(int x);
//         void Pop();
//         int Top();
//         bool IsEmpty();
// };

struct Node {
    int data;
    Node* next;
};

void Reverse(char *C, int n){
    stack <char> S;
    for (int i=0; i<n; i++){
        S.push(C[i]);
    }
    for (int i=0; i<n; i++){
        C[i] = S.top();
        S.pop();
    }
}

// void ReverseLink(char *C, int n){
//     if (head == NULL){
//         return;
//     }
//     stack <struct Node*> S;
//     Node* temp = head;
//     while (temp != NULL){
//         S.push(temp);
//         temp = temp->next;
//     }
//     temp = S.top();
//     head = temp;
//     S.pop();
//     while (!S.empty()){
//         temp->next = S.top();
//         S.pop();
//         temp = temp->next;
//     } 
//     temp->next = NULL;
// }

int main(){
    char C[51];
    printf("Enter a String: ");
    gets(C);
    Reverse(C, strlen(C));
    printf("Output = %s\n", C);
    system("pause");
    return 0;
}