#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_N 5
#define MAX_M 5

void matrix_output(int **x, int const n, int const m)
{
	std::cout << "Matrix: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << x[i][j] << '\t';
		std::cout << std::endl;
	}
	return;
}

void cut_matrix(int(&a)[MAX_N][MAX_M], int del_row, int del_column)
{
	int** new_matrix = new int*[MAX_N - 1];

	for (int i = 0; i < MAX_N-1; ++i)
	{
		new_matrix[i] = new int[MAX_M - 1];
		for (int j = 0; j < MAX_M-1; ++j)
		{
			if (i < del_row - 1)
				if (j < del_column - 1) new_matrix[i][j] = a[i][j];
				else      new_matrix[i][j] = a[i][j + 1];
			else
				if (j < del_column - 1) new_matrix[i][j] = a[i + 1][j];
				else      new_matrix[i][j] = a[i + 1][j + 1];
		}
	}

	matrix_output(new_matrix, MAX_N-1, MAX_M-1);

	for (int i = 0; i < MAX_N-1; i++)
		delete[] new_matrix[i];
	delete[] new_matrix;

	return;
}

int main()
{
	int const min_random = -15;
	int const max_random = 30;
	srand(time(NULL));

	int matrix[MAX_N][MAX_M];

	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_M; ++j)
			matrix[i][j] = min_random + (rand() % (max_random - min_random + 1));
	}

	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_M; ++j)
		{
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	int del_row, del_column;
	std::cout << "Write the row number: ";
	std::cin >> del_row;
	std::cout << std::endl;
	std::cout << "Write the column number: ";
	std::cin >> del_column;
	std::cout << std::endl;

	if (del_row > MAX_N || del_column > MAX_M)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	else
	{
		cut_matrix(matrix, del_row, del_column);
	}

	return 0;
}