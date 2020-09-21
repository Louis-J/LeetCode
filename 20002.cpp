#include <iostream>

using s64 = long long;
using u64 = unsigned long long;
class Fraction {
    s64 numerator = 1;
    u64 denominator = 1;
    static s64 GetMaxL(u64 a, u64 b) {
        if(a < b)
            std::swap(a, b);
        while(a%b != 0) {
            a = a%b;
            std::swap(a, b);
        }
        return b;
    }
public:
    friend Fraction operator+(const Fraction &a, const Fraction &b) {
        Fraction rlt;
        u64 maxl = GetMaxL(a.denominator, b.denominator);
        u64 ap = b.denominator/maxl, bp = a.denominator/maxl;
        
        rlt.numerator = a.numerator*ap + b.numerator*bp;
        rlt.denominator = a.denominator*ap;

        if(rlt.numerator == 0)
            rlt.denominator = 1;
        else {
            s64 rmaxl = GetMaxL(std::abs(rlt.numerator), rlt.denominator);
            rlt.numerator /= rmaxl;
            rlt.denominator /= rmaxl;
        }
        return rlt;
    }
    friend Fraction operator-(const Fraction &a, const Fraction &b) {
        Fraction rlt;
        u64 maxl = GetMaxL(a.denominator, b.denominator);
        u64 ap = b.denominator/maxl, bp = a.denominator/maxl;
        
        rlt.numerator = a.numerator*ap - b.numerator*bp;
        rlt.denominator = a.denominator*ap;

        if(rlt.numerator == 0)
            rlt.denominator = 1;
        else {
            s64 rmaxl = GetMaxL(std::abs(rlt.numerator), rlt.denominator);
            rlt.numerator /= rmaxl;
            rlt.denominator /= rmaxl;
        }
        return rlt;
    }
    friend Fraction operator*(const Fraction &a, const Fraction &b) {
        Fraction rlt;
        rlt.numerator = a.numerator * b.numerator;
        rlt.denominator = a.denominator * b.denominator;

        if(rlt.numerator == 0)
            rlt.denominator = 1;
        else {
            s64 rmaxl = GetMaxL(std::abs(rlt.numerator), rlt.denominator);
            rlt.numerator /= rmaxl;
            rlt.denominator /= rmaxl;
        }
        return rlt;
    }
    friend std::istream &operator>>(std::istream &istr, Fraction &f) {
        char c;
        return istr >> f.numerator >> c >> f.denominator;
    }
    friend std::ostream &operator<<(std::ostream &ostr, Fraction &f) {
        if(f.denominator == 1)
            return ostr << f.numerator;
        else
            return ostr << f.numerator << '/' << f.denominator;
    }
    friend std::ostream &operator<<(std::ostream &ostr, Fraction &&f) {
        if(f.denominator == 1)
            return ostr << f.numerator;
        else
            return ostr << f.numerator << '/' << f.denominator;
    }
};

int main() {
    Fraction a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n' << a - b << '\n' << a * b;
    return 0;
}