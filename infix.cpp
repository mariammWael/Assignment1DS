// #include <iostream>
// #include <string>
// #include <cctype>
// #include "Stackt.h"
//I used the Shunting Yard Algorithim which involves seperating the characters from the operators
//cred: https://brilliant.org/wiki/shunting-yard-algorithm/
// // Function to determine precedence of operators
// int precedence(char op) {
//     if (op == '+' || op == '-') return 1;
//     if (op == '*' || op == '/') return 2;
//     return 0;
// }
//
// // Function to perform arithmetic operations
// int applyOperation(int a, int b, char op) {
//     switch (op) {
//         case '+': return a + b;
//         case '-': return a - b;
//         case '*': return a * b;
//         case '/': return a / b;
//         default: return 0;
//     }
// }
//
// // Function to evaluate the expression
// int evaluateExpression(const std::string &expression) {
//     Stackt<int> values;
//     Stackt<char> ops;      // Stack to store operators
//
//     for (size_t i = 0; i < expression.length(); i++) {
//         // Skip spaces
//         if (isspace(expression[i]))
//             continue;
//
//         // Current character is a digit (handle multi-digit numbers)
//         if (isdigit(expression[i])) {
//             int value = 0;
//             // There may be more than one digit in the number
//             while (i < expression.length() && isdigit(expression[i])) {
//                 value = (value * 10) + (expression[i] - '0');
//                 i++;
//             }
//             values.push(value);
//             i--;  // Adjust for loop increment
//         }
//
//         // Current character is an operator
//         else if (expression[i] == '+' || expression[i] == '-' ||
//                  expression[i] == '*' || expression[i] == '/') {
//             // While the precedence of the current operator is less than or equal
//             // to the precedence of the operator on the top of the stack,
//             // apply the operator on top of the stack.
//             while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(expression[i])) {
//                 int val2 = values.pop();
//                 int val1 = values.pop();
//                 char op = ops.pop();
//                 values.push(applyOperation(val1, val2, op));
//             }
//
//             // Push current operator to 'ops'
//             ops.push(expression[i]);
//         }
//     }
//
//     // Entire expression has been parsed at this point, apply remaining ops
//     while (!ops.isEmpty()) {
//         int val2 = values.pop();
//         int val1 = values.pop();
//         char op = ops.pop();
//         values.push(applyOperation(val1, val2, op));
//     }
//
//     // Top of 'values' contains the result
//     return values.pop();
// }
//
// int main() {
//     std::string expression;
//     std::cout << "Enter an expression: ";
//     std::getline(std::cin, expression);
//
//     try {
//         int result = evaluateExpression(expression);
//         std::cout << "Result: " << result << std::endl;
//     } catch (const std::exception &e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
//
//     return 0;
// }
