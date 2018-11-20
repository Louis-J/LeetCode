#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool minus = (dividend < 0) ^ (divisor < 0);
        unsigned udividend = abs(dividend);
        unsigned udivisor = abs(divisor);
        int rlt = 0;

        unsigned i = 1;
        for(; udivisor < udividend; i <<= 1){
			//cout << udivisor << endl;
            udivisor <<= 1;
        }
        for(; i >= 1; i >>= 1, udivisor >>= 1){
            if(udividend >= udivisor){
                udividend -= udivisor;
                rlt += i;
            }
        }
        return minus?-rlt:rlt;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);

        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
