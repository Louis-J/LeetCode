#include <iostream>
#include <PatMat.hpp>
#include <Switch.hpp>
#include <boost/timer.hpp>
#include <mpark/patterns.hpp>

using namespace std;
using namespace GTL::PatMat;
using namespace GTL::Switch;

int which = 0;

const auto match0 = [](int n) {
    which++;
    using namespace mpark::patterns;
    return match(n)(
        pattern(19) = [](){return 10;},
        pattern(16) = [](){return 11;},
        pattern(13) = [](){return 12;},
        pattern(10) = [](){return 13;},
        pattern(8 ) = [](){return 14;},
        pattern(6 ) = [](){return 15;},
        pattern(4 ) = [](){return 16;},
        pattern(3 ) = [](){return 17;},
        pattern(2 ) = [](){return 18;},
        pattern(1 ) = [](){return 19;},

        pattern(39) = [](){return 20;},
        pattern(36) = [](){return 21;},
        pattern(33) = [](){return 22;},
        pattern(30) = [](){return 23;},
        pattern(28) = [](){return 24;},
        pattern(26) = [](){return 25;},
        pattern(24) = [](){return 26;},
        pattern(23) = [](){return 27;},
        pattern(22) = [](){return 28;},
        pattern(21) = [](){return 29;},

        pattern(59) = [](){return 30;},
        pattern(56) = [](){return 31;},
        pattern(53) = [](){return 32;},
        pattern(50) = [](){return 33;},
        pattern(48) = [](){return 34;},
        pattern(46) = [](){return 35;},
        pattern(44) = [](){return 36;},
        pattern(43) = [](){return 37;},
        pattern(42) = [](){return 38;},
        pattern(41) = [](){return 39;},

        pattern(79) = [](){return 40;},
        pattern(76) = [](){return 41;},
        pattern(73) = [](){return 42;},
        pattern(70) = [](){return 43;},
        pattern(68) = [](){return 44;},
        pattern(66) = [](){return 45;},
        pattern(64) = [](){return 46;},
        pattern(63) = [](){return 47;},
        pattern(62) = [](){return 48;},
        pattern(61) = [](){return 49;},

        pattern(99) = [](){return 50;},
        pattern(96) = [](){return 51;},
        pattern(93) = [](){return 52;},
        pattern(90) = [](){return 53;},
        pattern(88) = [](){return 54;},
        pattern(86) = [](){return 55;},
        pattern(84) = [](){return 56;},
        pattern(83) = [](){return 57;},
        pattern(82) = [](){return 58;},
        pattern(81) = [](){return 59;},

        pattern(_ ) = [](){return 0 ;}
    );
};

const auto match1 = [](int n)
// const auto match1(int n)
{
    which++;
    if(n == 19) return 10;
    if(n == 16) return 11;
    if(n == 13) return 12;
    if(n == 10) return 13;
    if(n == 8 ) return 14;
    if(n == 6 ) return 15;
    if(n == 4 ) return 16;
    if(n == 3 ) return 17;
    if(n == 2 ) return 18;
    if(n == 1 ) return 19;

    if(n == 39) return 20;
    if(n == 36) return 21;
    if(n == 33) return 22;
    if(n == 30) return 23;
    if(n == 28) return 24;
    if(n == 26) return 25;
    if(n == 24) return 26;
    if(n == 23) return 27;
    if(n == 22) return 28;
    if(n == 21) return 29;

    if(n == 59) return 30;
    if(n == 56) return 31;
    if(n == 53) return 32;
    if(n == 50) return 33;
    if(n == 48) return 34;
    if(n == 46) return 35;
    if(n == 44) return 36;
    if(n == 43) return 37;
    if(n == 42) return 38;
    if(n == 41) return 39;

    if(n == 79) return 40;
    if(n == 76) return 41;
    if(n == 73) return 42;
    if(n == 70) return 43;
    if(n == 68) return 44;
    if(n == 66) return 45;
    if(n == 64) return 46;
    if(n == 63) return 47;
    if(n == 62) return 48;
    if(n == 61) return 49;

    if(n == 99) return 50;
    if(n == 96) return 51;
    if(n == 93) return 52;
    if(n == 90) return 53;
    if(n == 88) return 54;
    if(n == 86) return 55;
    if(n == 84) return 56;
    if(n == 83) return 57;
    if(n == 82) return 58;
    if(n == 81) return 59;

    return 0 ;
};

