#include <iostream>
#include <algorithm>
#include <set>
using std::set;

void PrintN1Impl(char arr[], set<char> &hasno, size_t n) {
    if(hasno.size() == 0) {
        for(size_t i = 0; i < n; i++)
            std::cout << arr[i] << ' ';
        std::cout << '\n';
    } else {
        size_t now = n - hasno.size();
        auto i = hasno.begin();
        for(size_t j = hasno.size(); j; j--) {
            char temp = *i;
            hasno.erase(i);
            arr[now] = temp;
            PrintN1Impl(arr, hasno, n);
            i = hasno.emplace(temp).first;
            i++;
        }
    }
}
void PrintN1(size_t n) {
    char arr[n];
    set<char> hasno;
    for(size_t i = 0; i < n; i++)
        hasno.emplace(n + '0' - i);
    PrintN1Impl(arr, hasno, n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n;
    std::cin >> n;
    PrintN1(n);
    return 0;
}