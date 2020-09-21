#include <iostream>
#include <vector>
#include <memory>

using std::vector;
using std::pair;
using std::tuple;
using std::shared_ptr;

class NodeVal {
    // 计算汉明重量
    static uint8_t swar32(uint32_t i) {
        i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
        return (i * (0x01010101) >> 24);
    }
    static uint8_t actural(uint16_t i) {
        switch(i) {
        case 1 << 0: return 1;
        case 1 << 1: return 2;
        case 1 << 2: return 3;
        case 1 << 3: return 4;
        case 1 << 4: return 5;
        case 1 << 5: return 6;
        case 1 << 6: return 7;
        case 1 << 7: return 8;
        case 1 << 8: return 9;
        default: assert(false);
        }
    }
    // static uint16_t swar(uint16_t i) {
    //     i = (i & 0x5555) + ((i >> 1) & 0x5555);
    //     i = (i & 0x3333) + ((i >> 2) & 0x3333);
    //     i = (i & 0x0F0F) + ((i >> 4) & 0x0F0F);
    //     return i = (i * (0x0101) >> 0);
    // }

public:
    uint16_t probable = 0x1FF;
    uint8_t probNum = 9;
    uint8_t actualNum = 0;
    
public:
    NodeVal() {}
    NodeVal(uint8_t n): probable(1 << (n - 1)), probNum(1), actualNum(n) {}
    bool IfConflict(uint16_t mask) {
        return (this->probable & mask) != 0;
    }
    NodeVal Minus(uint16_t mask) {
        NodeVal nv;
        nv.probable = this->probable & ~mask;
        nv.probNum = swar32(nv.probable);
        if(nv.probNum == 1)
            nv.actualNum = actural(nv.probable);
        return nv;
    }
};

class Prosess {
public:
    enum Reason {
        A,
        Br,
        Bc,
        Bb,
        Cr,
        Cc,
        Cb,
    };
    Reason reason;
    size_t turn;
};

class Node {
public:
    vector<pair<Prosess, NodeVal>> history;
    
public:
    // Node(uint8_t n): history({{nullptr, n}}) {}
    NodeVal &Now() {
        return history[history.size()-1].second;
    }
    size_t NowIndex() {
        return history.size()-1;
    }
    void Add(Prosess &&p, NodeVal &&nv) {
        history.emplace_back(p, nv);
    }
};

class Board {
public:
    Node board[9][9];
    uint8_t solvedNum;
    size_t turn = 0;

