#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int orderOfLargestPlusSign1(int n, vector<vector<int>>& mines) {
        int rect[n * n];
        tuple<int, int, int, int> info[n * n];
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++)
                rect[i * n + j] = 1;
        }
        for (auto& posi : mines) {
            rect[posi[0] * n + posi[1]] = 0;
        }

        for (int i = 1; i < n - 1;i++) {
            get<0>(info[0 * n + i]) = rect[0 * n + i];
            get<1>(info[0 * n + i]) = rect[0 * n + i];
            get<2>(info[0 * n + i]) = rect[0 * n + i];
            get<3>(info[0 * n + i]) = rect[0 * n + i];

            get<0>(info[(n - 1) * n + i]) = rect[(n - 1) * n + i];
            get<1>(info[(n - 1) * n + i]) = rect[(n - 1) * n + i];
            get<2>(info[(n - 1) * n + i]) = rect[(n - 1) * n + i];
            get<3>(info[(n - 1) * n + i]) = rect[(n - 1) * n + i];

            get<0>(info[i * n + 0]) = rect[i * n + 0];
            get<1>(info[i * n + 0]) = rect[i * n + 0];
            get<2>(info[i * n + 0]) = rect[i * n + 0];
            get<3>(info[i * n + 0]) = rect[i * n + 0];

            get<0>(info[i * n + (n - 1)]) = rect[i * n + (n - 1)];
            get<1>(info[i * n + (n - 1)]) = rect[i * n + (n - 1)];
            get<2>(info[i * n + (n - 1)]) = rect[i * n + (n - 1)];
            get<3>(info[i * n + (n - 1)]) = rect[i * n + (n - 1)];
        }
        get<0>(info[0 * n + 0]) = rect[0 * n + 0];
        get<1>(info[0 * n + 0]) = rect[0 * n + 0];
        get<2>(info[0 * n + 0]) = rect[0 * n + 0];
        get<3>(info[0 * n + 0]) = rect[0 * n + 0];

        get<0>(info[0 * n + (n - 1)]) = rect[0 * n + (n - 1)];
        get<1>(info[0 * n + (n - 1)]) = rect[0 * n + (n - 1)];
        get<2>(info[0 * n + (n - 1)]) = rect[0 * n + (n - 1)];
        get<3>(info[0 * n + (n - 1)]) = rect[0 * n + (n - 1)];

        get<0>(info[(n - 1) * n + 0]) = rect[(n - 1) * n + 0];
        get<1>(info[(n - 1) * n + 0]) = rect[(n - 1) * n + 0];
        get<2>(info[(n - 1) * n + 0]) = rect[(n - 1) * n + 0];
        get<3>(info[(n - 1) * n + 0]) = rect[(n - 1) * n + 0];

        get<0>(info[(n - 1) * n + (n - 1)]) = rect[(n - 1) * n + (n - 1)];
        get<1>(info[(n - 1) * n + (n - 1)]) = rect[(n - 1) * n + (n - 1)];
        get<2>(info[(n - 1) * n + (n - 1)]) = rect[(n - 1) * n + (n - 1)];
        get<3>(info[(n - 1) * n + (n - 1)]) = rect[(n - 1) * n + (n - 1)];


        for (int i = 0; i < n;i++) {
            for (int j = 1; j < n;j++) {
                if (rect[i * n + j] == 0)
                    get<0>(info[i * n + j]) = 0;
                else
                    get<0>(info[i * n + j]) = get<0>(info[i * n + j - 1]) + 1;

                if (rect[j * n + i] == 0)
                    get<2>(info[j * n + i]) = 0;
                else
                    get<2>(info[j * n + i]) = get<2>(info[(j - 1) * n + i]) + 1;
            }
            for (int j = n - 2; j >= 0;j--) {
                if (rect[i * n + j] == 0)
                    get<1>(info[i * n + j]) = 0;
                else
                    get<1>(info[i * n + j]) = get<1>(info[i * n + j + 1]) + 1;

                if (rect[j * n + i] == 0)
                    get<3>(info[j * n + i]) = 0;
                else
                    get<3>(info[j * n + i]) = get<3>(info[(j + 1) * n + i]) + 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++)
                ret = max(ret, min({ get<0>(info[i * n + j]),get<1>(info[i * n + j]),get<2>(info[i * n + j]),get<3>(info[i * n + j]) }));
        }
        return ret;
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int rect[n * n];
        int info[n * n];
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++) {
                rect[i * n + j] = 1;
            }
        }
        for (auto& posi : mines) {
            rect[posi[0] * n + posi[1]] = 0;
        }
        //1
        for (int i = 0; i < n;i++) {
            int tmp = rect[i * n + 0];
            info[i * n + 0] = tmp;
            for (int j = 1; j < n;j++) {
                if (rect[i * n + j] == 0)
                    tmp = 0;
                else
                    tmp++;
                info[i * n + j] = tmp;
            }
        }
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++)
                cout << info[i * n + j] << ' ';
            cout << endl;
        }
        cout << endl;
        //2
        for (int i = 0; i < n;i++) {
            int tmp = rect[0 * n + i];
            info[0 * n + i] = tmp;
            for (int j = 1; j < n;j++) {
                if (rect[j * n + i] == 0)
                    tmp = 0;
                else
                    tmp++;
                info[j * n + i] = min(info[j * n + i], tmp);
            }
        }
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++)
                cout << info[i * n + j] << ' ';
            cout << endl;
        }
        cout << endl;
        //3
        for (int i = 0; i < n;i++) {
            int tmp = rect[i * n + (n - 1)];
            info[i * n + (n - 1)] = tmp;
            for (int j = n - 2; j >= 0;j--) {
                if (rect[i * n + j] == 0)
                    tmp = 0;
                else
                    tmp++;
                info[i * n + j] = min(info[i * n + j], tmp);
            }
        }
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++)
                cout << info[i * n + j] << ' ';
            cout << endl;
        }
        cout << endl;
        //4
        int ret = 0;
        for (int i = 0; i < n;i++) {
            int tmp = rect[(n - 1) * n + i];
            info[(n - 1) * n + i] = tmp;
            ret = max(ret, tmp);
            for (int j = n - 2; j >= 0;j--) {
                if (rect[j * n + i] == 0)
                    tmp = 0;
                else
                    tmp++;
                ret = max(ret, min(info[j * n + i], tmp));
                info[j * n + i] = min(info[j * n + i], tmp);
            }
        }
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++)
                cout << info[i * n + j] << ' ';
            cout << endl;
        }
        cout << endl;
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int n = 5;
        vector<vector<int>> mines = { {4, 2} };
        cout << Solution().orderOfLargestPlusSign(n, mines) << endl;
        //2
    }
    cout << "2:" << endl;
    {
        int n = 2;
        vector<vector<int>> mines = { };
        cout << Solution().orderOfLargestPlusSign(n, mines) << endl;
        //1
    }
    cout << "3:" << endl;
    {
        int n = 1;
        vector<vector<int>> mines = { {0, 0} };
        cout << Solution().orderOfLargestPlusSign(n, mines) << endl;
        //0
    }
    cout << "4:" << endl;
    {
        int n = 2;
        vector<vector<int>> mines = { {0, 0},{0, 1},{1, 0} };
        cout << Solution().orderOfLargestPlusSign(n, mines) << endl;
        //0
    }

    return 0;
}
#endif
