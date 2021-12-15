#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

//On
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 2) {
            if(ratings.size() == 2)
                return ratings[0] == ratings[1] ? 2 : 3;
            else
                return ratings.size();
        }
        vector<int> nums(ratings.size());
        if(ratings[0] <= ratings[1])
            nums[0] = 1;
        for(int i = 1; i < ratings.size()-1; i++) {
            if(nums[i-1] != 0 && ratings[i] > ratings[i-1]) {
                nums[i] = nums[i-1]+1;
            } else if(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]) {
                nums[i] = 1;
                for(int j = i-1; j >= 0; j--) {
                    if(nums[j] > nums[j+1] || ratings[j] < ratings[j+1] || (nums[j] != 0 && ratings[j] == ratings[j+1]))
                        break;
                    if(ratings[j] > ratings[j+1])
                        nums[j] = nums[j+1]+1;
                    else
                        nums[j] = nums[j+1];
                }
            }
        }
        if(ratings[ratings.size()-1] <= ratings[ratings.size()-2]) {
            nums[ratings.size()-1] = 1;
            for(int j = ratings.size()-2; j >= 0; j--) {
                if(nums[j] > nums[j+1] || ratings[j] < ratings[j+1] || (nums[j] != 0 && ratings[j] == ratings[j+1]))
                    break;
                if(ratings[j] > ratings[j+1])
                    nums[j] = nums[j+1]+1;
                else
                    nums[j] = nums[j+1];
            }
        } else {
            nums[ratings.size()-1] = nums[ratings.size()-2]+1;
        }
        int sum = 0;
        for(auto &i : nums)
            sum += i;
        return sum;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {1, 0, 2};
        cout << Solution().candy(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {1, 2, 2};
        cout << Solution().candy(nums) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums = {1, 3, 2, 2, 1};
        cout << Solution().candy(nums) << endl;
    }
    cout << "4:" << endl;
    {
        vector<int> nums = {1, 2, 3, 3, 3, 2, 1};
        cout << Solution().candy(nums) << endl;
    }
    
    return 0;
}
#endif