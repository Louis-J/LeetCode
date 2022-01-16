#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

struct Curve {
    int a, b, c;
    static Curve GetCurve(int x1, int y1, int x2, int y2) {
        if(x1 == x2) {
            return Curve{0, 1, x1};
        } else if(y1 == y2) {
            return Curve{1, 0, y1};
        } else {
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
        if(a == cur.a) {
            if(b == cur.b)
                return c < cur.c;
            else
                return b < cur.b;
        }
        return a < cur.a;
    }
    bool operator==(const Curve &cur) const {
        return a == cur.a && b == cur.b && c == cur.c;
    }
};
namespace std {
    template <>
    class hash<Curve> {
    public:
        size_t operator()(const Curve &cur) const {
            size_t result = 2166136261;
            result = (result * 16777619) ^ cur.a;
            result = (result * 16777619) ^ cur.b;
            result = (result * 16777619) ^ cur.c;
            return result;
        }
    };
    template <>
    class hash<pair<int, int>> {
    public:
        size_t operator()(const pair<int, int> &pii) const {
            size_t result = 2166136261;
            result = (result * 16777619) ^ pii.first;
            result = (result * 16777619) ^ pii.second;
            return result;
        }
    };
}
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2)
            return points.size();
        unordered_map<pair<int, int>, int> pps;
        pps.reserve(points.size());
        for(auto &i: points)
            pps[make_pair(i[0], i[1])]++;

        unordered_map<Curve, int> cs;
        for(auto it = pps.begin(); it != pps.end(); it++)
            for(auto jt = it; ++jt != pps.end();) {
                auto c = Curve::GetCurve(it->first.first, it->first.second, jt->first.first, jt->first.second);
                auto rt = cs.find(c);
                if(rt == cs.end())
                    cs.emplace(c, it->second + jt->second);
                else
                    rt->second += it->second + jt->second;
            }
        int maxn = 0;
        for(auto &i: cs)
            maxn = max(maxn, i.second);
        return sqrt(maxn*2);
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    //     cout << Solution().maxPoints(points) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    //     cout << Solution().maxPoints(points) << endl;
    // }
    cout << "3:" << endl;
    {
        vector<vector<int>> points = {{0,0},{-1,-1},{2,2}};
        cout << Solution().maxPoints(points) << endl;
    }
    return 0;
}
#endif