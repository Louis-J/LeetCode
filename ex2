#include <iostream>
#include <vector>
#include <Switch.hpp>
#include <boost/timer.hpp>

using namespace std;
using namespace GTL::Switch;

int which = 0;

const auto match0 = [](int n)
{
    which++;
    switch(n) {
        case 19: return 10;
        case 16: return 11;
        case 13: return 12;
        case 10: return 13;
        case 8 : return 14;
        case 6 : return 15;
        case 4 : return 16;
        case 3 : return 17;
        case 2 : return 18;
        case 1 : return 19;

        case 39: return 20;
        case 36: return 21;
        case 33: return 22;
        case 30: return 23;
        case 28: return 24;
        case 26: return 25;
        case 24: return 26;
        case 23: return 27;
        case 22: return 28;
        case 21: return 29;

        case 59: return 30;
        case 56: return 31;
        case 53: return 32;
        case 50: return 33;
        case 48: return 34;
        case 46: return 35;
        case 44: return 36;
        case 43: return 37;
        case 42: return 38;
        case 41: return 39;

        case 79: return 40;
        case 76: return 41;
        case 73: return 42;
        case 70: return 43;
        case 68: return 44;
        case 66: return 45;
        case 64: return 46;
        case 63: return 47;
        case 62: return 48;
        case 61: return 49;

        case 99: return 50;
        case 96: return 51;
        case 93: return 52;
        case 90: return 53;
        case 88: return 54;
        case 86: return 55;
        case 84: return 56;
        case 83: return 57;
        case 82: return 58;
        case 81: return 59;

        default: return 0 ;
    };
};

const auto match1 = [](int n)
{
    static constexpr auto pat = [](){
        std::array<uint64_t, 100> pat{};
        pat[19] = 10;
        pat[16] = 11;
        pat[13] = 12;
        pat[10] = 13;
        pat[8 ] = 14;
        pat[6 ] = 15;
        pat[4 ] = 16;
        pat[3 ] = 17;
        pat[2 ] = 18;
        pat[1 ] = 19;

        pat[39] = 20;
        pat[36] = 21;
        pat[33] = 22;
        pat[30] = 23;
        pat[28] = 24;
        pat[26] = 25;
        pat[24] = 26;
        pat[23] = 27;
        pat[22] = 28;
        pat[21] = 29;

        pat[59] = 30;
        pat[56] = 31;
        pat[53] = 32;
        pat[50] = 33;
        pat[48] = 34;
        pat[46] = 35;
        pat[44] = 36;
        pat[43] = 37;
        pat[42] = 38;
        pat[41] = 39;

        pat[79] = 40;
        pat[76] = 41;
        pat[73] = 42;
        pat[70] = 43;
        pat[68] = 44;
        pat[66] = 45;
        pat[64] = 46;
        pat[63] = 47;
        pat[62] = 48;
        pat[61] = 49;

        pat[99] = 50;
        pat[96] = 51;
        pat[93] = 52;
        pat[90] = 53;
        pat[88] = 54;
        pat[86] = 55;
        pat[84] = 56;
        pat[83] = 57;
        pat[82] = 58;
        pat[81] = 59;

        return pat;
    }();
    which++;
    return pat[n];
};

const auto match2 = [](int n)
{
    static constexpr auto pat = [](){
        std::array<uint64_t, 99> pat{};
        pat[19 - 1] = 10;
        pat[16 - 1] = 11;
        pat[13 - 1] = 12;
        pat[10 - 1] = 13;
        pat[8  - 1] = 14;
        pat[6  - 1] = 15;
        pat[4  - 1] = 16;
        pat[3  - 1] = 17;
        pat[2  - 1] = 18;
        pat[1  - 1] = 19;

        pat[39 - 1] = 20;
        pat[36 - 1] = 21;
        pat[33 - 1] = 22;
        pat[30 - 1] = 23;
        pat[28 - 1] = 24;
        pat[26 - 1] = 25;
        pat[24 - 1] = 26;
        pat[23 - 1] = 27;
        pat[22 - 1] = 28;
        pat[21 - 1] = 29;

        pat[59 - 1] = 30;
        pat[56 - 1] = 31;
        pat[53 - 1] = 32;
        pat[50 - 1] = 33;
        pat[48 - 1] = 34;
        pat[46 - 1] = 35;
        pat[44 - 1] = 36;
        pat[43 - 1] = 37;
        pat[42 - 1] = 38;
        pat[41 - 1] = 39;

        pat[79 - 1] = 40;
        pat[76 - 1] = 41;
        pat[73 - 1] = 42;
        pat[70 - 1] = 43;
        pat[68 - 1] = 44;
        pat[66 - 1] = 45;
        pat[64 - 1] = 46;
        pat[63 - 1] = 47;
        pat[62 - 1] = 48;
        pat[61 - 1] = 49;

        pat[99 - 1] = 50;
        pat[96 - 1] = 51;
        pat[93 - 1] = 52;
        pat[90 - 1] = 53;
        pat[88 - 1] = 54;
        pat[86 - 1] = 55;
        pat[84 - 1] = 56;
        pat[83 - 1] = 57;
        pat[82 - 1] = 58;
        pat[81 - 1] = 59;

        return pat;
    }();
    which++;
    return pat[n - 1];
};

