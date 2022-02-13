#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution0 {
    static inline void AddStrL(vector<string> &strs, string &s, size_t b, size_t e) {
        vector<string> slices;
        for(size_t i = b; i <= e; i++) {
            if(s[i] == '(' && (i == s.size() - 1 || s[i + 1] != '(')) {
                string tmp;
                for(size_t j = b; j < i; j++) tmp += s[j];
                for(size_t j = i + 1; j <= e; j++) tmp += s[j];
                slices.emplace_back(tmp);
            }
        }
        if(strs.size() == 0) {
            swap(slices, strs);
        } else {
            vector<string> newstrs;
            for(auto &i : strs)
                for(auto &j : slices) newstrs.emplace_back(j + i);
            swap(newstrs, strs);
        }
    }
    static inline void AddStrR(vector<string> &strs, string &s, size_t b, size_t e) {
        vector<string> slices;
        for(size_t i = b; i <= e; i++) {
            if(s[i] == ')' && (i == 0 || s[i - 1] != ')')) {
                string tmp;
                for(size_t j = b; j < i; j++) tmp += s[j];
                for(size_t j = i + 1; j <= e; j++) tmp += s[j];
                slices.emplace_back(tmp);
            }
        }
        if(strs.size() == 0) {
            swap(slices, strs);
        } else {
            vector<string> newstrs;
            for(auto &i : strs)
                for(auto &j : slices) newstrs.emplace_back(i + j);
            swap(newstrs, strs);
        }
    }
    static inline void RemoveR(string &s, vector<string> &retR, int &last) {
        size_t le = 0, sum = 0, lc = 0;
        for(size_t i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case '(':
                    sum++;
                    break;
                case ')':
                    if(sum == 0) {
                        if(le != i) AddStrR(retR, s, le, i);
                        le = i + 1;
                    } else
                        sum--;
                    if(sum == 0) lc = i + 1;
                    break;
                default:
                    if(sum == 0) lc = i + 1;
                    break;
            }
        }
        if(retR.size() == 0) retR.emplace_back();
        if(lc > le) {
            for(auto &i : retR) i.append(&(s[le]), &(s[lc]));
        }
        last = max(lc, le);
    }
    static inline void RemoveL(string &s, vector<string> &retL, int &last) {
        int le = s.size() - 1, sum = 0, lc = le;
        for(int i = le; i >= last; i--) {
            switch(s[i]) {
                case ')':
                    sum++;
                    break;
                case '(':
                    if(sum == 0) {
                        if(le != i) AddStrL(retL, s, i, le);
                        le = i - 1;
                    } else
                        sum--;
                    if(sum == 0) lc = i - 1;
                    break;
                default:
                    if(sum == 0) lc = i - 1;
                    break;
            }
        }
        if(lc > le) {
            if(retL.size() == 0)
                retL.emplace_back(&(s[le]), &(s[lc]));
            else
                for(auto &i : retL) i.append(&(s[le]), &(s[lc]));
        }
    }

public:
    vector<string> removeInvalidParentheses0(string s) {
        vector<string> retR;
        int            last;
        RemoveR(s, retR, last);
        if(last != s.size()) {
            vector<string> retL;
            RemoveL(s, retL, last);
            if(retL.size() != 0) {
                vector<string> newstrs;
                for(auto &i : retR)
                    for(auto &j : retL) newstrs.emplace_back(i + j);
                swap(newstrs, retR);
            }
        }
        return retR;
    }
    vector<string> removeInvalidParentheses(string s) {
        size_t b = 0, e = s.size() - 1;
        for(; b < e && s[b] != '('; b++)
            ;
        for(; b < e && s[e] != ')'; b++)
            ;
        vector<string> retR;
        int            last;
        RemoveR(s, retR, last);
        if(last != s.size()) {
            vector<string> retL;
            RemoveL(s, retL, last);
            if(retL.size() != 0) {
                vector<string> newstrs;
                for(auto &i : retR)
                    for(auto &j : retL) newstrs.emplace_back(i + j);
                swap(newstrs, retR);
            }
        }
        return retR;
    }
};

