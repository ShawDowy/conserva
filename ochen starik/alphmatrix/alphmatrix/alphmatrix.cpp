//Разработать программу, которая сортирует все строки массива по алфавиту.//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_N 5
#define MAX_M 20

using namespace std;

void matrix_sort(char** x)
{
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_M; j++)
		{
			for (int k = MAX_M - 1; k > j; k--)
				if (int(x[i][k]) < int(x[i][k - 1]))
				{
					char tmp = x[i][k] ;
					x[i][k] = x[i][k - 1];
					x[i][k - 1] = tmp;
				}
		}
	}
	return;
}


void matrix_output(char** x)
{
	cout << "Matrix: " << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_M; j++)
			cout << x[i][j];
		cout << endl;
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

	matrix_output(matrix);

	cout << endl;

	matrix_sort(matrix);
	matrix_output(matrix);


	for (int i = 0; i < MAX_N; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}
