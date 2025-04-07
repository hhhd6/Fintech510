#include "expr.hpp"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>

Expression * parseExpression(const char ** strp);

void ignoreWhitespace(const char ** strp) {
    while (isspace(**strp)) {
        ++(*strp);
    }
}

Expression * createExpression(char operatorChar, Expression * left, Expression * right) {
    switch (operatorChar) {
        case '+':
            return new AddExpression(left, right);
        case '-':
            return new SubtractExpression(left, right);
        case '*':
            return new MultiplyExpression(left, right);
        case '/':
            return new DivideExpression(left, right);
        default:
            std::cerr << "Invalid operator: " << operatorChar << "\n";
            std::abort();
    }
}

bool isOperator(char character) {
    return strchr("+-*/", character) != nullptr;
}

Expression * parseOperator(const char ** strp) {
    ignoreWhitespace(strp);
    char operatorChar = **strp;
    if (!isOperator(operatorChar)) {
        std::cerr << "Unexpected operator: " << operatorChar << "\n";
        return nullptr;
    }
    ++(*strp);
    Expression * leftExpr = parseExpression(strp);
    if (leftExpr == nullptr) {
        return nullptr;
    }
    Expression * rightExpr = parseExpression(strp);
    if (rightExpr == nullptr) {
        delete leftExpr;
        return nullptr;
    }
    ignoreWhitespace(strp);
    if (**strp == ')') {
        ++(*strp);
        return createExpression(operatorChar, leftExpr, rightExpr);
    }
    std::cerr << "Mismatched parenthesis at: " << *strp << "\n";
    delete leftExpr;
    delete rightExpr;
    return nullptr;
}

Expression * parseExpression(const char ** strp) {
    ignoreWhitespace(strp);
    if (**strp == '\0') {
        std::cerr << "Unexpected end of input!\n";
        return nullptr;
    }
    else if (**strp == '(') {
        ++(*strp);
        return parseOperator(strp);
    }
    else {
        char * endPointer;
        long number = strtol(*strp, &endPointer, 10);
        if (endPointer == *strp) {
            std::cerr << "Expected a number but found: " << *strp << "\n";
            return nullptr;
        }
        *strp = endPointer;
        return new NumericExpression(number);
    }
}

int main() {
    char * inputLine = nullptr;
    size_t bufferSize = 0;
    while (getline(&inputLine, &bufferSize, stdin) != -1) {
        const char * temp = inputLine;
        std::cout << "Input received: " << inputLine;
        Expression * expression = parseExpression(&temp);
        if (expression != nullptr) {
            std::cout << "Parsed expression: " << expression->toString() << "\n";
            std::cout << "Result: " << expression->evaluate() << "\n";
            delete expression;
        }
        else {
            std::cout << "Failed to parse input. Please check your input format.\n";
        }
    }
    free(inputLine);
    return 0;
}
