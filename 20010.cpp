// 注意k == 0
// #include <iostream>

// using s64 = long long;
// int main() {
//     std::ios_base::sync_with_stdio(false);
//     size_t n, k;
//     std::cin >> n;
//     s64 arr1[n], arr2[n];
//     for(size_t i = 0; i < n; i++)
//         std::cin >> arr1[i];
//     std::cin >> k;
//     if(k == 0)
//         return 0;
//     s64 *arrOld = arr1, *arrNew = arr2;
//     for(size_t j = 1; j < k; j++) {
//         for(size_t i = 0; i < n - j; i++)
//             arrNew[i] = std::max(arrOld[i], arrOld[i+1]);
//         std::swap(arrOld, arrNew);
//     }
//     for(size_t i = 0; i < n - k; i++)
//         std::cout << arrOld[i] << ' ';
//     std::cout << arrOld[n - k];
//     return 0;
// }


#include <iostream>

using s64 = long long;
class CirQue {
    const size_t capacity;
    size_t num = 0;
    size_t start = 0;
    s64 *const que;
public:
    CirQue(size_t n): capacity(n), que(new s64[n]) {}
    ~CirQue() {delete[] que;}
    bool empty() {return num == 0;}
    s64 &front() {return que[start];}
    s64 &back() {return que[(start+num-1)%capacity];}
    void pop_front() {
        start = (start+1)%capacity;
        num--;
    }
    void pop_back() {
        num--;
        // num = (num+capacity-1)%capacity;
    }
    void push_back(s64 n) {
        que[(start+num)%capacity] = n;
        num++;
    }
};
int main() {
    size_t n;
    std::cin >> n;
    s64 arr[n];
    for(auto &i : arr)
        std::cin >> i;
    size_t k;
    std::cin >> k;
    if(k == 0)
        return 0;
    CirQue window(k);
    k--;
    for(size_t i = 0; i < k; i++) {
        while(!window.empty() && arr[window.back()] <= arr[i])
            window.pop_back();
        window.push_back(i);
    }
    
    for(size_t i = 0; i < n-k; i++) {
        if(window.front() < i)
            window.pop_front();
        while(!window.empty() && arr[window.back()] <= arr[i+k])
            window.pop_back();
        window.push_back(i+k);
        std::cout << arr[window.front()] << ' ';
    }
}
