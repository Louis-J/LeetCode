#include <iostream>

using s64 = long long;
// 优先级:
// 0:遍历计算直到\n或\-1
// 1:遍历计算直到)
// 2:只计算乘除
// 3:只获取下一个数字
s64 Calc(size_t priority) {
    s64 num = 0;
    switch(priority) {
        case 0:
        case 1: {
            num = Calc(3);
            while(true) {
                switch(std::cin.get()) {
                    case '*': num *= Calc(3); break;
                    case '/': num /= Calc(3); break;
                    case '+': num += Calc(2); break;
                    case '-': num -= Calc(2); break;
                    case '\0':
                    case '\r':
                    case '\n':
                        std::cin.unget();
                        return num;
                    case -1: //OJ系统会eof返回-1
                    case ')':
                        return num;
                }
            }
        }
        case 2: {
            num = Calc(3);
            while(true) {
                switch(std::cin.get()) {
                    case '*': num *= Calc(3); break;
                    case '/': num /= Calc(3); break;
                    case '+':
                    case '-':
                    case ')':
                    case '\n':
                        std::cin.unget();
                        return num;
                    case -1: //OJ系统会eof返回-1
                        return num;
                }
            }
        }
        case 3: {
            if(std::cin.peek() == '(') {
                std::cin.ignore();
                num = Calc(1);
            } else {
                std::cin >> num;
            }
            return num;
        }
    }
}

int main() {
    std::cout << Calc(0);
    return 0;
}