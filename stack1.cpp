#include <iostream>
#include <string>

using namespace std;

class stack {
public:
    char arr[100];
    int top;

    stack() {
        top = -1;
    }

    void push(char c) {
        if (top >= (100 - 1)) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = c;
        }
    }

    char pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return '\0';
        } else {
            return arr[top--];
        }
    }

    char topcompare() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return '\0';
        } else {
            return arr[top];
        }
    }

    int empty() {
        return (top < 0);
    }
};

int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c);
string infixToPostfix(string infix) {
    stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isOperand(c)) {
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
            while (st.empty() == 0 && precedence(c) <= precedence(st.topcompare())) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    while (st.empty() == 0) {
        postfix += st.pop();
    }

    return postfix;
}

string prefixToInfix(string prefix) {
    stack st;
    string infix = "";

    int n = prefix.length();

    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperand(c)) {
            st.push(c);
        } else if (isOperator(c)) {
            char t1 = st.pop();
            char t2 = st.pop();
            infix = "(" + string(1, t1) + c + string(1, t2) + ")";

        for (int i = 0; i < infix.length(); i++) {
            st.push(infix[i]);
        }
        }
    }
    return infix;
}

int evaluatePostfix(string postfix) {
    stack st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isOperand(c) && isdigit(c)) {
            st.push(c);
        } else if (isOperator(c)) {
            int val2 = st.pop() - '0';  
            int val1 = st.pop() - '0';  

            int result;
            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            st.push(result + '0');
        }
    }

    return st.pop() - '0';
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

int main() {
    int choice;
    cout << "Choose the conversion type:\n1. Infix to Postfix\n2. Prefix to Infix\n3. Evaluate Postfix\n";
    cin >> choice;

    if (choice == 1) {
        string infix;
        cout << "Enter an infix expression: ";
        cin >> infix;

        string postfix = infixToPostfix(infix);
        cout << "Postfix expression: " << postfix << endl;
    } 
    else if (choice == 2) {
        string prefix;
        cout << "Enter a prefix expression: ";
        cin >> prefix;

        string infix = prefixToInfix(prefix);
        cout << "Infix expression: " << infix << endl;
    } 
    else if (choice == 3) {
        string postfix;
        cout << "Enter a postfix expression: ";
        cin >> postfix;

        int result = evaluatePostfix(postfix);
        cout << "Result of postfix evaluation: " << result << endl;
    } 
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
