#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<memory>

using namespace::std;

class Solution {
public:
    double findMedianSortedArrays0(vector<int>& nums1, vector<int>& nums2) {
        unique_ptr<vector<int>> L, S;
        if(nums1.size() > nums2.size()){
            L = unique_ptr<vector<int>>(&nums1);
            S = unique_ptr<vector<int>>(&nums2);
        }
        else{
            S = unique_ptr<vector<int>>(&nums1);
            L = unique_ptr<vector<int>>(&nums2);
        }


        const unsigned int lenSum = nums1.size() + nums2.size();
        const unsigned int lenHalf = (lenSum + 1)/2;
        unsigned int iMin = 0, iMax = S -> size();

        while (iMin <= iMax) {
            unsigned int i = (iMin + iMax) / 2;
            unsigned int j = lenHalf - i;

            if(i < iMax && (*L)[j - 1] > (*S)[i]){
                iMin = i + 1;
            }
            else if(i > 0 && (*S)[i - 1] > (*L)[j]){
                iMax = i;
            }
            else{
                if(lenSum % 2 == 1){
                    if(i == 0){
                        return (*L)[j-1];
                    }
                    else if(j == 0){
                        return (*S)[i-1];
                    }
                    else{
                        return max((*S)[i-1] , (*L)[j-1]);
                    }
                }
                else{
                    int maxLeft, minRight;
                    if(i == 0){
                        maxLeft = (*L)[j-1];
                    }
                    else if(j == 0){
                        maxLeft = (*S)[i-1];
                    }
                    else{
                        maxLeft = max((*S)[i-1] , (*L)[j-1]);
                    }
                    if(i == S -> size()){
                        minRight = (*L)[j];
                    }
                    else if(j == L -> size()){
                        minRight = (*S)[i];
                    }
                    else{
                        minRight = min((*S)[i] , (*L)[j]);
                    }
                    return (maxLeft + minRight)/2.0;
                }
            }
        }
    }
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *L, *S;
        if(nums1.size() > nums2.size()){
            L = &nums1;
            S = &nums2;
        }
        else{
            S = &nums1;
            L = &nums2;
        }

        const unsigned int lenSum = nums1.size() + nums2.size();
        const unsigned int lenHalf = (lenSum + 1)/2;
        unsigned int iMin = 0, iMax = S -> size();

        while (iMin <= iMax) {
            unsigned int i = (iMin + iMax) / 2;
            unsigned int j = lenHalf - i;

            if(i < iMax && (*L)[j - 1] > (*S)[i]){
                iMin = i + 1;
            }
            else if(i > 0 && (*S)[i - 1] > (*L)[j]){
                iMax = i;
            }
            else{
                if(lenSum % 2 == 1){
                    if(i == 0){
                        return (*L)[j-1];
                    }
                    else if(j == 0){
                        return (*S)[i-1];
                    }
                    else{
                        return max((*S)[i-1] , (*L)[j-1]);
                    }
                }
                else{
                    int maxLeft, minRight;
                    if(i == 0){
                        maxLeft = (*L)[j-1];
                    }
                    else if(j == 0){
                        maxLeft = (*S)[i-1];
                    }
                    else{
                        maxLeft = max((*S)[i-1] , (*L)[j-1]);
                    }
                    if(i == S -> size()){
                        minRight = (*L)[j];
                    }
                    else if(j == L -> size()){
                        minRight = (*S)[i];
                    }
                    else{
                        minRight = min((*S)[i] , (*L)[j]);
                    }
                    return (maxLeft + minRight)/2.0;
                }
            }
        }
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays0(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}