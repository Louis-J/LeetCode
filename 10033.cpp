#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t vMin;
    std::cin >> vMin;
    size_t maxDiff = 0;
    for(size_t vTemp; std::cin >> vTemp;) {
        if(vTemp < vMin)
            vMin = vTemp;
        else
            maxDiff = std::max(maxDiff, vTemp-vMin);
    }
    std::cout << maxDiff;
    return 0;
}
