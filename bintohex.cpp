#include <iostream>
#include <cmath>


using namespace std;


int strlen_(char* bin)
{
	int i = 0;
	while (bin[i])
	{
		i++;
	}
	return i;
}


int find_dot_index(char* bin)
{
	int index = 0;
	for (int i = 0; i < strlen_(bin); ++i)
	{
		if (bin[i] == '.')
		{
			index = i;
			return index;
		}
	}
	return index;
}



int bin_to_hex(char* bin, int& len)
{
	if (find_dot_index(bin) > 0)
	{
		int arrlen_integer = find_dot_index(bin);
		char* bin_integer = new char[arrlen_integer+1];


		for (int i = 0; i < arrlen_integer; ++i)
		{
			bin_integer[i] = bin[i];
		}


		int z = 0;
		int dec_integer = 0;


		while (z < arrlen_integer)
		{
			dec_integer += ((int)bin_integer[z] - 48) * pow(2, arrlen_integer - (1 + z));
			++z;
		}
		delete[] bin_integer;

		return dec_integer;
	}
	else
	{
		int z = 0;
		int dec_integer = 0;


		while (z < len)
		{
			dec_integer += ((int)bin[z] - 48) * pow(2, len - (1 + z));
			++z;
		}
		return dec_integer;
	}
}


int main()
{
	char bin[150];

	cin >> bin;


	int arrlen = strlen_(bin);


	cout << hex << bin_to_hex(bin, arrlen);


	if (find_dot_index(bin) > 0)
	{
		cout << '.';


		int arrlen_float = (arrlen - (find_dot_index(bin) + 1)) + (4 - ((arrlen - (find_dot_index(bin) + 1)) % 4) );
		char* bin_float = new char[arrlen_float+1];


		for (int i = 0; i < (arrlen - (find_dot_index(bin) + 1)); ++i)
		{
			bin_float[i] = bin[i + (find_dot_index(bin)) + 1];
		}

		for (int i = 0; i < (4 - ((arrlen - (find_dot_index(bin) + 1)) % 4)); ++i)
		{
			bin_float[i + (arrlen - (find_dot_index(bin) + 1))] = '0';
		}


		int z = 0;
		int dec_3 = 0;
		int f_ = 4;


		while (z < arrlen_float)
		{
			int f = z + 1;
			dec_3 += ((int)bin_float[z] - 48) * pow(2, f_ - f);
			if (f % 4 == 0)
			{
				cout << hex << dec_3;
				f_ += 4;
				dec_3 = 0;
			}
			++z;
		}
		delete[] bin_float;

		return 0;
	}
	return 0;
}