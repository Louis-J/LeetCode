#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class MinStack {
    vector<pair<int, int>> stk;

public:
    void push(int val) {
        if(stk.size() == 0)
            stk.emplace_back(val, val);
        else
            stk.emplace_back(val, min(stk.back().second, val));
    }

    void pop() { stk.pop_back(); }

    int top() { return stk.back().first; }

    int getMin() { return stk.back().second; }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        MinStack minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        cout << minStack.getMin() << endl;  //返回 -3.
        minStack.pop();
        cout << minStack.top() << endl;     //返回 0.
        cout << minStack.getMin() << endl;  //返回 -2.
    }
    return 0;
}
#endif