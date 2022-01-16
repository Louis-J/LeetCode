#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //false分3种:往外，往内，先外后内
    bool isSelfCrossing(vector<int>& x) {
        if(x.size() <= 3)
            return false;
        int px = 0, py = 0;
        // int lines[4][3] = {};//x1, x2, y/y1, y2, x/右上左下

        // py += x[0];
        // lines[0][1] = py;

        // px -= x[1];
        // lines[1][0] = px;
        // lines[1][2] = py;

        // lines[2][2] = px;
        // lines[2][1] = py;
        // py -= x[2];
        // lines[2][0] = py;

        // lines[3][0] = px;
        // lines[3][2] = py;
        // px += x[3];
        // lines[3][1] = py;

        // int points[4][2] = {};

        // py += x[0];
        // points[0][0] = 0;
        // points[0][1] = py;

        // px -= x[1];
        // points[1][0] = px;
        // points[1][1] = py;

        // py -= x[2];
        // points[2][0] = px;
        // points[2][1] = py;

        // px += x[3];
        // points[3][0] = px;
        // points[3][1] = py;

        int posi[4] = {};//上左下右
        int lastposiA = 0;
        int lastposiB = 0;
        py += x[0];
        posi[0] = py;
        px -= x[1];
        posi[1] = px;
        py -= x[2];
        posi[2] = py;
        px += x[3];
        posi[3] = px;

        if(px >= 0 && py >= 0)
            return true;

        bool inner = false;
        int t = 0;//方向
        size_t i = 4;
        if(px <= 0) {//往内
            inner = true;
            if(px == 0) {
                // points[0][1] = 0;
                // points[1][1] = 0;
                posi[0] = 0;
            }
        } else {//往外
            for(; i < x.size() && !inner; i++, t = (t+1)%4) {
                switch(t) {
                case 0:
                    if(x[i] <= posi[0]-posi[2]) {//转向往内
                        inner = true;
                        if(x[i] >= lastposiB-posi[2])
                            posi[1] = lastposiA;
                    }
                    lastposiB = lastposiA;
                    lastposiA = posi[0];
                    py += x[i];
                    posi[0] = py;
                break;
                case 1:
                    if(x[i] <= posi[3]-posi[1]) {//转向往内
                        inner = true;
                        if(x[i] >= posi[3]-lastposiB)
                            posi[2] = lastposiA;
                    }
                    lastposiB = lastposiA;
                    lastposiA = posi[1];
                    px -= x[i];
                    posi[1] = px;
                break;
                case 2:
                    if(x[i] <= posi[0]-posi[2]) {//转向往内
                        inner = true;
                        if(x[i] >= posi[0]-lastposiB)
                            posi[3] = lastposiA;
                    }
                    lastposiB = lastposiA;
                    lastposiA = posi[2];
                    py -= x[i];
                    posi[2] = py;
                break;
                case 3:
                    if(x[i] <= posi[3]-posi[1]) {//转向往内
                        inner = true;
                        if(x[i] >= lastposiB-posi[1])
                            posi[0] = lastposiA;
                    }
                    lastposiB = lastposiA;
                    lastposiA = posi[3];
                    px += x[i];
                    posi[3] = px;
                break;
                }
            }
        }
        if(inner) {
            for(; i < x.size(); i++, t = (t+1)%4) {
                switch(t) {
                case 0:
                    if(x[i] >= posi[0]-posi[2])
                        return true;
                    py += x[i];
                    posi[0] = py;
                break;
                case 1:
                    if(x[i] >= posi[3]-posi[1])
                        return true;
                    px -= x[i];
                    posi[1] = px;
                break;
                case 2:
                    if(x[i] >= posi[0]-posi[2])
                        return true;
                    py -= x[i];
                    posi[2] = py;
                break;
                case 3:
                    if(x[i] >= posi[3]-posi[1])
                        return true;
                    px += x[i];
                    posi[3] = px;
                break;
                }
            }
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> x = {2, 1, 1, 2};
        cout << Solution().isSelfCrossing(x) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> x = {1, 2, 3, 4};
        cout << Solution().isSelfCrossing(x) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> x = {1, 1, 1, 1};
        cout << Solution().isSelfCrossing(x) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> x = {1, 1, 2, 2, 1, 1};
        cout << Solution().isSelfCrossing(x) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> x = {1, 1, 2, 2, 3, 1, 1};
        cout << Solution().isSelfCrossing(x) << endl;
    }
    return 0;
}
#endif