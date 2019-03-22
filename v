#include <iostream>
#include <utility>
#include <PatMat.hpp>
#include <Switch.hpp>
#include <boost/timer.hpp>
#include <mpark/patterns.hpp>

using namespace std;
using namespace GTL::PatMat;
using namespace GTL::Switch;

template <std::size_t N>
void more();

constexpr auto SwitchJ1 = [](auto inp, auto cases) {
    //constexpr auto [repeatKey, arr] = cases();
    static_assert(std::get<0>(cases()) == false, " ");
    //static constexpr auto pridict = 1;
    return;
};

constexpr auto SwitchJ2 = [](auto inp, auto cases) {
    static_assert(std::get<0>(cases()) == false, " ");
    //static constexpr auto pridict = 1;
    return;
};

constexpr auto SwitchJ3 = [](auto inp, auto cases) {
    static_assert(std::get<0>(cases()) == false, "键值有重复！");
    return std::get<1>(cases());
};

constexpr auto makePredicJ4 = [](auto cases){
    constexpr auto arr = std::get<1>(cases());
    using TypeC = decltype(arr[0].key);
    using TypeD = decltype(arr[0].deal);
    constexpr auto _N = arr.size();
    constexpr auto offset = arr[0].key;
    constexpr std::size_t length =  arr[_N-1].key - arr[0].key + 1;

    return GTL::Switch::detail::PredicJ<length, TypeC, TypeD, offset> {
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

inline auto SwitchJ4 = [](auto inp, auto cases) {
    static_assert(std::get<0>(cases()) == false, "键值有重复！");
    static constexpr auto pridict = makePredicJ4(cases);
    return pridict(inp);
};

template <>
void more<0>() {
    int a = 100;
    SwitchJ1(a, CONVALS(
        false, 
        Case<int, int>{1, 1},
    ));
    SwitchJ2(a, CASES(
        Case<int, int>{2, 2},
        Case<int, int>{1, 1},
        //Case<int, int>{1, 3},
    ));
    //constexpr auto cs2 = Cases(array{
    //    Case<int, int>{2, 2},
    //    Case<int, int>{1, 1},
    //    Case<int, int>{4, 4},
    //    Case<int, int>{3, 3},
    //    Case<int, int>{2, 22},
    //});
    //cout << "casearray 1:\n";
    //cout << cs2 << endl;


    //constexpr auto cs3 = Cases2(array{
    //    Case<int, int>{2, 2},
    //    Case<int, int>{1, 1},
    //    Case<int, int>{4, 4},
    //    Case<int, int>{3, 3},
    //    Case<int, int>{2, 22},
    //});
    //auto cs3a = get<1>(cs3);
    //bool cs3i = get<0>(cs3);
    //cout << "casearray 2:";
    //cout << cs3i << endl;
    //for(auto &cs3ac :cs3a)
    //    cout << cs3ac.key << ":" << cs3ac.deal << std::endl;


    cout << "casearray 3:\n";
    cout << SwitchJ3(a, CASES(
        Case<int, int>{2, 2},
        Case<int, int>{1, 1},
        Case<int, int>{4, 4},
        Case<int, int>{3, 3},
        //Case<int, int>{2, 22}, 成功！
    ));

    cout << "casearray 4:\n";
    cout << SwitchJ4(1, CASES(
        Case<int, int>{2, 2},
        Case<int, int>{1, 1},
        Case<int, int>{4, 4},
        Case<int, int>{3, 3},
        //Case<int, int>{2, 22}, 成功！
    )) << endl;


}

template<typename T, std::size_t N>
std::size_t BS (std::array<T, N> &arr, T &target)
{
    std::size_t bot = 0, top = N;

    while (bot < top) {
        std::size_t mid = (bot + top) / 2;
        if (arr[mid] < std::move(target))
            bot = mid + 1;
        else
            top = mid;
    }
    if (bot == N || arr[bot] != target) {
        return -1;
    } else {
        return bot;
    }
}

template <>
void more<1>() {

    auto cs0 = std::array{1, 5, 9, 13, 100};
    cout << "\ncasearray 0:\n";
    for(auto i = 0; i < 10; i++) {
        cout << "find:" << i << "=" << BS(cs0, i) << std::endl;
    }

    constexpr auto cs1 = CASES(
       Case<int, int>{2, 2},
       Case<int, int>{1, 1},
       Case<int, int>{4, 4},
       Case<int, int>{3, 3},
       Case<int, int>{2, 22},
    );

    bool cs1i = get<0>(cs1());
    auto cs1a = get<1>(cs1());
    cout << "\ncasearray 1:";
    cout << cs1i << endl;
    // for(auto &cs1ac :cs1a)
    //     cout << "key:" << cs1ac.key << "=" << cs1ac.deal << std::endl;
    for(auto i = 0; i < 10; i++) {
        auto cs1d = Case<int, int>{i, 0};
        cout << "find" << i << ":" << BS(cs1a, cs1d) << std::endl;
    }
}

template<std::size_t N>
int BS2 (std::array<Case<int, int>, N> &arr, int &target)
{
    std::size_t bot = 0, top = N;

    while (bot < top) {
        cout << "Q";
        std::size_t mid = (bot + top) / 2;
        cout << "Q";
        if (arr[mid].key < target)
            bot = mid + 1;
        else
            top = mid;
    }
    cout << "Q";
    if (bot == N) {
        return -1;
    } else {
        cout << "Q";
        if (arr[bot].key != target) {
            return -1;
        } else {
            return arr[bot].deal;
        }
    }
}

int BS2OUHE (int val)
{
    cout << "Q";
    if (val < 0 || val > 9) {
        return -1;
    }
    cout << "Q";
    if (val < 6) {
        cout << "Q";
        if (val == 0) {
            return 0;
        } else {
            cout << "Q";
            if (val == 3) {
                return 3;
            }
        }
    } else {
        cout << "Q";
        if (val < 9) {
            cout << "Q";
            if (val == 6) {
                return 6;
            }
        } else {
            return 9;
        }
    }
    return -1;
}

template<typename TypeC, typename TypeD, std::size_t N>
struct CTBS_helper {
    std::array<Case<TypeC, TypeD>, N> arr;
    TypeD dft;
    constexpr auto operator()() {
        if constexpr (N == 2) {
            return [&](auto val){
                if (val == arr[0].key) {
                    return arr[0].deal;
                } else if (val == arr[1].key) {
                    return arr[1].deal;
                } else {
                    return dft;
                }
            };
        } else if constexpr (N == 1) {
            return [&](auto val){
                if (val == arr[0].key) {
                    return arr[0].deal;
                } else {
                    return dft;
                }
            };
        } else {
            constexpr auto mid = N/2;
            return [&](auto val){
                if (val < arr[mid]) {
                    return CTBS_helper<TypeC, TypeD, mid>{
                        [&]{
                            std::array<Case<TypeC, TypeD>, mid> nxt{};
                            for(auto i = 0; i < mid; i++) {
                                nxt[i] = arr[i];
                            }
                            return nxt;
                        },
                        dft,
                    }()(val);
                } else {
                    return CTBS_helper<TypeC, TypeD, N - mid>{
                        [&]{
                            //std::array<Case<TypeC, TypeD>, N - mid> nxt(
                            //    arr.begin() + mid, arr.end());
                            std::array<Case<TypeC, TypeD>, N - mid> nxt{};
                            for(auto i = 0; i < N - mid; i++) {
                                nxt[i] = arr[i + mid];
                            }
                            return nxt;
                        },
                        dft,
                    }()(val);
                }
            };
        }
    }
};

template<typename TypeC, typename TypeD, std::size_t N>
struct CTBS_helper2 {
    std::array<Case<TypeC, TypeD>, N> arr;
    TypeD dft;
    constexpr auto operator()() {
        if constexpr (N == 2) {
            return [&](auto val){
                return dft;
            };
        } else {
            return [&](auto val){
                return dft;
            };
        }
    }
};

constexpr auto addition()
{
    return [](int a, int b){ return a+b; };
}

template <>
void more<2>() {
    auto cs0 = std::array{
        Case<int, int>{0, 0},
        Case<int, int>{3, 3},
        Case<int, int>{6, 6},
        Case<int, int>{9, 9},
    };

    cout << "\ncasearray 0:\n";
    for(auto i = 0; i < 10; i++) {
        cout << "find:" << i << "\t= " << BS2(cs0, i) << std::endl;
    }
    cout << "\ncasearray 1:\n";
    for(auto i = 0; i < 10; i++) {
        cout << "find:" << i << "\t= " << BS2OUHE(i) << std::endl;
    }

    constexpr auto cs2 = std::array{
        Case<int, int>{0, 0},
        Case<int, int>{3, 3},
        Case<int, int>{6, 6},
        Case<int, int>{9, 9},
    };
    //constexpr auto BS3 = CTBS_helper2<int, int, 4>{cs2, -1}();
    auto a = addition();
    cout << a(100, 200);
}

















int main(int argc,char* argv[])
{
    //普通探索
    constexpr Case<int, int> a{1, 1};
    constexpr Case<int, int> b{2, 2}; 
    constexpr int ak = a.key;

    //不带参数的lambda
    constexpr int akl1 = [&](){return a.key;}();
    //constexpr auto aklf1 = [&](){return a.key;}; error in clang
    constexpr auto aklf1 = [=](){return a.key;};
    constexpr int aklr1 = aklf1();

    //带参数的lambda
    constexpr int akl2 = [](const Case<int, int> &aa){return aa.key;}(a);
    constexpr auto aklf2 = [](const Case<int, int> &aa){return aa.key;};
    constexpr int aklr2 = aklf2(a);

    //比较
    //constexpr Case<int, int> &ref_c = a < b ? a : b; error
    constexpr Case<int, int> c = a < b ? a : b; 
    constexpr int ck = c.key;

    //不带参数的labmda内比较
    constexpr int ckl1 = [&](){
        //constexpr Case<int, int> &c = a < b ? a : b;
        constexpr Case<int, int> c = a < b ? a : b;
        return c.key;
    }();
    constexpr auto cklf1 = [=](){
        constexpr Case<int, int> c = a < b ? a : b;
        return c.key;
    };
    constexpr int cklr1 = cklf1();

    //带参数的labmda内比较
    constexpr int ckl2 = [](const Case<int, int> aa, const Case<int, int> bb){
        Case<int, int> cc = aa < bb ? aa : bb;
        return cc.key;
    }(a, b);
    constexpr auto cklf2 = [](const Case<int, int> aa, const Case<int, int> bb){
        Case<int, int> cc = aa < bb ? aa : bb;
        return cc.key;
    };
    constexpr int cklr2 = cklf2(a, b);

    //直接比较key
    constexpr Case<int, int> d = a.key < b.key ? a : b; 
    constexpr int dk = d.key;

    constexpr int eak = a.key;
    constexpr int ebk = b.key;
    constexpr Case<int, int> e = eak < ebk ? a : b;
    constexpr Case<int, int> e2 = a.key < b.key ? a : b;

    //Case array排序
    //constexpr auto s2 = Cases(array{
    //    Case<int, int> {2, 2},
    //    Case<int, int> {1, 1},
    //});
    //std::copy(std::cbegin(s2), std::cend(s2), std::ostream_iterator<Case<int, int>>{std::cout, " "});

    //constexpr int s2ak = s2[0].key;
    //
    //constexpr int s2mink = s2[0].key;
    //constexpr int s2maxk = s2[1].key;
    //constexpr int s2maxk0 = s2[s2.size() - 1].key;

    //constexpr参数
    //https://mpark.github.io/programming/2017/05/26/constexpr-function-parameters/
    //以下两个不能用
    constexpr auto cep_l1 = [](const Case<int, int> a, const Case<int, int> b){
        //static_assert(a.key != b.key); error
        return a < b ? a : b;
    }(a, b);
    constexpr auto cep_l2 = [](const std::tuple<Case<int, int>> a, const std::tuple<Case<int, int>> b){
        //static_assert(std::get<0>(a).key != std::get<0>(b).key, "bad"); error
        return a < b ? a : b;
    }(a, b);

    constexpr auto cep_l3 = [](auto x) {
        static_assert(std::get<0>(x()) == 101, "");
        static_assert(std::get<1>(x()) == 202, "");
        return x();
    }([]{return std::make_tuple(101, 202);});

    constexpr auto cep_l4 = [](auto x) {
        static_assert(std::get<0>(x()).key == 2, "");
        static_assert(std::get<1>(x()).key == 1, "");
        return x();
    }([]{return std::tuple{Case<int, int>{2, 2}, Case<int, int>{1, 1}};});



    constexpr auto cep_l5 = [](auto x, auto y) {
        static_assert(std::get<0>(x()).key == 2, "");
        static_assert(std::get<1>(x()).key == 1, "");

        static_assert(std::get<0>(y()).key == 2, "");
        static_assert(std::get<1>(y()).key == 1, "");
        return std::tuple{x(), y()};
    }(CONVALS(Case<int, int>{2, 2}, Case<int, int>{1, 1},), CONARRY(Case<int, int>{2, 2}, Case<int, int>{1, 1},));



    //more<0>();
    //more<1>();
    more<2>();








    return 0;
}
