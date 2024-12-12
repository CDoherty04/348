#include <iostream>
#include <stack>
#include <string>
#include <cmath>

// defines order for operations
int precedence(char op) {
    switch (op) {
        // higher number for higher precedence
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            if (b == 0) {
                throw runtime_error("Division by zero");
            }
            return a / b;
        case '%':
            if (b == 0) {
                throw runtime_error("Modulo by zero");
            }
            return a % b;
        case '^':
            return 3;
    }
    return -1;
}

int operation(int a, int b, char op){
    // returns the output of the desired operation
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
        case '**':
            return pow(a, b);
    }
    // or zero if incorrect operator
    return 0;
}

int evaluate(string expression){
    stack<int> values;
    stack<char> operators;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ')
            continue;
    }
}