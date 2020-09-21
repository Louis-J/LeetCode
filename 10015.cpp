#include <iostream>
#include <string>
#include <string_view>

void Post(std::string_view pre, std::string_view in) {
    if(pre.size() == 0)
        return;
    else if(pre.size() == 1) {
        std::cout << pre[0];
        return;
    }
    size_t pos = in.find(pre[0]);
    Post(pre.substr(1, pos), in.substr(0, pos));
    Post(pre.substr(pos + 1), in.substr(pos + 1));
    std::cout << pre[0];
}
int main() {
    std::string pre, in;
    std::cin >> pre >> in;
    Post(pre, in);
    return 0;
}

// #include <iostream>
// #include <string>

// void Post(std::string pre, std::string in) {
//     if(pre.size() == 0)
//         return;
//     else if(pre.size() == 1) {
//         std::cout << pre[0];
//         return;
//     }
//     size_t pos = in.find(pre[0]);
//     Post(pre.substr(1, pos), in.substr(0, pos));
//     Post(pre.substr(pos + 1), in.substr(pos + 1));
//     std::cout << pre[0];
// }
// int main() {
//     std::string pre, in;
//     std::cin >> pre >> in;
//     Post(pre, in);
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <algorithm>

// void Post(char pre[], char in[], size_t length) {
//     if(length == 0)
//         return;
//     else if(length == 1) {
//         std::cout << pre[0];
//         return;
//     }
//     size_t pos = std::find(in, in + length, pre[0]) - in;
//     Post(pre + 1, in, pos);
//     Post(pre + pos + 1, in + pos + 1, length - pos - 1);
//     std::cout << pre[0];
// }
// int main() {
//     std::string pre, in;
//     std::cin >> pre >> in;
//     Post(&pre[0], &in[0], pre.size());
//     return 0;
// }