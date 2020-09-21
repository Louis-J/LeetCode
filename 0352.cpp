#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class SummaryRanges {
    map<int, int> amap;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        if(amap.size() == 0) {
            amap.emplace(val, val);
            return;
        }
        auto it = amap.upper_bound(val);
        if(it == amap.end()) {
            it--;
            if(it->second < val) {
                if(it->second == val-1)
                    it->second = val;
                else
                    amap.emplace_hint(it, val, val);
            }
        } else if(it == amap.begin()) {
            if(it->first == val+1) {
                amap.emplace(val, it->second);
                amap.erase(it);
            } else
                amap.emplace_hint(it, val, val);
        } else {
            auto jt = it;
            it--;
            if(it->second < val) {
                if(jt->first-2 == it->second) {
                    it->second = jt->second;
                    amap.erase(jt);
                } else if(it->second == val-1)
                    it->second = val;
                else if(jt->first == val+1) {
                    amap.emplace(val, jt->second);
                    amap.erase(jt);
                } else
                    amap.emplace_hint(it, val, val);
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for(auto &i : amap) {
            ret.emplace_back(vector<int>{i.first, i.second});
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        SummaryRanges* obj = new SummaryRanges();
        obj->addNum(1);
        cout << obj->getIntervals() << endl;
        obj->addNum(3);
        cout << obj->getIntervals() << endl;
        obj->addNum(7);
        cout << obj->getIntervals() << endl;
        obj->addNum(2);
        cout << obj->getIntervals() << endl;
        obj->addNum(6);
        cout << obj->getIntervals() << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     SummaryRanges* obj = new SummaryRanges();
    //     obj->addNum(0);
    //     obj->addNum(4);
    //     obj->addNum(6);
    //     obj->addNum(7);
    //     obj->addNum(8);
    //     cout << obj->getIntervals() << endl;
    //     obj->addNum(5);
    //     cout << obj->getIntervals() << endl;
    // }
    return 0;
}
#endif

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

