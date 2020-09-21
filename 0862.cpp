#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int shortestSubarray0(vector<int>& A, int K) {
        size_t minLen = A.size()+1;

        //规避负数情况，判断当l处在什么位置时一定要l增加
        //当某个位置有负数时，一直到前几位加起来为正为止，这一段加起来总和为负，因此l需要一口气越过这几处
        vector<char> mustMinus(A.size(), false);
        for(int i = A.size()-1, sum = 0; i >= 0; i--) {
            if(sum >= 0)
                sum = A[i];
            else
                sum += A[i];
            if(sum < 0)
                mustMinus[i] = true;
        }
        for(long long l = 0, r = 0, sum = 0; (r < A.size()) || (r == A.size() && l < r && (sum >= K || mustMinus[l]));) {
            if(sum >= K || (l < r && mustMinus[l])) {
                sum -= A[l];
                l++;
            } else {
                sum += A[r];
                r++;
            }
            if(sum >= K && r-l < minLen) {
                minLen = r-l;
                if(minLen == 1)
                    return 1;
            }
        }
        if(minLen == A.size()+1)
            return -1;
        return minLen;
    }
    int shortestSubarray(vector<int>& A, int K) {
        size_t minLen = A.size()+1;

        //规避负数情况，判断当l处在什么位置时一定要l增加
        //当某个位置有负数时，一直到前几位加起来为正为止，这一段加起来总和为负，因此l需要一口气越过这几处
        vector<int> lMustJump(A.size(), 0);
        lMustJump[A.size()-1] = A.size();
        for(int i = A.size()-2, sum = 0; i >= 0; i--) {
            if(sum >= 0)
                sum = A[i];
            else
                sum += A[i];

            if(sum < 0)
                if(lMustJump[i+1] == 0)
                    lMustJump[i] = i+1;
                else
                    lMustJump[i] = lMustJump[i+1];
        }

        for(long long l = 0, r = 0, sum = 0; (r < A.size()) || (r == A.size() && l < r && (sum >= K || lMustJump[l]));) {
            if(l < r && lMustJump[l]) {
                if(r <= lMustJump[l]) {
                    sum = 0;
                    r = lMustJump[l];
                    l = lMustJump[l];
                } else {
                    while(l < lMustJump[l])
                        sum -= A[l++];
                }
            } else if(sum >= K) {
                sum -= A[l++];
            } else {
                sum += A[r++];
            }
            if(sum >= K && r-l < minLen) {
                minLen = r-l;
                if(minLen == 1)
                    return 1;
            }
        }
        if(minLen == A.size()+1)
            return -1;
        return minLen;
    }
};

#ifdef LEETCODE
int main() {
    std::pair<vector<int>, int> AKs[] = {
        // {{1}, 1},
        // {{1, 2}, 4},
        {{2,-1,2}, 3},
        {{84,-37,32,40,95}, 167},
        {{-34,37,51,3,-12,-50,51,100,-47,99,34,14,-13,89,31,-14,-44,23,-38,6}, 151},
    };
    for(auto &i : AKs)
        cout << Solution().shortestSubarray(i.first, i.second) << '\n';

    return 0;
}
#endif