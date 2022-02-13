#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution0 {
    static constexpr int sqs[100] = {
        1*1,
        2*2,
        3*3,
        4*4,
        5*5,
        6*6,
        7*7,
        8*8,
        9*9,
        
        10*10,
        11*11,
        12*12,
        13*13,
        14*14,
        15*15,
        16*16,
        17*17,
        18*18,
        19*19,
        
        20*20,
        21*21,
        22*22,
        23*23,
        24*24,
        25*25,
        26*26,
        27*27,
        28*28,
        29*29,
        
        30*30,
        31*31,
        32*32,
        33*33,
        34*34,
        35*35,
        36*36,
        37*37,
        38*38,
        39*39,
        
        40*40,
        41*41,
        42*42,
        43*43,
        44*44,
        45*45,
        46*46,
        47*47,
        48*48,
        49*49,
        
        50*50,
        51*51,
        52*52,
        53*53,
        54*54,
        55*55,
        56*56,
        57*57,
        58*58,
        59*59,
        
        60*60,
        61*61,
        62*62,
        63*63,
        64*64,
        65*65,
        66*66,
        67*67,
        68*68,
        69*69,
        
        70*70,
        71*71,
        72*72,
        73*73,
        74*74,
        75*75,
        76*76,
        77*77,
        78*78,
        79*79,
        
        80*80,
        81*81,
        82*82,
        83*83,
        84*84,
        85*85,
        86*86,
        87*87,
        88*88,
        89*89,
        
        90*90,
        91*91,
        92*92,
        93*93,
        94*94,
        95*95,
        96*96,
        97*97,
        98*98,
        99*99,

        100*100,
    };
    static int nums[10000];
    static int count;
public:
    int numSquares(int n) {
        if(count < n) {
            for(count++; count <= n; count++) {
                int minn = count;
                for(int i = sqrt(count); i >= 0; i--) {
                    minn = min(minn, nums[count-i*i] + 1);
                }
                nums[count] = minn;
            }
        }
        return nums[n];
    }
};
int Solution0::nums[10000];
int Solution0::count = 0;

class Solution1 {
public:
    int numSquares(int n) {
        int dp[n + 1];
        for(int i = 0; i <= n; i++) dp[i] = i;
        for(int i = 2, i2 = 4; i2 <= n; i++, i2 = i * i) {
            for(int j = i2; j <= n; j++) dp[j] = min(dp[j - i2] + 1, dp[j]);
        }
        return dp[n];
    }
};

class Solution2 {
    static int nums[10001];
    static int count;

public:
    int numSquares(int n) {
        if(n <= count) return nums[n];

        for(int i = count + 1; i <= n; i++) nums[i] = i;
        int i = 2, i2 = 4;
        for(; i2 <= count; i++, i2 = i * i) {
            for(int j = count + 1; j <= n; j++) nums[j] = min(nums[j - i2] + 1, nums[j]);
        }
        for(; i2 <= n; i++, i2 = i * i) {
            for(int j = i2; j <= n; j++) nums[j] = min(nums[j - i2] + 1, nums[j]);
        }
        count = n;
        return nums[n];
    }
};
int Solution2::nums[10001] = {0};
int Solution2::count       = 0;

class Solution3 {
    static unordered_set<int> sqNum;
    static bool               check1(int x) { return sqNum.find(x) != sqNum.end(); }
    static bool               check2(int x) {
        for(int i = 1, i2 = 1; i2 <= x / 2; i++, i2 = i * i)
            if(sqNum.find(x - i2) != sqNum.end()) return true;
        return false;
    }
    static bool check4(int x) {
        while(x % 4 == 0) x /= 4;
        return x % 8 == 7;
    }

public:
    int numSquares(int n) {
        if(sqNum.size() == 0)
            for(int i = 1; i <= 100; i++) sqNum.emplace(i * i);
        if(check1(n))
            return 1;
        else if(check4(n))
            return 4;
        else if(check2(n))
            return 2;
        else
            return 3;
    }
};
unordered_set<int> Solution3::sqNum;

class Solution {
    static constexpr int sqs[100] = {
        1 * 1,     2 * 2,   3 * 3,   4 * 4,   5 * 5,   6 * 6,   7 * 7,   8 * 8,   9 * 9,

        10 * 10,   11 * 11, 12 * 12, 13 * 13, 14 * 14, 15 * 15, 16 * 16, 17 * 17, 18 * 18, 19 * 19,

        20 * 20,   21 * 21, 22 * 22, 23 * 23, 24 * 24, 25 * 25, 26 * 26, 27 * 27, 28 * 28, 29 * 29,

        30 * 30,   31 * 31, 32 * 32, 33 * 33, 34 * 34, 35 * 35, 36 * 36, 37 * 37, 38 * 38, 39 * 39,

        40 * 40,   41 * 41, 42 * 42, 43 * 43, 44 * 44, 45 * 45, 46 * 46, 47 * 47, 48 * 48, 49 * 49,

        50 * 50,   51 * 51, 52 * 52, 53 * 53, 54 * 54, 55 * 55, 56 * 56, 57 * 57, 58 * 58, 59 * 59,

        60 * 60,   61 * 61, 62 * 62, 63 * 63, 64 * 64, 65 * 65, 66 * 66, 67 * 67, 68 * 68, 69 * 69,

        70 * 70,   71 * 71, 72 * 72, 73 * 73, 74 * 74, 75 * 75, 76 * 76, 77 * 77, 78 * 78, 79 * 79,

        80 * 80,   81 * 81, 82 * 82, 83 * 83, 84 * 84, 85 * 85, 86 * 86, 87 * 87, 88 * 88, 89 * 89,

        90 * 90,   91 * 91, 92 * 92, 93 * 93, 94 * 94, 95 * 95, 96 * 96, 97 * 97, 98 * 98, 99 * 99,

        100 * 100,
    };
    static bool check1(int x) {
        int i = 0, j = 99, middle;
        while(i <= j) {
            middle = (i + j) / 2;
            if(sqs[middle] == x)
                return true;
            else if(sqs[middle] < x)
                i = middle + 1;
            else
                j = middle - 1;
        }
        return false;
    }
    static bool check2(int x) {
        int i = 0, j = 99;
        while(i <= j) {
            int res = sqs[i] + sqs[j];
            if(res == x)
                return true;
            else if(res < x)
                i++;
            else
                j++;
        }
        return false;
    }
    static bool check4(int x) {
        while(x % 4 == 0) x /= 4;
        return x % 8 == 7;
    }

public:
    int numSquares(int n) {
        if(check1(n))
            return 1;
        else if(check4(n))
            return 4;
        else if(check2(n))
            return 2;
        else
            return 3;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    { cout << Solution().numSquares(4) << endl; }
    // cout << "2:" << endl;
    // {
    // }
    // cout << "3:" << endl;
    // {
    //     string s = "cb";
    //     string p = "?a";
    //     cout << boolalpha << Solution().isMatch(s, p) << endl;
    // }

    return 0;
}
#endif
