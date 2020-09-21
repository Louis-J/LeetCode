#include <iostream>
// #include <array>

// using std::array;
class Cow {
    // array<size_t, 5> ageNum = {1};
    size_t ageNum[5] = {1};
    void NextYear() {
        ageNum[4] += ageNum[3];
        ageNum[3] = ageNum[2];
        ageNum[2] = ageNum[1];
        ageNum[1] = ageNum[0];
        ageNum[0] = ageNum[4];
    }
public:
    void NYear(size_t n) {
        while(n--)
            NextYear();
    }
    size_t GetSum() {
        size_t sum = 0;
        for(auto &i : ageNum)
            sum += i;
        return sum;
    }
};
int main() {
    size_t n;
    std::cin >> n;
    Cow cow;
    cow.NYear(n);
    std::cout << cow.GetSum();
    return 0;
}