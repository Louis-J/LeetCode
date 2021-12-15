#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    // 删除法, 链表, O(n), 但很慢
    string removeKdigits0(string num, int k) {
        // 特殊情况处理, 但性能无影响
        if(num.size() == k)
            return "0";
        else if(num.size() == k+1) {
            char c = num[0];
            for(int i = 1; i < num.size(); i++)
                c = min(c, num[i]);
            return string(1, c);
        }
        list<char> l(num.begin(), num.end());
        
        for(auto jt = l.begin(), it = jt++; k > 0; k--) {
            while(true) {
                if(jt == l.end()) {
                    l.erase(it);
                    it = l.end();
                    jt = it--;
                    break;
                } else if(*it > *jt){
                    it = --l.erase(it);
                    break;
                } else {
                    it++, jt++;
                }
            }
        }
        for(auto it = l.begin(); it != l.end() && *it == '0'; it = l.erase(it)) {}
        if(l.size() == 0)
            return "0";
        else
            return string(l.begin(), l.end());
    }
    // 插入法, 双向队列, 插入n-k个, 均摊O(n)
    string removeKdigits(string num, int k) {
        // 特殊情况处理
        if(num.size() == k)
            return "0";
        else if(num.size() == k+1) {
            char c = num[0];
            for(int i = 1; i < num.size(); i++)
                c = min(c, num[i]);
            return string(1, c);
        }
        // 双向队列, 值为数字的下标, 数字升序排列, 插入时若降序则删除
        // 操作为均摊O(1), 可用定长数组优化为O(1)
        deque<int> que;
        int l = num.size()-k;
        int i = 0;
        for(; i <= k; i++) {
            while(que.size() !=0 && num[que.back()] > num[i]) {
                que.pop_back();
            }
            que.push_back(i);
        }
        string ret;
        ret.reserve(l);
        for(; l > 1; l--, i++) {
            if(ret.size() != 0 || num[que.front()] !='0')
                ret += num[que.front()];
            que.pop_front();
            while(que.size() !=0 && num[que.back()] > num[i]) {
                que.pop_back();
            }
            que.push_back(i);
        }
        ret += num[que.front()];
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string num = "1432219";
        int k = 3;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << "2:" << endl;
    {
        string num = "10200";
        int k = 1;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << "3:" << endl;
    {
        string num = "10";
        int k = 2;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << "4:" << endl;
    {
        string num = "1234567890";
        int k = 9;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << "5:" << endl;
    {
        string num = "100";
        int k = 1;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    
    return 0;
}
#endif
