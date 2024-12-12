#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

// defines order of operations
int precedence(char op)
{
    switch (op)
    {
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

float operation(float a, float b, char op)
{
    // returns the output of the desired operation
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            // does not allow divide by zero
            throw runtime_error("Division by zero");
        }
        return a / b;
    case '%':
        if (b == 0)
        {
            // does not allow modulo by zero
            throw runtime_error("Modulo by zero");
        }
        return (int)(a) % (int)(b);
    case '^':
        return pow(a, b);
    }
    // or zero if incorrect operator
    return 0;
}

float evaluate(string expression)
{
    stack<float> values;
    stack<char> operators;
    int i = 0; // Start index for parsing
    // Evaluates the expression
    while (i < expression.length())
    {
        if (expression[i] == ' ')
        {
            // skips the spaces in the expression
            i++;
            continue;
        }

        // Evaluates Digits
        if (isdigit(expression[i]))
        {
            float num = 0;
            while (i < expression.length() && isdigit(expression[i]))
            {
                num = num * 10 + (float)(expression[i] - '0');
                i++;
            }
            values.push(num);
        }
        // Evaluates Parenthesis
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
            i++;
        }
        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                // If closes out a left parenthesis with operators/digits inside of it:
                // Solves equation
                float val2 = values.top();
                values.pop();
                float val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(operation(val1, val2, op));
            }
            operators.pop();
            i++;
        }
        else
        {
            // Evaluates high precedence operators first (%,/,x)
            while (!operators.empty() && precedence(expression[i]) <= precedence(operators.top()))
            {
                // Solves equation
                float val2 = values.top();
                values.pop();
                float val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(operation(val1, val2, op));
            }
            operators.push(expression[i]);
            i++;
        }
    }

    // Evaluates the rest of the operators
    while (!operators.empty())
    {
        float val2 = values.top();
        values.pop();
        float val1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(operation(val1, val2, op));
    }

    return values.top();
}

// Input handling
int main()
{
    string expr;
    while (true)
    {
        cout << "Enter an arithmetic expression: ";
        getline(cin, expr);

        try
        {
            cout << "Result: " << evaluate(expr) << endl;
        }
        catch (const runtime_error &e)
        {
            // error handling
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
