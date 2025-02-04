#include "Matrix.h"
Matrix::Matrix(int n)
{
	size = n;
	convertDirection[Direction::Top] = { -1,0 };
	convertDirection[Direction::Right] = { 0,1 };
	convertDirection[Direction::Bottom] = { 1,0 };
	convertDirection[Direction::Left] = { 0,-1 };

	std::vector<int> vec(n);
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		*it = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		matrix.push_back(vec);
	}
}
void Matrix::clear()
{
	for (auto& vec : matrix)
	{
		for (auto& num : vec)
		{
			num = 0;
		}
	}
}
void Matrix::build()
{
	int i = 0, j = 0, number = 0;
	while (number < size * size)
	{
		matrix[i][j] = ++number;
		if (needChangeDirection(i, j))
		{
			currDirection = nextDirection();
			//std::cout << *this<<"\n\n";
		}
		i = convertDirection[currDirection].first + i;
		j = convertDirection[currDirection].second + j;
	}
}
std::ostream& operator<<(std::ostream& out, const Matrix& mtrx)
{
	for (auto& vec : mtrx.matrix)
	{
		for (auto& num : vec)
		{
			out << num << '\t';
		}
		out << '\n';
	}
	return out;
}
Matrix::Direction Matrix::nextDirection() const
{
	switch (currDirection)
	{
	case Matrix::Direction::Top:
		return (rotation == Rotation::ClockWise) ? (Matrix::Direction::Right) : (Matrix::Direction::Left);
	case Matrix::Direction::Right:
		return (rotation == Rotation::ClockWise) ? (Matrix::Direction::Bottom) : (Matrix::Direction::Top);
	case Matrix::Direction::Bottom:
		return (rotation == Rotation::ClockWise) ? (Matrix::Direction::Left) : (Matrix::Direction::Right);
	case Matrix::Direction::Left:
		return (rotation == Rotation::ClockWise) ? (Matrix::Direction::Top) : (Matrix::Direction::Bottom);
	default:
		return Matrix::Direction::Top;
	}
}
bool Matrix::needChangeDirection(int i, int j)
{
	int nexti = convertDirection[currDirection].first + i;
	int nextj = convertDirection[currDirection].second + j;

	if (((nexti >= 0) && (nexti < size)) && ((nextj >= 0) && (nextj < size)))
	{
		if (matrix[nexti][nextj] != 0)
		{
			return true;
		}
		return false;
	}
	return true;
}
void  Matrix::setRotation(Matrix::Rotation rotation)
{
	this->rotation = rotation;
	if (rotation == Rotation::ClockWise)
	{
		currDirection = Direction::Right;
	}
	else
	{
		currDirection = Direction::Bottom;
	}
}