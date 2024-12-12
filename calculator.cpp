#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    switch (op) {
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

int applyOp(int a, int b, char op) {
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
    return 0;
}

int evaluate(string expr) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ')
            continue;

        if (isdigit(expr[i])) {
            int num = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                num = num * 10 + (int)(expr[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        } else if (expr[i] == '(') {
            ops.push(expr[i]);
        } else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop();
        } else {
            while (!ops.empty() && precedence(expr[i]) <= precedence(ops.top())) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    string expr;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expr);

    cout << "Result: " << evaluate(expr) << endl;

    return 0;
}