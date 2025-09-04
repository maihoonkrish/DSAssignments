#include <iostream>
#include <string>
#include <stack>

bool areParenthesesBalanced(const std::string& expr) {
    std::stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    std::string expr;
    std::cout << "Enter an expression: ";
    std::cin >> expr;

    if (areParenthesesBalanced(expr)) {
        std::cout << "The expression has balanced parentheses.\n";
    } else {
        std::cout << "The expression does not have balanced parentheses.\n";
    }

    return 0;
}
