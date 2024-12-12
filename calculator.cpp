#include <iostream>

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
        case '^':
            return pow(a, b);
    }
    // or zero if incorrect operator
    return 0;
}