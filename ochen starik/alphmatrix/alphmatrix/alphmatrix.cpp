//Разработать программу, которая сортирует все строки массива по алфавиту.//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_N 1
#define MAX_M 100

using namespace std;

void matrix_sort(char** x, int const n, int const m, char** new_x)
{
	for (int i = 0; i < MAX_N; i++)
	{
		new_x[i] = new char[MAX_M];
		for (int j = 0; j < MAX_M; j++)
		{
			for (int k = MAX_M - 1; k > j; k--)
				if (int(x[i][k]) < int(x[i][k - 1]))
				{
					int tmp = x[i][k];
					x[i][k] = x[i][k - 1];
					x[i][k - 1] = tmp;
				}
			new_x[i][j] = x[i][j];
		}
	}
	return;
}


void matrix_output(char** x, int const n, int const m)
{
	std::cout << "Matrix: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << x[i][j];
		std::cout << std::endl;
	}
	return;
}


int main()
{
	int const min_random = 97;
	int const max_random = 122;
	srand(time(NULL));

	char** matrix = new char* [MAX_N];

	for (int i = 0; i < MAX_N; ++i)
	{
		matrix[i] = new char[MAX_M];
		for (int j = 0; j < MAX_M; ++j)
			matrix[i][j] = char(min_random + (rand() % (max_random - min_random + 1)));
	}

	matrix_output(matrix, MAX_N, MAX_M);

	cout << endl;

	char** new_matrix = new char* [MAX_N];

	matrix_sort(matrix, MAX_N, MAX_M, new_matrix);
	matrix_output(new_matrix, MAX_N, MAX_M);


	for (int i = 0; i < MAX_N; i++)
		delete[] new_matrix[i];
	delete[] new_matrix;

	for (int i = 0; i < MAX_N; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}