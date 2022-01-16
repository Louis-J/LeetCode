#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    unordered_map<pair<int, int>, vector<string>> map;
    vector<string> AO(string &num, int e, int target, bool onlycc) {
        if(e == 1) {
            if(num[0]-'0' == target)
                return vector<string>{to_string(target)};
            else
                return vector<string>{};
        } else {
            int b = e-1;
            int plus = 1;
            int sum = (num[b]-'0');
            for(; b > 0; b--, plus*=10, sum += (num[b]-'0')*plus) {
                if(sum == '0')
                    if(b == 0 || num[b-1] != 0) {
                    
                    }
                else {
                    vector<string> ret;
                    if(target%sum == 0) {
                        auto r = AO(num, b, target/sum, );
                    }
                    AO(num, b, )
                }
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().addOperators("123", 6) << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().addOperators("232", 8) << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().addOperators("00", 0) << endl;
    }
    cout << " 4:" << endl;
    {
        cout << Solution().addOperators("3456237490", 9191) << endl;
    }
    return 0;
}
#endif