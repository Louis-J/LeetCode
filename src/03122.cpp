#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //全排列，超时
    int maxCoins0(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 2) {
                return nums[0]*nums[1] + max(nums[0], nums[1]);
            } else if(nums.size() == 1) {
                return nums[0];
            } else {
                return 0;
            }
        }
        int tmp;
        vector<int> index(nums.size()-2);
        tmp = 1;
        for(auto &i : index)
            i = tmp++;
        sort(index.begin(), index.end(), [&nums](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> lidx(nums.size());
        tmp = -1;
        for(auto &i : lidx)
            i = tmp++;
        vector<int> ridx(nums.size());
        tmp = 1;
        for(auto &i : ridx)
            i = tmp++;

        int sum = nums[0]*nums[nums.size()-1] + max(nums[0], nums[nums.size()-1]);
        for(auto &i : index) {
            sum += nums[i]*nums[lidx[i]]*nums[ridx[i]];
            lidx[i+1] = lidx[i];
            ridx[i-1] = ridx[i];
        }
        return sum;
    }
    int maxCoins1(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 2) {
                return nums[0]*nums[1] + max(nums[0], nums[1]);
            } else if(nums.size() == 1) {
                return nums[0];
            } else {
                return 0;
            }
        } else {
            vector<int> newnums(nums.begin()+1, nums.end());
            int summax = maxCoins1(newnums) + nums[0]*nums[1];
            size_t i;
            for(i = 0; i < newnums.size()-1; i++) {
                newnums[i] = nums[i];
                int ret = maxCoins1(newnums);
                int tmp = ret + nums[i]*nums[i+1]*nums[i+2];
                if(summax < tmp)
                    summax = tmp;
            }
            newnums[i] = nums[i];
            int ret = maxCoins1(newnums);
            int tmp = ret + nums[i]*nums[i+1];
            if(summax < tmp)
                summax = tmp;
            return summax;
        }
    }
    //参考的答案：通过设计，建立一个可以分解子问题的模型，做成动态规划
    int maxCoins3(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 2) {
                return nums[0]*nums[1] + max(nums[0], nums[1]);
            } else if(nums.size() == 1) {
                return nums[0];
            } else {
                return 0;
            }
        }

        int numsn[nums.size()+2];
        for(int i = 0; i < nums.size(); i++)
            numsn[i+1] = nums[i];
        numsn[0] = numsn[nums.size()+1] = 1;

        //长度/起始点
        vector<vector<int>> dp(nums.size());
        for(int i = 1; i <= nums.size(); i++)
            dp[0].emplace_back(numsn[i-1]*numsn[i]*numsn[i+1]);
        for(int i = 1; i < dp.size(); i++) {
            for(int j = 0; j < nums.size()-i; j++) {
                //j ~ j+i+2
                int sum = dp[i-1][j+1] + numsn[j]*numsn[j+1]*numsn[j+i+2];
                sum = max(sum, dp[i-1][j] + numsn[j]*numsn[j+i+1]*numsn[j+i+2]);

                //j ~ k + k ~ j+i+2 + numsn[j]*numsn[k]*numsn[j+i+2]
                for(int k = j+2; k < j+i+1; k++) {
                    sum = max(sum, dp[k-j-2][j] + dp[j+i-k][k] + numsn[j]*numsn[k]*numsn[j+i+2]);
                }
                dp[i].emplace_back(sum);
            }
        }
            
        // cout << "haha";
        return dp[dp.size()-1][0];
    }
    //再优化一下数组，降低多维数组开销
    int maxCoins(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 2) {
                return nums[0]*nums[1] + max(nums[0], nums[1]);
            } else if(nums.size() == 1) {
                return nums[0];
            } else {
                return 0;
            }
        }

        int numsn[nums.size()+2];
        for(int i = 0; i < nums.size(); i++)
            numsn[i+1] = nums[i];
        numsn[0] = numsn[nums.size()+1] = 1;

        //长度/起始点
        int N = nums.size();
        int dp[N*N];
        for(int i = 1; i <= N; i++)
            dp[i-1] = numsn[i-1]*numsn[i]*numsn[i+1];


        for(int i = 1; i < N; i++) {
            for(int j = 0; j < N-i; j++) {
                //j ~ j+i+2
                int sum = dp[(i-1)*N+(j+1)] + numsn[j]*numsn[j+1]*numsn[j+i+2];
                sum = max(sum, dp[(i-1)*N+j] + numsn[j]*numsn[j+i+1]*numsn[j+i+2]);

                //j ~ k + k ~ j+i+2 + numsn[j]*numsn[k]*numsn[j+i+2]
                for(int k = j+2; k < j+i+1; k++) {
                    sum = max(sum, dp[(k-j-2)*N+j] + dp[(j+i-k)*N+k] + numsn[j]*numsn[k]*numsn[j+i+2]);
                }
                dp[i*N+j] = sum;
            }
        }
            
        // cout << "haha";
        return dp[N*N-N];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {3, 1, 5, 8};
        cout << Solution().maxCoins(nums) << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {9, 76, 64, 21, 97, 60};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     /*
    //     9 76 64 97 60
    //     130368

    //     9 76 97 60
    //     602176

    //     9 76 60
    //     1044496

    //     >>
    //     1086136
    //     */
    // }
    cout << " 3:" << endl;
    {
        vector<int> nums = {104, 105, 106, 108, 106};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums = {9, 76, 64, 21, 97, 60};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums = {35, 16, 83, 87, 84, 59, 48, 41, 20, 54};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << " 6:" << endl;
    {
        vector<int> nums = {35, 16, 83, 87, 84, 59, 48, 41, 54};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << " 7:" << endl;
    {
        vector<int> nums = {35, 16, 83, 84, 59, 48, 41, 54};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << " 8:" << endl;
    {
        vector<int> nums = {35, 16, 83, 59, 48, 41, 54};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << " 9:" << endl;
    {
        vector<int> nums = {35, 16, 83, 48, 41, 54};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << " 10:" << endl;
    {
        vector<int> nums = {35, 16, 83, 41, 54};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    return 0;
}
#endif