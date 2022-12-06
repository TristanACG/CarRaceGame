#pragma once

struct Position
{
	int col;
	int row;
	Position() {};
	Position(int c, int r)
	{
		col = c;
		row = r;
	}

	Position operator+=(int value)
	{
		this->col += value;
		this->row += value;
		return *this;
	}
};