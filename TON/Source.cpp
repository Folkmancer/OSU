//проверяет, является ли число удвоенным нечётным
//twice odd number
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	unsigned int number;
	bool t;
	cout << "Enter number" << endl;
	cin >> number;
	t = ((number % 2) == 0) && ((number % 4) != 0);
	cout << t << endl;
	system("pause");
	return 0;
}