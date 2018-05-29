#include <set>
#include <iterator>
#include <algorithm>
#include <iostream>
#pragma warning (disable:4786);

using namespace std;


int main()
{
	int hyh = 0;
	int mass[3] = { 3,2,1 };
	set<int> chisla(mass, mass+1);
	//set<int> nat(0, 10);
	set<int>::iterator iter;
	chisla.insert(5);
	iter = chisla.begin();
	cout << chisla.count;
	/*
	for (int i = 0; i < 11;i++) {
		chisla.insert(rand);
	}
	if (chisla.begin % 2 == 0) {
		nat.insert(chisla.begin);
	};
	*/
	return 0;
}