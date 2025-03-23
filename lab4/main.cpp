// Файл main.cpp
#include <iostream>
#include "Stack.h"  // Теперь заголовок находится в директории stack

int main() {
    int number = 3960;
    MyStack<int> stack;
    
    // Разложение числа на простые множители
    Multipliers(number, stack);
    
    // Печать множителей по убыванию (как они были добавлены в стек)
    std::cout << number << "=";
    MyStack<int> tempStack = stack; // Создаем копию для первого вывода
    
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
    
    // Печать множителей по возрастанию (обратный порядок)
    std::cout << number << "=";
    
    // Перекладываем элементы из первого стека во временный стек
    // для вывода в обратном порядке
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