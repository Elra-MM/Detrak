#include <iostream>
#include <random>

#include "Painter.h"
#include "Detrak.h"

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
        {'X', Symbols::X}

    };
}

[[nodiscard]] char symbolsToChar(const Symbols& symb) {
    for (auto [c, s] : matchings) {
        if (symb == s)
            return c;
    }
    std::cerr << "Can't find the symbol, return X";
    return 'X';
}


[[nodiscard]] Symbols firstSymbol() {
    std::cout << "Choose your first symbol within { 'A', 'B', 'C', 'D', 'E', 'F' }" << std::endl;

    while (true) {
        char answer;
        std::cin >> answer;

        for (auto [c, s] : matchings)
        {
            if (answer == c)
                return s;
        }
        std::cout << "Choose better stp" << std::endl;
    }
}

[[nodiscard]] Symbols getRandomSymbol() {

    std::random_device seed;  // a seed source for the random number engine
    std::mt19937 gen(seed()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);

    int random = distrib(gen);
    std::cout << "random = " << random << std::endl;
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


[[nodiscard]] bool Board::isAvailable(Coordinate const coord) {
    return matrix[coord.x][coord.y] == Symbols::_;
}

[[nodiscard]] bool Board::hasAdjacentFields(Coordinate const coord) {
    return matrix[coord.x + 1][coord.y] == Symbols::_ &&
        matrix[coord.x - 1][coord.y] == Symbols::_ &&
        matrix[coord.x][coord.y + 1] == Symbols::_ &&
        matrix[coord.x][coord.y - 1] == Symbols::_;
}


[[nodiscard]] std::vector<Coordinate> Board::getAvailableNeighbors(Coordinate& const coord){
    std::vector<Coordinate> neighbors;
    int x = coord.x;
    int y = coord.y;

    if (matrix[x + 1][y] == Symbols::_)
        neighbors.emplace_back(x + 1, y );
    if (matrix[x - 1][y] == Symbols::_)
        neighbors.emplace_back( x - 1, y );
    if (matrix[x][y + 1] == Symbols::_)
        neighbors.emplace_back( x, y + 1 );
    if (matrix[x][y - 1] == Symbols::_)
        neighbors.emplace_back( x , y - 1);

    return neighbors;
}


[[nodiscard]] Coordinate Board::chooseFirstCoordinate() {
    while (true)
    {
        //TODO : check if the cin is a int and not a char or string
        Coordinate coord;
        std::cout << "Where do you want to put the first one ? (x row, y column, with x,y =[0,4])" << std::endl;
        std::cout << "row = ?" << std::endl;
        std::cin >> coord.x;
        std::cout << "column = ?" << std::endl;
        std::cin >> coord.y;

        if (isAvailable(coord))
        {
            if (hasAdjacentFields(coord))
                return coord;
            else
            {
                std::cout << "sorry, this field has no adjacent field available, try again" << std::endl;
                continue;
            }
        }
        std::cout << "sorry, this case is not available, try again " << std::endl;
    }
}

[[nodiscard]] Coordinate Board::chooseSecondCoordinate(Coordinate& const coord1) {
    std::vector<Coordinate> neighbors = getAvailableNeighbors(coord1);

    //TODO : check if the cin is a int and not a char or string

    while (true)
    {
        for (size_t i = 0; i < neighbors.size(); i++)
        {
            std::cout << "Choose " << i << " for the coordinate " << neighbors[i] << std::endl;
        }
        int choice;
        std::cin >> choice;

        if (choice < neighbors.size())
            return neighbors[choice];
    }
}

void Board::drawSymbols(Symbols& const symb1, Symbols& const symb2)
{
    Coordinate coord1 = chooseFirstCoordinate();
    Coordinate coord2 = chooseSecondCoordinate(coord1);

    matrix[coord1.x][coord1.y] = symb1;
    matrix[coord2.x][coord2.y] = symb2;
}

bool Board::canTheGameContinue()
{
    for (unsigned short int i = 0; i < board_size; i++) 
    {
        for (unsigned short int j = 0; j < board_size; j++)
        {
            if (Board::matrix[i][j] == Symbols::_ && hasAdjacentFields({ i, j }))
            {
                return true;
            }
        }
    }
    return false;
}
