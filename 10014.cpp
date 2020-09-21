#include <iostream>

template<typename CmpFuncType>
size_t getBoarder(unsigned int arr[], unsigned int n, unsigned int target, CmpFuncType CmpFunc) {
    size_t l = 0, r = n-1;
    while(r-l > 1) {
        unsigned int mid = (l+r)/2;
        if(CmpFunc(arr[mid], target))
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main() {
    unsigned int n, target;
    std::cin >> n;
    unsigned int arr[n];
    for(auto &i : arr)
        std::cin >> i;
    std::cin >> target;
    
    std::cout << getBoarder(arr, n, target, std::less_equal<unsigned int>()) - getBoarder(arr, n, target, std::less<unsigned int>());
    return 0;
}