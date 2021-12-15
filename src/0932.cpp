#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static bool isvalid(vector<int> &arr, int b, int e) {
        if((arr[b] + arr[e])%2 == 1)
            return true;
        int mid = (arr[b] + arr[e])/2;
        for(int i = b+1; i < e; i++)
            if(arr[i] == mid)
                return false;
        return true;
    }
    static bool validate(vector<int> &arr, int b, int e) {
        if(e <= b) {
            if(e < b)
                return true;
            bool valid = true;
            for(int i = 1; i <= b; i++) {
                if (!isvalid(arr, b-i, b) || !isvalid(arr, b, b+i)) {
                    valid = false;
                    break;
                }
            }
            return valid;
        }
        for(int i = b; i < e; i++) {
            swap(arr[b], arr[i]);
            bool valid = true;
            for(int i = e+1; i < arr.size(); i++) {
                if (!isvalid(arr, b, i)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                for(int j = e; j > b; j--) {
                    swap(arr[e], arr[j]);
                    for(int i = 0; i < b; i++) {
                        if (!isvalid(arr, i, e)) {
                            valid = false;
                            break;
                        }
                    }
                    if(valid && isvalid(arr, b, e) && validate(arr, b + 1, e - 1))
                        return true;
                    swap(arr[e], arr[j]);
                }
            }
            swap(arr[b], arr[i]);
        }
        return false;
    }
    void ba(vector<int> &arr, int b, int e, int k, int a) {
        if(e == b)
            arr[b] = k+a;
        else {
            ba(arr, b, (e+b)/2, k*2, a-k);
            ba(arr, (e+b)/2+1, e, k*2, a);
        }
    }
public:
    vector<int> beautifulArray0(int N) {
        vector<int> arr;
        arr.reserve(N);
        for(int i = 1; i <= N; i++)
            arr.emplace_back(i);

        validate(arr, 0, N-1);
        return arr;
    }
    vector<int> beautifulArray(int N) {
        vector<int> arr(N);
        // arr.reserve(N);
        ba(arr, 0, N-1, 1, 0);
        return arr;
    }
};

#ifdef LEETCODE
int main()
{
    cout << " 1:" << endl;
    {
        cout << Solution().beautifulArray(4) << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().beautifulArray(5) << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().beautifulArray(3) << endl;
    }
    cout << " 4:" << endl;
    {
        cout << Solution().beautifulArray(1) << endl;
    }
    return 0;
}
#endif