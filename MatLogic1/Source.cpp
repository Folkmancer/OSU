#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void main()
{
	setlocale(LC_ALL, ".1251");
	system("cls");
	cout << "\np - —эмми и Ѕоб одного возраста" << "\ns - —элли старше Ѕоба" << "\nq - Ќенси и Ѕоб не одного возраста" << "\nr - Ѕоб старше ”олтера";
	cout << "\n1) p||s" << "\n2) !p||q" << "\n3) !s||r" << "\n4) !q \n5) !r" << "\n_________________________________________";
	const int m = 100, n = 4;
	int num = 6, i, j, flag, p = 5, st = 40, s, a1, a2, q, s1 = 0, s2, c = 0; //st - максимальное количество строк, p - изначальное количество посылок
	int table[m][n] =														  //num - номер, с которого начинаетс€ отсчет посылок
	{ { 1,1,0,0 },			//“аблица истинности дл€ начальных посылок			
	  { -1,0,1,0 },         //-1 - отрицание, 1 - обычный предикат, 0 - отсутствие предиката
	  { 0,-1,0,1 },
	  { 0,0,-1,0 },
	  { 0,0,0,-1 }
	};
	for (i = p;i<m;i++)
		for (j = 0;j<n;j++)
			table[i][j] = 0;
	gotoxy(st, 4);         //перемещение указател€ дл€ отображени€ таблицы в нужном месте, должно быть равно кол-ву литер
	cout << " p s q r"; //заголовок таблицы истинности
	for (i = 0;i<p;i++)
	{
		for (j = 0;j<n;j++)
		{
			gotoxy(st + 2 * j, 5 + i); //таблица строитс€ начина€ с X + i строчки
			if (table[i][j] >= 0)
				cout << " " << table[i][j];
			else
				cout << table[i][j];
		}
	}
	gotoxy(st, 5 + i);
	cout << "________\n";
	s = 5 + i;
	_getch();
	while (!s1)
	{
		for (q = 0;q<n;q++)
		{
			s2 = 0;
			if (q == 0 && c == 0)
			{
				for (i = 0;i<p;i++)
					if (table[i][q] == 1)
					{
						a1 = i;
						s2++;
						break;
					}
				for (i = a1 + 1;i<m;i++)
					if (table[i][q] == -1)
					{
						a2 = i;
						s2++;
						break;
					}
				c++;
			}
			else
			{
				for (i = p - 1;i >= 0;i--)
					if (table[i][q] == 1)
					{
						a1 = i;
						s2++;
						break;
					}
				for (i = a1 + 1;i >= 0;i--)
					if (table[i][q] == -1)
					{
						a2 = i;
						s2++;
						break;
					}
			}
			if (s2 == 2)
			{
				for (i = 0;i<n;i++)
				{
					if (i != q&&table[a1][i] != 0)
						table[p][i] = table[a1][i];
					if (i != q&&table[a2][i] != 0)
						table[p][i] = table[a2][i];
				}
				s++;
				for (i = 0;i<n;i++)
				{
					gotoxy(st + 2 * i, s);
					if (table[p][i] >= 0)
						cout << ' ' << table[p][i];
					else cout << table[p][i];
				}
				_getch();
				gotoxy(0, s);
				cout << num << ")";
				flag = 0;
				for (i = 0;i<n;i++)
					if (table[p][i] != 0)
					{
						switch (i)
						{
						case 0:
						{
							if (table[p][i]>0)
								if (flag == 0)
									cout << "p";
								else
									cout << "||p";
							else if (flag == 0)
								cout << "!p";
							cout << "||!p";
						}
						break;
						case 1:
						{
							if (table[p][i]>0)
								if (flag == 0)
									cout << "s";
								else
									cout << "||s";
							else if (flag == 0)
								cout << "!s";
							else
								cout << "||!s";
						}
						break;
						case 2:
						{
							if (table[p][i]>0)
								if (flag == 0)
									cout << "q";
								else
									cout << "||q";
							else if (flag == 0)
								cout << "!q";
							else
								cout << "||!q";
						}
						break;
						case 3:
						{
							if (table[p][i]>0)
								if (flag == 0)
									cout << "r";
								else
									cout << "||r";
							else if (flag == 0)
								cout << "!r";
							else
								cout << "||!r";
						}
						break;
						}
						if (flag == 0)
							flag++;
					}
				cout << " из " << a1 + 1 << " и " << a2 + 1 << " посылок";
				_getch();
				p++;
				num++;
			}
		}
		c = 0;
		for (i = 0;i<n;i++)
			if (!table[p - 1][i])
				c++;
		if (c == n)
			s1++;
	}
	cout << endl;
}
