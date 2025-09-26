#include "ExpressionEvaluator.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Input expression:" << std::endl;
    std::string expr;
    std::getline(std::cin, expr);

    ExpressionEvaluator evaluator;
    try {
        int result = evaluator.evaluate(expr);
        std::cout << "Output" << std::endl;
        std::cout << "=" << result << std::endl;
        std::cout << "End" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error evaluating expression: " << e.what() << std::endl;
    }

    return 0;
}