const auto match3 = [](int n)
{
    which++;
    return SwitchJ_Test(n);
};

const auto match4 = [](int n)
{
    which++;
    return SwitchJ_Test2(n);
};

const auto match5 = [](int n)
{
    which++;
    return SwitchJ_Test3(n);
    //return SwitchJ(n, CASES(
    //    Case<int, int>{19, 10},
    //    Case<int, int>{16, 11},
    //    Case<int, int>{13, 12},
    //    Case<int, int>{10, 13},
    //),  DEFAULT((int)9)
    //);
};

const auto match6 = [](int n)
{
    which++;
    return SwitchJ(n, CASES(
        Case<int, int>{19, 10},
        Case<int, int>{16, 11},
        Case<int, int>{13, 12},
        Case<int, int>{10, 13},
        Case<int, int>{8 , 14},
        Case<int, int>{6 , 15},
        Case<int, int>{4 , 16},
        Case<int, int>{3 , 17},
        Case<int, int>{2 , 18},
        Case<int, int>{1 , 19},

        Case<int, int>{39, 20},
        Case<int, int>{36, 21},
        Case<int, int>{33, 22},
        Case<int, int>{30, 23},
        Case<int, int>{28, 24},
        Case<int, int>{26, 25},
        Case<int, int>{24, 26},
        Case<int, int>{23, 27},
        Case<int, int>{22, 28},
        Case<int, int>{21, 29},

        Case<int, int>{59, 30},
        Case<int, int>{56, 31},
        Case<int, int>{53, 32},
        Case<int, int>{50, 33},
        Case<int, int>{48, 34},
        Case<int, int>{46, 35},
        Case<int, int>{44, 36},
        Case<int, int>{43, 37},
        Case<int, int>{42, 38},
        Case<int, int>{41, 39},

        Case<int, int>{79, 40},
        Case<int, int>{76, 41},
        Case<int, int>{73, 42},
        Case<int, int>{70, 43},
        Case<int, int>{68, 44},
        Case<int, int>{66, 45},
        Case<int, int>{64, 46},
        Case<int, int>{63, 47},
        Case<int, int>{62, 48},
        Case<int, int>{61, 49},

        Case<int, int>{99, 50},
        Case<int, int>{96, 51},
        Case<int, int>{93, 52},
        Case<int, int>{90, 53},
        Case<int, int>{88, 54},
        Case<int, int>{86, 55},
        Case<int, int>{84, 56},
        Case<int, int>{83, 57},
        Case<int, int>{82, 58},
        Case<int, int>{81, 59},
    ));
};

const auto match7 = [](int n)
{
    which++;
    return SwitchJ(n, CASES(
        Case<int, int>{0, 0},

        Case<int, int>{19, 10},
        Case<int, int>{16, 11},
        Case<int, int>{13, 12},
        Case<int, int>{10, 13},
        Case<int, int>{8 , 14},
        Case<int, int>{6 , 15},
        Case<int, int>{4 , 16},
        Case<int, int>{3 , 17},
        Case<int, int>{2 , 18},
        Case<int, int>{1 , 19},

        Case<int, int>{39, 20},
        Case<int, int>{36, 21},
        Case<int, int>{33, 22},
        Case<int, int>{30, 23},
        Case<int, int>{28, 24},
        Case<int, int>{26, 25},
        Case<int, int>{24, 26},
        Case<int, int>{23, 27},
        Case<int, int>{22, 28},
        Case<int, int>{21, 29},

        Case<int, int>{59, 30},
        Case<int, int>{56, 31},
        Case<int, int>{53, 32},
        Case<int, int>{50, 33},
        Case<int, int>{48, 34},
        Case<int, int>{46, 35},
        Case<int, int>{44, 36},
        Case<int, int>{43, 37},
        Case<int, int>{42, 38},
        Case<int, int>{41, 39},

        Case<int, int>{79, 40},
        Case<int, int>{76, 41},
        Case<int, int>{73, 42},
        Case<int, int>{70, 43},
        Case<int, int>{68, 44},
        Case<int, int>{66, 45},
        Case<int, int>{64, 46},
        Case<int, int>{63, 47},
        Case<int, int>{62, 48},
        Case<int, int>{61, 49},

        Case<int, int>{99, 50},
        Case<int, int>{96, 51},
        Case<int, int>{93, 52},
        Case<int, int>{90, 53},
        Case<int, int>{88, 54},
        Case<int, int>{86, 55},
        Case<int, int>{84, 56},
        Case<int, int>{83, 57},
        Case<int, int>{82, 58},
        Case<int, int>{81, 59},
    ));
};

const auto add0(const size_t circle, int n)
{
    const auto timeBegin = boost::timer();
    uint64_t ret = 0;
    for (size_t i = 0; i < circle; ++i)
        ret += match0(n);
    const uint32_t timeBy = timeBegin.elapsed() * 1000;
    return tuple(ret, timeBy);
}

