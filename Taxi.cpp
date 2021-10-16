#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int people;
	cout << "Введите количество сотрудников: ";
	cin >> people;
	cout << endl;

	int* distance = new int[people];
	int* money = new int[people];
	int* number_taxi = new int[people];
	int* number_emp = new int[people];

	 //
	for (int i = 0; i < people; i++)
	{
		cout << "Введите расстояние " << i + 1 << "-го сотрудника: ";
		cin >> distance[i];
		number_emp[i] = i + 1;
	}
	cout << endl;

	for (int i = 0; i < people; i++)
	{
		cout << "Введите тариф в такси #" << i + 1 << " (руб/км): ";
		cin >> money[i];
		number_taxi[i] = i + 1;
	}
	cout << endl;

	// сортировка
	for (int i = 0; i < people; i++)
	{

		for (int j = 0; j < people - i - 1; j++)
		{
			// сортировка расстояний сотрудников по возрастанию
			if (distance[j] > distance[j + 1])
			{
				swap(distance[j], distance[j + 1]);
				swap(number_emp[j], number_emp[j + 1]);
			}

			// сортировка цен за такси по убыванию
			if (money[j] < money[j + 1])
			{
				swap(money[j], money[j + 1]);
				swap(number_taxi[j], number_taxi[j + 1]);
			}
		}
	}

	// сортировка номеров сотрудников и номеров соответствующих такси
	for (int i = 0; i < people; i++)
	{
		for (int j = 0; j < people - i - 1; j++)
		{
			if (number_emp[j] > number_emp[j + 1])
			{
				swap(number_emp[j], number_emp[j + 1]);
				swap(number_taxi[j], number_taxi[j + 1]);
			}
		}
	}
	
	// вывод
	for (int i = 0; i < people; i++)
	{
		cout << number_emp[i] << "-й сотрудник => " << "такси #" << number_taxi[i] << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
