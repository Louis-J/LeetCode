#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    static inline size_t FindKImpl(vector<int> &arr, size_t b, size_t e, size_t K) {
        auto CmpFunc = std::greater<int>();
        switch(e-b) {
            case 3: {
                if(!CmpFunc(arr[b], arr[b+1]))
                    std::swap(arr[b], arr[b+1]);
                if(!CmpFunc(arr[b+1], arr[b+2]))
                    std::swap(arr[b+1], arr[b+2]);
                if(!CmpFunc(arr[b], arr[b+1]))
                    std::swap(arr[b], arr[b+1]);
                return arr[K];
            }
            case 2: {
                if(CmpFunc(arr[b+1], arr[b]))
                    std::swap(arr[b], arr[b+1]);
                return arr[K];
            }
            case 1: return arr[K];
            default: {
                size_t midNum = arr[(b+e)/2];
                if(CmpFunc(midNum, arr[b]) + CmpFunc(midNum, arr[e-1]) != 1) { //midNum不是三者之中
                    if(CmpFunc(midNum, arr[b])) { //midNum最小
                        if(!CmpFunc(arr[b], arr[e-1]))
                            std::swap(arr[b], arr[e-1]);
                        midNum = arr[b];
                    } else { //midNum最大
                        if(CmpFunc(arr[b], arr[e-1]))
                            std::swap(arr[b], arr[e-1]);
                        midNum = arr[b];
                    }
                } else {
                    std::swap(arr[(b+e)/2], arr[b]);
                    midNum = arr[b];
                }
                size_t l = b, r = e-1;
                while(l < r) {
                    while(l < r && !CmpFunc(arr[r], midNum))
                        r--;
                    if(l == r)
                        break;
                    arr[l] = arr[r];
                    // std::swap(arr[l], arr[r]);
                    while(l < r && CmpFunc(arr[l], midNum))
                        l++;
                    if(l == r)
                        break;
                    arr[r] = arr[l];
                    // std::swap(arr[l], arr[r]);
                }
                arr[l] = midNum;
                if(K == l)
                    return arr[K];
                else if(K < l)
                    return FindKImpl(arr, b, l, K);
                else
                    return FindKImpl(arr, r+1, e, K);
            }
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return FindKImpl(nums, 0, nums.size(), k-1);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {3, 2, 1, 5, 6, 4};
        cout << Solution().findKthLargest(nums, 2) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        cout << Solution().findKthLargest(nums, 4) << endl;
    }
    // cout << "3:" << endl;
    // {
    // }
    // cout << "4:" << endl;
    // {
    // }
    
    return 0;
}
#endif