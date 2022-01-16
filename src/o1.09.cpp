#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class CQueue {
    stack<int> stkHead, stkTail;
    bool isHead = false;

    void toHead() {
        isHead = true;
        for(;!stkTail.empty();stkTail.pop())
            stkHead.emplace(stkTail.top());
    }

    void toTail() {
        isHead = false;
        for(;!stkHead.empty();stkHead.pop())
            stkTail.emplace(stkHead.top());
    }
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        if(!isHead)
            toHead();
        stkHead.emplace(value);
    }
    
    int deleteHead() {
        if(isHead)
            toTail();
        if(stkTail.empty())
            return -1;
        int ret = stkTail.top();
        stkTail.pop();
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        CQueue obj;
        obj.appendTail(3);
        cout << obj.deleteHead() << endl;
        cout << obj.deleteHead() << endl;
    }
    cout << " 2:" << endl;
    {
        CQueue obj;
        cout << obj.deleteHead() << endl;
        obj.appendTail(5);
        obj.appendTail(2);
        cout << obj.deleteHead() << endl;
        cout << obj.deleteHead() << endl;
    }
    return 0;
}
#endif