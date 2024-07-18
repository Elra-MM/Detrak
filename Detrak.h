#pragma once
#include <vector>
#include <ostream>


enum class Symbols { A, B, C, D, E, F, _ };
[[nodiscard]] char symbolsToChar(const Symbols&);

Symbols firstSymbol();
Symbols getRandomSymbol();

struct Coordinate
{
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& out, const Coordinate& coord);

constexpr size_t Board_size = 5;

template<typename T, size_t N>
using Matrix = T[N][N];

class Board final
{
public:

	Board();
	Board(const Board&) = delete; //copy contructor
	Board(Board&&) = default; //move constructor, && = temporary value, r-value
	Board& operator=(const Board&) = delete;
	Board& operator=(Board&&) = default;
	~Board() = default;

	Matrix<Symbols, Board_size> matrix;

	bool isAvailable(Coordinate const);
	bool hasAdjacentFields(Coordinate const);
	std::vector<Coordinate> getNeighborsAvailable(Coordinate const);
	Coordinate chooseFirstCoordinate();
	Coordinate chooseSecondCoordinate(Coordinate const);
	void drawSymbols(Symbols const symb1, Symbols const symb2);
};

