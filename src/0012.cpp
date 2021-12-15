#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char one[] = {'I', 'X', 'C', 'M'};
        char five[] = {'V', 'L', 'D'};
        string roman;

        int index = floor(log10(num));
        for(; index >= 0; index --){
            int wei = pow(10.0f, index);
            int thiswei = num / wei;
            num %= wei;
            if(thiswei < 4){
                roman.append(thiswei, one[index]);
            }else if(thiswei == 4){
                roman.append(1, one[index]);
                roman.append(1, five[index]);
            }else if(thiswei < 9){
                roman.append(1, five[index]);
                roman.append(thiswei - 5, one[index]);
            }else{
                roman.append(10 - thiswei, one[index]);
                roman.append(1, one[index + 1]);
            }
        }
        return roman;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}