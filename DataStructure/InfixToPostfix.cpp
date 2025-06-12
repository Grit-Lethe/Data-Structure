#include <iostream>
#include <stack>
#include <string>
using namespace std;

string InfixToPostfix(string expression);
int HasHigherPrecedence(char operator1, char operator2);
bool IsOperator(char C);
bool IsOperand(char C);
int EvaluatePostfix(string expression);
int PerformOperation(char operation, int operand1, int operand2);

int main(){
    string expression;
    cout << "Enter Infix Expression\n" << endl;
    getline(cin, expression);
    string postfix = InfixToPostfix(expression);
    cout << "Output = " << postfix << endl;
    cout << "Postfix Evaluation = " << EvaluatePostfix(postfix) << endl;
    system("pause");
    return 0;
}

string InfixToPostfix(string expression){
    stack <char> S;
    string postfix = "";
    for (int i=0; i<expression.length(); i++){
        if (expression[i] == ' ' || expression[i] == ','){
            continue;
        }
        else if (IsOperator(expression[i])){
            while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i])){
                postfix += S.top();
                S.pop();
            }
            S.push(expression[i]);
        }
        else if (IsOperand(expression[i])){
            int operand = 0;
            while(i<expression.length() && IsOperand(expression[i])){
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            postfix += to_string(operand);
            postfix += ' ';
            i--;
            // postfix += expression[i];
        }
        else if (expression[i] == '('){
            S.push(expression[i]);
        }
        else if (expression[i] == ')'){
            while (!S.empty() && S.top() != '('){
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    while (!S.empty()){
        postfix += S.top();
        S.pop();
    }
    return postfix;
}

bool IsOperand(char C){
    if (C >= '0' && C <= '9'){
        return true;
    }
    // else if (C >= 'a' && C <= 'z'){
    //     return true;
    // }
    // else if (C >= 'A' && C <= 'Z'){
    //     return true;
    // }
    else {
        return false;
    }
}

bool IsOperator(char C){
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$'){
        return true;
    }
    else {
        return false;
    }
}

//  int IsRightAssociative(char op){
//     if (op == '$'){
//         return true;
//     }
//     else {
//         return false;
//     }
//  }

 int GetOperatorWeight(char op){
    int weight = -1;
    switch (op){
        case '+':
        case '-':
            weight = 1; break;
        case '*':
        case '/':
            weight = 2; break;
        // case '$':
        // weight = 3; break;
    }
    return weight;
 }

 int HasHigherPrecedence(char op1, char op2){
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
    if (op1Weight == op2Weight){
        // if (IsRightAssociative(op1)){
        //     return false;
        // }
        // else {
        //     return true;
        // }
        return true;
    }
    else {
        return op1Weight > op2Weight ? true : false;
    }
    // return op1Weight > op2Weight ? true : false;
 }

int EvaluatePostfix(string expression){
    stack <char> S;
    for (int i=0; i<expression.length(); i++){
        if (expression[i] == ' ' || expression[i] == ','){
            continue;
        }
        else if (IsOperator(expression[i])){
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();
            int result = PerformOperation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if (IsOperand(expression[i])){
            int operand = 0;
            while (i<expression.length() && IsOperand(expression[i])){
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            S.push(operand);
            i--;
        }
    }
    return S.top();
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
                cout << "Division by zero error" << endl;
                exit(1);
            }
            else {
                return operand1 / operand2;
            }
        default:
            cout << "Invalid operator" << endl;
            exit(1);
    }
}
