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
	cout <<"List" << setw(15) << "Date" << setw(15) << "Car brand" << setw(15) << "Year" << setw(15) << "Colour" << setw(15) << "Number" << "\n\n";
	for (int i = 0; i < N; i++)
	{
		cout << i+1
			<< setw(15)
			<< M[i].date
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
	return;
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
	return;
}

void find_structure(vehicle* M, int N)
{
	cout << "\n";

	char date[12];
	cout << "Date of vehicle: ";
	cin >> date;

	char car_brand[30];
	cout << "Car brand of vehicle: ";
	cin >> car_brand;

	char number[12];
	cout << "Number of vehicle: ";
	cin >> number;

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if ((strcmp(M[i].date, date) == 0) and (strcmp(M[i].car_brand, car_brand) == 0) and (strcmp(M[i].number, number) == 0))
		{
			cout << i+1
				<< setw(15)
				<< M[i].date
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
	cout << "There is no such structure";
	cout << endl;
	return;
	
}

void swap_structure(vehicle* M, int N, int X)
{
		for (int i = X-1; i < N; ++i)
		{
			vehicle &tmp = M[i];
			M[i] = M[i+1];
			M[i+1] = tmp;
		}
		return;
}


int main()
{
	int Number_of_vehicles;
	cout << "Write N: ";
	cin >> Number_of_vehicles;

	vehicle* Massive_of_vehicles = new vehicle[Number_of_vehicles];
	GetData(Massive_of_vehicles, Number_of_vehicles);

	system("cls");
	ShowData(Massive_of_vehicles, Number_of_vehicles);

	find_structure(Massive_of_vehicles, Number_of_vehicles);

	int list_to_del;
	cout << endl;
	cout << "Choose list that you want to delete :";
	cin >> list_to_del;
	cout << endl;
	if (Number_of_vehicles >= list_to_del)
	{
		swap_structure(Massive_of_vehicles, Number_of_vehicles, list_to_del);
		ShowData(Massive_of_vehicles, Number_of_vehicles - 1);
	}
	else
	{
		cout << "There is no such list" << endl;
	}

	delete[]Massive_of_vehicles;
	return 0;
}
