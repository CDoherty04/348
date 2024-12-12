#include <iostream>

// defines order for operations
int precedence(char op) {
    switch (op) {
        // higher number for higher precedence
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
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
