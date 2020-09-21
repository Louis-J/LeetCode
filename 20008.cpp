#include <iostream>

using u64 = unsigned long long;
constexpr u64 ModN = 1000000007;
/* O1复杂度
 * 思路:
 * 令S(n) = 矩阵:
 * Fn   Fn-1
 * Fn-1 Fn-1
 * 令M = 矩阵:
 * 1    1
 * 1    0
 * 则Sn = M*Sn-1 = M^(n-1)*S1 = M^n
 * 实际编写时经过优化
 */
class FibFriendCount {
    u64 a[64] = {1};
    u64 b[64] = {1};
    u64 c[64] = {1};
    u64 d[64] = {0};
public:
    FibFriendCount () {
        for(size_t i=1; i<64; i++) {
            a[i] = (a[i-1]*a[i-1]+b[i-1]*c[i-1]) % ModN;
            b[i] = (a[i-1]*b[i-1]+b[i-1]*d[i-1]) % ModN;
            c[i] = (c[i-1]*a[i-1]+d[i-1]*c[i-1]) % ModN;
            d[i] = (c[i-1]*b[i-1]+d[i-1]*d[i-1]) % ModN;
        }
    }
    u64 GetRet(u64 n) {
        if(n <= 1)
            return 1;
        u64 ra = 1, rb =0, mask=1;
        for(size_t i=0; i < 64; i++){
            if((n&mask)!=0) {
                u64 tempa = (ra*a[i]+rb*c[i]) % ModN;
                u64 tempb = (ra*b[i]+rb*d[i]) % ModN;
                ra = tempa;
                rb = tempb;
            }
            mask = mask <<1;
        }
        return ra*rb % ModN;
    }
};

size_t FastReadUnsigend() {
    size_t ret = 0;
    char c = std::getchar();
    for(; c < '0' || c > '9'; c = std::getchar()) {}
    for(; c >= '0' && c <= '9'; c = std::getchar())
        ret = ret * 10 + c - '0';
    return ret;
}
void FastPrintUnsigend(size_t u) {
    size_t digit;
    if(u*10/10 != u)
        digit = 1000000000000000000;
    else {
        digit = 1;
        while(digit < u)
            digit *= 10;
        digit /= 10;
    }
    for(;digit != 0; digit /= 10) {
        std::cout << char('0'+u/digit);
        u %= digit;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    FibFriendCount fc;
    for(u64 n; std::cin >> n;) {
        std::cout << fc.GetRet(n) << '\n';
    }
    return 0;
}
