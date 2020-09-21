#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    for(size_t n, b, e; std::cin >> n >> b >> e;) {
        size_t fromNum = 0, fromLen = 0, digitNum = 1;
        size_t nextNum = 10, nextLen = digitNum*nextNum;
        for(;nextLen < b; digitNum++, nextNum*=10, nextLen += digitNum*(nextNum-fromNum)) {
            fromLen = nextLen;
            fromNum = nextNum;
        }
        size_t nums = (b + digitNum - 1 - fromLen)/digitNum;
        fromNum += nums;
        fromLen += digitNum*nums;

        if(fromLen - b != 0) {
            std::string str = std::to_string(fromNum-1);
            std::cout << std::to_string(fromNum-1).substr(str.size() - (fromLen - b));
        }

        while(e-fromLen > digitNum) {
            std::cout << fromNum;
            fromLen += digitNum;
            if(++fromNum == nextNum) {
                nextNum*=10;
                digitNum++;
                nextLen += digitNum*nextNum;
            }
        }
        if(e-fromLen != 0)
            std::cout << std::to_string(fromNum).substr(0, e-fromLen) << '\n';
    }
    return 0;
}
