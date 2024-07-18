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


Symbols firstSymbol() {
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

std::ostream& operator<<(std::ostream& out, const Coordinate& coord) {
    return out << "[ " << coord.x << " , " << coord.y << " ] ";
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


bool Board::isAvailable(Coordinate const coord) {
    return this->matrix[coord.x][coord.y] == Symbols::_;
}

bool Board::hasAdjacentFields(Coordinate const coord) {
    return matrix[coord.x + 1][coord.y] == Symbols::_ &&
        matrix[coord.x - 1][coord.y] == Symbols::_ &&
        matrix[coord.x][coord.y + 1] == Symbols::_ &&
        matrix[coord.x][coord.y - 1] == Symbols::_;
}


std::vector<Coordinate> Board::getNeighborsAvailable(Coordinate const coord){
    vector<Coordinate> neighbors;
    if (matrix[coord.x + 1][coord.y] == Symbols::_)
        neighbors.push_back({ coord.x + 1, coord.y });
    if (matrix[coord.x - 1][coord.y] == Symbols::_)
        neighbors.push_back({ coord.x - 1, coord.y });
    if (matrix[coord.x][coord.y + 1] == Symbols::_)
        neighbors.push_back({ coord.x, coord.y + 1 });
    if (matrix[coord.x][coord.y - 1] == Symbols::_)
        neighbors.push_back({ coord.x , coord.y - 1});

    return neighbors;
}


Coordinate Board::chooseFirstCoordinate() {
    while (true)
    {
        //TODO : check if the cin is a int and not a char or string
        Coordinate coord;
        cout << "Where do you want to put the first one ? (x row, y column, with x,y =[0,4])" << endl;
        cout << "row = ?" << endl;
        cin >> coord.x;
        cout << "column = ?" << endl;
        cin >> coord.y;

        if (isAvailable(coord))
        {
            if (hasAdjacentFields(coord))
                return coord;
            else
            {
                cout << "sorry, this field has no adjacent field available, try again" << endl;
                continue;
            }
        }
        cout << "sorry, this case is not available, try again " << endl;
    }
}

Coordinate Board::chooseSecondCoordinate(Coordinate const coord1) {
    vector<Coordinate> neighbors = getNeighborsAvailable(coord1);

    //TODO : check if the cin is a int and not a char or string

    while (true)
    {
        for (size_t i = 0; i < neighbors.size(); i++)
        {
            cout << "Choose " << i << " for the coordinate " << neighbors[i] << endl;
        }
        int choice;
        cin >> choice;

        if (choice < neighbors.size())
            return neighbors[choice];
    }
}

void Board::drawSymbols(Symbols const symb1, Symbols const symb2)
{
    Coordinate coord1 = chooseFirstCoordinate();
    Coordinate coord2 = chooseSecondCoordinate(coord1);

    matrix[coord1.x][coord1.y] = symb1;
    matrix[coord2.x][coord2.y] = symb2;
}
