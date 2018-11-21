#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rlt;
        for(int s = 0, e = 0, sum = 0;; e++){
            if(e == words.size()){
                string str(words[s]);
                for(int i = s + 1; i < e; i++){
                    str.push_back(' ');
                    str += words[i];
                }
				str.insert(str.end(), maxWidth-str.size(), ' ');
                rlt.emplace_back(str);
				break;
            }else if(sum + words[e].size() > maxWidth){
                string str(words[s]);
                for(int i = s + 1; i < e; i++){
                    str.insert(str.end(), (maxWidth - sum + e - s + e - i - 1)/(e-s-1), ' ');
                    str += words[i];
                }
                rlt.emplace_back(str);
                s = e;
                sum = words[e].size() + 1;
            }else{
            	sum += words[e].size() + 1;
            }
        }
        return rlt;
    }
};

int main()
{
	vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
	int maxWidth = 16;
	for(auto &s : Solution().fullJustify(words, maxWidth)){
		cout << s << endl;
	}
    return 0;
}