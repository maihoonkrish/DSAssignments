#include <iostream>
#include <queue>
using namespace std;

class Stack1Q {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (--size) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) cout << "Empty\n";
        else q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
};
