#include <iostream>
#include <string> 
#include <fstream> 

using namespace std; 

int main() {
	setlocale(0, "");
	string *name = new string[100];
	string *weight = new string[100];
	string *type = new string[100];
	int k = 0, z = 0;
	
	string s,p,q;
	ifstream file("C:\\Users\\Vault Hunter\\Desktop\\Item.txt");
	while (getline(file, s))
	{
		if (k == 0) 
		{
			name[z] = s;
			k++;
		}
		else if (k == 1) 
		{
			weight[z] = s;
			k++;
		}
		else if (k == 2) 
		{
			type[z] = s;
			k = 0;
			z++;
		}
	}
	cout << "Вывод по полупроводникам:" << endl;
	for (int x = 0; x <= z; x++)
	{
		if (type[x] == "полупроводник") 
		{
			cout << name[x] << endl;
			cout << weight[x] << endl;
			cout << type[x] << endl;
		}
	}
	string h, l, f;
	for (int x = 0; x < z; x++)
	{
		for (int j = x; j <= z; j++)
		{
			if (weight[x] < weight[j])
			{
				h = weight[x];
				weight[x] = weight[j];
				weight[j] = h;
				l = name[x];
				name[x] = name[j];
				name[j] = l;
				f = type[x];
				type[x] = type[j];
				type[j] = f;
			}
		}
	}
	cout << "\nВывод по проводникам:" << endl;
	for (int x = 0; x <= z; x++)
	{
		if (type[x] == "проводник")
		{
			cout << name[x] << endl;
			cout << weight[x] << endl;
			cout << type[x] << endl;
		}
	}
	file.close(); // обязательно закрываем файл что бы не повредить его
	system("pause");
	return 0;
}