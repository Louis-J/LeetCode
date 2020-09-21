#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n;
    std::cin >> n;
    int vMin;
    std::cin >> vMin;
    int maxDiff = -1000;
    while(--n) {
        int vTemp;
        std::cin >> vTemp;
        maxDiff = std::max(maxDiff, vTemp-vMin);
        vMin = std::min(vMin, vTemp);
    }
    std::cout << maxDiff;
    return 0;
}
