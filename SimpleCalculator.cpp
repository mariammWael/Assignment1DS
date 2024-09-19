#include "SimpleCalculator.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <stack>  // Missing include for std::stack

using namespace std;

SimpleCalculator::SimpleCalculator() {}

bool SimpleCalculator::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

int SimpleCalculator::precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/' || op == '%') {
        return 2;
    }
    return 0;
}

double SimpleCalculator::applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        case '%': return static_cast<int>(a) % static_cast<int>(b);  // Handle integer modulo
        default: throw runtime_error("Invalid operator");
    }
}

string SimpleCalculator::infixToPostfix(const string& infix) {
    stack<char> operators;
    stringstream postfix;
    bool lastWasDigit = false;

    for (char ch : infix) {
        if (isspace(ch)) {
            continue;  // Ignore spaces
        }

        if (isdigit(ch)) {
            if (lastWasDigit) {
                postfix << ch;  // Append digit to multi-digit number
            } else {
                postfix << ' ' << ch;  // Start a new number
                lastWasDigit = true;
            }
        } else {
            lastWasDigit = false;
            if (ch == '(') {
                operators.push(ch);
            } else if (ch == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfix << ' ' << operators.top();
                    operators.pop();
                }
                if (!operators.empty()) operators.pop();  // Pop '('
            } else if (isOperator(ch)) {
                while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                    postfix << ' ' << operators.top();
                    operators.pop();
                }
                postfix << ' ';
                operators.push(ch);
            }
        }
    }

    while (!operators.empty()) {
        postfix << ' ' << operators.top();
        operators.pop();
    }

    return postfix.str();
}

double SimpleCalculator::evaluatePostfix(const string& postfix) {
    stack<double> values;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            // Handle multi-digit numbers
            values.push(stod(token));
        } else if (isOperator(token[0])) {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            values.push(applyOperation(a, b, token[0]));
        }
    }

    return values.top();
}

void SimpleCalculator::calculate(const string& infix) {
    try {
        cout << "Input infix expression: " << infix << endl;
        string postfix = infixToPostfix(infix);
        cout << "Postfix: " << postfix << endl;
        double result = evaluatePostfix(postfix);
        cout << "Result: " << result << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}
