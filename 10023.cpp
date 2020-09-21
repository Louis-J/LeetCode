// #include <iostream>
// #include <string>
// #include <string_view>
// #include <map>

// int main() {
//     std::string s1, s2;
//     std::cin >> s1 >> s2;
//     const std::string_view s1v(s1), s2v(s2);
//     std::map<std::string_view, size_t> ss;
//     for(auto i = 0; i < s1v.size(); i++)
//         for(auto j = i + 1; j < s1v.size() + 1; j++)
//             ss[s1v.substr(i, j-i)]++;
//     size_t nums = 0;
//     for(auto &[k, v] : ss) {
//         int num = 0;
//         for(size_t pos = s2v.find(k); pos != std::string::npos; pos = s2v.find(k, pos + 1))
//             num++;
//         nums += num*v;
//     }
//     std::cout << nums;
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <map>

// int main() {
//     std::string s1, s2;
//     std::cin >> s1 >> s2;
//     std::map<std::string, size_t> ss;
//     for(auto i = 0; i < s1.size(); i++)
//         for(auto j = i + 1; j < s1.size() + 1; j++)
//             ss[s1.substr(i, j-i)]++;
//     size_t nums = 0;
//     // for(auto &[k, v] : ss) {
//     for(auto &i : ss) {
//         auto &k = i.first;
//         auto &v = i.second;
//         int num = 0;
//         for(size_t pos = s2.find(k); pos != std::string::npos; pos = s2.find(k, pos + 1))
//             num++;
//         nums += num*v;
//     }
//     std::cout << nums;
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <array>

// unsigned int f(const unsigned int n) {
//     return n * (n + 1) / 2;
// }

// int main() {
//     std::string s1, s2;
//     std::cin >> s1 >> s2;
//     size_t nums = 0;
//     for(auto i = 0; i < s1.size(); i++) {
//         size_t len = 0;
//         for(auto j = 0; j < std::min(s1.size() - i, s2.size()); j++) {
//             auto &c1 = s1[i + j];
//             auto &c2 = s2[j];
//             if(c1 == c2) {
//                 len++;
//             } else if(len != 0) {
//                 nums += f(len);
//                 len = 0;
//             }
//         }
//         nums += f(len);
//     }
//     for(auto i = 1; i < s2.size(); i++) {
//         size_t len = 0;
//         for(auto j = 0; j < std::min(s2.size() - i, s1.size()); j++) {
//             auto &c2 = s2[i + j];
//             auto &c1 = s1[j];
//             if(c1 == c2) {
//                 len++;
//             } else if(len != 0) {
//                 nums += f(len);
//                 len = 0;
//             }
//         }
//         nums += f(len);
//     }

//     std::cout << nums;
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <set>

// int main() {
//     std::string s1, s2;
//     std::cin >> s1 >> s2;
//     size_t nums = 0;
//     std::set<std::string> sold, snew;
//     for(std::string s = "a"; s[0] <= 'z'; s[0]++)
//         sold.emplace(s);
//     while(sold.size()) {
//         for(auto &str : sold) {
//             int num1 = 0;
//             for(size_t pos = s1.find(str); pos != std::string::npos; pos = s1.find(str, pos + 1)) {
//                 num1++;
//                 if(pos != 0)
//                     snew.emplace(s1.substr(pos-1, str.size()+1));
//                 if(pos + str.size() < s1.size())
//                     snew.emplace(s1.substr(pos, str.size() + 1));
//             }
//             int num2 = 0;
//             for(size_t pos = s2.find(str); pos != std::string::npos; pos = s2.find(str, pos + 1)) {
//                 num2++;
//                 if(pos != 0)
//                     snew.emplace(s2.substr(pos-1, str.size()+1));
//                 if(pos + str.size() < s2.size())
//                     snew.emplace(s2.substr(pos, str.size() + 1));
//             }
//             nums += num1 * num2;
//         }
//         std::swap(sold, snew);
//         snew.clear();
//     }
//     std::cout << nums;
//     return 0;
// }

#include "bits/stdc++.h"
#include <string>
using namespace std;
using u64 = unsigned long long;
using std::string;
const int maxn = 1e6+10;

string s1, s2;
int ch[maxn][27], fa[maxn], len[maxn];
int last=1, sz=1;
int cnt[maxn][2];
int a[maxn], c[maxn];

void add(int c, int f) {
    int p=last, np=last=++sz;
    len[np]=len[p]+1, cnt[np][f]=1;
    for(; p&&!ch[p][c]; p=fa[p]) ch[p][c]=np;
    if(!p) fa[np]=1;
    else {
        int q=ch[p][c];
        if(len[q]==len[p]+1) fa[np]=q;
        else {
            int nq=++sz;
            fa[nq]=fa[q], len[nq]=len[p]+1;
            memcpy(ch[nq],ch[q],108);
            fa[q]=fa[np]=nq;
            for(; p&&ch[p][c]==q; p=fa[p]) ch[p][c]=nq;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin >> s1 >> s2;
    // scanf("%s%s", s0, s1);
    for(int i = 0; i < s1.size(); ++i)
        add(s1[i]-'a', 0);
    add(26,0);
    for(int i = 0; i < s2.size(); ++i)
        add(s2[i]-'a', 1);

    for(int i=1; i<=sz; ++i)
        c[len[i]]++;
    for(int i=1; i<=sz; ++i)
        c[i]+=c[i-1];
    for(int i=1; i<=sz; ++i)
        a[c[len[i]]--]=i;

    for(int i=sz; i; --i)
        cnt[fa[a[i]]][0]+=cnt[a[i]][0],
        cnt[fa[a[i]]][1]+=cnt[a[i]][1];
    u64 ans=0;
    
    for(int i=1; i<=sz; ++i)
        ans+=1LL*cnt[i][0]*cnt[i][1]*(len[i]-len[fa[i]]);
    cout<<ans<<endl;
}