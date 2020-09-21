#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using u8 = unsigned char;
class BigNum {
    vector<u8> digit;// 低位在前，高位在后，每位为0-9, 最少为1位

    friend BigNum operator*(const BigNum &a, const int b) {
        BigInt rlt;
        rlt.digit.resize(a.digit.size() + 1, 0);
        u8 overflow = 0;
        for(size_t i = 0; i < a.digit.size(); i++) {
            overflow += a.digit[i] * b;
            rlt.digit.emplace_back(overflow % 10);
            overflow /= 10;
        }
        if(overflow != 0)
            rlt.digit.emplace_back(overflow);
        return rlt;
    }
    size_t getMinGreater(const BigNum bs[], size_t posi) {
        size_t bssize = bs[0].digit.size();
        size_t u = 8, d = 0;
        signed char overcmp[9] = {0};

        for(auto i = posi, j = bssize; u != d; i--, j--) {
            for(auto k = d; k <= u; k++) {
                if(overcmp[k] == 0) {
                    if()
                }
            }
        }
        if(a.size() != b.size())
            return a.size() < b.size();
        for(size_t i = a.size()-1; i > 0; i--) {
            if(a[i] != b[i])
                return a[i] < b[i];
        }
        return a[0] < b[0];;
    }
public:
    BigInt(size_t i = 0) {
        while(i != 0) {
            digit.emplace_back(i % 10);
            i /= 10;
        }
        if(digit.size() == 0)
            digit.emplace_back(0);
    }
    friend BigNum operator/(BigNum &a, BigNum &b) {
        BigNum bs[9] = {b, b*2, b*3, b*4, b*5, b*6, b*7, b*8, b*9};

        size_t bssize = bs[8].digit.size();
        for(auto &i : bs)
            i.resize(bssize, 0);

        u8 overflow = 0;
        BigNum rlt;
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
    friend std::istream &operator>>(std::istream &istr, BigNum &b) {
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
    string toString() {
        if(digit.size() == 0)
            return '0';
        else
            return string(digit.rbegin(), digit.rend());
    }
};
int main() {
    BigNum a, b;
    std::stringstream sstm;
    std::cin >> sstm >> b;
    sstm << string(20, '0');
    sstm >> a;
    string str = (a / b).toString();
    if(str.size() <= 20) {
        std::cout << "0." << string(20 - str.size(), '0') << str;
    } else {
        std::cout << str.substr(0, str.size() - 20) << '.' << str.substr(str.size() - 20);
    }
    // std::cout << BigNum() << '\n' << a << '\n' << b << '\n' << a + b;
    return 0;
}