#include "ExpressionManager.h"
#include <iostream>

using namespace std;

void ExpressionManager::readExpression(const string& input) {
    expression = input;
}

bool ExpressionManager::isBalanced(const string& expression) {
    stack<char> s;
    for (char c : expression) {
        switch (c) {
            case '{': case '(': case '[':
                s.push(c);
                break;
            case '}': case ')': case ']':
                if (s.empty() ||
                    (c == '}' && s.top() != '{') ||
                    (c == ')' && s.top() != '(') ||
                    (c == ']' && s.top() != '[')) { 
                    return false;
                }
                s.pop();
                break;
            default:
                // ignore all other characters
                break;
        }
    }
    return s.empty();
}


string ExpressionManager::infixToPostfix(const string&expression) {
    stack<char> opStack;
    string postfix;
    for (char c: expression) {
        if (isOperator(c)) {
            processOperator(opStack, postfix, c);
        } else if (c == '(' || c == '{' || c == '[') {
            opStack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            while (!opStack.empty() && opStack.top() != '(' && opStack.top() != '{' && opStack.top() != '[') {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty()) {
                opStack.pop(); // Pop the opening parenthesis.
            }
        }
        else if (isalnum(c)) {
            postfix += c;
        }
        // Ignore other characters
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}


void ExpressionManager::convertAndPrint() {
    if (!isBalanced(expression)) {
        cout << "The expression is invalid due to unbalanced parentheses." << endl;
        return;
    }

    string postfix = infixToPostfix(expression);
    cout << "\nThe postfix expression is: " << postfix << "\n" << endl;
}

int ExpressionManager::getPrecedence(char op) {
    switch (op) {
        case '+': case '-':
            return 1;
        case '*': case '/': case '%':
            return 2;
        default:
            return 0;
    }
}


bool ExpressionManager::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

void ExpressionManager::processOperator(stack<char> &opStack, string &postfix, char op) {
    while (!opStack.empty() && isOperator(opStack.top()) && getPrecedence(opStack.top()) >= getPrecedence(op)) {
        postfix += opStack.top();
        opStack.pop();
    }
    opStack.push(op);
}

