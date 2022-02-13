#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Fancy1 {
    int size = 1000;
    long long* arr = new long long[size];
    int length = 0;
    static constexpr int MODNUM = 1e9 + 7;
private:
    void resize() {
        size *= 2;
        long long* newArr = new long long[size];
        for (int i = 0; i < length; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }
public:
    ~Fancy1() {
        delete[] arr;
    }

    void append(int val) {
        if (length == size)
            resize();
        arr[length++] = val;
    }

    void addAll(int inc) {
        for (int i = 0; i < length; i++)
            arr[i] = (arr[i] + inc) % MODNUM;
    }

    void multAll(int m) {
        for (int i = 0; i < length; i++)
            arr[i] = (arr[i] * m) % MODNUM;

    }

    int getIndex(int idx) {
        // if (idx >= length)
        //     cout << -1 << endl;
        // else
        //     cout << arr[idx] << endl;

        if (idx >= length)
            return -1;
        else
            return arr[idx];
    }
};

class Fancy2 {
    static constexpr long long MODNUM = 1e9 + 7;
    int size = 1000;
    int* arr = new int[size];
    int length = 0;
    tuple<bool, int, int> plusAdd;
private:
    void resize() {
        size *= 2;
        int* newArr = new int[size];
        for (int i = 0; i < length; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }
    void doOp() {
        auto& [have, plus, add] = plusAdd;
        if (have) {
            for (int i = 0; i < length; i++)
                arr[i] = ((long long)arr[i] * plus + add) % MODNUM;
            have = false;
        }
    }
public:
    ~Fancy2() {
        delete[] arr;
    }

    void append(int val) {
        doOp();
        if (length == size)
            resize();
        arr[length++] = val;
    }

    void addAll(int inc) {
        auto& [have, plus, add] = plusAdd;
        if (have) {
            add = (add + inc) % MODNUM;
        } else {
            have = true;
            plus = 1;
            add = inc;
        }
    }

    void multAll(int m) {
        auto& [have, plus, add] = plusAdd;
        if (have) {
            plus = ((long long)plus * m) % MODNUM;
            add = ((long long)add * m) % MODNUM;
        } else {
            have = true;
            plus = m;
            add = 0;
        }
    }

    int getIndex(int idx) {
        // if (idx >= length)
        //     cout << -1 << endl;
        // else {
        //     doOp();
        //     cout << arr[idx] << endl;
        // }

        if (idx >= length)
            return -1;
        else {
            doOp();
            return arr[idx];
        }
    }
};

class Fancy3 {
    static constexpr long long MODNUM = 1e9 + 7;
    vector<pair<int, int>> arr;
    vector<tuple<int, int, int>> opList;
private:
    int doOp(int index) {
        auto& [val, ver] = arr[index];
        if (ver == opList.size())
            return val;
        auto& [plus, add, verTo] = opList[ver];
        while (verTo != opList.size()) {
            auto& [plus2, add2, verTo2] = opList[verTo];
            plus = ((long long)plus * plus2) % MODNUM;
            add = ((long long)add * plus2 + add2) % MODNUM;
            verTo = verTo2;
        }
        val = ((long long)val * plus + add) % MODNUM;
        ver = verTo;
        return val;
    }
public:
    ~Fancy3() {}

    void append(int val) {
        arr.emplace_back(val, opList.size());
    }

    void addAll(int inc) {
        opList.emplace_back(1, inc, opList.size() + 1);
    }

    void multAll(int m) {
        opList.emplace_back(m, 0, opList.size() + 1);
    }

