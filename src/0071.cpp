#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <sstream>
#include <functional>
#include <assert.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        list<string> paths;
        for(int b = 0, e = path.find('/', 1); b < path.size(); b = e, e = path.find('/', e + 1)){
            paths.emplace_back(path.substr(b, e - b));
            //cout << path.substr(b, e - b) << endl;
        }
        for(list<string>::iterator i = paths.begin(); i != paths.end();){
            if(*i == "/" || *i == "/."){
                i = paths.erase(i);
            }else if(*i == "/.."){
                if(i != paths.begin()){
                    i = paths.erase(--i);
                }
                i = paths.erase(i);
            }else{
                i++;
            }
        }
        //return string(paths.begin(), paths.end());
        if(paths.size() == 0){
            return string("/");
        }
        string rlt;
        for(auto i : paths){
            rlt += i;
        }
        return rlt;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string path = stringToString(line);

        string ret = Solution().simplifyPath(path);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}