#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>

using std::vector;
using std::set;
using std::map;
using std::multimap;
using std::tuple;

size_t Kruskal1(vector<tuple<size_t, size_t, size_t>> edges, size_t N) {
    std::sort(edges.begin(), edges.end(), [](tuple<size_t, size_t, size_t> &x, tuple<size_t, size_t, size_t> &y) {
        return std::get<2>(x) < std::get<2>(y);
    });
    set<set<size_t>> points;
    size_t sum = 0;
    for(auto &i : edges) {
        if(N == 0)
            break;
        auto &a = std::get<0>(i);
        auto &b = std::get<1>(i);
        auto &c = std::get<2>(i);

        set<set<size_t>>::iterator ait, bit;
        for(ait = points.begin();
            ait != points.end() && ait->find(a) == ait->end(); ait++) {}
        for(bit = points.begin();
            bit != points.end() && bit->find(b) == bit->end(); bit++) {}

        if(ait == bit) {
            if(ait != points.end())
                continue;
            else
                points.insert({a, b});
        } else if(ait == points.end() || bit == points.end()) {
            if(bit == points.end()) {
                set<size_t> &aref = const_cast<set<size_t> &>(*ait);
                aref.emplace(b);
            } else {
                set<size_t> &bref = const_cast<set<size_t> &>(*bit);
                bref.emplace(a);
            }
        } else {
            set<size_t> &aref = const_cast<set<size_t> &>(*ait);
            aref.insert(bit->begin(), bit->end());
            points.erase(bit);
        }
        sum += c;
        N--;
    }
    return sum;
}

size_t Kruskal2(vector<tuple<size_t, size_t, size_t>> edges, size_t N) {
    size_t points[N+1];
    for(auto &i : points)
        i = 0;
    std::sort(edges.begin(), edges.end(), [](tuple<size_t, size_t, size_t> &x, tuple<size_t, size_t, size_t> &y) {
        return std::get<2>(x) < std::get<2>(y);
    });
    map<size_t, vector<size_t>> pointsAt;
    size_t mapTag = 0;
    size_t sum = 0;
    for(auto &i : edges) {
        if(N == 0)
            break;
        auto &a = std::get<0>(i);
        auto &b = std::get<1>(i);
        auto &c = std::get<2>(i);

        const auto aAt = points[a], bAt = points[b];
        if(aAt == bAt) {
            if(aAt != 0)
                continue;
            else {
                mapTag++;
                pointsAt.insert({mapTag, {a, b}});
                points[a] = points[b] = mapTag;
            }
        } else if(aAt == 0 || bAt == 0) {
            if(bAt == 0) {
                points[b] = aAt;
                pointsAt[aAt].emplace_back(b);
            } else {
                points[a] = bAt;
                pointsAt[bAt].emplace_back(a);
            }
        } else {
            for(auto &j : pointsAt[bAt])
                points[j] = aAt;
            pointsAt[aAt].insert(pointsAt[aAt].end(), pointsAt[bAt].begin(), pointsAt[bAt].end());
            pointsAt.erase(bAt);
        }
        // if constexpr(LCDEBUG) std::cout << a << ' ' << aAt << ' ' << b << ' ' << bAt << ' ' << c << '\n';
        sum += c;
        N--;
    }
    return sum;
}

size_t GetRealPosi(size_t points[], size_t at) {
    if(points[at] != at)
        return points[at] = GetRealPosi(points, points[at]);
    else
        return at;
}
size_t Kruskal3(vector<tuple<size_t, size_t, size_t>> edges, size_t N) {
    size_t points[N+1];
    for(size_t i = 1; i <= N; i++)
        points[i] = i;

    std::sort(edges.begin(), edges.end(), [](tuple<size_t, size_t, size_t> &x, tuple<size_t, size_t, size_t> &y) {
        return std::get<2>(x) < std::get<2>(y);
    });
    size_t sum = 0;
    for(auto &i : edges) {
        if(N == 0)
            break;
        auto &a = std::get<0>(i);
        auto &b = std::get<1>(i);
        auto &c = std::get<2>(i);

        size_t aAt = GetRealPosi(points, a), bAt = GetRealPosi(points, b);
        
        if(aAt == bAt) {
            continue;
        } else {
            points[bAt] = aAt;
        }
        sum += c;
        N--;
    }
    return sum;
}
size_t Kruskal3_1(vector<tuple<size_t, size_t, size_t>> &edges, size_t N) {
    size_t points[N];
    for(size_t i = 1; i <= N; i++)
        points[i] = i;

    std::sort(edges.begin(), edges.end(), [](tuple<size_t, size_t, size_t> &x, tuple<size_t, size_t, size_t> &y) {
        return std::get<2>(x) < std::get<2>(y);
    });
    size_t sum = 0;
    for(auto &i : edges) {
        if(N == 0)
            break;
        auto &a = std::get<0>(i);
        auto &b = std::get<1>(i);
        auto &c = std::get<2>(i);

        size_t aAt = GetRealPosi(points, a), bAt = GetRealPosi(points, b);
        
        if(aAt == bAt) {
            continue;
        } else {
            points[bAt] = aAt;
        }
        sum += c;
        N--;
    }
    return sum;
}

