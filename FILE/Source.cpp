//Даны символьные файлы f и g. Записать в файл h все начальные совпадающие компоненты файлов f и g.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	ifstream fout1("C:\\Users\\Vault Hunter\\Desktop\\f.txt");
	ifstream fout2("C:\\Users\\Vault Hunter\\Desktop\\g.txt");
	ofstream fin("C:\\Users\\Vault Hunter\\Desktop\\h.txt");
	string str1;
	string str2;
	string temp;
	if (!fout1.is_open()) cout << "Файл f не может быть открыт!\n";
	else if (!fout2.is_open()) cout << "Файл g не может быть открыт!\n";
	else 
	{
		while (!fout1.eof())
		{
			getline(fout1, temp);
			str1 += temp;
		}
		cout << "Содержание файла f: " << str1 << endl;
		fout1.close();
		while (!fout2.eof())
		{
			getline(fout2, temp);
			str2 += temp;
		}
	
	int k = 0;
	while (str1[k] == str2[k])
	{
		fin << str1[k]; // запись строки в файл
		k++;
	}
	fin.close(); // закрываем файл
	cout << "Содержание файла g: " << str2 << endl;
	}
	system("pause");
	return 0;
}