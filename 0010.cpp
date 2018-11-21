#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<memory>
#include<assert.h>

using namespace std;

class Solution {
    /*
    enum Types{S,R,A,C,E};
    class Node{
    public:
        Types type;
        int strb, stre;

        Node(Types type, int strb, int stre):type(type),strb(strb),stre(stre){}
    };
    Node getNext(string& p, int& pos){
        if(pos == (int)p.size()){
            return Node(E,0,0);
        }
        int endPos = min(p.find('*', pos), p.find('.', pos));

        if(endPos == -1){//无R A C
            return Node(S, pos, (pos = p.size()));
        }
        else if(p[endPos] == '*'){//S or R
            if(endPos - pos == 1){//R
                return Node(R, pos, (pos = endPos));
            }
            else{//S
                return Node(S, pos, (pos = endPos));
            }
        }
        else{//(p[endPos] == '.')  S or A or C
            if(endPos - pos > 0){//S
                return Node(S, pos, (pos = endPos));
            }
            else if(endPos + 1 < (int)p.size() && p[endPos + 1] == '*'){//A
                return Node(A, pos, (pos = endPos));
            }
            else{//C
                return Node(C, pos, (pos = endPos));
            }
        }
    }
public:
    bool isMatch(string s, string p) {
        int pPos = 0;
        int sPos = 0;
        Node pThis = getNext(p, pPos), pNext = getNext(p, pPos);

        while(pThis.type != E){
            if(sPos >= s.size()){
                return pThis.type == A && pNext.type == E;
            }
            //AA or AR or RA -> A
            if(pThis.type == A && pNext.type == A || (pThis.type == A && pNext.type == R) || (pThis.type == R && pNext.type == A)){
                pThis.type = A;
                pNext = getNext(p, pos);
            }
            //AC or CA -> (sPos+1),A
            else if((pThis.type == A && pNext.type == C) || (pThis.type == C && pNext.type == A)){
                sPos += 1;
                pThis.type = A;
                pNext = getNext(p, pos);
            }
            else{
                if(pThis.type == S){
                    if(s.substr(sPos, pThis.stre - pThis.strb) == p.substr(pPos, pThis.stre - pThis.strb)){
                        sPos += pThis.stre - pThis.strb;
                        pThis = pNext;
                        pNext = getNext(p, pos);
                    }
                    else{
                        return false;
                    }
                }
                else if(pThis.type == C){
                    sPos ++;
                    pThis = pNext;
                    pNext = getNext(p, pos);
                }
                else if(pThis.type == A && pNext.type == S){
                    pNext = getNext(p, pos);
                }
                else if(pThis.type == R && pNext.type == S){
                    sPos ++;
                    pThis = pNext;
                    pNext = getNext(p, pos);
                }
                else if(pThis.type == R && pNext.type == C){
                    sPos ++;
                    pThis = pNext;
                    pNext = getNext(p, pos);
                }
            }
        }
        return sPos == (int)s.size();
    }*/

public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        if(p.length() >= 2 && p[1] == '*'){
            return (isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
        }
        else{
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
//真是个大傻逼，其实题目本身很简单，只是自己想复杂了。匹配万变不离其宗:单向顺序，不论是