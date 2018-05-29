//Даны действительные числа x, ε(x≠0, ε >0).
//Вычислить с - 3, -4, -5, -6, точностью ε(ε = 10, 10, 10, 10) сумма ряда и указать количество учтенных слагаемых.


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(0,"");
	double x, e, s;
	int j[4] = {-3, -4, -5, -6}, k, m;
	cout << "Введите X: ";
	cin >> x;
	try
	{
		if (x == 0) throw 1;
		cout << "____________________________" << endl;
		cout << setw(4) << "E" << setw(4) << "|" << setw(9) << "Сумма"  << setw(5) << "|" << setw(3) << "N" << setw(3) << "|" << endl;
		cout << "-------|-------------|-----|" << endl;
		for (int i = 0; i < 4; i++)
		{
			k = 1;
			s = 0;
			e = pow(10, j[i]);
			do
			{
				s = x / (pow(k, 3) + k) * sqrt(abs(x) + 1);
				k++;
				//if (k == 10) break;
			} 
			while (s > e);
			cout << setw(4) << "10^" << j[i] << setw(2) << "|" << setw(12) << s << setw(2) << "|" << setw(4) << k << setw(2) << "|" << endl;
		}
		cout << "_______|_____________|_____|" << endl;
	}
	catch(int)
	{
		cout << "X должен быть отличен от нуля!" << endl;
	}
	system("pause");
	return 0;
}