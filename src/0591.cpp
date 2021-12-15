#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    enum class STATUS {
        begin,
        end,
        tagbegin,
        cdatabegin,
        incdata,
        intag,
        inrtag,
        content,
    };
public:
    bool isValid(string code) {
        stack<string, vector<string>> stks;

        STATUS status = STATUS::begin;
        char tagc[9];
        int tagn;
        //0: 
        for(auto &i : code) {
            switch (status) {
            case STATUS::begin:
                if(i == '<')
                    status = STATUS::tagbegin;
                else
                    return false;
                break;
            
            case STATUS::tagbegin:
                tagn = 0;
                if(i == '/')
                    status = STATUS::inrtag;
                else if(i == '!') {
                    if(stks.empty())
                        return false;
                    status = STATUS::cdatabegin;
                } else {
                    status = STATUS::intag;
                    if(i == '_' || (i <= 'Z' && i >= 'A'))
                        tagc[tagn++] = i;
                    else
                        return false;
                }
                break;

            case STATUS::intag:
                if(i == '>') {
                    stks.push(string(tagc, tagc+tagn));
                    status = STATUS::content;
                } else if(tagn < 9 && (i == '_' || (i <= 'Z' && i >= 'A')))
                    tagc[tagn++] = i;
                else
                    return false;
                break;
                
            case STATUS::inrtag:
                if(i == '>') {
                    if(stks.empty() || stks.top() != string(tagc, tagc+tagn))
                        return false;
                    stks.pop();
                    if(stks.empty())
                        status = STATUS::end;
                    else
                        status = STATUS::content;
                } else if(tagn < 9 && (i == '_' || (i <= 'Z' && i >= 'A')))
                    tagc[tagn++] = i;
                else
                    return false;
                break;

            case STATUS::incdata:
                if(tagn == 2 && i == '>') {
                    if(stks.empty())
                        status = STATUS::end;
                    else
                        status = STATUS::content;
                } else {
                    if(i == ']') {
                        if(tagn < 2)
                            tagn++;
                    } else
                        tagn = 0;
                }
                break;

            case STATUS::cdatabegin:
                switch(tagn++) {
                case 0:
                    if(i != '[')
                        return false;
                break;
                case 1:
                    if(i != 'C')
                        return false;
                break;
                case 2:
                    if(i != 'D')
                        return false;
                break;
                case 3:
                    if(i != 'A')
                        return false;
                break;
                case 4:
                    if(i != 'T')
                        return false;
                break;
                case 5:
                    if(i != 'A')
                        return false;
                break;
                case 6:
                    if(i != '[')
                        return false;
                    else {
                        status = STATUS::incdata;
                        tagn = 0;
                    }
                break;
                }
                break;

            case STATUS::content:
                if(i == '<')
                    status = STATUS::tagbegin;
                break;

            case STATUS::end:
                return false;
            }
        }
        if(status != STATUS::end)
            return false;
        return true;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>") << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>") << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().isValid("<A>  <B> </A>   </B>") << endl;
        cout << Solution().isValid("<DIV>  div tag is not closed  <DIV>") << endl;
        cout << Solution().isValid("<DIV>  unmatched <  </DIV>") << endl;
        cout << Solution().isValid("<DIV> closed tags with invalid tag name  <b>123</b> </DIV>") << endl;
        cout << Solution().isValid("<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>") << endl;
        cout << Solution().isValid("<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>") << endl;
    }
    cout << " 4:" << endl;
    {
        cout << Solution().isValid("<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>") << endl;
    }
    cout << " 5:" << endl;
    {
        cout << Solution().isValid("<A><CDATA></CDATA></A>") << endl;
    }
    return 0;
}
#endif