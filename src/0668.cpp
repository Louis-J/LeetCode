#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //比较low的方法
    int findKthNumber0(int m, int n, int k) {
        if(m > n)
            swap(m, n);
        if(m == 1)
            return k;
        if(k == 1)
            return 1;
        if(k == m*n)
            return m*n;
        
        //先确定是否在对角线的哪两个相邻点之间
        k = m*n-k+1;//k转换为第k大
        int ai = 1, bi = n;
        int as = m*n, bs = (m == n);
        
        while(bi-ai != 1) {
            int mid = (ai+bi)/2;
            int mid2 = mid*mid;

            int sum = (m-min(m, (mid-1)))*(n-mid+1);

            for(int i = min(m, (mid-1)), j = mid+1;;) {
                if(i*j >= mid2) {
                    sum += n-(j-1);
                    sum += m-min(j-1, m);
                    if(i == 1)
                        break;
                    else
                        i--;
                } else {
                    if(j == n)
                        break;
                    else
                        j++;
                }
            }
            if(k == sum)
                return mid2;
            else if(k > sum)
                bi = mid, bs = sum;
            else
                ai = mid, as = sum;
        }

        vector<int> therange;

        int a2 = ai*ai, b2 = bi*bi;
        for(int i = min(ai, m), j1 = a2/i, j2 = b2/i;
            i > 0; i--) {
            while(j2 <= n && i*j2 < b2)
                j2++;
            while(j1 <= n && i*j1 < a2)
                j1++;
            if(j1 > n)
                break;
            for(int l = j1; l < j2; l++)
                therange.emplace_back(i*l);
            for(int l = j1; l < min(m+1, j2); l++)
                therange.emplace_back(i*l);
        }
        //ai*ai会多添一次，可忽略
        sort(therange.begin(), therange.end(), std::greater<int>());
        return therange[k-bs-1];
    }
    //性能提升3倍，但仍然很慢
    int findKthNumber1(int m, int n, int k) {
        if(m > n)
            swap(m, n);
        if(m == 1)
            return k;
        if(k == 1)
            return 1;
        if(k == m*n)
            return m*n;
        
        int ai = 1, bi = m*n;
        while(1) {
            // int mid = sqrt(ai*bi);
            int mid = (ai+bi)/2;
            int sqmid = sqrt(mid);
            int midm = ai, midp = bi;

            int sum = sqmid*min(m, sqmid);
            int sumequal = 0;

            int i = 1;
            for(; i <= min(m, sqmid); i++) {
                int j = mid/i;
                if(j >= n)
                    j = n;
                else {
                    if(j*i < mid)
                        midp = min(midp, (j+1)*i);
                    else if(j*i == mid)
                        midp = min(midp, mid);
                }
                if(j*i > midm) {
                    sum += sumequal;
                    sumequal = 0;
                    midm = j*i;
                }
                if(j*i == midm) {
                    sum += j-1-sqmid;
                    if(j <= m) {
                        sum += j-1-min(m, sqmid);
                        sumequal += 2;
                    } else {
                        sum += m-min(m, sqmid);
                        sumequal += 1;
                    }
                } else {
                    sum += j-sqmid;
                    sum += min(m, j)-min(m, sqmid);
                }
            }
            if(i <= m) {
                int j = mid/i;
                if(j < n) {
                    if(j*i < mid)
                        midp = min(midp, (j+1)*i);
                    else if(j*i == mid)
                        midp = min(midp, mid);
                }
            }
            if(sqmid <= m && sqmid*sqmid == midm)
                sum++, sumequal--;
            if(k > sum + sumequal) {
                ai = midp;
            } else if(k <= sum) {
                bi = midm;
            } else {
                return midm;
            }
        }
    }
    //题解的答案，居然比我的快10ms，就能超越50%的人
    int findKthNumber2(int m, int n, int k) {
        int low=1, high=m*n+1;
        while (low<high) {
            int mid = low + (high - low) / 2;
            int count=0;
            for (int i = 1;i<= m;i++)         //计算乘法表中不大于mid的值的总数
               count += min(mid/i,n);              //i：行号  n：矩阵列数  num / i：第i行中比num小的个数
            if (count>=k) 
                high=mid;
            else 
                low=mid+1;
        }
        return low;
    }
    int findKthNumber(int m, int n, int k) {
        if(m > n)
            swap(m, n);

        if(m == 1)
            return k;
        if(k == 1)
            return 1;
        if(k == m*n)
            return m*n;
            
        int l = 1, r = m*n+1;
        while (l < r) {
            int mid = (l + r) / 2;
            int sum = 0;
            for(int i = 1; i <= m; i++)
                sum += min(mid/i, n);
            if(sum >= k)
                r = mid;
            else 
                l = mid+1;
        }
        return l;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().findKthNumber(3, 3, 6) << endl;//4
        cout << Solution().findKthNumber(3, 3, 5) << endl;//3
        cout << Solution().findKthNumber(2, 3, 6) << endl;//6
        cout << Solution().findKthNumber(2, 3, 5) << endl;//4
        cout << Solution().findKthNumber(2, 3, 4) << endl;//3

        
        cout << Solution().findKthNumber(5, 5, 24) << endl;//20
        cout << Solution().findKthNumber(5, 5, 23) << endl;//20
        cout << Solution().findKthNumber(5, 5, 22) << endl;//16
        cout << Solution().findKthNumber(5, 5, 21) << endl;//15
        cout << Solution().findKthNumber(5, 5, 20) << endl;//15
        cout << Solution().findKthNumber(4, 2, 7) << endl;//6
    }
    cout << " 2:" << endl;
    {
        cout << Solution().findKthNumber(1, 3, 3) << endl;//3
        cout << Solution().findKthNumber(9, 2, 3) << endl;//2
        cout << Solution().findKthNumber(45, 12, 471) << endl;//312
        cout << Solution().findKthNumber(8, 3, 21) << endl;//16
    }
    return 0;
}
#endif