#include <iostream>
#include <list>
#include <iterator> 
using namespace std;

int main()
{
	setlocale(0, "");
	int mas1[3] = { 2, 3, 7 };
	list<int> myList;
	for (int i = 0; i < 3; i++) 
	{
		myList.push_back(mas1[i]);
	}
	cout << "Список: ";
	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	system("pause");
	return 0;
}