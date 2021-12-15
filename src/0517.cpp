#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int findMinMoves0(vector<int>& machines) {
        const size_t n = machines.size();
        int sum = 0;
        for(auto &i : machines)
            sum += i;
        if(sum%n != 0)
            return -1;
        
        const int should = sum/n;
        
        int ret = 0;
        for(int i = 0, rem = machines[0]-should; i < machines.size();) {
            if(rem == 0) {
                i++;
                if(i < machines.size())
                    rem = machines[i]-should;
            } else if(rem < 0) {
                ret = max(ret, -rem);
                for(int j = i+1;; j++) {
                    rem += machines[j]-should;
                    if(rem >= 0) {
                        ret = max(ret, machines[j]-should);
                        i = j;
                        break;
                    } else {
                        ret = max(ret, -rem);
                    }
                }
            } else {
                ret = max(ret, rem);
                for(int j = i+1;; j++) {
                    rem += machines[j]-should;
                    ret = max(ret, rem);
                    if(rem <= 0) {
                        i = j;
                        break;
                    }
                }
            }
        }
        return ret;
    }
    int findMinMoves(vector<int>& machines) {
        const size_t n = machines.size();
        int sum = 0;
        for(auto &i : machines)
            sum += i;
        if(sum%n != 0)
            return -1;
        const int should = sum/n;
        
        int ret = 0;
        int rem = 0;
        for(int i = 0; i < machines.size(); i++) {
            if(rem == 0) {
                rem = machines[i]-should;
            } else if(rem < 0) {
                ret = max(ret, -rem);
                rem += machines[i]-should;
                if(rem >= 0)
                    ret = max(ret, machines[i]-should);
            } else {
                ret = max(ret, rem);
                rem += machines[i]-should;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> machines = {1, 0, 5};
        cout << Solution().findMinMoves(machines) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> machines = {0, 3, 0};
        cout << Solution().findMinMoves(machines) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> machines = {0, 2, 0};
        cout << Solution().findMinMoves(machines) << endl;
    }
    cout << " 4:" << endl;
    {
        //50000
        vector<int> machines = {100000,0,100000,0,100000,0,100000,0,100000,0,100000,0};
        cout << Solution().findMinMoves(machines) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> machines = {0, 0, 11, 5};
        cout << Solution().findMinMoves(machines) << endl;
    }
    return 0;
}
#endif