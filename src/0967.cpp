#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ret;
        if (k == 0) {
            ret.reserve(n);
            int plus = 0;
            for (int i = 0; i < n; i++)
                plus = plus * 10 + 1;
            for (int i = 1; i <= 9; i++)
                ret.emplace_back(i * plus);
        } else {
            int n1 = n-1;
            for (int binOrder = 0; binOrder >> n1 == 0;binOrder++) {
                for (int i = 1; i <= 9; i++) {
                    bool fail = false;
                    int num = i;
                    int tmp = i;
                    for (int j = 0; j < n1; j++) {
                        if ((binOrder >> j) % 2) {
                            tmp += k;
                            if (tmp > 9) {
                                fail = true;
                                break;
                            }
                        } else {
                            tmp -= k;
                            if (tmp < 0) {
                                fail = true;
                                break;
                            }
                        }
                        num = num * 10 + tmp;
                    }
                    if (!fail)
                        ret.emplace_back(num);
                }
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int n = 3, k = 7;
        cout << Solution().numsSameConsecDiff(n, k) << endl;
        //[181,292,707,818,929]
    }
    cout << "2:" << endl;
    {
        int n = 2, k = 1;
        cout << Solution().numsSameConsecDiff(n, k) << endl;
        //[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
    }
    cout << "3:" << endl;
    {
        int n = 2, k = 0;
        cout << Solution().numsSameConsecDiff(n, k) << endl;
        //[11,22,33,44,55,66,77,88,99]
    }
    cout << "4:" << endl;
    {
        int n = 2, k = 2;
        cout << Solution().numsSameConsecDiff(n, k) << endl;
        //[13,20,24,31,35,42,46,53,57,64,68,75,79,86,97]
    }

    return 0;
}
#endif
