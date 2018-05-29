#include <iostream>
#include <string> 
#include <fstream>
#include <cstdbool>
#include <iterator>
#include <vector>
#include <algorithm>
#include <new>
using namespace std;
int countElement;


struct medicine
{
	int code;
	string name;
	string rel_Date;
	int	per_Storage;
	string form;
	int	lot_size;
};

medicine* AddElement(medicine *, int &);
void DelElement(medicine *, int &);
void OutElement(medicine *, int &);
void SearchElement(medicine *, int &);


int main() {
	setlocale(0, "");
	countElement = 0;
	int k = 0, z = 0;
	string s;
	medicine *asb;
	ifstream file("C:\\Users\\Vault Hunter\\Desktop\\Medicine.txt");

	while (!file.eof())
	{
		std::getline(file, s);
		countElement++;
	}
	countElement /= 6;
	file.seekg(0, std::ios::beg);
	asb = new medicine[countElement];
	while (getline(file, s))
	{
		if (k == 0)
		{
			asb[z].code = atoi(s.c_str());
			k++;
		}
		else if (k == 1)
		{
			asb[z].name = s;
			k++;
		}
		else if (k == 2)
		{
			asb[z].rel_Date = s;
			k++;
		}
		else if (k == 3)
		{
			asb[z].per_Storage = atoi(s.c_str());
			k++;
		}
		else if (k == 4)
		{
			asb[z].form = s;
			k++;
		}
		else if (k == 5)
		{
			asb[z].lot_size = atoi(s.c_str());
			k = 0;
			z++;
		}
	}
	asb = AddElement(asb, countElement);
	//asb = AddElement(asb, countElement);
	//asb = AddElement(asb, countElement);
	SearchElement(asb, countElement);
	DelElement(asb, countElement);
	OutElement(asb, countElement);
	//system("cls");
	file.close();
	system("pause");
	return 0;
}

medicine* AddElement(medicine *Array, int &countElement)
{
	countElement++;
	system("pause");
	medicine *NewArray = new medicine[countElement];
	cout << Array[countElement - 2].code << endl;
	//memcpy(NewArray, NewArray, sizeof(medicine) * (countElement - 1));
	for (int i = 0; i < (countElement - 1); i++)
	{
		NewArray[i] = Array[i];
	}
	delete[] Array;
	int elem = countElement - 1;
	cout << countElement << endl;
	cout << elem << endl;
	cout << "¬ведите код" << endl;
	cin >> NewArray[elem].code;
	cout << "¬ведите название" << endl;
	cin >> NewArray[elem].name;
	cout << "¬ведите дату выпуска" << endl;
	cin >> NewArray[elem].rel_Date;
	cout << "¬ведите срок хранени€" << endl;
	cin >> NewArray[elem].per_Storage;
	cout << "¬ведите форму" << endl;
	cin >> NewArray[elem].form;
	cout << "¬ведите размер партии" << endl;
	cin >> NewArray[elem].lot_size;
	int number_element = countElement;
	for (int i = 0; i < number_element; i++)
	{
		cout << NewArray[i].code << endl;
		cout << NewArray[i].name << endl;
		cout << NewArray[i].rel_Date << endl;
		cout << NewArray[i].per_Storage << endl;
		cout << NewArray[i].form << endl;
		cout << NewArray[i].lot_size << endl;
	}
	return NewArray;
}

void SearchElement(medicine *Array, int &countElement)
{
	int num;
	cout << "¬ведите код элемента" << endl;
	cin >> num;
	for (int i = 0; i < countElement; i++)
	{
		if (Array[i].code == num)
		{
			cout << Array[i].code << endl;
			cout << Array[i].name << endl;
			cout << Array[i].rel_Date << endl;
			cout << Array[i].per_Storage << endl;
			cout << Array[i].form << endl;
			cout << Array[i].lot_size << endl;
		}
	}
}

void DelElement(medicine *Array, int &countElement)
{
	int num;
	int number_element = countElement;
	cout << "¬ведите код удал€емого элемента" << endl;
	cin >> num;
	for (int i = 0; i < number_element; i++)
	{
		if (Array[i].code == num)
		{
			for (int j = i; j < number_element - 1; ++j)
			{
				Array[j] = Array[j + 1];
			}
			--number_element;
		}
	}
	countElement--;
}

void OutElement(medicine *Array, int &countElement)
{
	int number_element = countElement;
	for (int i = 0; i < number_element; i++)
	{
		cout << Array[i].code << endl;
		cout << Array[i].name << endl;
		cout << Array[i].rel_Date << endl;
		cout << Array[i].per_Storage << endl;
		cout << Array[i].form << endl;
		cout << Array[i].lot_size << endl;
	}
}