#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <string>

/**
 * @brief 中缀表达式求值器
 */
class ExpressionEvaluator {
public:
    int evaluate(const std::string& expression);

private:
    bool isOperator(char c);
    int precedence(char op);
    int applyOperator(char op, int a, int b);
};

#endif // EXPRESSION_EVALUATOR_H
