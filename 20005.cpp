#include <iostream>
#include <vector>
#include <map>

using u64 = unsigned long long;
using std::vector;
using std::map;
class FibCount {
    map<u64, size_t> valuesHave{{10001, 2}};
    vector<u64> values = {0, 1, 1};
    bool circled = false;
    size_t circleCount;
    size_t circleFrom;
public:
    u64 GetN(u64 n) {
        if(circled)
            return values[(n-circleFrom)%circleCount + circleFrom];
        for(size_t i = values.size(); i <= n; i++) {
            u64 next = (values[i-1] + values[i-2]) % 10000;
            u64 code = next*10000 + values[i-1];
            auto iter = valuesHave.find(code);
            if(iter != valuesHave.end()) {
                circled = true;
                circleFrom = iter->second;
                circleCount = i - circleFrom;
                return values[(n-circleFrom)%circleCount + circleFrom];
            }
            values.emplace_back(next);
            valuesHave.emplace(code, i);
        }
        return values[n];
    }
};

class FibCount2 {
    vector<u64> values = {0, 1, 1};
    constexpr static size_t circleCount = 15000;
    constexpr static size_t circleFrom = 2;
public:
    u64 GetN(u64 n) {
        size_t realN = (n-circleFrom)%circleCount + circleFrom;
        if(values.size() <= realN)
            for(size_t i = values.size(); i <= realN; i++) {
                u64 next = (values[i-1] + values[i-2]) % 10000;
                values.emplace_back(next);
            }
        return values[realN];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    FibCount2 fc;
    u64 n;
    for(std::cin >> n; n != -1; std::cin >> n) {
        std::cout << fc.GetN(n) << '\n';
    }
    return 0;
}
