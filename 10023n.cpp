#include <iostream>
#include <set>
#include <tuple>

using std::multiset;
int main0() {
    size_t n;
    std::cin >> n;
    size_t arr[n];
    size_t noMove[n] = {0}; //偏移i位后不需要动的数量
    for(size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
        noMove[(arr[i]+n-i-1)%n]++;
    }
    //最大的不需要动的数量
    size_t maxNoMove = 0;
    for(auto &i : noMove)
        if(i > maxNoMove)
            maxNoMove = i;

    //n-maxNoMove在3个以内，移动次数固定
    if(n == maxNoMove) {
        std::cout << n-maxNoMove;
        return 0;
    } else if(n-maxNoMove <= 3) {
        std::cout << n-maxNoMove-1;
        return 0;
    }
    //动的数量为i，则动的次数为[(i+1)/2, i-1], 计算最少可能要算到的
    size_t mayMinNum = (n-maxNoMove+1)/2;
    size_t mayMinNoMove = maxNoMove - mayMinNum + 1;
    multiset<size_t, std::greater<size_t>> offsets;
    for(size_t i = 0; i < n; i++)
        if(noMove[i] > mayMinNoMove)
            offsets.emplace(i);

    //判断实际所需要移动的次数
    auto TryMove = [&arr, &n](size_t offset) {
        size_t arrC[n];
        //转换为0-n，增加偏移
        for(size_t i = 0; i < n; i++)
            arrC[i] = (arr[i]+n-offset-1)%n;

        size_t moveNum = 0;
        for(size_t i = 0; i < n; i++)
            if(arrC[i] != i) {
                std::swap(arrC[i], arrC[arrC[i]]);
                moveNum++;
            }
        return moveNum;
    };
    size_t actualMinNum = n-maxNoMove-1;
    for(auto &i : offsets) {
        actualMinNum = std::min(actualMinNum, TryMove(i));
        if(actualMinNum == mayMinNum)
            break;
    }
    std::cout << actualMinNum;
    return 0;
}

int main1() {
    size_t n;
    std::cin >> n;
    size_t arr[n];
    for(size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
        arr[i]--;
    }
    // 找逆序对的个数
    size_t place[n] = {}; //位置
    for(size_t i = 0; i < n; i++)
        place[arr[i]] = i;

    size_t rSize[n] = {};
    for(size_t i = 0; i < n; i++)
        for(size_t j = i+1; j < n; j++)
            if(place[j] < place[i])
                rSize[i]++;
                
    size_t sum = 0;
    for(auto & i: rSize)
        sum += i;

    size_t minSum = sum;
    for(size_t i = 0; i < n-1; i++) { //循环让i设为最大值，更新逆序数
        for(size_t j = 0; j < n; j++)
            if(place[j] > place[i]) {
                rSize[j]++;
                sum++;
            }
        sum -= rSize[i];
        rSize[i] = 0;
        if(sum < minSum)
            minSum = sum;
    }

    // std::cout << '\n' << "minSum:" << minSum << '\n';
    std::cout << minSum;
    return 0;
}

#include <random>

using std::mt19937_64;
int main() {
    size_t n;
    char yOrN;
    std::cin >> n >> yOrN;
    int arr[n];
    if(yOrN == 'y') {
        // 随机打乱
        for(size_t i = 0; i < n; i++) {
            arr[i] = i;
        }
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<> distribution(0, n-1);
        for(size_t i = 0; i < 5*n; i++) {
            std::swap(arr[distribution(gen)], arr[distribution(gen)]);
        }
        std::cout << "arr:\n";
        for(auto & i: arr) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    } else {
        for(auto & i: arr) {
            std::cin >> i;
        }
    }

    // //判断实际所需要移动的次数
    auto GetMinMove = [&arr, &n]() {
        // 找逆序对的个数
        size_t place[n] = {}; //位置
        for(size_t i = 0; i < n; i++)
            place[arr[i]] = i;

        size_t rSize[n] = {};
        for(size_t i = 0; i < n; i++)
            for(size_t j = i+1; j < n; j++)
                if(place[j] < place[i])
                    rSize[i]++;
                    
        size_t sum = 0;
        for(auto & i: rSize)
            sum += i;
        size_t zeroSum = sum;

        size_t lastNum = n-1;
        size_t minSum = sum;
        for(size_t i = 0; i < n-1; i++) { //循环让i设为最大值，更新逆序数
            for(size_t j = 0; j < n; j++)
                if(place[j] > place[i]) {
                    rSize[j]++;
                    sum++;
                }
            sum -= rSize[i];
            rSize[i] = 0;
            if(sum < minSum) {
                lastNum = i;
                minSum = sum;
            }
        }
        return std::make_tuple(lastNum, minSum, zeroSum);
    };

    auto [lastNum, minSum, zeroSum] = GetMinMove();
    std::cout << "minSum : " << minSum << ", lastNum : " << lastNum << ", firstNum : " << (lastNum+1)%n << ", zeroSum : " << zeroSum <<'\n';


    int place[n] = {}; //位置
    for(size_t i = 0; i < n; i++)
        place[arr[i]] = i;

    int placeDiff[n] = {};
    // size_t sumDiffA = 0;
    for(int i = 0; i < n; i++) {
        placeDiff[i] = i - place[i];
        std::cout << placeDiff[i] << ' ';
        // sumDiffA += std::abs(placeDiff[i]);
    }
    std::cout << '\n';
    // sumDiffB -= std::abs(placeDiff[n-1]+n);

    for(int i = 0; i < n; i++) {
        auto v = arr[i] - 1 - arr[(i+n-1)%n];
        // if(v > 0)
        //     v-=1;
        std::cout << v << ' ';
    }
    std::cout << '\n';

    for(int i = 0; i < n; i++) {
        auto v = place[i] - place[(i+n-1)%n];
        if(v > 0)
            v-=1;
        std::cout << v << ' ';
    }
    std::cout << '\n';
    // size_t arrC[n];
    // auto TryMove = [&arr, &arrC, &n](size_t offset) {
    //     //转换为0-n，增加偏移
    //     for(size_t i = 0; i < n; i++)
    //         arrC[i] = (arr[i]+n-offset)%n;

    //     size_t moveNum = 0;
    //     for(size_t i = 0; i < n; i++)
    //         while(arrC[i] != i) {
    //             for(size_t j = i; j < arrC[j]; j++) {
    //                 std::swap(arrC[j], arrC[j+1]);
    //                 moveNum++;
    //             }
    //         }
    //     return moveNum;
    // };
    // std::cout << "TryMove:\n";
    // size_t actualMinNum = n;
    // for(size_t i = 0; i < n; i++) {
    //     std::cout << TryMove(i) << ' ';
    //     actualMinNum = std::min(actualMinNum, TryMove(i));
    // }
    // std::cout << '\n';
    // std::cout << "actualMinNum:" << actualMinNum;
    return 0;
}
