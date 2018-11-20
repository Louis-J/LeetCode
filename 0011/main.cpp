#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

class Solution {
public:
    class tudian{
    private:
        int value,index;
        bool lessthan(tudian &t){
            return value < t.value;
        }
    public:
        tudian(int value, int index):value(value),index(index){}
        friend int getsize(tudian &a, tudian &b){
            return min(a.value, b.value)*(b.index - a.index);
        }
        bool operator<(tudian &t){
            return index < t.index;
        }
        friend void update(vector<tudian>::iterator &a, vector<tudian>::iterator &b){
            if(a->lessthan(*b)){
                a ++;
            }else if(b->lessthan(*a)){
                b ++;
            }else{
                a ++;
                b ++;
            }
        }
    };
    int maxArea0(vector<int>& height) {
        vector<tudian> hl,hr;

        int i, maxt;
        i = 1;
        maxt = height[0];
        for(hl.push_back(tudian(maxt,0)); i < height.size(); i ++){
            if(height[i] > maxt){
                maxt = height[i];
                hl.push_back(tudian(maxt,i));
            }
        }

        i = height.size() - 2;
        maxt = height[height.size() - 1];
        for(hr.push_back(tudian(maxt,i + 1)); i >= 0; i --){
            if(height[i] > maxt){
                maxt = height[i];
                hr.push_back(tudian(maxt,i));
            }
        }

        int maxsize = 0;
        for(vector<tudian>::iterator l = hl.begin(), r = hr.begin();
            l != hl.end() && r != hr.end() && l < r; update(l, r)){
            if(getsize(*l, *r) > maxsize){
                maxsize = getsize(*l, *r);
            }
        }
        return maxsize;
    }
    int maxArea(vector<int>& height) {
        auto getsize = [&height](int il, int ir) -> int{
            return min(height[il], height[ir])*(ir - il);
        };
        auto updatel = [&height](int &l, int &r, int &lnow){
            for(; l < r; l ++){
                if(height[l] > lnow){
                    lnow = height[l];
                    break;
                }
            }
        };
        auto updater = [&height](int &l, int &r, int &rnow){
            for(; l < r; r --){
                if(height[r] > rnow){
                    rnow = height[r];
                    break;
                }
            }
        };
        auto update = [&height,&updatel,&updater](int &l, int &r, int &lnow, int &rnow){
            if(lnow < rnow){
                updatel(l, r, lnow);
            }else if(lnow > rnow){
                updater(l, r, rnow);
            }else{
                updatel(l, r, lnow);
                updater(l, r, rnow);
            }
        };

        int l = 0, r = height.size() - 1;
        int maxsize = getsize(l, r);

        for(int lnow = height[l], rnow = height[r]; l < r;update(l, r, lnow, rnow)){
            maxsize = max(maxsize, getsize(l, r));
        }
        return maxsize;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
