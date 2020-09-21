#include <iostream>
#include <algorithm>

using std::pair;
using PUU = pair<size_t, size_t>;
int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n;
    std::cin >> n;
    PUU arr[n];
    for(size_t i = 0; i < n; i++)
        std::cin >> arr[i].first >> arr[i].second;
    std::stable_sort(arr, arr+n, [](const PUU &a, const PUU &b) {return a.first < b.first;});
    size_t timeNow = 1;
    for(size_t i = 0; i < n; i++)
        if(timeNow < arr[i].first)
            timeNow = arr[i].second;
        else
            timeNow += arr[i].second - arr[i].first + 1;
    std::cout << timeNow - 1;
    return 0;
}