#include <iostream>
#include "Stack.h"

int main() {
    int number = 3960;
    MyStack<int> stack;

    Multipliers(number, stack);

    std::cout << number << "=";
    MyStack<int> tempStack = stack;

    bool first = true;
    while (!tempStack.empty()) {
        if (!first) {
            std::cout << " * ";
        } else {
            first = false;
        }
        std::cout << tempStack.top_inf();
        tempStack.pop();
    }
    std::cout << std::endl;

    std::cout << number << "=";

    MyStack<int> reverseStack;
    while (!stack.empty()) {
        reverseStack.push(stack.top_inf());
        stack.pop();
    }

    first = true;
    while (!reverseStack.empty()) {
        if (!first) {
            std::cout << " * ";
        } else {
            first = false;
        }
        std::cout << reverseStack.top_inf();
        reverseStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
