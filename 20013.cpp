// 假设数字不重复
// 假设错误
// #include <iostream>
// #include <map>

// using std::map;
// int main() {
//     map<int, size_t> dict;
//     while(true) {
//         int i;
//         std::cin >> i;
//         dict.emplace(i, dict.size());
//         if(std::cin.get() != ',')
//             break;
//     };

//     int target;
//     std::cin >> target;

//     for(auto &i : dict) {
//         if(target == i.first + i.first)
//             continue;
//         auto j = dict.find(target - i.first);
//         if(j != dict.end()) {
//             std::cout << std::min(i.second, j->second) << ',' << std::max(i.second, j->second);
//             break;
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <map>

using std::multimap;

int main() {
    multimap<int, size_t> dict;
    while(true) {
        int i;
        std::cin >> i;
        dict.emplace(i, dict.size());
        if(std::cin.get() != ',')
            break;
    };
    int target;
    std::cin >> target;

    if(target % 2 == 0) {
        auto i = dict.lower_bound(target / 2);
        if(i != dict.end()) {
            auto j = i++;
            if(i != dict.end() && i->first == target / 2) {
                std::cout << std::min(i->second, j->second) << ',' << std::max(i->second, j->second);
                return 0;
            }
        }
    }
    // if(target % 2 == 0) {
    //     if(dict.count(target / 2) == 2) {
    //         auto i = dict.lower_bound(target % 2);
    //         auto j = i++;
    //         std::cout << "haha" << std::min(i->second, j->second) << ',' << std::max(i->second, j->second);
    //         return 0;
    //     }
    // }
    for(auto &i : dict) {
        auto j = dict.find(target - i.first);
        if(j != dict.end()) {
            std::cout << std::min(i.second, j->second) << ',' << std::max(i.second, j->second);
            break;
        }
    }
    return 0;
}