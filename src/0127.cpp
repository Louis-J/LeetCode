#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<sstream>
#include<string>
#include<memory>
#include<map>
//#include <boost/progress.hpp>
#include<assert.h>
//#include <range/v3/all.hpp>
#include<cstdarg>

using namespace std;
//using namespace ranges;

class Solution {
public:
    //类djistra，628ms，性能有点低
    int ladderLength0(std::string beginWord, string endWord, vector<string>& wordList) {
        auto ifnext = [](string& a, string& b){
            for(int i = 0, sum = 0; i < a.size(); i++){
                if(a[i] != b[i] && ++sum >= 2){
                    return false;
                }
            }
            return true;
        };

        list<string> words;
        bool has = false;
        for(auto& s : wordList){
            if(!has && s == endWord){
                has = true;
            }else{
                words.emplace_back(s);
            }
        }
        if(!has){
            return 0;
        }
        multimap<int, string> rlt;
        rlt.emplace(1, beginWord);
        auto instep = [&](int step, auto& w){
            for(auto i = rlt.lower_bound(step); i != rlt.upper_bound(step); i++){
                if(ifnext(*w, i->second)){
                    rlt.emplace(step+1, *w);
                    w = words.erase(w);
                    return true;
                }
            }
            return false;
        };

        for(int i = 1; rlt.find(i) != rlt.end(); i++){
            for(auto j = rlt.lower_bound(i); j != rlt.upper_bound(i); j++){
                if(ifnext(endWord, j->second)){
                    return i+1;
                }
            }
            for(auto w = words.begin(); w != words.end();){
                if(!instep(i, w)){
                    w++;
                }
            }
        }
        return 0;
    }
    //试试最简单的递归实现
    int ladderLength(std::string beginWord, string endWord, vector<string>& wordList) {
        auto ifnext = [](string& a, string& b){
            for(int i = 0, sum = 0; i < a.size(); i++){
                if(a[i] != b[i] && ++sum >= 2){
                    return false;
                }
            }
            return true;
        };

        function recursion;
        recursion = [&](){
            
        };
        
        return 0;
    }
    //神级解答，没看懂
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hashset(wordList.begin(), wordList.end());
        if (!hashset.count(endWord)) return 0;
        
        unordered_set<string> stset{ beginWord };
        unordered_set<string> edset{ endWord };
        for (int step = 1; !stset.empty() && !edset.empty(); ++step) {
            unordered_set<string> tmp;
            if (stset.size() > edset.size())
                swap(stset, edset);
            for (auto w : stset) {
                for (int i = 0; i<beginWord.size(); i++) {
                    string word = w;
                    for (int c = 'a'; c <= 'z'; c++) {
                        if (c == word[i])
                            continue;
                        else
                            word[i] = c;

                        if (edset.count(word))
                            return step + 1;
                        if (hashset.count(word)) {
                            tmp.insert(word);
                            hashset.erase(word);
                        }
                    }
                }
            }
            swap(tmp, stset);
        }
        return 0;
    }
};

 
vector<string> StringVectorCreate(int count, ...)
{
    vector<string> result;
    va_list argptr;
    va_start(argptr, count);
 
    for (int i = 0; i < count; i++)
    {
        char *str = va_arg(argptr, char*);
        result.push_back(str);
    }
    va_end(argptr);
    return result;
}
 

int main() {
    string b("hit");
    string e("cog");
    vector<string> v{"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength(b, e, v);
    return 0;
}