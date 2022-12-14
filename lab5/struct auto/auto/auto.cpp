#include <iostream>
#include <iomanip>

using namespace std;

struct vehicle
{
	char date[12];
	char car_brand[30];
	char year[6];
	char colour[30];
	char number[12];
};

void ShowData(vehicle* M, int N)
{
	cout << "Date" << setw(15) << "Car brand" << setw(15) << "Year" << setw(15) << "Colour" << setw(15) << "Number" << "\n\n";
	for (int i = 0; i < N; i++)
	{
		cout << M[i].date
			<< setw(15)
			<< M[i].car_brand
			<< setw(15)
			<< M[i].year
			<< setw(15)
			<< M[i].colour
			<< setw(15)
			<< M[i].number;
		cout << endl;
	}
	cout << "\n";
}

void GetData(vehicle* M, int N)
{

	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		cout << "Date: ";
		cin >> M[i].date;

		cout << "Car brand: ";
		cin >> M[i].car_brand;

		cout << "Year: "; 
		cin >> M[i].year;

		cout << "Colour: ";
		cin >> M[i].colour;

		cout << "Number: ";
		cin >> M[i].number;
	}
}

void find_structure(vehicle* M, int N)
{
	cout << "\n";

	char date[12];
	cout << "Date: ";
	cin >> date;

	char car_brand[30];
	cout << "Car brand: ";
	cin >> car_brand;

	char number[12];
	cout << "Number: ";
	cin >> number;

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if ((strcmp(M[i].date, date) == 0) and (strcmp(M[i].car_brand, car_brand) == 0) and (strcmp(M[i].number, number) == 0))
		{
			cout << M[i].date
				<< setw(15)
				<< M[i].car_brand
				<< setw(15)
				<< M[i].year
				<< setw(15)
				<< M[i].colour
				<< setw(15)
				<< M[i].number;
			cout << endl;
			return;
		}
	}
	cout << "There is no such";
	return;
	
}

void del_structure(vehicle* M, int N, int X)
{
	if (N > X)
	{
		for (int i = X-1; i < N; ++i)
		{
			vehicle &tmp = M[i];
			M[i] = M[i+1];
			M[i+1] = tmp;
		}
	}
}


int main()
{
	system("cls");
	int N; cout << "Write N: "; cin >> N;
	vehicle* M = new vehicle[N]; 
	GetData(M, N); 
	system("cls");
	ShowData(M, N);
	int x;
	cout << endl;
	cout << "Choose to del: ";
	cin >> x;
	cout << endl;
	del_structure(M, N, x);
	ShowData(M, N - 1);
	delete[]M;
	system("pause");
	return 0;
}
