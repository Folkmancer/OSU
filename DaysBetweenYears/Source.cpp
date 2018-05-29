//���� ������ ����� A1, B1, C1  � A2, B2, C2, ������� ���������� ��� ����.
//��������� ���������� ����, ��������� ����� ����� ������.
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
	cout << "������� ��������� ����" << endl;
	cout << "����: ";
	cin >> DaysOne;
	cout << "�����: ";
	cin >> MonthOne;
	cout << "���: ";
	cin >> YearsOne;

	if ((YearsOne % 4 == 0) && (YearsOne % 100 != 0) || (YearsOne % 400 == 0)) temp1 = 1;
	else temp1 = 0;
	if (temp1 == 1 && DaysOne > CountDaysInMonthVis[MonthOne - 1])
	{
		cout << "��������� ���� ������� �������!" << endl;
	}
	else if (temp1 == 0 && DaysOne > CountDaysInMonth[MonthOne - 1])
	{
		cout << "��������� ���� ������� �������!" << endl;
	}
	else
	{
		cout << "������� �������� ����" << endl;
		cout << "����: ";
		cin >> DaysTwo;
		cout << "�����: ";
		cin >> MonthTwo;
		cout << "���: ";
		cin >> YearsTwo;

		if ((YearsTwo % 4 == 0) && (YearsTwo % 100 != 0) || (YearsTwo % 400 == 0)) temp2 = 1;
		else temp2 = 0;
		if (temp2 == 1 && DaysTwo > CountDaysInMonthVis[MonthTwo - 1])
		{
			cout << "�������� ���� ������� �������!" << endl;
		}
		else if (temp2 == 0 && DaysTwo > CountDaysInMonth[MonthTwo - 1])
		{
			cout << "�������� ���� ������� �������!" << endl;
		}
		else 
		{
			if (YearsTwo <= YearsOne && MonthTwo <= MonthOne && DaysTwo < DaysOne)
			{
				cout << "�������� ���� ������ ��������� ����!" << endl;
			}
			else if (YearsTwo <= YearsOne && MonthTwo < MonthOne) 
			{
				cout << "�������� ���� ������ ��������� ����!" << endl;
			}
			else if (YearsTwo < YearsOne)
			{
				cout << "�������� ���� ������ ��������� ����!" << endl;
			}
			else 
			{
				cout << "��������� ����:" << endl << DaysOne << '/' << MonthOne << '/' << YearsOne << endl;
				cout << "�������� ����:" << endl << DaysTwo << '/' << MonthTwo << '/' << YearsTwo << endl;
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
				cout << "���� ����� ������: " << CountDaysInDate << endl;
			}
		}
	}
	system("pause");
	return 0;
}