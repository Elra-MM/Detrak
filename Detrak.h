#pragma once

enum class Symbols { A, B, C, D, E, F, _ };
[[nodiscard]] char symbolsToChar(const Symbols&);

Symbols firstAnswer();


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
};
