#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //复杂度过高，超时
    bool canCross0(vector<int>& stones) {
        if(stones[1] != 1)
            return false;
        if(stones.size() <= 2)
            return true;
        multimap<int, int> ss;
        for(size_t i = 2; i < stones.size(); i++) {
            ss.emplace(stones[i], i);
        }
        multimap<int, int> posi{{1, stones[1]-stones[0]}};
        while(posi.size() != 0) {
            auto it = posi.begin();
            auto nextn = stones[it->first] + it->second;

            auto jt = ss.find(nextn+1);
            if(jt != ss.end()) {
                if(jt->second == stones.size()-1)
                    return true;
                posi.emplace(jt->second, it->second+1);
            }

            jt = ss.find(nextn);
            if(jt != ss.end()) {
                if(jt->second == stones.size()-1)
                    return true;
                posi.emplace(jt->second, it->second);
            }

            if(it->second > 1) {
                jt = ss.find(nextn-1);
                if(jt != ss.end()) {
                    if(jt->second == stones.size()-1)
                        return true;
                    posi.emplace(jt->second, it->second-1);
                }
            }

            posi.erase(it);
        }
        return false;
    }
    //接近o(nlogn)的办法
    //并非最优
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
            return false;
        if(stones.size() <= 2)
            return true;
            
        unordered_map<int, int> ss;
        for(size_t i = 2; i < stones.size(); i++) {
            ss.emplace(stones[i], i);
        }
        vector<vector<int>> from(stones.size()-1);
        from[1].emplace_back(0);
        for(size_t i = 1; i < from.size(); i++) {
            int addnum = 2147483647;
            for(auto &j : from[i]) {
                int diff = stones[i] - stones[j];
                if(diff + 1 < addnum) {
                    addnum = diff + 1;
                    auto kt = ss.find(addnum+stones[i]);
                    if(kt != ss.end()) {
                        if(kt->second == stones.size()-1)
                            return true;
                        from[kt->second].emplace_back(i);
                    }
                }
                if(diff < addnum) {
                    addnum = diff;
                    auto kt = ss.find(addnum+stones[i]);
                    if(kt != ss.end()) {
                        if(kt->second == stones.size()-1)
                            return true;
                        from[kt->second].emplace_back(i);
                    }
                }
                if(diff == 1)
                    break;
                if(diff - 1 < addnum) {
                    addnum = diff - 1;
                    auto kt = ss.find(addnum+stones[i]);
                    if(kt != ss.end()) {
                        if(kt->second == stones.size()-1)
                            return true;
                        from[kt->second].emplace_back(i);
                    }
                }
            }
        }

        return false;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
        cout << Solution().canCross(stones) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
        cout << Solution().canCross(stones) << endl;
    }
    // cout << "3:" << endl;
    // {
    // }
    // cout << "4:" << endl;
    // {
    // }
    
    return 0;
}
#endif