class Solution1 {
    // static inline vector<string> getstrsL(string &s, size_t b, size_t e, int diff, vector<pair<size_t, int>> &llist)
    // {
    //     size_t lend = llist.size()-1, lendn;
    //     for(int m = diff; ; lend--) {
    //         if(m < llist[lend]) {
    //             lendn = llist[lend] - m;
    //             break;
    //         } else {
    //             m -= llist[lend];
    //         }
    //     }
    //     if()
    // }
    static inline vector<string> getstrsR(string &s, size_t b, size_t e, int diff, vector<pair<size_t, int>> &rlist) {
        //全排列，逐个往后移
        vector<string> ret;
        int            last;
        vector<int>    del(rlist.size(), 0);
        for(int i = 0, rem = diff;; i++) {
            if(rem <= rlist[i].second) {
                del[i] = rem;
                rem    = 0;
                last   = i;
                break;
            } else {
                del[i] = rlist[i].second;
                rem -= del[i];
            }
        }

        string out(&s[b], &s[rlist[0].first]);
        for(int i = 1; i < rlist.size(); i++)
            out.append(&s[rlist[i - 1].first + rlist[i - 1].second - del[i - 1]], &s[rlist[i].first]);
        out.append(&s[rlist[rlist.size() - 1].first + rlist[rlist.size() - 1].second - del[rlist.size() - 1]],
                   &s[e + 1]);
        ret.emplace_back(out);

        while(last >= 0) {
            for(int lastp = last, posi = last + 1; posi != del.size(); posi++) {
                if(rlist[posi].second > del[posi]) {
                    del[lastp]--;
                    del[posi]++;
                    lastp = posi;

                    out.resize(rlist[0].first - b);
                    for(int i = 1; i < rlist.size(); i++)
                        out.append(&s[rlist[i - 1].first + rlist[i - 1].second - del[i - 1]], &s[rlist[i].first]);
                    out.append(
                        &s[rlist[rlist.size() - 1].first + rlist[rlist.size() - 1].second - del[rlist.size() - 1]],
                        &s[e + 1]);
                    ret.emplace_back(out);
                }
            }
            if(del[last] == 0) last--;
        }
        return ret;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        size_t b = 0, e = s.size() - 1;
        for(size_t i = 0;; i++) {  // i <= e && s[i] != '('
            if(i > e)
                return vector<string>{s.substr(b)};
            else if(s[i] == '(')
                break;
            else if(s[i] == ')')
                b = i + 1;
        }

        for(size_t i = e;; i--) {  // i >= b && s[i] != ')'
            if(i < b)
                return vector<string>{s.substr(b, e - b)};
            else if(s[i] == ')')
                break;
            else if(s[i] == '(')
                e = i - 1;
        }

        vector<pair<size_t, int>> llist, rlist;
        int                       lnum = 0, rnum = 0;
        for(size_t i = b; i <= e; i++) {
            if(s[i] == '(') {
                lnum++;
                if(i > 0 && s[i - 1] == '(') {
                    llist[llist.size() - 1].second++;
                } else {
                    llist.emplace_back(i, 1);
                }
            } else if(s[i] == ')') {
                rnum++;
                if(s[i - 1] == ')') {
                    rlist[rlist.size() - 1].second++;
                } else {
                    rlist.emplace_back(i, 1);
                }
            }
        }

        if(lnum == rnum) {
            return vector<string>{s.substr(b, e - b)};
        } else if(lnum > rnum) {
            int diff = lnum - rnum;
            return vector<string>{};
            // return getstrs(s, diff, llist);
        } else {
            int diff = rnum - lnum;
            // return vector<string>{};
            return getstrsR(s, b, e, diff, rlist);
        }
    }
};

class Solution2 {
    vector<string> removeInvalidParentheses(string s, int lpAll, int rpAll) {
        vector<tuple<string, int, int>> strCut{{}};
        vector<string>                  ret;
        string                          tmp;
        int                             lp   = 0;
        int                             rp   = 0;
        bool                            inRp = false;
        for(auto &c : s) {
            if(c == ')') {
                if(!inRp) inRp = true;
                rp++;
            }
        }
        return ret;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int lp = 0;
        int rp = 0;
        for(auto &c : s) switch(c) {
                case '(':
                    lp++;
                    break;
                case ')':
                    rp++;
                    break;
            }
    }
};

