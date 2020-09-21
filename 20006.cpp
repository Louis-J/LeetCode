#include <iostream>
#include <algorithm>

// 效率差
int main0() {
    std::ios_base::sync_with_stdio(false);
    size_t n;
    std::cin >> n;
    int arr[n];

    size_t sum = 0;
    for(size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
        arr[i] %= 7;
        arr[i] = (arr[i] + 7) % 7;
        sum += arr[i];
    }
    size_t need[n+1];//正着数
    size_t have[n+1];//反着数
    
    need[0] = sum % 7;
    have[0] = 0;
    for(size_t i = 1; i <= n; i++) {
        need[i] = (need[i-1] + 7 - arr[i-1]) % 7;
        have[i] = (have[i-1] + 7 + arr[n-i]) % 7;
    }

    size_t maxLen = 0;
    for(size_t i = 0; i < n-maxLen; i++) {
        int j = std::find(have, have + n - i, need[i]) - have;
        if(j != -1 && j != n - i && n-i-j > maxLen)
            maxLen = n-i-j;
    }
    std::cout << maxLen;

    
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n;
    std::cin >> n;
    int arr[n];

    size_t sum = 0;
    for(size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
        arr[i] %= 7;
        arr[i] = (arr[i] + 7) % 7;
        sum += arr[i];
    }

    size_t needTable[7] = {0};  //从1开始数
    size_t haveTable[7] = {0};  //从1开始数
    
    size_t need = sum % 7;  //正着数
    size_t have = 0;        //反着数

    needTable[need] = 1;
    haveTable[have] = 1;
    for(size_t i = 1; i <= n; i++) {
        need = (need + 7 - arr[i-1]) % 7;
        have = (have + 7 + arr[n-i]) % 7;
        if(needTable[need] == 0)
            needTable[need] = i+1;
        if(haveTable[have] == 0)
            haveTable[have] = i+1;
    }

    size_t maxLen = 0;
    for(size_t i = 0; i < 7; i++) {
        if(needTable[i] != 0 && haveTable[i] != 0 && n + 2 - needTable[i] - haveTable[i] > maxLen)
            maxLen = n + 2 - needTable[i] - haveTable[i];
    }
    std::cout << maxLen;

    
    return 0;
}