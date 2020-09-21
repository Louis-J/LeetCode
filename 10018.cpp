#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using s64 = long long;
using std::vector;

void SortImpl(vector<s64> &arr, size_t b, size_t e) {
    auto CmpFunc = std::less<s64>();
    switch(e-b) {
        case 3: {
            if(!CmpFunc(arr[b], arr[b+1]))
                std::swap(arr[b], arr[b+1]);
            if(!CmpFunc(arr[b+1], arr[b+2]))
                std::swap(arr[b+1], arr[b+2]);
            if(!CmpFunc(arr[b], arr[b+1]))
                std::swap(arr[b], arr[b+1]);
            return;
        }
        case 2: {
            if(CmpFunc(arr[b+1], arr[b]))
                std::swap(arr[b], arr[b+1]);
            return;
        }
        case 1: return;
        case 0: return;
        default: {
            s64 midNum = arr[(b+e)/2];
            if(CmpFunc(midNum, arr[b]) + CmpFunc(midNum, arr[e-1]) != 1) { //midNum不是三者之中
                if(CmpFunc(midNum, arr[b])) { //midNum最小
                    if(!CmpFunc(arr[b], arr[e-1]))
                        std::swap(arr[b], arr[e-1]);
                    midNum = arr[b];
                } else { //midNum最大
                    if(CmpFunc(arr[b], arr[e-1]))
                        std::swap(arr[b], arr[e-1]);
                    midNum = arr[b];
                }
            } else {
                std::swap(arr[(b+e)/2], arr[b]);
                midNum = arr[b];
            }
            size_t l = b, r = e-1;
            while(l < r) {
                while(l < r && !CmpFunc(arr[r], midNum))
                    r--;
                if(l == r)
                    break;
                arr[l] = arr[r];
                // std::swap(arr[l], arr[r]);
                while(l < r && CmpFunc(arr[l], midNum))
                    l++;
                if(l == r)
                    break;
                arr[r] = arr[l];
                // std::swap(arr[l], arr[r]);
            }
            arr[l] = midNum;
            SortImpl(arr, b, l);
            SortImpl(arr, r+1, e);
        }
    }
}

// template<typename CmpFunc = std::less<s64>>
void Sort(vector<s64> &arr) {
    SortImpl(arr, 0, arr.size());
}

int main() {
    std::ios::sync_with_stdio(false); //C++的输入输出流设计不好，尤其同步后对性能影响很大
    // auto t_start = std::chrono::high_resolution_clock::now();
    size_t n;
    std::cin >> n;

    vector<s64> arr;
    arr.reserve(n);
    while(n--) {
        s64 i;
        std::cin >> i;
        arr.emplace_back(i);
    }
    // Sort(arr);
    std::sort(arr.begin(), arr.end());
    for(auto &i : arr)
        std::cout << i << ' ';

    // auto t_end = std::chrono::high_resolution_clock::now();
    // std::cout << '\n' << std::chrono::duration<double, std::milli>(t_end-t_start).count() << "ms\n";
    return 0;
}
