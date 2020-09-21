#include <iostream>
#include <limits>
#include <cmath>

constexpr size_t BigNum = 200907;
// constexpr size_t U64Max = ULLONG_MAX;
constexpr auto U64Max = std::numeric_limits<unsigned long long>::max();

size_t EqualAdd(size_t begin, size_t add, size_t k) {
    if(add * k / k == add)
        return ((add * k % BigNum) + begin) % BigNum;
    else {
        size_t chu = U64Max/add, chuyu = add * chu % BigNum;
        return ((k / chu * chuyu % BigNum) + begin + (k % chu * add % BigNum)) % BigNum;
    }
}

size_t EqualPlus(size_t begin, size_t plus, size_t k) {
    if(std::log10(U64Max) / std::log10(plus) > k) {
        size_t n = 1;
        for(auto i = 0; i < k; i++)
            n *= plus;
        return (n % BigNum) * begin % BigNum;
    }
    else {
        size_t chuyu = 1, chu = std::log10(U64Max) / std::log10(plus);
        for(auto i = 0; i < chu; i++)
            chuyu *= plus;
        chuyu %= BigNum;

        size_t kyu = 1;
        for(auto i = 0; i < k%chu; i++)
            kyu *= plus;
        kyu %= BigNum;
        return EqualPlus(begin, chuyu, k/chu) * kyu % BigNum;
    }
}

int main() {
    size_t T;
    std::cin >> T;

    while(T--) {
        size_t a, b, c, k;
        std::cin >> a >> b >> c >> k;
        if(a+c == b+b) {
            std::cout << EqualAdd(a % BigNum, (b - a) % BigNum, k-1) << '\n';
        } else {
            std::cout << EqualPlus(a % BigNum, (b / a) % BigNum, k-1) << '\n';
        }
    }
    return 0;
}
