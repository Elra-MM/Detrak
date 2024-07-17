#include <iostream>
using namespace std;
#include "Painter.h"
#include "Detrak.h"
#include <random>

namespace { //it is available only in this file
    struct CastSymbol
    {
        char character;
        Symbols symbol;
    };

    constexpr CastSymbol matchings[] = {
        {'A', Symbols::A},
        {'B', Symbols::B},
        {'C', Symbols::C},
        {'D', Symbols::D},
        {'E', Symbols::E},
        {'F', Symbols::F},
        {'_', Symbols::_},

    };
}

char symbolsToChar(const Symbols& symb) {
    for (auto [c, s] : matchings) {
        if (symb == s)
            return c;
    }
    cout << "Can't find your symbol";
}


Symbols firstAnswer() {
    cout << "Choose your first symbol within { 'A', 'B', 'C', 'D', 'E', 'F' }" << endl;

    while (true) {
        char answer;
        cin >> answer;

        for (auto [c, s] : matchings)
        {
            if (answer == c)
                return s;
        }
        cout << "Choose better stp" << endl;
    }
}

Symbols getRandomSymbol() {

    std::random_device seed;  // a seed source for the random number engine
    std::mt19937 gen(seed()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);

    int random = distrib(gen);
    cout << "random = " << random << endl;
    return matchings[random].symbol;
}

Board::Board()
{
    for (auto& row : Board::matrix)
    {
        for (auto& symb : row)
        {
            symb = Symbols::_;
        }
    }
}