    int getIndex(int idx) {
        // if (idx >= arr.size())
        //     cout << -1 << endl;
        // else
        //     cout << doOp(idx) << endl;

        if (idx >= arr.size())
            return -1;
        else
            return doOp(idx);
    }
};

class Fancy4 {
    static constexpr long long MODNUM = 1e9 + 7;
    int arrSize = 100;
    pair<int, int>* arr = new pair<int, int>[arrSize];
    int arrLen = 0;
    int opSize = 100;
    tuple<int, int, int>* opList = new tuple<int, int, int>[arrSize];
    int opLen = 0;
private:
    void resizeArr() {
        arrSize *= 10;
        pair<int, int>* newArr = new  pair<int, int>[arrSize];
        for (int i = 0; i < arrLen; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }
    void resizeOp() {
        opSize *= 10;
        tuple<int, int, int>* newOpList = new tuple<int, int, int>[opSize];
        for (int i = 0; i < opLen; i++)
            newOpList[i] = opList[i];
        delete[] opList;
        opList = newOpList;
    }
    int doOp(int index) {
        auto& [val, ver] = arr[index];
        if (ver == opLen)
            return val;
        auto& [plus, add, verTo] = opList[ver];
        while (verTo != opLen) {
            auto& [plus2, add2, verTo2] = opList[verTo];
            plus = ((long long)plus * plus2) % MODNUM;
            add = ((long long)add * plus2 + add2) % MODNUM;
            verTo = verTo2;
        }
        val = ((long long)val * plus + add) % MODNUM;
        ver = verTo;
        return val;
    }
public:
    ~Fancy4() {
        delete[] arr;
        delete[] opList;
    }

    void append(int val) {
        if (arrLen == arrSize)
            resizeArr();
        arr[arrLen].first = val;
        arr[arrLen].second = opLen;
        arrLen++;
    }

    void addAll(int inc) {
        if (opLen == opSize)
            resizeOp();
        auto& [plus, add, verTo] = opList[opLen++];
        plus = 1;
        add = inc;
        verTo = opLen;
    }

    void multAll(int m) {
        if (opLen == opSize)
            resizeOp();
        auto& [plus, add, verTo] = opList[opLen++];
        plus = m;
        add = 0;
        verTo = opLen;
    }

    int getIndex(int idx) {
        // if (idx >= arrLen)
        //     cout << -1 << endl;
        // else
        //     cout << doOp(idx) << endl;

        if (idx >= arrLen)
            return -1;
        else
            return doOp(idx);
    }
};

class Fancy5 {
    static constexpr long long MODNUM = 1e9 + 7;
    pair<int, int>* arr = new pair<int, int>[100000];
    int arrLen = 0;
    tuple<int, int, int>* opList = new tuple<int, int, int>[100000];
    int opLen = 0;
private:
    int doOp(int index) {
        auto& [val, ver] = arr[index];
        if (ver == opLen)
            return val;
        auto& [plus, add, verTo] = opList[ver];
        while (verTo != opLen) {
            auto& [plus2, add2, verTo2] = opList[verTo];
            plus = ((long long)plus * plus2) % MODNUM;
            add = ((long long)add * plus2 + add2) % MODNUM;
            verTo = verTo2;
        }
        val = ((long long)val * plus + add) % MODNUM;
        ver = verTo;
        return val;
    }
public:
    ~Fancy5() {
        delete[] arr;
        delete[] opList;
    }

    void append(int val) {
        arr[arrLen].first = val;
        arr[arrLen].second = opLen;
        arrLen++;
    }

    void addAll(int inc) {
        auto& [plus, add, verTo] = opList[opLen++];
        plus = 1;
        add = inc;
        verTo = opLen;
    }

    void multAll(int m) {
        auto& [plus, add, verTo] = opList[opLen++];
        plus = m;
        add = 0;
        verTo = opLen;
    }

    int getIndex(int idx) {
        // if (idx >= arrLen)
        //     cout << -1 << endl;
        // else
        //     cout << doOp(idx) << endl;

        if (idx >= arrLen)
            return -1;
        else
            return doOp(idx);
    }
};
class Fancy : public Fancy5 {};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        Fancy fancy;
        fancy.append(2);   // 奇妙序列：[2]
        fancy.addAll(3);   // 奇妙序列：[2+3] -> [5]
        fancy.append(7);   // 奇妙序列：[5, 7]
        fancy.multAll(2);  // 奇妙序列：[5*2, 7*2] -> [10, 14]
        fancy.getIndex(0); // 返回 10
        fancy.addAll(3);   // 奇妙序列：[10+3, 14+3] -> [13, 17]
        fancy.append(10);  // 奇妙序列：[13, 17, 10]
        fancy.multAll(2);  // 奇妙序列：[13*2, 17*2, 10*2] -> [26, 34, 20]
        fancy.getIndex(0); // 返回 26
        fancy.getIndex(1); // 返回 34
        fancy.getIndex(2); // 返回 20
    }
    cout << "2:" << endl;
    {
        // Fancy* obj = new Fancy();
        // obj->append(val);
        // obj->addAll(inc);
        // obj->multAll(m);
        // int param_4 = obj->getIndex(idx);
    }
    cout << "3:" << endl;
    {
        Fancy fancy;
        fancy.append(8);
        fancy.getIndex(0);
        fancy.multAll(7);
        fancy.append(5);
        fancy.getIndex(0);
        fancy.append(3);
        fancy.addAll(6);
        fancy.getIndex(0);
    }
    return 0;
}
#endif
// 乘法逆元最快，但需要数学加持

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
 // @lc code=end

