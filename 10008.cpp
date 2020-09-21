#include <iostream>
#include <algorithm>

int main() {
    size_t n;
    std::cin >> n;
    size_t arr[n];
    for(auto &i : arr)
        std::cin >> i;
    // std::sort(arr, arr+n, std::greater<size_t>());
    std::sort(arr, arr+n);
    size_t now = 0, sum = 0;
    for(auto &i : arr) {
        sum += now;
        now += i;
    }
    std::cout << sum;
    return 0;
}