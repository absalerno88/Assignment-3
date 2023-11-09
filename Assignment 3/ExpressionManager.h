#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H

#include <string>
#include <stack>

class ExpressionManager {
public:
    // Reads an infix expression from the user.
    void readExpression(const std::string& input);

    // Converts the infix expression to postfix and prints it.
    void convertAndPrint();

private:
    std::string expression; // infix expression

    // Checks if the parentheses are balanced.
    bool isBalanced(const std::string &expression);

    // Converts an infix expression to a postfix expression.
    std::string infixToPostfix(const std::string &expression);

    // Returns the precedence of the operator.
    int getPrecedence(char op);

    // Checks if the character is an operator.
    bool isOperator(char c);

    // Helper function to process operators in the infixToPostfix function.
    void processOperator(std::stack<char> &opStack, std::string&postfix, char op);
};

#endif // EXPRESSIONMANAGER_H
