#include <iostream>
#include <conio.h>
using namespace std;

bool function(bool p, bool q, bool r, bool s)
{
	bool result = (q && p && r && !s) || (!q && !p) || (!q && !r) || (!q && s);
	return result;
}

void main()
{
	locale::global(locale("rus"));
	bool realizability = false;
	bool generalMeaning = true;
	int �odel = 0;
	cout << "���������� �������: !q <-> (p -> !r || s)" << "\n\n";
	cout << "| p | q | r | s | rezult |" << "\n";
	cout << "|---|---|---|---|--------|" << "\n";
	for (int x = 0;x <= 1;x++)
		for (int y = 0;y <= 1;y++)
			for (int z = 0;z <= 1;z++)
				for (int f = 0;f <= 1;f++)
				{
					cout << "| " << x << " | " << y << " | " << z << " | " << f << " |    " << function((bool)x, (bool)y, (bool)z, (bool)f) << "   |" << endl;
					if (function((bool)x, (bool)y, (bool)z, (bool)f == 1))
					{
						realizability = true;
						�odel++;
					}
					else generalMeaning = false;
				}
	if (generalMeaning)
		cout << "\n���������� ������� �������� ������������" << "\n";
	else
		cout << "\n���������� ������� �� �������� ������������" << "\n";
	cout << "���������� �������";
	if (realizability)
		cout << " ���������" << "\n";
	else
		cout << " �����������" << "\n";
	cout << "����� �������: " << �odel << "\n";
	_getch();
}
