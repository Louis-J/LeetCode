#include <iostream>
#include <array>

//编译期进行计算
constexpr unsigned int f(const unsigned int n) {
    return n > 1 ? f(n - 1) * n : 1;
}

int main() {
    constexpr std::array<unsigned int, 10> dict {f(1), f(2), f(3), f(4), f(5), f(6), f(7), f(8), f(9), f(10)};
    unsigned int n;
    std::cin >> n;
    std::cout << dict[n - 1];
    return 0;
}