    size_t SolveBRow(uint8_t i) {
        size_t change = 0;
        bool noNeed[9] = {false};
        for(uint8_t j = 0; j < 9; j++) {
            auto &bij = board[i][j];
            auto &bijNow = bij.Now();
            if(bijNow.probNum == 1)
                noNeed[bijNow.actualNum-1] = true;
        }

        for(uint8_t num = 0; num <9; num++) {
            if(noNeed[num] == false) {
                int8_t first = -1;
                for(uint8_t j = 0; j < 9; j++) {
                    auto &bij = board[i][j];
                    auto &bijNow = bij.Now();
                    if(bijNow.probNum != 1 && bijNow.IfConflict(1 << num)) {
                        if(first == -1)
                            first = j;
                        else {
                            first = -2;
                            break;
                        }
                    }
                }
                if(first >= 0) {
                    change++;
                    board[i][first].Add(Prosess{Prosess::Reason::Br, turn}, NodeVal(num+1));
                }
            }
        }
        return change;
    }
    size_t SolveBCol(uint8_t j) {
        size_t change = 0;
        bool noNeed[9] = {false};
        for(uint8_t i = 0; i < 9; i++) {
            auto &bij = board[i][j];
            auto &bijNow = bij.Now();
            if(bijNow.probNum == 1)
                noNeed[bijNow.actualNum-1] = true;
        }

        for(uint8_t num = 0; num <9; num++) {
            if(noNeed[num] == false) {
                int8_t first = -1;
                for(uint8_t i = 0; i < 9; i++) {
                    auto &bij = board[i][j];
                    auto &bijNow = bij.Now();
                    if(bijNow.probNum != 1 && bijNow.IfConflict(1 << num)) {
                        if(first == -1)
                            first = i;
                        else {
                            first = -2;
                            break;
                        }
                    }
                }
                if(first >= 0) {
                    change++;
                    board[first][j].Add(Prosess{Prosess::Reason::Bc, turn}, NodeVal(num+1));
                }
            }
        }
        return change;
    }
    size_t SolveBBox(uint8_t k) {
        size_t change = 0;
        bool noNeed[9] = {false};
        for(uint8_t i = k/3*3; i < k/3*3+3; i++)
            for(uint8_t j = k%3*3; j < k%3*3+3; j++) {
                auto &bij = board[i][j];
                auto &bijNow = bij.Now();
                if(bijNow.probNum == 1)
                    noNeed[bijNow.actualNum-1] = true;
            }

        for(uint8_t num = 0; num <9; num++) {
            if(noNeed[num] == false) {
                int8_t first = -1;
                for(uint8_t i = k/3*3; i < k/3*3+3; i++) {
                    for(uint8_t j = k%3*3; j < k%3*3+3; j++) {
                        auto &bij = board[i][j];
                        auto &bijNow = bij.Now();
                        if(bijNow.probNum != 1 && bijNow.IfConflict(1 << num)) {
                            if(first == -1)
                                first = i*9 + j;
                            else {
                                first = -2;
                                break;
                            }
                        }
                    }
                }
                if(first >= 0) {
                    change++;
                    board[first/9][first%9].Add(Prosess{Prosess::Reason::Bb, turn}, NodeVal(num+1));
                }
            }
        }
        return change;
    }
public:
    Board(uint8_t input[9][9]) {
        solvedNum = 0;
        for(uint8_t i = 0; i < 9; i++) {
            for(uint8_t j = 0; j < 9; j++) {
                if(input[i][j] != 0) {
                    solvedNum++;
                    board[i][j].Add(Prosess{Prosess::Reason::A, turn}, NodeVal(input[i][j]));
                } else {
                    board[i][j].Add(Prosess{Prosess::Reason::A, turn}, NodeVal());
                }
            }
        }
        turn++;
    }
    size_t SolveA() {
        size_t change = 0;
        uint16_t rMask[9] = {0};
        uint16_t cMask[9] = {0};
        uint16_t bMask[9] = {0};
        for(uint8_t i = 0; i < 9; i++) {
            for(uint8_t j = 0; j < 9; j++) {
                if(board[i][j].Now().probNum == 1) {
                    uint16_t prob = board[i][j].Now().probable;
                    rMask[i] |= prob;
                    cMask[j] |= prob;
                    bMask[i/3*3 + j/3] |= prob;
                }
            }
        }
        for(uint8_t i = 0; i < 9; i++) {
            for(uint8_t j = 0; j < 9; j++) {
                auto &bijNow = board[i][j].Now();
                if(bijNow.probNum != 1) {
                    uint16_t mask = rMask[i] | cMask[j] | bMask[i/3*3 + j/3];
                    if(bijNow.IfConflict(mask)) {
                        change++;
                        board[i][j].Add(Prosess{Prosess::Reason::A, turn}, bijNow.Minus(mask));
                    }
                }
            }
        }
        turn++;
        return change;
    }
    size_t SolveB() {
        size_t change = 0;
        for(uint8_t i = 0; i < 9; i++) {
            change += SolveBRow(i);
        }
        for(uint8_t i = 0; i < 9; i++) {
            change += SolveBCol(i);
        }
        for(uint8_t i = 0; i < 9; i++) {
            change += SolveBBox(i);
        }
        turn++;
        return change;
    }
    // bool SolveOneTurn() {
    //     bool change = false;
    //     change |= SolveA();
    //     change |= SolveB();
    //     return change;
    // }
    void Print() {
        char output[35][53];

        for(uint8_t i = 0; i < 35; i++) {
            for(uint8_t j = 0; j < 53; j++) {
                output[i][j] = ' ';
                if(i % 4 == 3 || j % 6 == 5)
                    output[i][j] = '.';
                if(i % 12 == 11)
                    output[i][j] = '=';
                if(j % 18 == 17)
                    output[i][j] = '|';
                if(i % 12 == 11 && j % 18 == 17)
                    output[i][j] = '+';
            }
        }

        for(uint8_t i = 0; i < 9; i++) {
            for(uint8_t j = 0; j < 9; j++) {
                auto &bijNow = board[i][j].Now();
                if(bijNow.probNum == 1) {
                    uint8_t realnum;
                    switch(bijNow.probable) {
                    case 1 << 0: realnum = 1; break;
                    case 1 << 1: realnum = 2; break;
                    case 1 << 2: realnum = 3; break;
                    case 1 << 3: realnum = 4; break;
                    case 1 << 4: realnum = 5; break;
                    case 1 << 5: realnum = 6; break;
                    case 1 << 6: realnum = 7; break;
                    case 1 << 7: realnum = 8; break;
                    case 1 << 8: realnum = 9; break;
                    }
                    output[i*4+1][j*6+4] = '-';
                    output[i*4+1][j*6+3] = '-';
                    output[i*4+1][j*6+2] = realnum+'0';
                    output[i*4+1][j*6+1] = '-';
                    output[i*4+1][j*6+0] = '-';
                } else {
                    if(bijNow.probable & 1 << 0) output[i*4+0][j*6+0] = '1';
                    if(bijNow.probable & 1 << 1) output[i*4+0][j*6+2] = '2';
                    if(bijNow.probable & 1 << 2) output[i*4+0][j*6+4] = '3';
                    if(bijNow.probable & 1 << 3) output[i*4+1][j*6+0] = '4';
                    if(bijNow.probable & 1 << 4) output[i*4+1][j*6+2] = '5';
                    if(bijNow.probable & 1 << 5) output[i*4+1][j*6+4] = '6';
                    if(bijNow.probable & 1 << 6) output[i*4+2][j*6+0] = '7';
                    if(bijNow.probable & 1 << 7) output[i*4+2][j*6+2] = '8';
                    if(bijNow.probable & 1 << 8) output[i*4+2][j*6+4] = '9';
                }
            }
        }

        for(uint8_t i = 0; i < 35; i++) {
            for(uint8_t j = 0; j < 53; j++) {
                std::cout << output[i][j];
            }
            std::cout << '\n';
        }
    }
};


int main(int argc, char *argv[])
{
    uint8_t input[9][9];
    for(uint8_t i = 0; i < 9; i++) {
        for(uint8_t j = 0; j < 9; j++) {
            std::cin >> input[i][j];
            input[i][j] -= '0';
        }
    }
    std::cin.ignore();

    // for(uint8_t i = 0; i < 9; i++) {
    //     std::cout << '\n';
    //     for(uint8_t j = 0; j < 9; j++)
    //         std::cout << input[i][j] << ' ';
    // }
    Board b(input);

    // for(uint8_t i = 0; i < 9; i++) {
    //     std::cout << '\n';
    //     for(uint8_t j = 0; j < 9; j++)
    //         std::cout << (int)b.board[i][j].Now().probNum << ' ';
    // }
    for(char c = std::cin.get(); c != '0'; c = std::cin.get()) {
        if(c == '1') {
            b.Print();
        } else if(c == '2') {
            std::cout << b.SolveA() << '\n';
        } else if(c == '3') {
            std::cout << b.SolveB() << '\n';
        }
    }
    return 0;
}
