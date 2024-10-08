#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
    char arr[100];
    int top;

    Stack(){
         top = -1;
    }

    void push(char c){
        if (top >= (100 - 1)) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = c;
        }
    }

    char pop(){
        if (top < 0){
            cout << "Stack Underflow" << endl;
            return '\0';
        } 
        else{
            return arr[top--];
        }
    }

    char topcompare(){
        if (top < 0){
            cout << "Stack is Empty" << endl;
            return '\0';
        } 
        else{
            return arr[top];
        }
    }

    int empty(){
        return (top < 0);
    }
};

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }

        else if (c == '(') {
            st.push(c);
        }

        else if (c == ')') {
            while (!st.empty() && st.topcompare() != '(') {
                postfix += st.pop();
            }
            st.pop();
        }

        else if (isOperator(c)) {
            while (st.empty() == false && precedence(c) <= precedence(st.topcompare())) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    while (st.empty() == false) {
        postfix += st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
