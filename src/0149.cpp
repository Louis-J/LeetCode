/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
    struct Curve {
        int a, b, c;
        static Curve GetCurve(int x1, int y1, int x2, int y2) {
            if(x1 == x2) {
                return Curve{0, 1, x1};
            } else if(y1 == y2) {
                return Curve{1, 0, y1};
            } else {
                // int gcd = GetGCD(x1, y1, x2, y2);
                int x = x1-x2;
                int y = y1-y2;
                int g = gcd(x, y);
                int a = x/g, b = y/g, c;
                if(a < 0) {
                    a = -a;
                    b = -b;
                }
                if(x1 == 0)
                    c = y1;
                else if(x1 < 0) {
                    int p = (-x1)/a+1;
                    c = (x1+p*a) + (y1+p*b)*100;
                } else {
                    int p = x1/a;
                    c = (x1-p*a) + (y1-p*b)*100;
                }
                return Curve{a, b, c};
            }
        }
        bool operator<(const Curve &cur) const {
            if(a == cur.a)
                if(b == cur.b)
                    return c < cur.c;
                else
                    return b < cur.b;
            return a < cur.a;
        }
    };
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2)
            return points.size();
        map<Curve, int> cs;
        for(auto it = points.begin(); it != points.end(); it++)
            for(auto jt = it+1; jt != points.end(); jt++) {
                auto &r = cs[Curve::GetCurve((*it)[0], (*it)[1], (*jt)[0], (*jt)[1])];
                cout << r;
                r++;
                // if(r == 1)
                //     r = 2;
            }
        int maxn = 0;
        for(auto it = cs.begin(); it != cs.end(); it++)
            maxn = max(maxn, it->second);
        return sqrt(maxn*2)+1;
    }
};
// @lc code=end

