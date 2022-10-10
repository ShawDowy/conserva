#include <iostream>
#include <cmath>

using namespace std;

int strlen_(char* bin)
{
	int counter = 0;
	int i = 0;
	while (bin[i])
	{
		i++;
	}
	return i;
}

int find_symbol_index(char* bin)
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
	if (find_symbol_index(bin) > 0)
	{
		int len2 = find_symbol_index(bin) + (4 - (find_symbol_index(bin) % 4));
		char* bin_2 = new char[len2];

		for (int i = 0; i < 4 - (find_symbol_index(bin) % 4); ++i)
		{
			bin_2[i] = '0';
		}

		for (int i = 0; i < find_symbol_index(bin); ++i)
		{
			bin_2[i + (4 - (find_symbol_index(bin) % 4))] = bin[i];
		}

		int z = 0;
		int dec_2 = 0;

		while (z < len2)
		{
			dec_2 += ((int)bin_2[z] - 48) * pow(2, len2 - (1 + z));
			++z;
		}
		return dec_2;
	}
	else
	{
		char* bin_2 = new char[len];

		for (int i = 0; i < len; ++i)
		{
			bin_2[i] = bin[i];
		}

		int z = 0;
		int dec_2 = 0;
		while (z < len)
		{
			dec_2 += ((int)bin_2[z] - 48) * pow(2, len - (1 + z));
			++z;
		}
		return dec_2;
	}
}


int main()
{
	char bin2[150];
	cin >> bin2;


	int arrlen = strlen_(bin2);

	cout << hex << bin_to_hex(bin2, arrlen);

	if (find_symbol_index(bin2) > 0)
	{
		cout << '.';

		int len2 = (arrlen - (find_symbol_index(bin2) + 1)) + (4 - ((arrlen - (find_symbol_index(bin2) + 1)) % 4));
		char* bin_3 = new char[len2];

		for (int i = 0; i < (arrlen - (find_symbol_index(bin2) + 1)); ++i)
		{
			bin_3[i] = bin2[i + (find_symbol_index(bin2)) + 1];
		}

		for (int i = 0; i < (4 - ((arrlen - (find_symbol_index(bin2) + 1)) % 4)); ++i)
		{
			bin_3[i + (arrlen - (find_symbol_index(bin2) + 1))] = '0';
		}

		int z = 0;
		int dec_3 = 0;
		int f_ = 4;

		while (z < len2)
		{
			int f = z + 1;
			dec_3 += ((int)bin_3[z] - 48) * pow(2, f_ - f);
			if (f % 4 == 0)
			{
				cout << hex << dec_3;
				dec_3 = 0;
				f_ += 4;
			}
			++z;
		}
	}
	return 0;
}
