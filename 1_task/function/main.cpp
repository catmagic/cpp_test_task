#include<iostream>
#include<vector>
std::vector<std::vector<int>>	find_z(int*** mtrx, int l, int m, int n, int z) 
{
	std::vector<std::vector<int>> result;
	for (int i = 0; i < l; ++i) 
	{
		for (int j = 0; j < m; ++j) 
		{
			for(int k = 0; k < n; ++k)
			{
				if (mtrx[i][j][k] == z) 
				{
					result.push_back({ i, j, k });
				}
			}
		}
	}
	return result;
}
int main()
{
	int*** mtrx;
	int l = 5;
	int m = 4;
	int n = 3;
	mtrx = (int***)malloc(l * sizeof(int**));
	if (mtrx) {
		for (int i = 0; i < l; ++i)
		{
			mtrx[i] = (int**)malloc(m * sizeof(int*));
			if (mtrx[i]) {
				for (int j = 0; j < m; ++j)
				{
					mtrx[i][j] = (int*)malloc(n * sizeof(int));
					if (mtrx[i][j]) {
						for (int k = 0; k < n; ++k)
						{
							mtrx[i][j][k] = (i + j * j + k * k * k) % 10;
						}
					}
				}
			}
		}
	}
	std::vector<std::vector<int>> result = find_z(mtrx, l, m, n, 0);
	for (auto vec : result) 
	{
		std::cout << "[" << vec[0] << ", " << vec[1] << ", " << vec[2] << "]\n";
	}
	
	
	if (mtrx) 
	{
		for (int i = 0; i < l; ++i)
		{
			if (mtrx[i]) {
				for (int j = 0; j < m; ++j)
				{
					free(mtrx[i][j]);
				}
				free(mtrx[i]);
			}
		}
	}
	free(mtrx);
	return 0;
}