const auto match2 = [](int n)
// const auto match2(int n)
{
    which++;
    if     (n == 19)    return 10;
    else if(n == 16)    return 11;
    else if(n == 13)    return 12;
    else if(n == 10)    return 13;
    else if(n == 8 )    return 14;
    else if(n == 6 )    return 15;
    else if(n == 4 )    return 16;
    else if(n == 3 )    return 17;
    else if(n == 2 )    return 18;
    else if(n == 1 )    return 19;

    else if(n == 39)    return 20;
    else if(n == 36)    return 21;
    else if(n == 33)    return 22;
    else if(n == 30)    return 23;
    else if(n == 28)    return 24;
    else if(n == 26)    return 25;
    else if(n == 24)    return 26;
    else if(n == 23)    return 27;
    else if(n == 22)    return 28;
    else if(n == 21)    return 29;

    else if(n == 59)    return 30;
    else if(n == 56)    return 31;
    else if(n == 53)    return 32;
    else if(n == 50)    return 33;
    else if(n == 48)    return 34;
    else if(n == 46)    return 35;
    else if(n == 44)    return 36;
    else if(n == 43)    return 37;
    else if(n == 42)    return 38;
    else if(n == 41)    return 39;

    else if(n == 79)    return 40;
    else if(n == 76)    return 41;
    else if(n == 73)    return 42;
    else if(n == 70)    return 43;
    else if(n == 68)    return 44;
    else if(n == 66)    return 45;
    else if(n == 64)    return 46;
    else if(n == 63)    return 47;
    else if(n == 62)    return 48;
    else if(n == 61)    return 49;

    else if(n == 99)    return 50;
    else if(n == 96)    return 51;
    else if(n == 93)    return 52;
    else if(n == 90)    return 53;
    else if(n == 88)    return 54;
    else if(n == 86)    return 55;
    else if(n == 84)    return 56;
    else if(n == 83)    return 57;
    else if(n == 82)    return 58;
    else if(n == 81)    return 59;

    else                return 0 ;
};

const auto match3 = [](int n)
{
    which++;
    return  (n == 19) ? 10:
            (n == 16) ? 11:
            (n == 13) ? 12:
            (n == 10) ? 13:
            (n == 8 ) ? 14:
            (n == 6 ) ? 15:
            (n == 4 ) ? 16:
            (n == 3 ) ? 17:
            (n == 2 ) ? 18:
            (n == 1 ) ? 19:

            (n == 39) ? 20:
            (n == 36) ? 21:
            (n == 33) ? 22:
            (n == 30) ? 23:
            (n == 28) ? 24:
            (n == 26) ? 25:
            (n == 24) ? 26:
            (n == 23) ? 27:
            (n == 22) ? 28:
            (n == 21) ? 29:

            (n == 59) ? 30:
            (n == 56) ? 31:
            (n == 53) ? 32:
            (n == 50) ? 33:
            (n == 48) ? 34:
            (n == 46) ? 35:
            (n == 44) ? 36:
            (n == 43) ? 37:
            (n == 42) ? 38:
            (n == 41) ? 39:

            (n == 79) ? 40:
            (n == 76) ? 41:
            (n == 73) ? 42:
            (n == 70) ? 43:
            (n == 68) ? 44:
            (n == 66) ? 45:
            (n == 64) ? 46:
            (n == 63) ? 47:
            (n == 62) ? 48:
            (n == 61) ? 49:

            (n == 99) ? 50:
            (n == 96) ? 51:
            (n == 93) ? 52:
            (n == 90) ? 53:
            (n == 88) ? 54:
            (n == 86) ? 55:
            (n == 84) ? 56:
            (n == 83) ? 57:
            (n == 82) ? 58:
            (n == 81) ? 59:

            0 ;
};

const auto match4 = [](int n)
// const auto match4(int n)
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

const auto match5 = [](int n)
{
    constexpr static auto pat = [](){
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
    if(n < 0 || n >= 100) {
        return (uint64_t)0;
    }
    return pat[n];
};

const auto match6 = [](int n)
{
    which++;
    return SwitchJ_Test(n);
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

    uint64_t times[7] = {0};
    for (int i = 0; i < 100; i++) {
        cout << "输入:" << i << endl;
        const auto [ret0, time0] = add0(CIRCLE, i);
        const auto [ret1, time1] = add1(CIRCLE, i);
        const auto [ret2, time2] = add2(CIRCLE, i);
        const auto [ret3, time3] = add3(CIRCLE, i);
        const auto [ret4, time4] = add4(CIRCLE, i);
        const auto [ret5, time5] = add5(CIRCLE, i);
        const auto [ret6, time6] = add6(CIRCLE, i);
        times[0] += time0;
        times[1] += time1;
        times[2] += time2;
        times[3] += time3;
        times[4] += time4;
        times[5] += time5;
        times[6] += time6;
        cout << "    结果0:" << ret0 << "    耗时0:" << time0 << "ms" << endl;
        cout << "    结果1:" << ret1 << "    耗时1:" << time1 << "ms" << endl;
        cout << "    结果2:" << ret2 << "    耗时2:" << time2 << "ms" << endl;
        cout << "    结果3:" << ret3 << "    耗时3:" << time3 << "ms" << endl;
        cout << "    结果4:" << ret4 << "    耗时4:" << time4 << "ms" << endl;
        cout << "    结果5:" << ret5 << "    耗时5:" << time5 << "ms" << endl;
        cout << "    结果6:" << ret6 << "    耗时6:" << time6 << "ms" << endl;
    }
    cout << "总耗时0:" << times[0] << "ms" << endl;
    cout << "总耗时1:" << times[1] << "ms" << endl;
    cout << "总耗时2:" << times[2] << "ms" << endl;
    cout << "总耗时3:" << times[3] << "ms" << endl;
    cout << "总耗时4:" << times[4] << "ms" << endl;
    cout << "总耗时5:" << times[5] << "ms" << endl;
    cout << "总耗时6:" << times[6] << "ms" << endl;

    return 0;
}
