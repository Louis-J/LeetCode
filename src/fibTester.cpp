#include <iostream>
#include <vector>
#include <ctime>

using namespace::std;

clock_t timeStart, timeEnd;
int timeTotal;

int fibFunc0a(int n) {
    if(n <= 2)
        return 1;
    return fibFunc0a(n - 1) + fibFunc0a(n - 2);
}

int fibFunc0b(int n) {
    if(n == 1 || n == 2)
        return 1;
    return fibFunc0b(n - 1) + fibFunc0b(n - 2);
}

class IFibFunc1a {
public:
    int execute(int n) {
        if(n <= 2)
            return 1;
        return execute(n - 1) + execute(n - 2);
    }
};

class IFibFunc1b {
public:
    int execute(int n) {
        if(n == 1 || n == 2)
            return 1;
        return execute(n - 1) + execute(n - 2);
    }
};
using FibFuncType = int(*)(int n);
FibFuncType fibFunc2a, fibFunc2b;
FibFuncType fibFunc3a[1], fibFunc3b[1];
vector<FibFuncType> fibFunc4a, fibFunc4b;

class Node {
public:
    virtual ~Node() {}
};

class IntNode {
public:
    virtual int execute(int param[]) const = 0;
    virtual ~IntNode() {};
};

class BoolNode :public Node {
public:
    virtual bool execute(int param[]) const = 0;
    virtual ~BoolNode() {};
};

class LitNode :public IntNode {
    const int litNum;
public:
    LitNode(int litNum):litNum(litNum) {}
    virtual ~LitNode() {}
    virtual int execute(int param[]) const {
        return litNum;
    }
};

class IfNode :public IntNode {
    const BoolNode *condition;
    const IntNode *stateTrue;
    const IntNode *stateFalse;
public:
    IfNode(BoolNode *condition, IntNode *stateTrue, IntNode *stateFalse)
        :condition(condition), stateTrue(stateTrue), stateFalse(stateFalse) {}
    virtual ~IfNode() {}
    virtual int execute(int param[]) const {
        if(condition->execute(param))
            return stateTrue->execute(param);
        else
            return stateFalse->execute(param);
    }
};

class EqualNode :public BoolNode {
    const IntNode *valueNode;
    const IntNode *litNode;
public:
    EqualNode(IntNode *valueNode, IntNode *litNode):valueNode(valueNode), litNode(litNode) {}
    virtual ~EqualNode() {}
    virtual bool execute(int param[]) const {
        return valueNode->execute(param) == litNode->execute(param);
    }
};

class LessEqualNode :public BoolNode {
    const IntNode *valueNode;
    const IntNode *litNode;
public:
    LessEqualNode(IntNode *valueNode, IntNode *litNode):valueNode(valueNode), litNode(litNode) {}
    virtual ~LessEqualNode() {}
    virtual bool execute(int param[]) const {
        return valueNode->execute(param) <= litNode->execute(param);
    }
};

class AndNode :public BoolNode {
    const BoolNode *condition1;
    const BoolNode *condition2;
public:
    AndNode(BoolNode *condition1, BoolNode *condition2):condition1(condition1), condition2(condition2) {}
    virtual ~AndNode() {}
    virtual bool execute(int param[]) const {
        return condition1->execute(param) && condition2->execute(param);
    }
};

class OrNode :public BoolNode {
    const BoolNode *condition1;
    const BoolNode *condition2;
public:
    OrNode(BoolNode *condition1, BoolNode *condition2):condition1(condition1), condition2(condition2) {}
    virtual ~OrNode() {}
    virtual bool execute(int param[]) const {
        return condition1->execute(param) || condition2->execute(param);
    }
};

class MinusNode :public IntNode {
    const IntNode *valueNode1;
    const IntNode *valueNode2;
public:
    MinusNode(IntNode *valueNode1, IntNode *valueNode2):valueNode1(valueNode1), valueNode2(valueNode2) {}
    virtual ~MinusNode() {}
    virtual int execute(int param[]) const {
        return valueNode1->execute(param) - valueNode2->execute(param);
    }
};

class PlusNode :public IntNode {
    const IntNode *valueNode1;
    const IntNode *valueNode2;
public:
    PlusNode(IntNode *valueNode1, IntNode *valueNode2):valueNode1(valueNode1), valueNode2(valueNode2) {}
    virtual ~PlusNode() {}
    virtual int execute(int param[]) const {
        return valueNode1->execute(param) + valueNode2->execute(param);
    }
};

class ValueNode :public IntNode {
public:
    virtual ~ValueNode() {}
    virtual int execute(int param[]) const {
        return param[0];
    }
};

class InvokeNode :public IntNode {
    IntNode *funcNode;
    const IntNode **paramNodes;
    const int paramLen;
public:
    InvokeNode(const IntNode **paramNodes, int paramLen):paramNodes(paramNodes), paramLen(paramLen) {}
    virtual ~InvokeNode() {}
    void setFunc(IntNode *funcNode) {
        this->funcNode = funcNode;
    }
    virtual int execute(int param[]) const {
        int newParam[paramLen];
        for(int i = 0; i < paramLen; i++) {
            newParam[i] = paramNodes[i]->execute(param);
        }
        return funcNode->execute(newParam);
    }
};

