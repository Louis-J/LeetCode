#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    // vector<int> decode(vector<int>& encoded) {
    //     // bool expel[encoded.size() + 1] = { false };
    //     bool expel[encoded.size() + 2];
    //     for (auto& i : expel) {
    //         i = false;
    //     }
    //     int temp = 0;
    //     vector<int> ret;
    //     ret.reserve(encoded.size() + 1);
    //     for (auto& i : encoded) {
    //         temp ^= i;
    //         if (temp < encoded.size() + 2)
    //             expel[temp] = true;
    //     }

    //     vector<int> trys;
    //     for (int i = 1; i <= encoded.size();i++) {
    //         if (!expel[i])
    //             trys.emplace_back(i);
    //     }
    //     for (auto i : trys) {
    //         ret.emplace_back(i);
    //         for (auto& j : encoded) {
    //             i ^= j;
    //             if (i > encoded.size() + 1)
    //                 break;
    //             ret.emplace_back(i);
    //         }
    //         if (ret.size() == encoded.size() + 1)
    //             break;
    //         ret.clear();
    //     }
    //     return ret;
    // }
    vector<int> decode(vector<int>& encoded) {
        int all = 0;
        for (int i = 1; i <= encoded.size() + 1; i++)
            all ^= i;
        for (int i = 1; i < encoded.size(); i += 2)
            all ^= encoded[i];
        vector<int> ret;
        ret.reserve(encoded.size() + 1);
        ret.emplace_back(all);
        for (auto& i : encoded) {
            all ^= i;
            ret.emplace_back(all);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> encoded = { 3,1 };
        cout << Solution().decode(encoded) << endl;
        //[1,2,3]
    }
    cout << "2:" << endl;
    {
        vector<int> encoded = { 6,5,4,6 };
        cout << Solution().decode(encoded) << endl;
        //[2,4,1,5,3]
    }

    return 0;
}
#endif
