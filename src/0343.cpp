#ifdef LEETCODE
#include "LeetCodeL.hpp"
#include <array>
#endif

//动规
// class Solution {
//     static int nums[59];
//     static int count;
// public:
//     int integerBreak(int n) {
//         if(count >= n)
//             return nums[n];
//         else {
//             while(count < n) {
//                 nums[++count] = max(2*nums[count-1], 3*nums[count-2]);
//                 // count++;
//             }
//             return nums[n];
//         }
//     }
// };
// int Solution::nums[59] = {0, 0, 1, 2, 4, 6, 9};
// int Solution::count = 6;

//编译期动规
// class Solution {
//     constexpr static array<int, 59> nums = [](){
//         array<int, 59> nums{0, 0, 1, 2, 4, 6, 9};
//         int count = 6;
//         while(++count < 58) {
//             nums[count] = max(3*nums[count-3], 2*nums[count-2]);
//         }
//         return nums;
//     }();
// public:
//     int integerBreak(int n) {
//         return nums[n];
//     }
// };

//非动规
class Solution {
public:
    int integerBreak(int n) {
        switch(n) {
            case 2: return 1;
            case 3: return 2;
            case 4: return 4;
            case 5: return 6;
            case 6: return 9;
            default: {
                int i = n/3, j = n%3;
                if(j == 0)
                    j = 1;
                else if(j == 1) {
                    j = 4;
                    i--;
                }

                int r = 1;
                while(i--)
                    r *= 3;
                return r*j;
            }
        }
    }
};
#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        cout << Solution().integerBreak(2) << endl;
    }
    cout << "2:" << endl;
    {
        cout << Solution().integerBreak(10) << endl;
    }
    cout << "3:" << endl;
    {
        cout << Solution().integerBreak(5) << endl;
    }
    cout << "4:" << endl;
    {
        cout << Solution().integerBreak(6) << endl;
    }
    cout << "5:" << endl;
    {
        cout << Solution().integerBreak(7) << endl;
    }
    cout << "6:" << endl;
    {
        cout << Solution().integerBreak(8) << endl;
    }
    
    return 0;
}
#endif