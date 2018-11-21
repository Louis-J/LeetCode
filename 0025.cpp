#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto hasknode = [&k](ListNode* h)->bool{
            for(int i = 0; i < k; i++){
                h = h->next;
                if(h == nullptr){
                    return false;
                }
            }
            return true;
        };
        auto revknode = [&hasknode, &k](ListNode* h)->ListNode*{
            if(!hasknode(h))
                return nullptr;
            ListNode *realend = h->next;
            ListNode *end = realend;
            ListNode *endn = end->next;
            ListNode *endnn = endn->next;
            for(int i = 0; i < k; i++){
                endn->next = end;
                end = endn;
                endn = endnn;
                endnn = endnn->next;
            }
            h->next = endn;
            realend->next = endnn;
            return realend;
        };
        if(k <= 1){
            return head;
        }
        ListNode newhead(0);
        newhead.next = head;
        for(ListNode *i = &newhead; i != nullptr; i = revknode(i)){}
        return newhead.next;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int k = stringToInteger(line);

        ListNode* ret = Solution().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}