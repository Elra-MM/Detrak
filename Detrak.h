#pragma once

#include <vector>
#include <ostream>


enum class Symbols { A, B, C, D, E, F, _ , X};
[[nodiscard]] char symbolsToChar(const Symbols&);

[[nodiscard]] Symbols firstSymbol();
[[nodiscard]] Symbols getRandomSymbol();

struct Coordinate final
{
	unsigned short int x;
	unsigned short int y;
};

std::ostream& operator<<(std::ostream& out, const Coordinate& coord);

constexpr size_t board_size = 5;

template<typename T, size_t N>
using Matrix = T[N][N];

class Board final
{
public:

	[[nodiscard]] Board();
	[[nodiscard]] Board(const Board&) = delete; //copy contructor
	[[nodiscard]] Board(Board&&) = default; //move constructor, && = temporary value, r-value
	Board& operator=(const Board&) = delete;
	Board& operator=(Board&&) = default;
	~Board() = default;

	Matrix<Symbols, board_size> matrix;

	[[nodiscard]] bool isAvailable(Coordinate const);
	[[nodiscard]] bool hasAdjacentFields(Coordinate const);
	[[nodiscard]] std::vector<Coordinate> getAvailableNeighbors(Coordinate& const);
	[[nodiscard]] Coordinate chooseFirstCoordinate();
	[[nodiscard]] Coordinate chooseSecondCoordinate(Coordinate& const);
	void drawSymbols(Symbols& const symb1, Symbols& const symb2);
};