class Solution3 {
public:
    void rmRHelper(vector<string> &ret, vector<pair<string, int>> &strCut, vector<int> &arr, int index, int num) {
        if(index == arr.size() - 1) {
            if(strCut[index].second >= num) {
                arr[index] = num;
                string str;
                for(int i = 0; i <= index; i++) {
                    str.append(strCut[i].first);
                    str.append(strCut[i].second - arr[i], ')');
                }
                ret.emplace_back(str);
            }
            return;
        }
        for(int i = 0; i <= strCut[index].second; i++) {
            arr[index] = i;
            rmRHelper(ret, strCut, arr, index + 1, num - i);
        }
    }
    vector<string> rmR(string s, int num) {
        vector<pair<string, int>> strCut{{"", 0}};
        bool                      inStr = true;
        for(auto &c : s) {
            if(c == ')') {
                if(inStr) inStr = false;
                strCut.back().second++;
            } else {
                if(!inStr) strCut.emplace_back(pair<string, int>{"", 0});
                strCut.back().first.append(1, c);
            }
        }

        vector<string> ret;
        vector<int>    arr(strCut.size());
        rmRHelper(ret, strCut, arr, 0, num);
        return ret;
    }
    vector<string> rmL(string s, int num) {
        string rev;
        for(auto it = s.rbegin(); it != s.rend(); it++) switch(*it) {
                case '(':
                    rev.append(1, ')');
                    break;
                case ')':
                    rev.append(1, '(');
                    break;
                default:
                    rev.append(1, *it);
            }
        auto           retRev = rmR(rev, num);
        vector<string> ret;
        for(auto &str : retRev) {
            rev.erase();
            for(auto it = str.rbegin(); it != str.rend(); it++) switch(*it) {
                    case '(':
                        rev.append(1, ')');
                        break;
                    case ')':
                        rev.append(1, '(');
                        break;
                    default:
                        rev.append(1, *it);
                }
            ret.emplace_back(rev);
        }
        return ret;
    }
    vector<string> removeInvalidParentheses(string s) {
        int lIndex = -1, lsum = 0;

        int rIndex = s.size(), rsum = 0;

        int sum;
        int state;

        sum = state = 0;
        for(int i = 0; i != s.size(); i++) {
            auto c = s[i];
            if(c == '(') {
                sum--;
                state++;
            } else if(c == ')') {
                sum++;
                if(state == 0)
                    lsum = sum, lIndex = i;
                else
                    --state;
            }
        }

        sum = state = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            auto c = s[i];
            if(c == ')') {
                sum--;
                state++;
            } else if(c == '(') {
                sum++;
                if(state == 0)
                    rsum = sum, rIndex = i;
                else
                    --state;
            }
        }

        cout << lIndex << ' ' << rIndex << endl;
        cout << lsum << ' ' << rsum << endl;
        return {};
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     string s = "()())()";
    //     cout << Solution().removeInvalidParentheses(s) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     string s = "(a)())()";
    //     cout << Solution().removeInvalidParentheses(s) << endl;
    // }
    // cout << "3:" << endl;
    // {
    //     string s = ")(";
    //     cout << Solution().removeInvalidParentheses(s) << endl;
    // }
    // cout << "4:" << endl;
    // {
    //     string s = "n";
    //     cout << Solution().removeInvalidParentheses(s) << endl;
    // }
    // cout << "5:" << endl;
    // {
    //     string s = "(()";
    //     cout << Solution().removeInvalidParentheses(s) << endl;
    // }
    // cout << "6:" << endl;
    // {
    //     string s = "((";
    //     cout << Solution().removeInvalidParentheses(s) << endl;
    // }
    // cout << "7:" << endl;
    // {
    //     string s = "((()";
    //     cout << Solution().removeInvalidParentheses(s) << endl;
    // }
    // cout << "8:" << endl;
    // {
    //     string s = "(r(()()(";
    //     cout << Solution().removeInvalidParentheses(s) << endl;
    // }
    cout << "9:" << endl;
    {
        // 4
        string s = ")()())r)";
        cout << Solution().removeInvalidParentheses(s) << endl;
    }

    return 0;
}
#endif
