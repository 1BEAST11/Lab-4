#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int people;

	// ввод количества сотрудников
	while (true)
	{
		cout << "Введите количество сотрудников (от 1 до 1000): ";
		cin >> people;

		// обработка ввода неверного типа данных
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << "Неверный тип данных.\n" << "Повторите попытку." << endl;
			cout << endl;
		}

		// обработка ввода числа, выходящего за пределы диапазона
		else if (people < 1 || people > 1000)
		{
			cout << endl;
			cout << "Введено число, которое не входит в заданный диапазон.\n" << "Повторите попытку." << endl;
			cout << endl;
		}

		else
		{
			cout << endl;
			break;
		}
	}

	int* distance = new int[people];
	int* money = new int[people];
	int* number_taxi = new int[people];
	int* number_emp = new int[people];

	// ввод расстояний
	for (int i = 0; i < people; i++)
	{
		while (true)
		{
			cout << "Введите расстояние " << i + 1 << "-го сотрудника (целое число от 1 до 1000): ";
			cin >> distance[i];

			// обработка ввода неверного типа данных
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << endl;
				cout << "Неверный тип данных.\n" << "Повторите попытку." << endl;
				cout << endl;
			}

			// обработка ввода числа, выходящего за пределы диапазона
			else if (distance[i] < 1 || distance[i] > 1000)
			{
				cout << endl;
				cout << "Введено число, которое не входит в заданный диапазон.\n" << "Повторите попытку." << endl;
				cout << endl;
			}

			else
			{
				break;
			}
		}
		number_emp[i] = i + 1;
	}
		cout << endl;

	// ввод тарифов
	for (int i = 0; i < people; i++)
	{
		while (true)
		{
			cout << "Введите тариф в такси #" << i + 1 << " (руб/км) (целое число от 1 до 10000): ";
			cin >> money[i];

			// обработка ввода неверного типа данных
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << endl;
				cout << "Неверный тип данных.\n" << "Повторите попытку." << endl;
				cout << endl;
			}

			// обработка ввода числа, выходящего за пределы диапазона
			else if (money[i] < 1 || money[i] > 10000)
			{
				cout << endl;
				cout << "Введено число, которое не входит в заданный диапазон.\n" << "Повторите попытку." << endl;
				cout << endl;
			}

			else
			{
				break;
			}
		}

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
