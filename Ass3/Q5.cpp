#include <iostream>
#include <string>
#include <stack>

bool isOperand(char c) {
    return isdigit(c);
}

int evaluatePostfix(const std::string& postfix) {
    std::stack<int> s;
    for (char c : postfix) {
        if (isOperand(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch (c) {
                case '+':
                    s.push(val1 + val2);
                    break;
                case '-':
                    s.push(val1 - val2);
                    break;
                case '*':
                    s.push(val1 * val2);
                    break;
                case '/':
                    s.push(val1 / val2);
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    std::string postfix;
    std::cout << "Enter a postfix expression: ";
    std::cin >> postfix;
    std::cout << "Result: " << evaluatePostfix(postfix) << "\n";
    return 0;
}
