#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using u8 = unsigned char;
class BigInt {
    vector<u8> digit;// 低位在前，高位在后，每位为0-9, 最少为1位
public:
    BigInt(size_t i = 0) {
        while(i != 0) {
            digit.emplace_back(i % 10);
            i /= 10;
        }
        if(digit.size() == 0)
            digit.emplace_back(0);
    }
    friend BigInt operator*(const BigInt &a, const BigInt &b) {
        if(a.digit.size() == 1 || b.digit.size() == 1) {
            if(a.digit.size() == 1) {
                if(a.digit[0] == 0)
                    return BigInt(0);
                else if(a.digit[0] == 1)
                    return BigInt(b);
            } else {
                if(b.digit[0] == 0)
                    return BigInt(0);
                else if(b.digit[0] == 1)
                    return BigInt(a);
            }
        }
        BigInt rlt;
        rlt.digit.resize(a.digit.size() + b.digit.size(), 0);
        for(size_t i = 0; i < a.digit.size(); i++) {
            for(size_t j = 0; j < b.digit.size(); j++) {
                rlt.digit[i+j] += a.digit[i] * b.digit[j];
                if(rlt.digit[i+j] >= 10) {
                    rlt.digit[i+j+1] += rlt.digit[i+j] / 10;
                    rlt.digit[i+j] %= 10;
                }
            }
        }
        if(rlt.digit[a.digit.size() + b.digit.size() - 1] == 0)
            rlt.digit.pop_back();
        return rlt;
    }
    friend std::istream &operator>>(std::istream &istr, BigInt &b) {
        string str;
        istr >> str;
        b.digit.clear();
        b.digit.reserve(str.size());
        for(auto i = str.rbegin(); i != str.rend(); i++) {
            b.digit.emplace_back(*i - '0');
        }
        size_t zeros = 0;
        for(auto i = b.digit.rbegin(); i != b.digit.rend() && *i == 0; i++)
            zeros++;
        b.digit.resize(b.digit.size() - zeros);
        return istr;
    }
    friend std::ostream &operator<<(std::ostream &ostr, BigInt &b) {
        string str;
        str.reserve(b.digit.size());
        for(auto i = b.digit.rbegin(); i != b.digit.rend(); i++) {
            str += *i + '0';
        }
        return ostr << str;
    }
    friend std::ostream &operator<<(std::ostream &ostr, BigInt &&b) {
        string str;
        str.reserve(b.digit.size());
        for(auto i = b.digit.rbegin(); i != b.digit.rend(); i++) {
            str += *i + '0';
        }
        return ostr << str;
    }
};
int main() {
    BigInt a, b;
    std::cin >> a >> b;
    std::cout << a * b;
    // std::cout << BigInt() << '\n' << a << '\n' << b << '\n' << a + b;
    return 0;
}