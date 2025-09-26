#include "ExpressionEvaluator.h"
#include "Stack.h"
#include <cctype>
#include <stdexcept>
#include <iostream>

bool ExpressionEvaluator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int ExpressionEvaluator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int ExpressionEvaluator::applyOperator(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        default: return 0;
    }
}

int ExpressionEvaluator::evaluate(const std::string& expr) {
    Stack<int> values(expr.size());
    Stack<char> ops(expr.size());

    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];

        if (isspace(c)) continue;

        if (isdigit(c)) {
            int num = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            values.push(num);
            i--; // 回退一格
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.isEmpty() && ops.peek() != '(') {
                int b = values.pop();
                int a = values.pop();
                char op = ops.pop();
                values.push(applyOperator(op, a, b));
            }
            if (!ops.isEmpty()) ops.pop(); // 弹出 '('
        }
        else if (isOperator(c)) {
            while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(c)) {
                int b = values.pop();
                int a = values.pop();
                char op = ops.pop();
                values.push(applyOperator(op, a, b));
            }
            ops.push(c);
        }
    }

    while (!ops.isEmpty()) {
        int b = values.pop();
        int a = values.pop();
        char op = ops.pop();
        values.push(applyOperator(op, a, b));
    }

    return values.pop();
}
