// 此法错误！
// #include <iostream>
// #include <string>

// using std::string;
// int main() {
//     string str;
//     std::cin >> str;
//     std::cout << (str.compare(string(str.rbegin(), str.rend())) == 0 ? "True" : "False");
//     return 0;
// }

#include <iostream>
#include <string>

using std::string;
int main() {
    long long n;
    std::cin >> n;
    string str = std::to_string(n);
    std::cout << (str.compare(string(str.rbegin(), str.rend())) == 0 ? "True" : "False");
    return 0;
}