#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <functional>
#include <assert.h>

using namespace std;

class Solution {
public:
    double myPow0(double x, int n) {
        unsigned un = abs(n);
        x = n < 0 ? 1 / x : x;

        unsigned wei;
        unsigned powwei;
        for(wei = 1, powwei = 1; powwei <= un/2; wei++, powwei *= 2){}

        vector<bool> ifadd(wei, false);
        for(unsigned i = powwei, j = wei - 1; un != 0;j--, i/= 2){
            if(un >= i){
                un -= i;
                ifadd[j] = true;
            }
        }
        double rlt = 1;
        for(auto add : ifadd){
            if(add){
                rlt *= x;
            }
            x *= x;
        }
        return rlt;
    }
    double myPow1(double x, int n) {
        unsigned un = abs(n);
        x = n < 0 ? 1 / x : x;

        double rlt = 1;
        for(unsigned i = 1; un >= i && i != 0; i *= 2){
            if(i&un){
                rlt *= x;
            }
            x *= x;
        }
        return rlt;
    }
    double myPow(double x, int n) {
        unsigned un = abs(n);
        x = n < 0 ? 1 / x : x;

        double rlt = 1;
        for(; un > 0; un /= 2){
            if(un%2){
                rlt *= x;
            }
            x *= x;
        }
        return rlt;
    }
};

int main()
{
    double x;
    int n;
    while(cin >> x >> n){
        cout << Solution().myPow(x, n) << endl;
    }
    return 0;
}