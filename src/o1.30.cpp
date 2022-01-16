#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class MinStack {
    stack<pair<int, int>> stk;  // value, minValue
public:
    void push(int x) {
        if(stk.empty())
            stk.emplace(x, x);
        else
            stk.emplace(x, std::min(stk.top().second, x));
    }

    void pop() {
        if(!stk.empty()) stk.pop();
    }

    int top() { return stk.top().first; }

    int min() { return stk.top().second; }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        MinStack minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        cout << minStack.min() << endl;
        minStack.pop();
        cout << minStack.top() << endl;
        cout << minStack.min() << endl;
    }
    cout << " 2:" << endl;
    {
    }
    return 0;
}
#endif