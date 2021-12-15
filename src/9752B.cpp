#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int Maximumlength3(string x) {
        string maxposs;
        int maxlen = x.size()/3;
        for(; maxlen > 0; maxlen--) {
            maxposs.clear();
            maxposs.insert(0, maxlen, 'a');
            maxposs.insert(maxlen, maxlen, 'b');
            maxposs.insert(maxlen*2, maxlen, 'c');
            if(x.find(maxposs) != string::npos)
                return maxlen*3;
        }
        return 0;
    }
    int Maximumlength0(string x) {
        int maxlen = 0;
        int len = 0;
        string maxposs;
        for(int i = 0; i < x.size(); i++) {
            if(x[i] == 'b') {
                len++;
            } else if(len != 0){
                if(len > maxlen) {
                    maxposs.clear();
                    maxposs.insert(0, len, 'a');
                    maxposs.insert(len, len, 'b');
                    maxposs.insert(len*2, len, 'c');
                    if(x.find(maxposs) != string::npos)
                        maxlen = len;
                }
                len = 0;
            }
        }
        return maxlen*3;
    }
    int Maximumlength4(string x) {
        int head = 0;
        int nail = x.size()-1;
        for(;; head++) {
            if(head == x.size())
                return 0;
            if(x[head] == 'a')
                break;
        }
        for(;; nail--) {
            if(nail == head)
                return 0;
            if(x[nail] == 'c')
                break;
        }

        string s;
        s.reserve(x.size());
        int acnum = 1, bnum = 0;
        for(auto it = x.begin() + head; it <= x.begin() + nail; it++) {
            if(*it == 'b')
                bnum++;
            if(*it >='a' && *it <= 'c')
                s += *it;
        }
        // 双指针:
        // anum : [0, i]
        // bnum : [i+1, j-1]
        // cnum : [j, s.size()-1]
        int i = 0, j = s.size()-1;
        while(bnum > acnum) {
            for(i++;; i++) {
                if(i == x.size())
                    return acnum*3;
                if(s[i] == 'a')
                    break;
                if(s[i] == 'b')
                    bnum--;
            }
            for(j--;; j--) {
                if(j == i)
                    return acnum*3;
                if(s[j] == 'c')
                    break;
                if(s[j] == 'b')
                    bnum--;
            }
            acnum++;
        }
        if(bnum == acnum)
            return acnum*3;
        else
            return acnum*3-3;
    }
    
    int Maximumlength5(string x) {
        auto head = x.begin();
        auto nail = --x.end();
        for(;; head++) {
            if(head == nail)
                return 0;
            if(*head == 'a')
                break;
        }
        for(;; nail--) {
            if(nail == head)
                return 0;
            if(*nail == 'c')
                break;
        }
 
        string s;
        int acnum = 1, bnum = 0;
        for(auto it = head; it <= nail; it++) {
            if(*it == 'b')
                bnum++;
            if(*it >='a' && *it <= 'c')
                s += *it;
        }
        // 双指针:
        // anum : [0, i]
        // bnum : [i+1, j-1]
        // cnum : [j, s.size()-1]
        auto i = s.begin(), j = --s.end();
        while(bnum > acnum) {
            for(i++;; i++) {
                if(i == j)
                    return acnum*3;
                if(*i == 'a')
                    break;
                if(*i == 'b')
                    bnum--;
            }
            for(j--;; j--) {
                if(j == i)
                    return acnum*3;
                if(*j == 'c')
                    break;
                if(*j == 'b')
                    bnum--;
            }
            acnum++;
        }
        if(bnum == acnum)
            return acnum*3;
        else
            return acnum*3-3;
    }
    
    int Maximumlength6(string x) {
        int i = 0;
        int j = x.size()-1;
        for(;; i++) {
            if(i == x.size())
                return 0;
            if(x[i] == 'a')
                break;
        }
        for(;; j--) {
            if(j == i)
                return 0;
            if(x[j] == 'c')
                break;
        }
        int acnum = 1, bnum = 0;
        for(int k = i+1; k < j; k++) {
            if(x[k] == 'b')
                bnum++;
        }
        // 双指针:
        // anum : [0, i]
        // bnum : [i+1, j-1]
        // cnum : [j, s.size()-1]
        while(bnum > acnum) {
            for(i++;; i++) {
                if(i == x.size())
                    return acnum*3;
                if(x[i] == 'a')
                    break;
                if(x[i] == 'b')
                    bnum--;
            }
            for(j--;; j--) {
                if(j == i)
                    return acnum*3;
                if(x[j] == 'c')
                    break;
                if(x[j] == 'b')
                    bnum--;
            }
            acnum++;
        }
        if(bnum == acnum)
            return acnum*3;
        else
            return acnum*3-3;
    }

    // 进35ms
    int Maximumlength(string x) {
        auto i = x.begin();
        auto j = --x.end();
        for(;; i++) {
            if(i == j)
                return 0;
            if(*i == 'a')
                break;
        }
        for(;; j--) {
            if(j == i)
                return 0;
            if(*j == 'c')
                break;
        }
        int acnum = 1, bnum = 0;
        for(auto k = i; k < j; k++) {
            if(*k == 'b')
                bnum++;
        }
        // 双指针:
        // anum : [0, i]
        // bnum : [i+1, j-1]
        // cnum : [j, s.size()-1]
        while(bnum > acnum) {
            for(i++;; i++) {
                if(i == j)
                    return acnum*3;
                if(*i == 'a')
                    break;
                if(*i == 'b')
                    bnum--;
            }
            for(j--;; j--) {
                if(j == i)
                    return acnum*3;
                if(*j == 'c')
                    break;
                if(*j == 'b')
                    bnum--;
            }
            acnum++;
        }
        if(bnum == acnum)
            return acnum*3;
        else
            return acnum*3-3;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string s = "cbacb";
        cout << Solution().Maximumlength(s) << endl;
    }
    cout << "2:" << endl;
    {
        string s = "abaabbcccc";
        cout << Solution().Maximumlength(s) << endl;
    }
    cout << "3:" << endl;
    {
        string s = "ababbcccc";
        cout << Solution().Maximumlength(s) << endl;
    }
    cout << "4:" << endl;
    {
        string s = "abccabbcccc";
        cout << Solution().Maximumlength(s) << endl;
    }
    cout << "5:" << endl;
    {
        string s = "aabccabbcccc";
        cout << Solution().Maximumlength(s) << endl;
    }
    cout << "6:" << endl;
    {
        string s = "aaaabbcc";
        cout << Solution().Maximumlength(s) << endl;
    }
    cout << "7:" << endl;
    {
        string s = "aaaabbcb";
        cout << Solution().Maximumlength(s) << endl;
    }
    cout << "8:" << endl;
    {
        string s = "aaaab";
        cout << Solution().Maximumlength(s) << endl;
    }
    // cout << "3:" << endl;
    // {
    //     string s = "";
    //     cout << Solution().Maximumlength0(s) << endl;
    //     cout << Solution().Maximumlength1(s) << endl;
    // }
    // cout << "4:" << endl;
    // {
    //     string s = "n";
    //     cout << Solution().Maximumlength0(s) << endl;
    //     cout << Solution().Maximumlength1(s) << endl;
    // }
    // cout << "5:" << endl;
    // {
    //     string s = "np";
    //     cout << Solution().Maximumlength0(s) << endl;
    //     cout << Solution().Maximumlength1(s) << endl;
    // }
    // cout << "6:" << endl;
    // {
    //     string s = "npy";
    //     cout << Solution().Maximumlength0(s) << endl;
    //     cout << Solution().Maximumlength1(s) << endl;
    // }
    
    return 0;
}
#endif