const auto add1(const size_t circle, int n)
{
    const auto timeBegin = boost::timer();
    uint64_t ret = 0;
    for (size_t i = 0; i < circle; ++i)
        ret += match1(n);
    const uint32_t timeBy = timeBegin.elapsed() * 1000;
    return tuple(ret, timeBy);
}

const auto add2(const size_t circle, int n)
{
    const auto timeBegin = boost::timer();
    uint64_t ret = 0;
    for (size_t i = 0; i < circle; ++i)
        ret += match2(n);
    const uint32_t timeBy = timeBegin.elapsed() * 1000;
    return tuple(ret, timeBy);
}

const auto add3(const size_t circle, int n)
{
    const auto timeBegin = boost::timer();
    uint64_t ret = 0;
    for (size_t i = 0; i < circle; ++i)
        ret += match3(n);
    const uint32_t timeBy = timeBegin.elapsed() * 1000;
    return tuple(ret, timeBy);
}

const auto add4(const size_t circle, int n)
{
    const auto timeBegin = boost::timer();
    uint64_t ret = 0;
    for (size_t i = 0; i < circle; ++i)
        ret += match4(n);
    const uint32_t timeBy = timeBegin.elapsed() * 1000;
    return tuple(ret, timeBy);
}

const auto add5(const size_t circle, int n)
{
    const auto timeBegin = boost::timer();
    uint64_t ret = 0;
    for (size_t i = 0; i < circle; ++i)
        ret += match5(n);
    const uint32_t timeBy = timeBegin.elapsed() * 1000;
    return tuple(ret, timeBy);
}

const auto add6(const size_t circle, int n)
{
    const auto timeBegin = boost::timer();
    uint64_t ret = 0;
    for (size_t i = 0; i < circle; ++i)
        ret += match6(n);
    const uint32_t timeBy = timeBegin.elapsed() * 1000;
    return tuple(ret, timeBy);
}

const auto add7(const size_t circle, int n)
{
    const auto timeBegin = boost::timer();
    uint64_t ret = 0;
    for (size_t i = 0; i < circle; ++i)
        ret += match7(n);
    const uint32_t timeBy = timeBegin.elapsed() * 1000;
    return tuple(ret, timeBy);
}

struct Case00 {
    int key;
};
template <class TypeC>
struct Case10 {
    TypeC key;
};

int main(int argc,char* argv[])
{
    size_t CIRCLE;
    if (argc == 2 && std::atoi(argv[1]) > 0) {
        CIRCLE = std::atoi(argv[1]);
    } else {
        while(!(cin >> CIRCLE)) {
            cin.clear();
            cin.sync();
        }
    }

    auto a0 = array{1, 2, 3, 4, 5};
    auto a1 = vector{1, 2, 3, 4, 5};
    auto b00 = Case00{1};
    auto b12 = Case10{array{1}};
    auto b10 = Case10{1};
    auto b11 = Case10{1};
    auto b = Case{{0},{0}};
    uint64_t times[8] = {0};
    for (int i = 0; i < 100; i++) {
        cout << "输入:" << i << endl;
        const auto [ret0, time0] = add0(CIRCLE, i);
        const auto [ret1, time1] = add1(CIRCLE, i);
        const auto [ret2, time2] = add2(CIRCLE, i);
        const auto [ret3, time3] = add3(CIRCLE, i);
        const auto [ret4, time4] = add4(CIRCLE, i);
        const auto [ret5, time5] = add5(CIRCLE, i);
        const auto [ret6, time6] = add6(CIRCLE, i);
        const auto [ret7, time7] = add7(CIRCLE, i);
        times[0] += time0;
        times[1] += time1;
        times[2] += time2;
        times[3] += time3;
        times[4] += time4;
        times[5] += time5;
        times[6] += time6;
        times[7] += time7;
        cout << "    结果0:" << ret0 << "    耗时0:" << time0 << "ms" << endl;
        cout << "    结果1:" << ret1 << "    耗时1:" << time1 << "ms" << endl;
        cout << "    结果2:" << ret2 << "    耗时2:" << time2 << "ms" << endl;
        cout << "    结果3:" << ret3 << "    耗时3:" << time3 << "ms" << endl;
        cout << "    结果4:" << ret4 << "    耗时4:" << time4 << "ms" << endl;
        cout << "    结果5:" << ret5 << "    耗时5:" << time5 << "ms" << endl;
        cout << "    结果6:" << ret6 << "    耗时6:" << time6 << "ms" << endl;
        cout << "    结果7:" << ret7 << "    耗时7:" << time7 << "ms" << endl;
    }
    cout << "总耗时0:" << times[0] << "ms" << endl;
    cout << "总耗时1:" << times[1] << "ms" << endl;
    cout << "总耗时2:" << times[2] << "ms" << endl;
    cout << "总耗时3:" << times[3] << "ms" << endl;
    cout << "总耗时4:" << times[4] << "ms" << endl;
    cout << "总耗时5:" << times[5] << "ms" << endl;
    cout << "总耗时6:" << times[6] << "ms" << endl;
    cout << "总耗时7:" << times[7] << "ms" << endl;

    return 0;
}
