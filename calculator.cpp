#include <iostream>
#include <stack>
#include <string>
#include <cmath>

// defines order of operations
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '**':
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
            if (b == 0) {
                // does not allow divide by zero
                throw runtime_error("Division by zero");
            }
            return a / b;
        case '%':
            if (b == 0) {
                // does not allow modulo by zero
                throw runtime_error("Modulo by zero");
            }
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
    // Evaluates Blank Space
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;
    }
    // Evaluates Digits
    if (isdigit(expression[i])) {
        // Parses digit and adds to values stack
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                // Shifts the digits one to the left and adds to rightmost index
                num = num * 10 + (int)(expression[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        } 
    }
    // Evaluates Parenthesis
    else if (expression[i] == '(') {
        // simply adds to operators list
            operators.push(expression[i]);
    }
    else if (expression[i] == ')') {
        while (!operators.empty() && operators.top() != '(') {
            // If closes out a left parenthesis with operators/digits inside of it:
            // Solves equation
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();
            char op = operators.top();
            operators.pop();
            values.push(operation(val1, val2, op));
        }
        operators.pop();
    }
    else {
        // Evaluates high precedence operators first (%,/,x)
            while (!operators.empty() && precedence(expression[i]) <= precedence(operators.top())) {
                // Solves equation
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(operation(val1, val2, op));
            }
            ops.push(expr[i]);
        }
    }
}