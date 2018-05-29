//Даны действительные числа a0..a6. Получить для x = 1,3,4 значения p(x+1) - p(x) , где p(y) = a6*y^6 + a5*y^5 + .. + a0. 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

float p(float*, int);

int main() {
	setlocale(0, "");
	srand(time(0));
	float a[7];
	int	x[3] = {1,3,4};
	cout << "Начальные значения:" << endl;
	for (int elem = 0; elem < sizeof(x) / 4; elem++)						
	{
		cout << "x" << elem << "=" << x[elem] << setw(2);
	}
	cout << setw(0) << endl;
	for (int elem = 0; elem < sizeof(a) / 4; elem++)						
		{
			a[elem] = 0.1 * (-11 + rand() % 21);
			cout << "a" << elem << "=" << a[elem] << setw(2);
		}
	cout << endl << "Результат работы процедуры:" << endl;
	float res;
	for (int i = 0; i < 3; i++) {
		res = p(a, x[i] + 1) - p(a, x[i]);
		cout << res << endl;;
	}
	system("pause");
	return 0;
}

float p(float* a, int b)
{
	float y = 0;
	for (int countEA = 6; countEA >= 0; countEA--)
	{
		y += a[countEA] * pow(b, a[countEA]);
	}
	return y;
}