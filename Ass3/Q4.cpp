#include <iostream>
#include <string>
#include <stack>

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

bool isOperator(char c) {
    return precedence(c) > 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix = "";
    std::stack<char> s;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            }
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    std::string infix;
    std::cout << "Enter an infix expression: ";
    std::cin >> infix;
    std::cout << "Postfix expression: " << infixToPostfix(infix) << "\n";
    return 0;
}
