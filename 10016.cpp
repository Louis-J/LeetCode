#include <iostream>

int main() {
    int n;
    std::cin >> n;
    size_t arr[n+1] = {1, 1};
    for(auto i = 2; i <= n; i++)
        arr[i] = arr[i-1] + arr[i-2];
    std::cout << arr[n];
    return 0;
}
