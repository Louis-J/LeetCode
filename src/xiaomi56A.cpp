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

int main() {
    int N, M;
    Point S, T;
    cin >> N >> M >> S.x >> S.y >> T.x >> T.y;

    map<Point, vector<vector<Point>>> pointsOld;
    map<Point, vector<vector<Point>>> pointsLast;
    map<Point, vector<vector<Point>>> pointsNew;

    Point temp;

    auto TryNew = [&] (int x, int y, vector<vector<Point>> trace) {
            temp.x = x;
            temp.y = y;
            if(temp.x >= 0 && temp.x <= N && temp.y >= 0 && temp.y <= M && pointsOld.find(temp) == pointsOld.end() && pointsLast.find(temp) == pointsLast.end()) {
                auto have = pointsNew.find(temp);
                if(have == pointsNew.end()) {
                    vector<vector<Point>> tr = vector<vector<Point>>(trace);
                    for (auto &t : tr)
                        t.emplace_back(temp);
                    pointsNew.emplace(temp, tr);
                } else {
                    vector<vector<Point>> tr = vector<vector<Point>>(trace);
                    for (auto &t : tr)
                        t.emplace_back(temp);
                    have->second.insert(have->second.end(), tr.begin(), tr.end());
                }
            }
        };

    pointsLast.emplace(S, vector<vector<Point>>{vector<Point>{S}});
    while (true) {
        for (auto &p : pointsLast) {
            TryNew(p.first.x-2, p.first.y-1, p.second);
            TryNew(p.first.x-1, p.first.y-2, p.second);
            TryNew(p.first.x+2, p.first.y-1, p.second);
            TryNew(p.first.x+1, p.first.y-2, p.second);
            TryNew(p.first.x-2, p.first.y+1, p.second);
            TryNew(p.first.x-1, p.first.y+2, p.second);
            TryNew(p.first.x+2, p.first.y+1, p.second);
            TryNew(p.first.x+1, p.first.y+2, p.second);
        }
        auto Tit = pointsNew.find(T);
        if(Tit != pointsNew.end()) {
            for(auto &i : Tit->second) {
                for(auto &j : i) {
                    cout << "-> {" << j.x << ", " << j.y << "}";
                }
                cout << endl;
            }
            // cout << Tit->second[0].size()-1;
            break;
        } else if(pointsNew.size() == 0) {
            cout << "None";
            // cout << -1;
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