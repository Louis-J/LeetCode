// #include <iostream>
// #include <string>
// #include <vector>
// #include <locale>

// class Book {
//     static size_t priceAll;
//     // constexpr static std::string maohao("：");

//     std::wstring name;
//     size_t price;
// public:
//     friend std::wistream &operator>>(std::wistream &istr, Book &b) {
//         // const static std::string maohao("：");
//         // std::getline(istr, b.name, L'：');
//         std::getline(istr, b.name);
//         // istr.getline(b.name, L'：');
//         istr >> b.price;
//         std::wcout << b.name << '\n' << b.price << '\n';
//         priceAll += b.price;
//         return istr;
//         // return istr.ignore(1);
//     }
//     friend std::wostream &operator<<(std::wostream &ostr, Book &b) {
//         return ostr << b.name << b.price << '\n';
//     }
//     static size_t GetPriceAll() {
//         return priceAll;
//     }
// };
// size_t Book::priceAll = 0;

// int main() {
//     setlocale(LC_ALL, "C.UTF-8");
// 	std::locale china("chs");
// 	std::wcin.imbue(china);
// 	std::wcout.imbue(china);

//     std::vector<Book> books;
//     while(!std::cin.eof() && !std::cin.fail()) {
//         // Book temp;
//         // std::wcin >> temp;
//         std::wstring name;
//         // std::wcin >> name;
//         std::getline(std::wcin, name, L'：');
//         std::wcout << name;
//         // std::wcout << '!' << temp;
//         // books.emplace_back(temp);
//     }
//     std::cout << Book::GetPriceAll();
    
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <locale>

class Book {
    static size_t priceAll;
    // constexpr static std::string maohao("：");

    std::string name;
    size_t price;
public:
    Book(std::string str = {}, size_t p = 0): name(str), price(p) {
        priceAll += price;
    }
    static Book Read(std::string line) {
        size_t epos = line.find("：");
        // std::cout << line << '\n' << epos << '\n' << line.substr(0, epos) << '\n' << std::stoull(line.substr(epos + 2)) << '\n';
        return Book(line.substr(0, epos), std::stoull(line.substr(epos + 2)));
    }
    friend std::ostream &operator<<(std::ostream &ostr, Book &b) {
        return ostr << b.name << "：" << b.price << '\n';
    }
    static size_t GetPriceAll() {
        return priceAll;
    }
};
size_t Book::priceAll = 0;

int main() {
    std::vector<Book> books;

    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> infos;
    for(size_t i = -2, j = line.find("；"); i != std::string::npos; i = j, j = line.find("；", j + 1)) {
        infos.emplace_back(line.substr(i + 2, j - i));
    }
    for(auto &i : infos) {
        books.emplace_back(Book::Read(i));
    }
    for(auto &i : books) {
        std::cout << i;
    }
    std::cout << "总价格为" << Book::GetPriceAll();
    
    return 0;
}
// Java程序设计：34 ；Web程序设计： 56；JSP程序设计：20