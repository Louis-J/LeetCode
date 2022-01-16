//本题用于其他项目(用于测试智能指针)的测试用例，因此做了些修改
#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1){
            return head;
        }
        //带头指针
        ListNode oldhead(0);
        oldhead.next = head;
        //算出长度
        int n = 0;
        for(ListNode *i = &oldhead; i -> next != NULL; i = i -> next){
            n++;
        }
        //新头指针
        ListNode newhead(0);
        ListNode *newtail = &newhead;
        //转换
        for(int i = 0; i < n/k; i++) {
            ListNode *temphead = newtail;
            newtail = oldhead.next;
            for(int j = 0; j < k && oldhead.next != NULL; j++) {
                //head取第一个插入temphead的开头
                ListNode *temp = oldhead.next;
                oldhead.next = temp -> next;
                temp -> next = temphead -> next;
                temphead -> next = temp;
            }
        }
        newtail -> next = oldhead.next;
        return newhead.next;
    }
};

#ifdef LEETCODE
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
template <class SOLU>
void InputListNode_Num() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int k = stoi(line);

        ListNode* ret = SOLU().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
}
int main() {
    InputListNode_Num<Solution>();
    return 0;
}
#endif