int main() {
    {
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc0a(35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time0a: " << timeTotal << "ms\n";
    }
    {
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc0b(35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time0b: " << timeTotal << "ms\n";
    }
    {
        auto fibFunc1a = IFibFunc1a();
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc1a.execute(35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time1a: " << timeTotal << "ms\n";
    }
    {
        auto fibFunc1b = IFibFunc1b();
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc1b.execute(35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time1b: " << timeTotal << "ms\n";
    }
    {
        fibFunc2a = [](int n) {
            if(n <= 2)
                return 1;
            return fibFunc2a(n - 1) + fibFunc2a(n - 2);
        };
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc2a(35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time2a: " << timeTotal << "ms\n";
    }
    {
        fibFunc2b = [](int n) {
            if(n == 1 || n == 2)
                return 1;
            return fibFunc2b(n - 1) + fibFunc2b(n - 2);
        };
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc2b(35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time2b: " << timeTotal << "ms\n";
    }
    {
        fibFunc3a[0] = [](int n) {
            if(n <= 2)
                return 1;
            return fibFunc3a[0](n - 1) + fibFunc3a[0](n - 2);
        };
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc3a[0](35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time3a: " << timeTotal << "ms\n";
    }
    {
        fibFunc3b[0] = [](int n) {
            if(n == 1 || n == 2)
                return 1;
            return fibFunc3b[0](n - 1) + fibFunc3b[0](n - 2);
        };
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc3b[0](35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time3b: " << timeTotal << "ms\n";
    }
    {
        fibFunc4a.emplace_back([](int n) {
            if(n <= 2)
                return 1;
            return fibFunc4a[0](n - 1) + fibFunc4a[0](n - 2);
        });
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc4a[0](35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time4a: " << timeTotal << "ms\n";
    }
    {
        fibFunc4b.emplace_back([](int n) {
            if(n == 1 || n == 2)
                return 1;
            return fibFunc4b[0](n - 1) + fibFunc4b[0](n - 2);
        });
        timeStart = clock();
        for (int i = 0; i < 5; i++) {
            cout << fibFunc4b[0](35) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time4b: " << timeTotal << "ms\n";
    }
    {
        auto lit1 = new LitNode(1);
        auto lit2 = new LitNode(2);
        auto valueNode = new ValueNode();
        auto invoke1 = new InvokeNode(new const IntNode*[]{new MinusNode(valueNode, lit1)}, 1);
        auto invoke2 = new InvokeNode(new const IntNode*[]{new MinusNode(valueNode, lit2)}, 1);
        auto fibFunc5 = new IfNode(
            new LessEqualNode(valueNode, lit2),
            lit1,
            new PlusNode(invoke1, invoke2)
        );
        invoke1->setFunc(fibFunc5);
        invoke2->setFunc(fibFunc5);
        
        timeStart = clock();
        int param[]{35};
        for (int i = 0; i < 5; i++) {
            cout << fibFunc5->execute(param) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time5a: " << timeTotal << "ms\n";
    }
    {
        auto lit1 = new LitNode(1);
        auto lit2 = new LitNode(2);
        auto valueNode = new ValueNode();
        auto invoke1 = new InvokeNode(new const IntNode*[]{new MinusNode(valueNode, lit1)}, 1);
        auto invoke2 = new InvokeNode(new const IntNode*[]{new MinusNode(valueNode, lit2)}, 1);
        auto fibFunc5 = new IfNode(
            new OrNode(new EqualNode(valueNode, lit1), new EqualNode(valueNode, lit2)),
            lit1,
            new PlusNode(invoke1, invoke2)
        );
        invoke1->setFunc(fibFunc5);
        invoke2->setFunc(fibFunc5);
        
        timeStart = clock();
        int param[]{35};
        for (int i = 0; i < 5; i++) {
            cout << fibFunc5->execute(param) << endl;
        }
        timeEnd = clock();
        timeTotal = (timeEnd - timeStart) * 1000 / CLOCKS_PER_SEC;
        cout << "total time5b: " << timeTotal << "ms\n";
    }
}

// python:
// from time import time

// def fiba(n):
//     if n <= 2:
//         return 1
//     return fiba(n - 1) + fiba(n - 2)

// def fibb(n):
//     if n == 1 or n == 2:
//         return 1
//     return fibb(n - 1) + fibb(n - 2)

// def testa():
//     i = 0
//     timeNow = time()
//     while i < 5:
//         print(fiba(35))
//         i += 1
//     print("time: " + str(int((time() - timeNow)*1000)) + "ms")

// def testb():
//     i = 0
//     timeNow = time()
//     while i < 5:
//         print(fibb(35))
//         i += 1
//     print("time: " + str(int((time() - timeNow)*1000)) + "ms")

// testa()
// testb()

// lua:
// function fib(n)
//     if n <= 2 then
//         return 1
//     else
//         return fib(n-1) + fib(n-2)
//     end
// end
// function timeTest()
//     local start = os.time()
//     for i = 0,4 do
//         print(fib(35))
//     end
//     print(string.format("time: %fms", (os.time() - start)))
// end

// ipy:
// 10141, 11354

// cpy:
// 7843, 8773

// graal py:
// 915, 996

// graal sl:
// 1481, 1533

// graal js:
// 468, 500

// graalvm(java) static func:
// 150, 152

// graalvm(java) class member func:
// 150, 155

// graalvm(java) class func List:
// 252, 259

// g++ 20-g3 static func:
// 67, 77

// g++ 20-g3 class member func:
// 68, 78

// g++ 20-g3 class func pointer:
// 143, 171

// g++ 20-g3 class func pointer array:
// 138, 152

// g++ 20-g3 class func pointer vector:
// 158, 155

// g++ 20-g3 class interpreter:
// 1649, 2140
