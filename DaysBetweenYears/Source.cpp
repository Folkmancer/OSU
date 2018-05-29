//Даны тройки чисел A1, B1, C1  и A2, B2, C2, которые обозначают две даты.
//Вычислить количество дней, прошедших между этими датами.
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	unsigned int DaysOne, MonthOne, YearsOne, 
				 DaysTwo, MonthTwo, YearsTwo, 
				 CountDaysInDate = 0, i, temp1, temp2,
				 CountDaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, 
		         CountDaysInMonthVis[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	cout << "Введите начальную дату" << endl;
	cout << "День: ";
	cin >> DaysOne;
	cout << "Месяц: ";
	cin >> MonthOne;
	cout << "Год: ";
	cin >> YearsOne;

	if ((YearsOne % 4 == 0) && (YearsOne % 100 != 0) || (YearsOne % 400 == 0)) temp1 = 1;
	else temp1 = 0;
	if (temp1 == 1 && DaysOne > CountDaysInMonthVis[MonthOne - 1])
	{
		cout << "Начальная дата введена неверно!" << endl;
	}
	else if (temp1 == 0 && DaysOne > CountDaysInMonth[MonthOne - 1])
	{
		cout << "Начальная дата введена неверно!" << endl;
	}
	else
	{
		cout << "Введите конечную дату" << endl;
		cout << "День: ";
		cin >> DaysTwo;
		cout << "Месяц: ";
		cin >> MonthTwo;
		cout << "Год: ";
		cin >> YearsTwo;

		if ((YearsTwo % 4 == 0) && (YearsTwo % 100 != 0) || (YearsTwo % 400 == 0)) temp2 = 1;
		else temp2 = 0;
		if (temp2 == 1 && DaysTwo > CountDaysInMonthVis[MonthTwo - 1])
		{
			cout << "Конечная дата введена неверно!" << endl;
		}
		else if (temp2 == 0 && DaysTwo > CountDaysInMonth[MonthTwo - 1])
		{
			cout << "Конечная дата введена неверно!" << endl;
		}
		else 
		{
			if (YearsTwo <= YearsOne && MonthTwo <= MonthOne && DaysTwo < DaysOne)
			{
				cout << "Конечная дата старше начальной даты!" << endl;
			}
			else if (YearsTwo <= YearsOne && MonthTwo < MonthOne) 
			{
				cout << "Конечная дата старше начальной даты!" << endl;
			}
			else if (YearsTwo < YearsOne)
			{
				cout << "Конечная дата старше начальной даты!" << endl;
			}
			else 
			{
				cout << "Начальная дата:" << endl << DaysOne << '/' << MonthOne << '/' << YearsOne << endl;
				cout << "Конечная дата:" << endl << DaysTwo << '/' << MonthTwo << '/' << YearsTwo << endl;
				for (i = YearsOne; i < YearsTwo; i++) 
				{
					if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
					{
						CountDaysInDate += 366;
					}
					else
					{
						CountDaysInDate += 365;
					}
				}

				if ((YearsOne % 4 == 0) && (YearsOne % 100 != 0) || (YearsOne % 400 == 0)) 
				{
					for (i = 0; i < (MonthOne - 1); i++) CountDaysInDate -= CountDaysInMonthVis[i];
				}
				else
				{
					for (i = 0; i < (MonthOne - 1); i++) CountDaysInDate -= CountDaysInMonth[i];
				}

				if ((YearsTwo % 4 == 0) && (YearsTwo % 100 != 0) || (YearsTwo % 400 == 0))
				{
					for (i = 0; i < (MonthTwo - 1); i++) CountDaysInDate += CountDaysInMonthVis[i];
				}
				else
				{
					for (i = 0; i < (MonthTwo - 1); i++) CountDaysInDate += CountDaysInMonth[i];
				}
				CountDaysInDate -= DaysOne;
				CountDaysInDate += DaysTwo;
				cout << "Дней между датами: " << CountDaysInDate << endl;
			}
		}
	}
	system("pause");
	return 0;
}