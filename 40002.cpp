// #include <iostream>
// #include <string>
// #include <set>

// using std::set;
// int main() {
//     std::string str;
//     std::cin >> str;
//     set<std::string> ss;
//     for(auto i = 0; i < str.size(); i++)
//         for(auto j = i + 1; j < str.size() + 1; j++)
//             ss.emplace(str.substr(i, j-i));
//     std::cout << ss.size();
//     return 0;
// }

#include <iostream>
#include <string>
#include <set>

int main() {
    std::string str;
    std::cin >> str;
    size_t nums = 0;

    std::set<std::string> sold, snew;
    for(std::string s = "A"; s[0] <= 'Z'; s[0]++) {
        if(str.find(s[0]) != std::string::npos) {
            sold.emplace(s);
            nums++;
        }
    }
    while(sold.size()) {
        size_t nextLen = sold.begin()->size()+1;
        for(auto &s : sold) {
            for(size_t pos = str.find(s); pos != std::string::npos; pos = str.find(s, pos + 1)) {
                if(pos != 0)
                    snew.emplace(str.substr(pos-1, nextLen));
                if(pos + nextLen <= str.size())
                    snew.emplace(str.substr(pos, nextLen));
            }
        }
        nums += snew.size();
        std::swap(sold, snew);
        snew.clear();
    }
    std::cout << nums;
    return 0;
}
