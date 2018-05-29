//Даны натуральное число n, символы s1..sn.Удалить из данной последовательности все группы букв вида "abcd".
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	string strOne, strTwo = "abcd";
	cout << "Введите строку" << endl;
	getline(cin, strOne);
	while (strOne.find(strTwo) != string::npos)
	{
		strOne.erase(strOne.find(strTwo), 4);
	}
	if (strOne[0] == ' ') strOne.erase(0, 1);
	cout << strOne << endl;
	system("pause");
	return 0;
}