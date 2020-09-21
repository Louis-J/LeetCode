#include <iostream>

int main() {
    unsigned int n;
    std::cin >> n;
    unsigned int a = n / 100;
    unsigned int b = n / 10 % 10;
    unsigned int c = n % 10;
    a = a*a*a;
    b = b*b*b;
    c = c*c*c;

    std::cout << (a+b+c == n ? "TRUE" : "FALSE");
    return 0;
}