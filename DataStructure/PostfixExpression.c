#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int EvaluatePostfix(char *expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsNumericDigit(char C);

int main(){
    char expression[100];
    printf("Enter a postfix experssion: \n");
    fgets(expression, sizeof(expression), stdin);
    int result = EvaluatePostfix(expression);
    printf("Result: %d\n", result);
    system("pause");
    return 0;
}

int EvaluatePostfix(char *expression){
    int S[100];
    int top = -1;
    for (int i=0; i<strlen(expression); i++){
        if (expression[i] == ' ' || expression[i] == ','){
            continue;
        }
        else if (IsOperator(expression[i])){
            int operand2 = S[top--];
            int operand1 = S[top--];
            int result = PerformOperation(expression[i], operand1, operand2);
            S[++top] = result;
        }
        else if (IsNumericDigit(expression[i])){
            int operand = 0;
            while (i<strlen(expression) && IsNumericDigit(expression[i])){
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            S[++top] = operand;
        }
    }
    return S[top];
}

bool IsNumericDigit(char C){
    if (C >= '0' && C <= '9'){
        return true;
    }
    else {
        return false;
    }
}

bool IsOperator(char C){
    if (C == '+' || C == '-' || C == '*' || C == '/'){
        return true;
    }
    else {
        return false;
    }
}

int PerformOperation(char operation, int operand1, int operand2){
    switch (operation){
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0){
                printf("Error: Division by zero\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            printf("Error: Invalid operator\n");
            exit(1);
    }
}
