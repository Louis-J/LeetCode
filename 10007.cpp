#include <iostream>

using s64 = long long;
// 优先级:
// 0:遍历计算直到\n
// 1:遍历计算直到)
// 2:只计算*/
int Calc(size_t priority) {
    s64 num = 0;
    switch(priority) {
        case 0:
        case 1: {
            // std::cout << "db0\n";
            if(std::cin.peek() == '(') {
                std::cin.ignore();
                num = Calc(1);
            } else {
                std::cin >> num;
            }
            // std::cout << "db1\n";
            while(true) {
                // std::cout << "db2 " << std::cin.peek() << char(std::cin.peek()) << '\n';
                switch(std::cin.get()) {
                    case '*': {
                        s64 opNum;
                        if(std::cin.peek() == '(') {
                            std::cin.ignore();
                            opNum = Calc(1);
                        } else {
                            std::cin >> opNum;
                        }
                        num *= opNum;
                    } break;
                    case '/': {
                        s64 opNum;
                        if(std::cin.peek() == '(') {
                            std::cin.ignore();
                            opNum = Calc(1);
                        } else {
                            std::cin >> opNum;
                        }
                        num /= opNum;
                    } break;
                    case '+': {
                        s64 opNum = Calc(2);
                        num += opNum;
                    } break;
                    case '-': {
                        s64 opNum = Calc(2);
                        num -= opNum;
                    } break;
                    case ')':
                        return num;
                    case '\0':
                    case '\r':
                    case '\n':
                        std::cin.unget();
                        return num;
                    case -1: //OJ系统会eof返回-1
                        return num;
                }
            }
        }
        case 2: {
            // std::cout << "db3\n";
            if(std::cin.peek() == '(') {
                std::cin.ignore();
                num = Calc(1);
            } else {
                std::cin >> num;
            }
            // std::cout << "db4\n";
            while(true) {
                // std::cout << "db5 " << std::cin.peek() << char(std::cin.peek()) << '\n';
                switch(std::cin.get()) {
                    case '*': {
                        s64 opNum;
                        if(std::cin.peek() == '(') {
                            std::cin.ignore();
                            opNum = Calc(1);
                        } else {
                            std::cin >> opNum;
                        }
                        num *= opNum;
                    } break;
                    case '/': {
                        s64 opNum;
                        if(std::cin.peek() == '(') {
                            std::cin.ignore();
                            opNum = Calc(1);
                        } else {
                            std::cin >> opNum;
                        }
                        num /= opNum;
                    } break;
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
    }
}

int main() {
    std::cout << Calc(0);
    return 0;
}