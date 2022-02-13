#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    struct PairLess {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
    };
    struct PairGreater {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };
    vector<int> assignTasks0(vector<int>& servers, vector<int>& tasks) {
        const int n = servers.size();
        const int m = tasks.size();
        vector<int> ans(m);
        multimap<pair<int, int>, int, PairLess> serverDict;
        for (int i = 0; i < n; i++)
            serverDict.emplace(make_pair(servers[i], i), i);
        multimap<int, int> serverFuture;
        set<int> taskSet;

        int timeNow = 0;
        taskSet.emplace(0);
        while (1) {
            auto it = taskSet.begin();
            auto jt = serverDict.begin();
            while (it != taskSet.end() && jt != serverDict.end()) {
                serverFuture.emplace(timeNow + tasks[*it], jt->second);
                ans[*it] = jt->second;
                it = taskSet.erase(it);
                jt = serverDict.erase(jt);
            }
            if (timeNow < m - 1) {
                timeNow += 1;
                taskSet.emplace(timeNow);
                for (auto kt = serverFuture.begin(); kt != serverFuture.end() && kt->first <= timeNow; kt = serverFuture.erase(kt)) {
                    auto index = kt->second;
                    serverDict.emplace(make_pair(servers[index], index), index);
                }
            } else if (taskSet.size() != 0) {
                timeNow = serverFuture.begin()->first;
                for (auto kt = serverFuture.begin(); kt != serverFuture.end() && kt->first <= timeNow; kt = serverFuture.erase(kt)) {
                    auto index = kt->second;
                    serverDict.emplace(make_pair(servers[index], index), index);
                }
            } else {
                break;
            }
        }
        return ans;
    }
    vector<int> assignTasks2(vector<int>& servers, vector<int>& tasks) {
        const int n = servers.size();
        const int m = tasks.size();
        vector<int> ans(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>, PairGreater> serverDict;
        for (int i = 0; i < n; i++)
            serverDict.emplace(servers[i], i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, PairGreater> serverFuture;
        set<int> taskSet;

        int timeNow = 0;
        taskSet.emplace(0);
        while (1) {
            auto it = taskSet.begin();
            while (it != taskSet.end() && !serverDict.empty()) {
                auto jt = serverDict.top();
                serverFuture.emplace(timeNow + tasks[*it], jt.second);
                ans[*it] = jt.second;
                it = taskSet.erase(it);
                serverDict.pop();
            }
            if (timeNow < m - 1) {
                timeNow += 1;
                taskSet.emplace(timeNow);
                while (!serverFuture.empty()) {
                    auto jt = serverFuture.top();
                    if (jt.first > timeNow)
                        break;
                    auto index = jt.second;
                    serverDict.emplace(servers[index], index);
                    serverFuture.pop();
                }
            } else if (taskSet.size() != 0) {
                timeNow = serverFuture.top().first;
                while (!serverFuture.empty()) {
                    auto jt = serverFuture.top();
                    if (jt.first > timeNow)
                        break;
                    auto index = jt.second;
                    serverDict.emplace(servers[index], index);
                    serverFuture.pop();
                }
            } else {
                break;
            }
        }
        return ans;
    }
    vector<int> assignTasks3(vector<int>& servers, vector<int>& tasks) {
        const int n = servers.size();
        const int m = tasks.size();
        vector<int> ans(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>, PairGreater> serverDict;
        for (int i = 0; i < n; i++)
            serverDict.emplace(servers[i], i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, PairGreater> serverFuture;
        int unHandledFrom = 0;

        int timeNow = 0;
        while (1) {
            while (unHandledFrom <= timeNow && unHandledFrom < m && !serverDict.empty()) {
                auto jt = serverDict.top();
                serverFuture.emplace(timeNow + tasks[unHandledFrom], jt.second);
                ans[unHandledFrom++] = jt.second;
                serverDict.pop();
            }
            if (timeNow < m - 1) {
                timeNow += 1;
                while (!serverFuture.empty()) {
                    auto jt = serverFuture.top();
                    if (jt.first > timeNow)
                        break;
                    auto index = jt.second;
                    serverDict.emplace(servers[index], index);
                    serverFuture.pop();
                }
            } else if (unHandledFrom < m) {
                timeNow = serverFuture.top().first;
                while (!serverFuture.empty()) {
                    auto jt = serverFuture.top();
                    if (jt.first > timeNow)
                        break;
                    auto index = jt.second;
                    serverDict.emplace(servers[index], index);
                    serverFuture.pop();
                }
            } else {
                break;
            }
        }
        return ans;
    }
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        const int n = servers.size();
        const int m = tasks.size();
        vector<int> ans(m);
        multimap<pair<int, int>, int, PairLess> serverDict;
        for (int i = 0; i < n; i++)
            serverDict.emplace(make_pair(servers[i], i), i);
        multimap<int, int> serverFuture;
        int unHandledFrom = 0;

        int timeNow = 0;
        while (1) {
            auto jt = serverDict.begin();
            while (unHandledFrom <= timeNow && unHandledFrom < m && jt != serverDict.end()) {
                serverFuture.emplace(timeNow + tasks[unHandledFrom], jt->second);
                ans[unHandledFrom++] = jt->second;
                jt = serverDict.erase(jt);
            }
            if (timeNow < m - 1) {
                timeNow += 1;
                for (auto kt = serverFuture.begin(); kt != serverFuture.end() && kt->first <= timeNow; kt = serverFuture.erase(kt)) {
                    auto index = kt->second;
                    serverDict.emplace(make_pair(servers[index], index), index);
                }
            } else if (unHandledFrom < m) {
                timeNow = serverFuture.begin()->first;
                for (auto kt = serverFuture.begin(); kt != serverFuture.end() && kt->first <= timeNow; kt = serverFuture.erase(kt)) {
                    auto index = kt->second;
                    serverDict.emplace(make_pair(servers[index], index), index);
                }
            } else {
                break;
            }
        }
        return ans;
    }
private:
    using PLI = pair<long long, int>;
    using PII = pair<int, int>;

public:
    vector<int> assignTasks33(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        // 工作中的服务器，存储二元组 (t, idx)
        priority_queue<PLI, vector<PLI>, greater<PLI>> busy;
        // 空闲的服务器，存储二元组 (w, idx)
        priority_queue<PII, vector<PII>, greater<PII>> idle;
        for (int i = 0; i < m; ++i) {
            idle.emplace(servers[i], i);
        }

        long long ts = 0;
        // 将优先队列 busy 中满足 t<=ts 依次取出并放入优先队列 idle
        auto release = [&]() {
            while (!busy.empty() && busy.top().first <= ts) {
                auto&& [_, idx] = busy.top();
                idle.emplace(servers[idx], idx);
                busy.pop();
            }
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ts = max(ts, static_cast<long long>(i));
            release();
            if (idle.empty()) {
                ts = busy.top().first;
                release();
            }
            auto&& [_, idx] = idle.top();
            ans.push_back(idx);
            busy.emplace(ts + tasks[i], idx);
            idle.pop();
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> servers = { 3,3,2 };
        vector<int> tasks = { 1,2,3,2,1,2 };
        cout << Solution().assignTasks(servers, tasks) << endl;
        //[2,2,0,2,1,2]
    }
    cout << "2:" << endl;
    {
        vector<int> servers = { 5,1,4,3,2 };
        vector<int> tasks = { 2,1,2,4,5,2,1 };
        cout << Solution().assignTasks(servers, tasks) << endl;
        //[1,4,1,4,1,3,2]
    }

    return 0;
}
#endif