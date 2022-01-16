#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int translateNum(int num) {
        if(num < 10) return 1;
        int         n1 = 1;
        int         n2 = 1;
        vector<int> nums;
        while(num != 0) {
            nums.emplace_back(num % 10);
            num /= 10;
        }
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i + 1] == 1 || (nums[i + 1] == 2 && nums[i] <= 5)) {
                n2 += n1;
                swap(n1, n2);
            } else {
                n2 = n1;
            }
        }
        return n1;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        int num = 12258;
        cout << Solution().translateNum(num) << endl;
    }
    cout << " 2:" << endl;
    {}
    return 0;
}
#endif