//稀疏图不适用
size_t Prim(vector<tuple<size_t, size_t, size_t>> edges, size_t N) {
    size_t mat[N+1][N+1] = {};
    bool inTree[N+1] = {false};
    for(auto &i : edges) {
        auto &a = std::get<0>(i);
        auto &b = std::get<1>(i);
        auto &c = std::get<2>(i);
        mat[a][b] = c;
        // mat[a][b] = mat[b][a] = c;
    }
    multimap<size_t, size_t> minDis;
    size_t sum = 0;
    inTree[1] = true;
    for(size_t i = 1; i <= N; i++) {
        if(mat[1][i] != 0)
            minDis.insert({mat[1][i], i});
        if(mat[i][1] != 0)
            minDis.insert({mat[i][1], i});
    }
    for(size_t i = 1; i < N; i++) {
        auto it = minDis.begin();
        for(; inTree[it->second]; it++) {}
        auto &e = it->second;
        auto &w = it->first;
        inTree[e] = true;
        // for(size_t i = 1; i <= N; i++) {
        //     if(mat[e][i] != 0)
        //         minDis.insert({mat[e][i], i});
        //     if(mat[i][e] != 0)
        //         minDis.insert({mat[i][e], i});
        // }
        for(size_t i = 1; i < e; i++)
            if(mat[i][e] != 0)
                minDis.insert({mat[i][e], i});
        for(size_t i = e+1; i <= N; i++)
            if(mat[e][i] != 0)
                minDis.insert({mat[e][i], i});
        sum += w;
    }
    return sum;
}
// size_t Prim(vector<tuple<size_t, size_t, size_t>> edges, size_t N) {
//     constexpr auto sortByP1 = [](tuple<size_t, size_t, size_t> &x, tuple<size_t, size_t, size_t> &y) {
//         return std::get<0>(x) < std::get<0>(y);
//     }
//     constexpr auto sortByP2 = [](tuple<size_t, size_t, size_t> &x, tuple<size_t, size_t, size_t> &y) {
//         return std::get<1>(x) < std::get<1>(y);
//     }
//     constexpr auto sortByW = [](tuple<size_t, size_t, size_t> &x, tuple<size_t, size_t, size_t> &y) {
//         return std::get<2>(x) < std::get<2>(y);
//     }

//     set<tuple<size_t, size_t, size_t>, sortByP1> edgeP1
//     std::sort(edges.begin(), edges.end(), [](tuple<size_t, size_t, size_t> &x, tuple<size_t, size_t, size_t> &y) {
//         return std::get<2>(x) < std::get<2>(y);
//     });
//     set<set<size_t>> points;
//     size_t sum = 0;
//     for(auto &i : edges) {
//         if(N == 0)
//             break;
//         auto &a = std::get<0>(i);
//         auto &b = std::get<1>(i);
//         auto &c = std::get<2>(i);

//         set<set<size_t>>::iterator ait, bit;
//         for(ait = points.begin();
//             ait != points.end() && ait->find(a) == ait->end(); ait++) {}
//         for(bit = points.begin();
//             bit != points.end() && bit->find(b) == bit->end(); bit++) {}

//         if(ait == bit) {
//             if(ait != points.end())
//                 continue;
//             else
//                 points.insert({a, b});
//         } else if(ait == points.end() || bit == points.end()) {
//             if(bit == points.end()) {
//                 set<size_t> &aref = const_cast<set<size_t> &>(*ait);
//                 aref.emplace(b);
//             } else {
//                 set<size_t> &bref = const_cast<set<size_t> &>(*bit);
//                 bref.emplace(a);
//             }
//         } else {
//             set<size_t> &aref = const_cast<set<size_t> &>(*ait);
//             aref.insert(bit->begin(), bit->end());
//             points.erase(bit);
//         }
//         sum += c;
//         N--;
//     }
//     return sum;
// }

size_t FastReadUnsigend() {
    size_t ret = 0;
    char c = std::getchar();
    for(; c < '0' || c > '9'; c = std::getchar()) {}
    for(; c >= '0' && c <= '9'; c = std::getchar())
        ret = ret * 10 + c - '0';
    return ret;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    size_t N = FastReadUnsigend(), M = FastReadUnsigend();
    vector<tuple<size_t, size_t, size_t>> edges;
    edges.reserve(M);
    while(M--) {
        size_t u = FastReadUnsigend()-1, v = FastReadUnsigend()-1, w = FastReadUnsigend();
        if(u != v)
            // edges.emplace_back(std::min(u, v), std::max(u, v), w);
            edges.emplace_back(u, v, w);
    }

    std::cout << Kruskal3_1(edges, N);

    return 0;
}
