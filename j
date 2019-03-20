#ifndef GTL_SWITCH_SWITCHJ_HPP
#define GTL_SWITCH_SWITCHJ_HPP

#include <array>
#include <experimental/array>
#include <algorithm>
#include <cstddef>
#include <type_traits>
#include "Switch/SwitchCommon.hpp"

namespace GTL::Switch {

namespace detail {
    template <std::size_t length, class TypeC, class TypeD, TypeC offset>
    struct PredicJ {
        std::array<TypeD, length> seq;
        TypeD dft;

        template <typename TypeV>
        decltype(dft) operator()(TypeV &&val) const {
            if (val - offset < 0 || val - offset >= length) {
                return dft;
            } else {
                return seq[val - offset];
            }
        }
        
        friend std::ostream& operator<<(std::ostream& ostr, PredicJ pj) {
            ostr << "length = " << length << ", offset = " << offset << ", array =\n";
            for(auto &c :pj.seq)
                ostr << c;
            return ostr;
        }
        friend std::ostream& operator<<(std::ostream& ostr, PredicJ &pj) {
            ostr << "length = " << length << ", offset = " << offset << ", array =\n";
            for(auto &c :pj.seq)
                ostr << c;
            return ostr;
        }
    };

    template <class CASES>
    constexpr auto makePredicJ(CASES cases) {
        constexpr auto Rcases = cases();
        static_assert(std::get<0>(Rcases) == false, "键值有重复！");
        constexpr auto arr = std::get<1>(Rcases);
        using TypeC = decltype(arr[0].key);
        using TypeD = decltype(arr[0].deal);
        constexpr auto _N = arr.size();
        constexpr auto offset = arr[0].key;
        constexpr std::size_t length =  arr[_N-1].key - arr[0].key + 1;
        
        return PredicJ<length, TypeC, TypeD, offset> {
            [&](){
                std::array<TypeC, length> pat{};
                for(auto c : arr) {
                    pat[c.key - offset] = c.deal;
                }
                return pat;
            }(),
            TypeD(),
        };
    };

    template <class CASES, class DFT>
    constexpr auto makePredicJ(CASES cases, DFT dft) {
        constexpr auto Rcases = cases();
        constexpr auto Rdft = dft();
        constexpr auto arr = std::get<1>(Rcases);
        using TypeC = decltype(arr[0].key);
        using TypeD = decltype(arr[0].deal);

        static_assert(typeid(arr[0].deal) == typeid(Rdft), "default类型不匹配！");
        static_assert(std::get<0>(Rcases) == false, "键值有重复！");

        constexpr auto _N = arr.size();
        constexpr auto offset = arr[0].key;
        constexpr std::size_t length =  arr[_N-1].key - arr[0].key + 1;
        
        return PredicJ<length, TypeC, TypeD, offset> {
            [&](){
                std::array<TypeC, length> pat{};
                pat.fill(Rdft);
                for(auto c : arr) {
                    pat[c.key - offset] = c.deal;
                }
                return pat;
            }(),
            Rdft,
        };
    };

}

template <class INPUT, class CASES>
inline auto SwitchJ(INPUT inp, CASES cases) {
    static constexpr auto predic = detail::makePredicJ(cases);
    return predic(inp);
};

template <class INPUT, class CASES, class DFT>
inline auto SwitchJ(INPUT inp, CASES cases, DFT dft) {
    static constexpr auto predic = detail::makePredicJ(cases, dft);
    return predic(inp);
};

inline auto SwitchJ_Test(int val) noexcept
{
    constexpr static detail::PredicJ<100, int, int, 0> predic{
        [](){
            std::array<int, 100> pat{};
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
        }(),
        0,
    };

    return predic(val);
}

inline auto SwitchJ_Test2(int val) noexcept
{
    constexpr static detail::PredicJ<99, int, int, 0> predic{
        [](){
            std::array<int, 99> pat{};
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
        }(),
        0,
    };

    return predic(val - 1);
}

inline auto SwitchJ_Test3(int val) noexcept
{
    constexpr static detail::PredicJ<99, int, int, 1> predic{
        [](){
            std::array<int, 99> pat{};
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
        }(),
        0,
    };

    return predic(val);
}

} // namespace GTL::Switch

#endif // GTL_SWITCH_SWITCHJ_HPP
