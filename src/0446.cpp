#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        unordered_map<int, int> addnum{{3, 1}, {4, 3}, {5, 7}};
        int diff = A[1] - A[0];
        int cont = 2;
        int ret = 0;

        int mut = 1;
        int same = 1;
        for(int i = 2; i < A.size(); i++) {
            if(A[i]-A[i-1] == diff) {
                cont++;
                if(same != 1) {
                    mut *= same;
                    same = 1;
                }
            } else if(A[i] == A[i-1]) {
                same++;
            } else {
                if(cont >= 3) {
                    if(same != 1) {
                        mut *= same;
                        same = 1;
                    }
                    auto jt = addnum.find(cont);
                    if(jt == addnum.end()) {
                        int sum = (cont-1)*(cont-2)/2;
                        for(int j = 3, k, tmp = cont - (j-1)*2; tmp >= 1; j++, tmp = cont - (j-1)*2) {
                            sum += tmp;
                            for(k = 3, tmp = cont - (j-1)*k; tmp >= 1; k++, tmp = cont - (j-1)*k) {
                                sum += tmp;
                            }
                        }
                        ret += mut*sum;
                        addnum.emplace(cont, sum);
                    } else {
                        ret += mut*jt->second;
                    }
                    mut = 1;
                }
                diff = A[i]-A[i-1];
                cont = 2;
            }
        }
        if(cont >= 3) {
            auto jt = addnum.find(cont);
            if(jt == addnum.end()) {
                int sum = (cont-1)*(cont-2)/2;
                for(int j = 3, k, tmp = cont - (j-1)*2; tmp >= 1; j++, tmp = cont - (j-1)*2) {
                    sum += tmp;
                    for(k = 3, tmp = cont - (j-1)*k; tmp >= 1; k++, tmp = cont - (j-1)*k) {
                        sum += tmp;
                    }
                }
                ret += sum;
                addnum.emplace(cont, sum);
            } else {
                ret += jt->second;
            }
        }

        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> A = {2, 4, 6, 8, 10};
        cout << Solution().numberOfArithmeticSlices(A) << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     //1
    //     cout << Solution().strongPasswordChecker("aa123") << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     //2
    //     cout << Solution().strongPasswordChecker("aaa111") << endl;
    // }
    return 0;
}
#endif