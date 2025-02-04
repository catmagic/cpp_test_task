#include<vector>
#include<iostream>
#include<map>
#include<tuple>
#include <iostream>
#pragma once

class Matrix
{
public:
	enum class Rotation {
		ClockWise=0,
		CounterClockWise=1
	};
	
	Matrix(int n);
	void clear();
	void build();
	
	void setRotation(Rotation rotation);
	
private:
	enum class Direction
	{
		Top,Right,Bottom,Left
	};
	int size;
	std::vector<std::vector<int>> matrix;
	std::map<Direction, std::pair<int, int>>  convertDirection;
	Direction currDirection=Direction::Right;
	Rotation rotation = Rotation::ClockWise;
	Direction nextDirection()const;
	bool needChangeDirection(int i, int j);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	
};
