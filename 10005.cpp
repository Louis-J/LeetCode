#include <iostream>
#include <string>

using std::string;
int main() {
    std::ios_base::sync_with_stdio(false);
    string str;
    string wordA, wordB;
    std::getline(std::cin, str);
    std::cin >> wordA >> wordB;
    size_t i = 0;
    for(size_t j = str.find(wordA); j != -1; i = j+wordA.size(), j = str.find(wordA, i)) {
        bool l = false, r = false;
        if(j == 0 || str[j-1] == ' ' || str[j-1] == ',' || str[j-1] == '.')
            l = true;
        if(j == str.size()-1 || str[j+wordA.size()] == ' ' || str[j+wordA.size()] == ',' || str[j+wordA.size()] == '.')
            r = true;
        if(l && r) {
            for(size_t k = i; k < j; k++)
                std::cout << str[k];
            std::cout << wordB;
        } else {
            for(size_t k = i; k < j; k++)
                std::cout << str[k];
            std::cout << wordA;
        }
    }
    return 0;
}
