#ifndef GTL_SWITCH_SWITCHJ_HPP
#define GTL_SWITCH_SWITCHJ_HPP

#include <array>
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
    };

    template <typename TypeC, typename TypeD>
    constexpr auto makePredicJ = [](std::initializer_list<Case<TypeC, TypeD>>&& cases){
        static_assert(cases.size() != 0, "NO CASES!");

        std::sort(cases.begin(), cases.end());
        TypeC offset = cases.begin()->key;
        std::size_t length =  cases.end()->key - cases.begin()->key + 1;

        return PredicJ<length, TypeC, TypeD, offset> {
            [&](){
                std::array<TypeC, length> pat{};
                for(auto c : cases) {
                    pat[c.key] = c.deal;
                }
                return pat;
            }(),
            TypeD(),
        };
    };
}

template <typename TypeV, typename TypeC, typename TypeD>
inline auto& SwitchJ(TypeV &&val, std::initializer_list<Case<TypeC, TypeD>>&& cases) noexcept
{
    constexpr static auto predic = detail::makePredicJ<TypeC, TypeD>(cases);
    return predic(val);
}

inline auto SwitchJ_Test2(int val) noexcept
{
    return SwitchJ(val, {
        Case<uint32_t, uint32_t>{1, 19},
        Case<uint32_t, uint32_t>{99, 1}
    });
}

inline auto SwitchJ_Test(int val) noexcept
{
    constexpr static detail::PredicJ<100, int, int, 0> predic{
        //std::array<int, 100>{
        //    1,2,3,4,5,6,
        //},
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

} // namespace GTL::Switch

#endif // GTL_SWITCH_SWITCHJ_HPP
