#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point &p) const {
        if(x == p.x)
            return y < p.y;
        return x < p.x;
    }
    bool operator<(const Point &&p) const {
        if(x == p.x)
            return y < p.y;
        return x < p.x;
    }
    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};
namespace std {
    template <>
    class hash<Point> {
    public:
        size_t operator () (const Point &p) const {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
        }
    };
}

int main() {
    int N, M;
    Point S, T;
    cin >> N >> M >> S.x >> S.y >> T.x >> T.y;
    if(S == T) {
        cout << 0;
        return 0;
    }

    unordered_set<Point> pointsOld;
    unordered_set<Point> pointsLast;
    unordered_set<Point> pointsNew;

    Point temp;

    auto TryNew = [&] (int x, int y) {
            temp.x = x;
            temp.y = y;
            if(temp.x >= 0 && temp.x <= N && temp.y >= 0 && temp.y <= M && pointsOld.find(temp) == pointsOld.end() && pointsLast.find(temp) == pointsLast.end()) {
                auto have = pointsNew.find(temp);
                if(have == pointsNew.end())
                    pointsNew.emplace(temp);
            }
        };

    pointsLast.emplace(S);
    for (int len = 1;; len++) {
        for (auto &p : pointsLast) {
            TryNew(p.x-2, p.y-1);
            TryNew(p.x-1, p.y-2);
            TryNew(p.x+2, p.y-1);
            TryNew(p.x+1, p.y-2);
            TryNew(p.x-2, p.y+1);
            TryNew(p.x-1, p.y+2);
            TryNew(p.x+2, p.y+1);
            TryNew(p.x+1, p.y+2);
        }
        auto Tit = pointsNew.find(T);
        if(Tit != pointsNew.end()) {
            cout << len;
            break;
        } else if(pointsNew.size() == 0) {
            cout << -1;
            break;
        } else {
            pointsOld.insert(pointsLast.begin(), pointsLast.end());
            // pointsLast = pointsNew;
            swap(pointsLast, pointsNew);
            pointsNew.clear();
        }
    }
    return 0;
}