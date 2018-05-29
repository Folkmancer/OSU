#ifndef Temp_list
#define Temp_list
using namespace std;

template <typename T> struct list
{
	T value[1];
	list* next;
};

template <typename T> void create_list(T * array, int count)
{
	list<T>* elem = new list<T>[count];
	list<T>* head(NULL);
	for (int i = 0; i < count; i++)
	{
		elem->value[0] = array[i];
		elem->next = head;
		head = elem;
		cout << elem->value[0] << " ";
	}
	cout << endl;
	delete[]elem;
}
#endif