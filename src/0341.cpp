/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

 // @lc code=start
 /**
  * // This is the interface that allows for creating nested lists.
  * // You should not implement it, or speculate about its implementation
  * class NestedInteger {
  *   public:
  *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
  *     bool isInteger() const;
  *
  *     // Return the single integer that this NestedInteger holds, if it holds a single integer
  *     // The result is undefined if this NestedInteger holds a nested list
  *     int getInteger() const;
  *
  *     // Return the nested list that this NestedInteger holds, if it holds a nested list
  *     // The result is undefined if this NestedInteger holds a single integer
  *     const vector<NestedInteger> &getList() const;
  * };
  */

class NestedIterator1 {
    vector<int> vals;
    void put(vector<NestedInteger>& nestedList) {
        for (auto& n : nestedList) {
            if (n.isInteger())
                vals.emplace_back(n.getInteger());
            else
                put(n.getList());
        }
    }
    int index = 0;
public:
    NestedIterator1(vector<NestedInteger>& nestedList) {
        put(nestedList);
    }

    int next() {
        return vals[index++];
    }

    bool hasNext() {
        return index < vals.size();
    }
};
class NestedIterator :public NestedIterator1 {};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
 // @lc code=end

