#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using std::vector;

size_t FindKImpl(vector<size_t> &arr, size_t b, size_t e, size_t K) {
    auto CmpFunc = std::less<size_t>();
    switch(e-b) {
        case 3: {
            if(!CmpFunc(arr[b], arr[b+1]))
                std::swap(arr[b], arr[b+1]);
            if(!CmpFunc(arr[b+1], arr[b+2]))
                std::swap(arr[b+1], arr[b+2]);
            if(!CmpFunc(arr[b], arr[b+1]))
                std::swap(arr[b], arr[b+1]);
            return arr[K];
        }
        case 2: {
            if(CmpFunc(arr[b+1], arr[b]))
                std::swap(arr[b], arr[b+1]);
            return arr[K];
        }
        case 1: return arr[K];
        default: {
            size_t midNum = arr[(b+e)/2];
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
            if(K == l)
                return arr[K];
            else if(K < l)
                return FindKImpl(arr, b, l, K);
            else
                return FindKImpl(arr, r+1, e, K);
        }
    }
}

// template<typename CmpFunc = std::less<size_t>>
size_t FindK(vector<size_t> &arr, size_t K) {
    return FindKImpl(arr, 0, arr.size(), K);
}

int main() {
    std::ios::sync_with_stdio(false); //C++的输入输出流设计不好，尤其同步后对性能影响很大
    // auto t_start = std::chrono::high_resolution_clock::now();
    size_t N, M, K;
    std::cin >> N >> M >> K;

    size_t numAll = N+M;
    vector<size_t> arr;
    arr.reserve(numAll);
    while(numAll--) {
        size_t i;
        std::cin >> i;
        arr.emplace_back(i);
    }
    std::cout << FindK(arr, K-1);

    // auto t_end = std::chrono::high_resolution_clock::now();
    // std::cout << '\n' << std::chrono::duration<double, std::milli>(t_end-t_start).count() << "ms\n";
    return 0;
}
