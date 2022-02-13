#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        auto svtoi = [](string_view strv) {
            int tmp = 0;
            for (auto& c : strv)
                tmp = tmp * 10 + c - '0';
            return tmp;
        };
        vector<int> times(n, 0);
        vector<tuple<int, int>> stored;
        for (auto& str : logs) {
            auto strv = string_view(str);
            auto p1 = str.find(':');
            auto p2 = str.find_last_of(':');

            auto id = svtoi(strv.substr(0, p1));
            auto isBegin = str[p1 + 1] == 's';
            auto time = svtoi(strv.substr(p2 + 1));
            if (!isBegin) {
                if (stored.size() > 1) {
                    auto& [id1, time1] = stored[stored.size() - 1];
                    auto& [id2, time2] = stored[stored.size() - 2];
                    times[id1] += time - time1 + 1;
                    time2 = time + 1;
                    stored.pop_back();
                } else {
                    auto& [id1, time1] = stored[stored.size() - 1];
                    times[id1] += time - time1 + 1;
                    stored.pop_back();
                }
            } else if (stored.size() != 0) {
                auto& [id1, time1] = stored[stored.size() - 1];
                times[id1] += time - time1;
                time1 = time;
                stored.emplace_back(id, time);
            } else {
                stored.emplace_back(id, time);
            }
        }
        return times;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int n = 2;
        vector<string> logs = { "0:start:0","1:start:2","1:end:5","0:end:6" };
        cout << Solution().exclusiveTime(n, logs) << endl;
        //[3,4]
    }
    cout << "2:" << endl;
    {
        int n = 1;
        vector<string> logs = { "0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7" };
        cout << Solution().exclusiveTime(n, logs) << endl;
        //[8]
    }
    cout << "3:" << endl;
    {
    }
    cout << "4:" << endl;
    {
    }
    cout << "5:" << endl;
    {
    }

    return 0;
}
#endif
