#include <iostream>
#include <string>

using std::string;
int main() {
    std::ios_base::sync_with_stdio(false);
    string str;
    size_t n;
    std::cin >> str >> n;
    std::cout << str.substr(n) << str.substr(0, n);
    return 0;
}