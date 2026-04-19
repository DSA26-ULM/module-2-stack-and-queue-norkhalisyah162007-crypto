#include "stack.h"
#include <iostream>
#include <string>
#include <stdexcept>
 
int main() {
    int n;
    std::cin >> n;
 
    Stack s;
    init(&s);
 
    for (int i = 0; i < n; i++) {
        std::string token;
        std::cin >> token;

        if (token == "+" || token == "-" || token == "*" || token == "/") {

            if (isEmpty(&s)) throw std::runtime_error("Not enough operands");
            int b = peek(&s); pop(&s);

            if (isEmpty(&s)) throw std::runtime_error("Not enough operands");
            int a = peek(&s); pop(&s);
 
            int result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else { // "/"
                if (b == 0) throw std::runtime_error("Division by zero");
                result = a / b;
            }

            push(&s, result);
        } else {
            push(&s, std::stoi(token));
        }
    }

    if (isEmpty(&s)) throw std::runtime_error("Empty expression");

    std::cout << peek(&s) << std::endl;
    return 0;
}