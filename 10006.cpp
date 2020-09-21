#include <iostream>
#include <algorithm>
#include <iomanip>

using u32 = unsigned long;
using u16 = unsigned short;
class ID {
    char str[19];
    u32 date;
public:
    friend std::istream &operator>>(std::istream &istr, ID &i) {
        istr >> i.str;
        u16 y = (i.str[6]-'0')*1000 + (i.str[7]-'0')*100 + (i.str[8]-'0')*10 + (i.str[9]-'0');
        u16 m = (i.str[10]-'0')*10 + (i.str[11]-'0');
        u16 d = (i.str[12]-'0')*10 + (i.str[13]-'0');
        i.date = y*10000 + m*100 + d;
        // std::cout << y << '-' << m << '-' << d << '\n';
        return istr;
    }
    void printStrln(std::ostream &ostr) {
        ostr << str << '\n';
    }
    void printDateln(std::ostream &ostr) {
        u16 y = date/10000;
        u16 m = date/100%100;
        u16 d = date%100;
        ostr << y << '-' << std::setw(2) << m << '-' << std::setw(2) << d << '\n';
    }
    friend bool operator<(ID &a, ID &b) {
        return a.date < b.date;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::internal << std::setfill('0');
    size_t n;
    std::cin >> n;
    ID ids[n];
    for(size_t i = 0; i < n; i++)
        std::cin >> ids[i];
    std::sort(ids, ids+n);

    std::string op;
    while(true) {
        std::cin >> op;
        if(op == "sort1")
            for(auto &i : ids)
                i.printDateln(std::cout);
        else if(op == "sort2")
            for(auto &i : ids)
                i.printStrln(std::cout);
        else {
            std::cout << "exit";
            return 0;
        }
    }
    return 0;
}