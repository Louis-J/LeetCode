#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

//过于复杂，且有bug
class AllOne0 {
    unordered_multimap<int, string> amap;
    unordered_map<int, tuple<int, int>> bmap;
    unordered_map<string, tuple<int, unordered_multimap<int, string>::iterator>> cmap;

    int maxkn;
    int minkn;
public:
    /** Initialize your data structure here. */
    // AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = cmap.find(key);
        if(it != cmap.end()) {
            auto &num = get<0>(it->second);
            auto &jt = get<1>(it->second);
            amap.erase(jt);
            jt = amap.emplace(num+1, key);
            if(amap.find(num) == amap.end()) {
                int priv = get<0>(bmap[num]);
                int next = get<1>(bmap[num]);
                bmap.erase(num);
                if(next == -1) {
                    bmap.emplace(num+1, make_tuple(priv, -1));
                    maxkn = num+1;
                } else if(next == num+1)
                    get<0>(bmap[next]) = priv;
                else {
                    bmap.emplace(num+1, make_tuple(priv, next));
                    get<0>(bmap[next]) = num+1;
                }
                if(priv != -1)
                    get<1>(bmap[priv]) = num+1;
                else
                    minkn = num+1;
            } else {
                int &next = get<1>(bmap[num]);
                if(next == -1) {
                    bmap.emplace(num+1, make_tuple(num, -1));
                    maxkn = num+1;
                    next = num+1;
                } else if(next != num+1) {
                    bmap.emplace(num+1, make_tuple(num, next));
                    get<0>(bmap[next]) = num+1;
                    next = num+1;
                }
            }
            num++;
        } else {
            if(amap.size() == 0) {
                bmap.emplace(1, make_tuple(-1, -1));
                auto jt = amap.emplace(1, key);
                cmap.emplace(key, make_tuple(1, jt));
                maxkn = minkn = 1;
            } else {
                auto it = bmap.find(1);
                auto jt = amap.emplace(1, key);
                if(it == bmap.end()) {
                    get<0>(bmap[minkn]) = 1;
                    bmap.emplace(1, make_tuple(-1, minkn));
                    minkn = 1;
                }
                cmap.emplace(key, make_tuple(1, jt));
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = cmap.find(key);
        if(it != cmap.end()) {
            auto &num = get<0>(it->second);
            auto &jt = get<1>(it->second);
            amap.erase(jt);
            if(num == 1) {
                if(amap.find(1) == amap.end()) {
                    int priv = get<0>(bmap[1]);
                    int next = get<1>(bmap[1]);
                    bmap.erase(1);
                    minkn = next;
                }
                cmap.erase(it);
                return;
            } else if(amap.find(num) == amap.end()) {
                int priv = get<0>(bmap[num]);
                int next = get<1>(bmap[num]);
                bmap.erase(num);
                if(priv == num-1) {
                    get<1>(bmap[priv]) = next;
                } else if(priv == -1) {
                    bmap.emplace(num-1, make_tuple(-1, next));
                    minkn = num-1;
                } else {
                    bmap.emplace(num-1, make_tuple(priv, next));
                    get<1>(bmap[priv]) = num-1;
                }
                if(next != -1)
                    get<0>(bmap[next]) = num-1;
                else
                    maxkn = num-1;
            } else {
                int priv = get<0>(bmap[num]);
                if(priv == -1) {
                    bmap.emplace(num-1, make_tuple(-1, num));
                    minkn = num-1;
                } else if(priv != num-1) {
                    bmap.emplace(num+1, make_tuple(priv, num));
                    get<0>(bmap[priv]) = num-1;
                }
            }
            num--;
            jt = amap.emplace(num, key);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(amap.size() == 0) {
            return "";
        } else {
            return amap.find(maxkn)->second;
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(amap.size() == 0) {
            return "";
        } else {
            return amap.find(minkn)->second;
        }
    }
};

//可能仍然有bug
class AllOne1 {
    unordered_multimap<int, string> amap;
    unordered_map<int, tuple<int, int>> bmap;
    unordered_map<string, tuple<int, unordered_multimap<int, string>::iterator>> cmap;

    int maxkn;
    int minkn;
public:
    /** Initialize your data structure here. */
    // AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = cmap.find(key);
        if(it != cmap.end()) {
            auto &num = get<0>(it->second);
            auto &jt = get<1>(it->second);
            amap.erase(jt);
            jt = amap.emplace(num+1, key);
            if(amap.find(num) == amap.end()) {
                int priv = get<0>(bmap[num]);
                int next = get<1>(bmap[num]);
                bmap.erase(num);
                if(next == -1) {
                    bmap.emplace(num+1, make_tuple(priv, -1));
                    maxkn = num+1;
                } else if(next == num+1)
                    get<0>(bmap[next]) = priv;
                else {
                    bmap.emplace(num+1, make_tuple(priv, next));
                    get<0>(bmap[next]) = num+1;
                }
                if(priv != -1)
                    get<1>(bmap[priv]) = num+1;
                else
                    minkn = num+1;
            } else {
                int &next = get<1>(bmap[num]);
                if(next == -1) {
                    bmap.emplace(num+1, make_tuple(num, -1));
                    maxkn = num+1;
                    next = num+1;
                } else if(next != num+1) {
                    bmap.emplace(num+1, make_tuple(num, next));
                    get<0>(bmap[next]) = num+1;
                    next = num+1;
                }
            }
            num++;
        } else {
            if(amap.size() == 0) {
                bmap.emplace(1, make_tuple(-1, -1));
                auto jt = amap.emplace(1, key);
                cmap.emplace(key, make_tuple(1, jt));
                maxkn = minkn = 1;
            } else {
                auto it = bmap.find(1);
                auto jt = amap.emplace(1, key);
                if(it == bmap.end()) {
                    get<0>(bmap[minkn]) = 1;
                    bmap.emplace(1, make_tuple(-1, minkn));
                    minkn = 1;
                }
                cmap.emplace(key, make_tuple(1, jt));
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = cmap.find(key);
        if(it != cmap.end()) {
            auto &num = get<0>(it->second);
            auto &jt = get<1>(it->second);
            amap.erase(jt);
            if(num == 1) {
                if(amap.find(1) == amap.end()) {
                    int priv = get<0>(bmap[1]);
                    int next = get<1>(bmap[1]);
                    bmap.erase(1);
                    minkn = next;
                    if(next != -1)
                        get<0>(bmap[next]) = -1;
                }
                cmap.erase(it);
                return;
            } else if(amap.find(num) == amap.end()) {
                int priv = get<0>(bmap[num]);
                int next = get<1>(bmap[num]);
                bmap.erase(num);
                if(priv == num-1) {
                    get<1>(bmap[priv]) = next;
                } else if(priv == -1) {
                    bmap.emplace(num-1, make_tuple(-1, next));
                    minkn = num-1;
                } else {
                    bmap.emplace(num-1, make_tuple(priv, next));
                    get<1>(bmap[priv]) = num-1;
                }
                if(next != -1)
                    get<0>(bmap[next]) = num-1;
                else
                    maxkn = num-1;
            } else {
                int &priv = get<0>(bmap[num]);
                if(priv == -1) {
                    bmap.emplace(num-1, make_tuple(-1, num));
                    minkn = num-1;
                    priv = num-1;
                } else if(priv != num-1) {
                    bmap.emplace(num-1, make_tuple(priv, num));
                    get<1>(bmap[priv]) = num-1;
                    priv = num-1;
                }
            }
            num--;
            jt = amap.emplace(num, key);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(amap.size() == 0) {
            return "";
        } else {
            return amap.find(maxkn)->second;
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(amap.size() == 0) {
            return "";
        } else {
            return amap.find(minkn)->second;
        }
    }
};

class AllOne {
    unordered_multimap<int, tuple<string, int, int>> amap;
    unordered_map<string, tuple<int, unordered_multimap<int, tuple<string, int, int>>::iterator>> cmap;

    int maxkn;
    int minkn;
public:
    /** Initialize your data structure here. */
    // AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // cout << "inc\n";
        auto it = cmap.find(key);
        if(it != cmap.end()) {
            auto &num = get<0>(it->second);
            auto &jt = get<1>(it->second);

            int priv = get<1>(amap.find(num)->second);
            int next = get<2>(amap.find(num)->second);
            amap.erase(jt);
            auto njt = amap.find(num);
            if(njt == amap.end()) {
                if(next == -1) {
                    jt = amap.emplace(num+1, make_tuple(key, priv, -1));
                    maxkn = num+1;
                } else if(next == num+1) {
                    auto &kt0 = amap.find(num+1)->second;
                    jt = amap.emplace(num+1, make_tuple(key, priv, -1));
                    auto &kt1 = jt->second;
                    get<1>(kt0) = priv;
                    get<2>(kt1) = get<2>(kt0);
                } else {
                    jt = amap.emplace(num+1, make_tuple(key, priv, next));
                    get<1>(amap.find(next)->second) = num+1;
                }
                if(priv != -1)
                    get<2>(amap.find(priv)->second) = num+1;
                else
                    minkn = num+1;
            } else {
                if(next == -1) {
                    jt = amap.emplace(num+1, make_tuple(key, num, next));
                    get<1>(njt->second) = priv;
                    get<2>(njt->second) = num+1;
                    maxkn = num+1;
                } else if(next != num+1) {
                    jt = amap.emplace(num+1, make_tuple(key, num, next));
                    get<1>(njt->second) = priv;
                    get<2>(njt->second) = num+1;
                    get<1>(amap.find(next)->second) = num+1;
                } else {
                    auto &kt = amap.find(next)->second;
                    jt = amap.emplace(num+1, make_tuple(key, num, get<2>(kt)));
                }
            }
            num++;
        } else {
            if(amap.size() == 0) {
                auto jt = amap.emplace(1, make_tuple(key, -1, -1));
                cmap.emplace(key, make_tuple(1, jt));
                maxkn = minkn = 1;
            } else {
                auto kt = amap.find(1);
                unordered_multimap<int, tuple<string, int, int>>::iterator jt;
                if(kt == amap.end()) {
                    jt = amap.emplace(1, make_tuple(key, -1, minkn));
                    get<2>(jt->second) = minkn;
                    get<1>(amap.find(minkn)->second) = 1;
                    minkn = 1;
                } else {
                    jt = amap.emplace(1, make_tuple(key, -1, get<2>(kt->second)));
                }
                cmap.emplace(key, make_tuple(1, jt));
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = cmap.find(key);
        if(it != cmap.end()) {
            auto &num = get<0>(it->second);
            auto &jt = get<1>(it->second);
            
            int priv = get<1>(amap.find(num)->second);
            int next = get<2>(amap.find(num)->second);
            amap.erase(jt);
            auto njt = amap.find(num);
            if(num == 1) {
                if(amap.find(1) == amap.end()) {
                    minkn = next;
                    if(next != -1)
                        get<1>(amap.find(next)->second) = -1;
                }
                cmap.erase(it);
                return;
            } else if(njt == amap.end()) {
                if(priv == -1) {
                    jt = amap.emplace(num-1, make_tuple(key, -1, next));
                    minkn = num-1;
                } else if(priv == num-1) {
                    auto &kt0 = amap.find(num-1)->second;
                    jt = amap.emplace(num-1, make_tuple(key, -1, next));
                    auto &kt1 = jt->second;
                    get<2>(kt0) = next;
                    get<1>(kt1) = get<1>(kt0);
                } else {
                    jt = amap.emplace(num-1, make_tuple(key, priv, next));
                    get<1>(amap.find(priv)->second) = num-1;
                }
                if(next != -1)
                    get<1>(amap.find(next)->second) = num-1;
                else
                    maxkn = num-1;
            } else {
                if(priv == -1) {
                    jt = amap.emplace(num-1, make_tuple(key, -1, num));
                    minkn = num-1;
                    get<1>(njt->second) = num-1;
                    get<2>(njt->second) = next;
                } else if(priv != num-1) {
                    jt = amap.emplace(num-1, make_tuple(key, priv, num));
                    get<2>(amap.find(priv)->second) = num-1;
                    get<1>(njt->second) = num-1;
                    get<2>(njt->second) = next;
                } else {
                    auto &kt = amap.find(priv)->second;
                    jt = amap.emplace(num-1, make_tuple(key, get<1>(kt), num));
                }
            }
            num--;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(amap.size() == 0) {
            return "";
        } else {
            return get<0>(amap.find(maxkn)->second);
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(amap.size() == 0) {
            return "";
        } else {
            return get<0>(amap.find(minkn)->second);
        }
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 0:" << endl;
    // {
    //     unordered_multimap<int, string> amap;
    //     auto it0 = amap.emplace(1, "haha");
    //     auto it1 = amap.emplace(1, "hehe");
    //     auto it2 = amap.emplace(1, "hoho");
    //     auto it3 = amap.emplace(1, "hihi");

    //     cout << it0->second << endl;
    //     cout << it1->second << endl;
    //     cout << it2->second << endl;
    //     cout << it3->second << endl;

    //     amap.erase(it2);
    //     amap.erase(it3);

    //     cout << it0->second << endl;
    //     cout << it1->second << endl;

    //     amap.erase(it0);
    //     amap.erase(it1);
    //     it0 = amap.emplace(1, "haha");
    //     it1 = amap.emplace(1, "hehe");
    //     it2 = amap.emplace(1, "hoho");
    //     it3 = amap.emplace(1, "hihi");
    //     amap.erase(it0);
    //     amap.erase(it1);

    //     cout << it2->second << endl;
    //     cout << it3->second << endl;
    // }
    // cout << " 1:" << endl;
    // {
    //     AllOne* obj = new AllOne();
    //     obj->inc("haha");
    //     obj->inc("haha");
    //     obj->dec("hehe");
    //     cout << obj->getMaxKey() << endl;
    //     cout << obj->getMinKey() << endl;
    //     obj->inc("hehe");
    //     cout << obj->getMinKey() << endl;
    //     obj->inc("hehe");
    //     obj->dec("haha");
    //     cout << obj->getMaxKey() << endl;
    //     cout << obj->getMinKey() << endl;
    //     obj->dec("haha");
    //     cout << obj->getMinKey() << endl;
    //     obj->dec("hehe");
    //     cout << obj->getMinKey() << endl;
    //     obj->dec("hehe");
    //     cout << obj->getMinKey() << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     AllOne* obj = new AllOne();
    //     obj->inc("hello");
    //     cout << obj->getMaxKey() << endl;
    //     cout << obj->getMinKey() << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     AllOne* obj = new AllOne();
    //     obj->inc("a");
    //     obj->inc("b");
    //     obj->inc("b");
    //     obj->inc("c");
    //     obj->inc("c");
    //     obj->inc("c");
    //     obj->dec("b");
    //     obj->dec("b");
    //     cout << obj->getMinKey() << endl;
    //     obj->dec("a");
    //     cout << obj->getMaxKey() << endl;
    //     cout << obj->getMinKey() << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     AllOne* obj = new AllOne();
    //     obj->inc("hello");
    //     obj->inc("goodbye");
    //     obj->inc("hello");
    //     obj->inc("hello");
    //     cout << obj->getMaxKey() << endl;
    //     obj->inc("leet");
    //     obj->inc("code");
    //     obj->inc("leet");
    //     obj->dec("hello");
    //     obj->inc("leet");
    //     obj->inc("code");
    //     obj->inc("code");
    //     cout << obj->getMaxKey() << endl;
    // }
    cout << " 5:" << endl;
    {
        AllOne* obj = new AllOne();
        obj->inc("hello");
        obj->inc("world");
        obj->inc("leet");
        obj->inc("code");
        obj->inc("DS");
        obj->inc("leet");
        cout << obj->getMaxKey() << endl;
        obj->inc("DS");
        obj->dec("leet");
        cout << obj->getMaxKey() << endl;
        obj->dec("DS");
        obj->inc("hello");
        cout << obj->getMaxKey() << endl;
        obj->inc("hello");
        obj->inc("hello");
        obj->dec("world");
        obj->dec("leet");
        obj->dec("code");
        obj->dec("DS");
        cout << obj->getMaxKey() << endl;
        obj->inc("new");
        obj->inc("new");
        obj->inc("new");
        obj->inc("new");
        obj->inc("new");
        obj->inc("new");
        cout << obj->getMaxKey() << endl;
        cout << obj->getMinKey() << endl;
    }
    return 0;
}
#endif