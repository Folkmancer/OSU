#include <iostream>
#include <string>
#include <set>
#include <iterator>
using namespace std;

struct kolhoz {
	string name;
	set<string> CropsInKolhoz;
};

int main()
{
	setlocale(0, "");
	string crops[5] = { "рожь", "пшеница", "овёс", "гречка", "картофель" };
	set<string> AllFarm, NotAllFarm;
	int n;
	cout << "Введите количество колхозов: ";
	cin >> n;
	kolhoz *cFarm = new kolhoz[n];
	for (int i = 0; i < n; i++) {
		cFarm[i].name = "Колхоз " + to_string(i + 1);
		cout << cFarm[i].name << endl;
		int k = (rand() % 5 + 1);
		for (int j = 0; j < k; j++)
		{
			cFarm[i].CropsInKolhoz.insert(crops[j]);
		}
		copy(cFarm[i].CropsInKolhoz.begin(), cFarm[i].CropsInKolhoz.end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}
	for (int f = 0; f < 5; f++)
	{
		int numbFarm = 0;
		for (int z = 0; z < n; z++) {
			if (cFarm[z].CropsInKolhoz.find(crops[f]) != cFarm[z].CropsInKolhoz.end())
			{
				numbFarm += 1;
			}
		}
		numbFarm == n ? AllFarm.insert(crops[f]) : NotAllFarm.insert(crops[f]);
	}
	cout << endl;
	cout << "Возделывается во всех колхозах:" << endl;
	copy(AllFarm.begin(), AllFarm.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	cout << "Возделывается не во всех колхозах:" << endl;
	copy(NotAllFarm.begin(), NotAllFarm.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	system("pause");
	delete[] cFarm;
	return 0;
}