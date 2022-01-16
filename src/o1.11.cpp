#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static pair<int, int> minMaxArray(vector<int> &numbers, int begin, int end) {
        if(begin == end) return {numbers[begin], numbers[end]};

        if(numbers[begin] < numbers[end]) return {numbers[begin], numbers[end]};

        int middle = (begin + end) / 2;
        if(numbers[begin] > numbers[end] || numbers[begin] != numbers[middle]) {
            if(numbers[begin] <= numbers[middle])
                return minMaxArray(numbers, middle + 1, end);
            else
                return minMaxArray(numbers, begin, middle);
        } else {
            auto ret = minMaxArray(numbers, begin, middle);
            if(ret.first < numbers[begin] || ret.second > numbers[begin])
                return ret;
            else
                return minMaxArray(numbers, middle + 1, end);
        }
    }

public:
    int minArray(vector<int> &numbers) { return minMaxArray(numbers, 0, numbers.size() - 1).first; }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        vector<int> numbers = {3, 4, 5, 1, 2};
        cout << Solution().minArray(numbers) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> numbers = {2, 2, 2, 0, 1};
        cout << Solution().minArray(numbers) << endl;
    }
    return 0;
}
#endif