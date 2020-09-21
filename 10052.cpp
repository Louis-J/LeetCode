#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using u8 = unsigned char;
class BigInt {
    vector<u8> digit;
public:
    friend BigInt operator+(BigInt &a, BigInt &b) {
        u8 overflow = 0;
        BigInt rlt;
        rlt.digit.reserve(std::min(a.digit.size(), b.digit.size()) + 1);
        for(size_t i = 0; i < std::min(a.digit.size(), b.digit.size()); i++) {
            overflow += a.digit[i] - '0' + b.digit[i] - '0';
            rlt.digit.emplace_back(overflow % 10 + '0');
            overflow /= 10;
        }
        if(a.digit.size() > b.digit.size())
            for(size_t i = b.digit.size(); i < a.digit.size(); i++) {
                overflow += a.digit[i] - '0';
                rlt.digit.emplace_back(overflow % 10 + '0');
                overflow /= 10;
            }
        else if(b.digit.size() > a.digit.size())
            for(size_t i = a.digit.size(); i < b.digit.size(); i++) {
                overflow += b.digit[i] - '0';
                rlt.digit.emplace_back(overflow % 10 + '0');
                overflow /= 10;
            }
        if(overflow == 1)
            rlt.digit.emplace_back('1');
        return rlt;
    }
    friend std::istream &operator>>(std::istream &istr, BigInt &b) {
        string str;
        istr >> str;
        b.digit.clear();
        b.digit.insert(b.digit.end(), str.rbegin(), str.rend());
        size_t zeros = 0;
        for(auto i = b.digit.rbegin(); i != b.digit.rend() && *i == '0'; i++)
            zeros++;
        b.digit.resize(b.digit.size() - zeros);
        return istr;
    }
    friend std::ostream &operator<<(std::ostream &ostr, BigInt &b) {
        if(b.digit.size() == 0)
            return ostr << '0';
        else
            return ostr << string(b.digit.rbegin(), b.digit.rend());
    }
    friend std::ostream &operator<<(std::ostream &ostr, BigInt &&b) {
        if(b.digit.size() == 0)
            return ostr << '0';
        else
            return ostr << string(b.digit.rbegin(), b.digit.rend());
    }
};
int main() {
    BigInt a, b;
    std::cin >> a >> b;
    std::cout << a + b;
    // std::cout << BigInt() << '\n' << a << '\n' << b << '\n' << a + b;
    return 0;
}