#include <iostream>
#include <string>
#include <typeinfo.h>
#include "Temp_list.h"
using namespace std;

int main()
{	
	setlocale(0, "");
	int vec[3] = { 12, 32, 445 }, count = 3;
    create_list(vec,count);
	system("pause");
	return 0;
}