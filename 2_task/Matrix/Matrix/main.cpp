#include"matrix.h"
#include<iostream>
#include<vector>
#include <stdlib.h> 
#include <time.h>
int main()
{
	srand(time(NULL));
	int minSize = 3;
	int maxSize = 10;
	int Size = minSize + rand() % (1 + maxSize - minSize);
	Matrix mat(Size);
	Matrix::Rotation rotation = Matrix::Rotation ( rand() % 2);
	mat.setRotation(rotation);
	mat.build();
	std::cout << mat;
}