#ifndef WorkWithData
#define WorkWithData
#include <iostream> // ��� ������ � ��������
#include <string>  // ��� ������ �� ��������
#include <fstream> // ��� ������ � �������
#include <conio.h> // ��� ������ _getch
#include <Windows.h> // ��� �����������
#include <ctime> // ��� ��������� ������� ����
#include <cctype>
#include <cmath> //��� ������
using namespace std;

struct dateElement
{
	int day;
	int month;
	int year;
};

struct medicine
{
	int code;
	string name;
	dateElement rel_date;
	dateElement	per_storage ;
	string form;
	int	lot_size;
};

void main_menu();
medicine* FromBD(int &);
void saveBD(medicine *, int &);
void ShowElement(medicine *, int &);
void MiniShowRel(medicine *, int &);
void MiniShowStorage(medicine *, int &);
medicine* AddElement(medicine *, int &);
void ChangeElement(medicine *, int &);
void DeleteElement(medicine *, int &);
void SearchElement(medicine *, int &);
void SortUpElement(medicine *, int &);
void SortDownElement(medicine *, int &);
void DeleteTimeOver(medicine *, int &);
void MaxSize(medicine *, int &);
void Perishable(medicine *, int &);
void CheckCode(medicine *, string &, int);
void CheckDateRel(string &);
void CheckDateStorage(string &);
void CheckSize(string &);

//////////////////////////////////////���� ������� ����////////////////////////////////////////

void main_menu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int countElement = 0;
	medicine *dataArray = FromBD(countElement);
	int done = 1;
	while (done != 0)
	{
		int variant_menu;
		cout << "1 �������� ������\n"
			<< "2 ���������� ������\n"
			<< "3 ������� ������\n"
			<< "4 �������� ������\n"
			<< "5 ����� ������\n"
			<< "6 ���������� ������\n"
			<< "0 �����" << endl;
		variant_menu = (_getch() - 48);
		cout << variant_menu << endl;
		switch (variant_menu) {
			case 1:
			{
				system("cls");
				cout << "1 �������� ������" << endl;
				
				cout << "1 ���� ��������\n"
					<< "2 � �������� �������� ������ ��������\n"
					<< "3 �������� ������ ���������� ��������" << endl;
				int variant_type = (_getch() - 48);
				system("cls");
				switch (variant_type)
				{
				case 1:
				{
					cout << "�������� ������ ���� ��������:" << endl;
					ShowElement(dataArray, countElement);
				}
				break;
				case 2:
				{
					cout << "�������� ������ � �������� �������� ������ ��������:" << endl;
					MaxSize(dataArray, countElement);
				}
				break;
				case 3:
				{
					cout << "�������� ������ �������� ������ ���������� ��������:" << endl;
					Perishable(dataArray, countElement);
				}
				break;
				default:
				{
					cerr << "�� ������� �������������� �������!" << endl;
					system("pause");
					system("cls");
				}
				break;
				}
			}
			break;
			case 2:
			{
				system("cls");
				cout << "2 ���������� ������" << endl;
				dataArray = AddElement(dataArray, countElement);
			}
			break;
			case 3:
			{
				system("cls");
				cout << "3 ��������� ������" << endl;
				ChangeElement(dataArray, countElement);
			}
			break;
			case 4:
			{
				system("cls");
				cout << "4 �������� ������" << endl;
				cout << "1 �� ���� ���������\n"
					<< "2 ������������ ��������" << endl;
				int variant_type = (_getch() - 48);
				system("cls");
				switch (variant_type)
				{
				case 1:
				{
					cout << "�������� ������ �� ���� ���������:" << endl;
					DeleteElement(dataArray, countElement);
				}
				break;
				case 2:
				{
					cout << "�������� ������ ������������ ��������:" << endl;
					DeleteTimeOver(dataArray, countElement);
				}
				break;
				default:
				{
					cerr << "�� ������� �������������� �������!" << endl;
					system("pause");
					system("cls");
				}
				break;
				}
			}
			break;
			case 5:
			{
				system("cls");
				cout << "5 ����� ������" << endl;
				SearchElement(dataArray, countElement);
			}	
			break;
			case 6:
			{
				system("cls");
				cout << "6 ���������� ������" << endl;
				cout << "1 �� �����������\n"
					<< "2 �� ��������" << endl;
				int variant_type = (_getch() - 48);
				system("cls");
				switch (variant_type)
				{
					case 1:
					{
						cout << "���������� ������ ������ �� �����������:" << endl;
						SortUpElement(dataArray, countElement);
					}
					break;
					case 2:
					{
						cout << "���������� ������ ������ �� ��������:" << endl;
						SortDownElement(dataArray, countElement);
					}
					break;
					default:
					{
						cerr << "�� ������� �������������� �������!" << endl;
						system("pause");
						system("cls");
					}
					break;
				}
			}
			break;
			case 0:
			{
				system("cls");
				saveBD(dataArray, countElement);
				done = NULL;
			}
			break;
			default:
			{
				cerr << "�� ������� �������� �������" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
	}
}

////////////////////////////////���� ������� ������ � ������///////////////////////////////////

medicine* FromBD(int &bd_element)
{
	ifstream bd_file("C:\\Users\\Vault Hunter\\Desktop\\Medicine.txt", ios_base::in);
	if (bd_file.is_open())
	{
		int i = 0, j = 0;
		std::string temp_string;
		while (!bd_file.eof())
		{
			std::getline(bd_file, temp_string);
			bd_element++;
		}
		bd_element /= 6;
		bd_file.seekg(0, std::ios::beg);
		medicine *NewArray = new medicine[bd_element];
		while (std::getline(bd_file, temp_string))
		{
			if (i == 0)
			{
				NewArray[j].code = atoi(temp_string.c_str());
				i++;
			}
			else if (i == 1)
			{
				NewArray[j].name = temp_string;
				i++;
			}
			else if (i == 2)
			{
				NewArray[j].rel_date.day = stoi(temp_string.substr(0, 2));
				NewArray[j].rel_date.month = stoi(temp_string.substr(3, 2));
				NewArray[j].rel_date.year = stoi(temp_string.substr(6, 4));
				i++;
			}
			else if (i == 3)
			{
				NewArray[j].per_storage.day = 1;
				NewArray[j].per_storage.month = stoi(temp_string.substr(0, 2));
				NewArray[j].per_storage.year = stoi(temp_string.substr(3, 4));
				i++;
			}
			else if (i == 4)
			{
				NewArray[j].form = temp_string;
				i++;
			}
			else if (i == 5)
			{
				NewArray[j].lot_size = atoi(temp_string.c_str());
				i = 0;
				j++;
			}
		}
		bd_file.close();
		return NewArray;
	}
	else 
	{
		cout << "���� �� ����� ���� ������!" << endl;
		system("pause");
		exit(0);
	}
}

void saveBD(medicine *SaveArray, int &save_element)
{
	ofstream bd_savefile("C:\\Users\\Vault Hunter\\Desktop\\Medicine.txt", ios_base::out | ios_base::trunc);
	if (bd_savefile.is_open())
	{
		for (int i = 0; i < save_element; i++)
		{
			bd_savefile << SaveArray[i].code << endl;
			bd_savefile << SaveArray[i].name << endl;
			if (SaveArray[i].rel_date.day < 10) { bd_savefile << '0' << SaveArray[i].rel_date.day << '/'; }
			else { bd_savefile << SaveArray[i].rel_date.day << '/'; }
			if (SaveArray[i].rel_date.month < 10) { bd_savefile << '0' << SaveArray[i].rel_date.month << '/'; }
			else { bd_savefile << SaveArray[i].rel_date.month << '/'; }
			bd_savefile << SaveArray[i].rel_date.year << endl;
			if (SaveArray[i].per_storage.month < 10) { bd_savefile << '0' << SaveArray[i].per_storage.month << '/'; }
			else { bd_savefile << SaveArray[i].per_storage.month << '/'; }
			bd_savefile << SaveArray[i].per_storage.year << endl;
			bd_savefile << SaveArray[i].form << endl;
			bd_savefile << SaveArray[i].lot_size;
			if (i != (save_element - 1)) { bd_savefile << endl; }
		}
		bd_savefile.close();
		delete[] SaveArray;
		cout << "��������� ���������!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���� �� ����� ���� ������!" << endl;
		system("pause");
		exit(0);
	}
}

/////////////////////////////////////���� ������� ������//////////////////////////////////////

void ShowElement(medicine *ShowArray, int &show_element)
{
	for (int i = 0; i < show_element; i++)
	{
		cout << ShowArray[i].code << endl;
		cout << ShowArray[i].name << endl;
		MiniShowRel(ShowArray, i);
		MiniShowStorage(ShowArray, i);
		cout << ShowArray[i].form << endl;
		cout << ShowArray[i].lot_size << endl;
	}
	system("pause");
	system("cls");
}

void MiniShowRel(medicine *miniArray, int &num_element)
{
	if (miniArray[num_element].rel_date.day < 10) { cout << '0' << miniArray[num_element].rel_date.day << '/'; }
	else { cout << miniArray[num_element].rel_date.day << '/'; }
	if (miniArray[num_element].rel_date.month < 10) { cout << '0' << miniArray[num_element].rel_date.month << '/'; }
	else { cout << miniArray[num_element].rel_date.month << '/'; }
	cout << miniArray[num_element].rel_date.year << endl;
}

void MiniShowStorage(medicine *miniArray, int &num_element)
{
	if (miniArray[num_element].per_storage.month < 10) { cout << '0' << miniArray[num_element].per_storage.month << '/'; }
	else { cout << miniArray[num_element].per_storage.month << '/'; }
	cout << miniArray[num_element].per_storage.year << endl;
}



/////////////////////////////////////���� �������� �������/////////////////////////////////////

medicine* AddElement(medicine *AddArray, int &add_element)
{
	add_element++;
	string temp_add_string;
	medicine *NewArray = new medicine[add_element];
	for (int i = 0; i < (add_element - 1); i++)
	{
		NewArray[i] = AddArray[i];
	}
	delete[] AddArray;
	int elem = add_element - 1;
	cout << "������� ���" << endl;
	cin >> temp_add_string;
	CheckCode(NewArray, temp_add_string, add_element);
	NewArray[elem].code = stoi(temp_add_string);
	cout << "������� ��������" << endl;
	cin >> NewArray[elem].name;
	cout << "������� ���� ������� � ������� dd/mm/yyyy" << endl;
	cin >> temp_add_string;
	CheckDateRel(temp_add_string);
	NewArray[elem].rel_date.day = stoi(temp_add_string.substr(0, 2));
	NewArray[elem].rel_date.month = stoi(temp_add_string.substr(3, 2));
	NewArray[elem].rel_date.year = stoi(temp_add_string.substr(6, 4));
	cout << "������� ���� �������� � ������� mm/yyyy" << endl;
	cin >> temp_add_string;
	CheckDateStorage(temp_add_string);
	NewArray[elem].per_storage.day = 1;
	NewArray[elem].per_storage.month = stoi(temp_add_string.substr(0, 2));
	NewArray[elem].per_storage.year = stoi(temp_add_string.substr(3, 4));
	cout << "������� �����" << endl;
	cin >> NewArray[elem].form;
	cout << "������� ������ ������" << endl;
	cin >> temp_add_string;
	CheckSize(temp_add_string);
	NewArray[elem].lot_size = stoi(temp_add_string);
	cout << "������� ��������!" << endl;
	system("pause");
	system("cls");
	return NewArray;
	delete[] NewArray;
}

void ChangeElement(medicine *ChangeArray, int &change_element)
{
	int num, k = 0;
	string temp_change_string;
	cout << "������� ��� ��������" << endl;
	cin >> num;
	for (int i = 0; i < change_element; i++)
	{
		if (ChangeArray[i].code == num)
		{
			cout << "������� �������� ����: " << ChangeArray[i].code << endl;
			cout << "����� �������� ����: " ;
			cin >> temp_change_string;
			//CheckCode(ChangeArray, temp_change_string, change_element);
			ChangeArray[i].code = stoi(temp_change_string);
			cout << "������� �������� ��������: " << ChangeArray[i].name << endl;
			cout << "����� �������� ��������: ";
			cin >> ChangeArray[i].name;
			cout << "������� �������� ���� �������: ";
			MiniShowRel(ChangeArray, i);
			cout << "����� �������� ���� ������� � ������� dd/mm/yyyy: ";
			cin >> temp_change_string;
			CheckDateRel(temp_change_string);
			ChangeArray[i].rel_date.day = stoi(temp_change_string.substr(0, 2));
			ChangeArray[i].rel_date.month = stoi(temp_change_string.substr(3, 2));
			ChangeArray[i].rel_date.year = stoi(temp_change_string.substr(6, 4));
			cout << "������� �������� ����� ��������: ";
			MiniShowStorage(ChangeArray, i);
			cout << "����� �������� ���� �������� � ������� mm/yyyy: ";
			cin >> temp_change_string;
			CheckDateStorage(temp_change_string);
			ChangeArray[i].per_storage.day = 1;
			ChangeArray[i].per_storage.month = stoi(temp_change_string.substr(0, 2));
			ChangeArray[i].per_storage.year = stoi(temp_change_string.substr(3, 4));
			cout << "������� �������� �����: " << ChangeArray[i].form << endl;
			cout << "����� �������� �����: ";
			cin >> ChangeArray[i].form;
			cout << "������� �������� ������� ������: " << ChangeArray[i].lot_size << endl;
			cout << "����� �������� ������� ������: ";
			cin >> temp_change_string;
			CheckSize(temp_change_string);
			ChangeArray[i].lot_size = stoi(temp_change_string);
		}
		else
		{
			k++;
		}
	}
	if (k == change_element) cout << "������ �� �������!" << endl;
	else cout << "��������� �������!" << endl;
	system("pause");
	system("cls");
}

void SearchElement(medicine *SearchArray, int &search_element)
{
	cout << "1 ����� �� ����\n"
		<< "2 ����� �� ��������\n"
		<< "3 ����� �� ���� �������\n"
		<< "4 ����� �� ����� ��������\n"
		<< "5 ����� �� ����� ��������\n"
		<< "6 ����� �� ������� ������" << endl;
	int variant_search = (_getch() - 48);
	system("cls");
	switch (variant_search) {
	case 1: {
		int scode, k = 0;
		cout << "������� ��� ��������" << endl;
		cin >> scode;
		for (int i = 0; i < search_element; i++)
		{
			if (SearchArray[i].code == scode)
			{
				cout << SearchArray[i].code << endl;
				cout << SearchArray[i].name << endl;
				MiniShowRel(SearchArray, i);
				MiniShowStorage(SearchArray, i);
				cout << SearchArray[i].form << endl;
				cout << SearchArray[i].lot_size << endl;
			}
			else
			{
				k++;
			}
		}
		if (k == search_element) cout << "������ �� �������!" << endl;
	}
		break;
	case 2: 
	{
		int k = 0;
		string sname;
		cout << "������� �������� ���������" << endl;
		cin >> sname;
		for (int i = 0; i < search_element; i++)
		{
			if (SearchArray[i].name == sname)
			{
				cout << SearchArray[i].code << endl;
				cout << SearchArray[i].name << endl;
				MiniShowRel(SearchArray, i);
				MiniShowStorage(SearchArray, i);
				cout << SearchArray[i].form << endl;
				cout << SearchArray[i].lot_size << endl;
			}
			else
			{
				k++;
			}
		}
		if (k == search_element) cout << "������ �� �������!" << endl;
	}
		break;
	case 3:
	{
		int k = 0;
		dateElement temp_date;
		string srel_date;
		cout << "������� ���� ������� � ������� dd/mm/yyyy" << endl;
		cin >> srel_date;
		temp_date.day = stoi(srel_date.substr(0, 2));
		temp_date.month = stoi(srel_date.substr(3, 2));
		temp_date.year = stoi(srel_date.substr(6, 4));
		for (int i = 0; i < search_element; i++)
		{
			if ((SearchArray[i].rel_date.day == temp_date.day) && (SearchArray[i].rel_date.month == temp_date.month) && (SearchArray[i].rel_date.year == temp_date.year))
			{
				cout << SearchArray[i].code << endl;
				cout << SearchArray[i].name << endl;
				MiniShowRel(SearchArray, i);
				MiniShowStorage(SearchArray, i);
				cout << SearchArray[i].form << endl;
				cout << SearchArray[i].lot_size << endl;
			}
			else
			{
				k++;
			}
		}
		if (k == search_element) cout << "������ �� �������!" << endl;
	}
		break;
	case 4:
	{
		int k = 0;
		string sper_storage;
		dateElement temp_date;
		temp_date.day = 1;
		temp_date.month = stoi(sper_storage.substr(0, 2));
		temp_date.year = stoi(sper_storage.substr(3, 4));
		cout << "������� ���� ��������" << endl;
		cin >> sper_storage ;
		for (int i = 0; i < search_element; i++)
		{
			if ((SearchArray[i].per_storage.day == temp_date.day) && (SearchArray[i].per_storage.month == temp_date.month) && (SearchArray[i].per_storage.year == temp_date.year))
			{
				cout << SearchArray[i].code << endl;
				cout << SearchArray[i].name << endl;
				MiniShowRel(SearchArray, i);
				MiniShowStorage(SearchArray, i);
				cout << SearchArray[i].form << endl;
				cout << SearchArray[i].lot_size << endl;
			}
			else
			{
				k++;
			}
		}
		if (k == search_element) cout << "������ �� �������!" << endl;
	}
		break;
	case 5:
	{
		int k = 0;
		string sform;
		cout << "������� ����� ��������" << endl;
		cin >> sform;
		for (int i = 0; i < search_element; i++)
		{
			if (SearchArray[i].form == sform)
			{
				cout << SearchArray[i].code << endl;
				cout << SearchArray[i].name << endl;
				MiniShowRel(SearchArray, i);
				MiniShowStorage(SearchArray, i);
				cout << SearchArray[i].form << endl;
				cout << SearchArray[i].lot_size << endl;
			}
			else
			{
				k++;
			}
		}
		if (k == search_element) cout << "������ �� �������!" << endl;
	}
		break;
	case 6:
	{
		int slot_size, k = 0;
		cout << "������� ���� �������" << endl;
		cin >> slot_size;
		for (int i = 0; i < search_element; i++)
		{
			if (SearchArray[i].lot_size == slot_size)
			{
				cout << SearchArray[i].code << endl;
				cout << SearchArray[i].name << endl;
				MiniShowRel(SearchArray, i);
				MiniShowStorage(SearchArray, i);
				cout << SearchArray[i].form << endl;
				cout << SearchArray[i].lot_size << endl;
			}
			else
			{
				k++;
			}
		}
		if (k == search_element) cout << "������ �� �������!" << endl;
	}
		break;
	default:
		cerr << "�� ������� �������� �������!" << endl;
	break;
	}
	system("pause");
	system("cls");
}

void DeleteElement(medicine *DelArray, int &delete_element)
{
	int num, k = 0, z = 0;
	cout << "������� ��� ���������� ��������" << endl;
	cin >> num;
	for (int i = 0; i < delete_element; i++)
	{
		if (DelArray[i].code == num)
		{
			for (int j = i; j < delete_element - 1; ++j)
			{
				DelArray[j] = DelArray[j + 1];
			}
			--delete_element;
			z++;
		}
		else
		{
			k++;
		}
	}
	if (z == 0) cout << "������ �� �������!" << endl;
	else cout << "������� �����!" << endl;
	system("pause");
	system("cls");
}

void SortUpElement(medicine *SortUpArray, int &sort_up_element)
{
	medicine temp;
	cout << "1 ����������� �� ����\n"
		<< "2 ����������� �� ��������\n"
		<< "3 ����������� �� ���� �������\n"
		<< "4 ����������� �� ����� ��������\n"
		<< "5 ����������� �� ����� ��������\n"
		<< "6 ����������� �� ������� ������" << endl;
	int variant_up = (_getch() - 48);
	switch (variant_up)
	{
		case 1:
		{
			for (int i = 0; i < sort_up_element - 1; i++)
			{
				for (int j = i + 1; j < sort_up_element; j++)
				{
					if (SortUpArray[i].code > SortUpArray[j].code)
					{
						swap(SortUpArray[i], SortUpArray[j]);
					}
				}
			}
		}
		break;
		case 2:
		{
			for (int i = 0; i < sort_up_element - 1; i++)
			{
				for (int j = i + 1; j < sort_up_element; j++)
				{
					if (SortUpArray[i].name > SortUpArray[j].name)
					{
						swap(SortUpArray[i], SortUpArray[j]);
					}
				}
			}
		}
		break;
		case 3:
		{
			for (int i = 0; i < sort_up_element - 1; i++)
			{
				for (int j = i + 1; j < sort_up_element; j++)
				{
					if ((SortUpArray[i].rel_date.day + SortUpArray[i].rel_date.month * 30 + SortUpArray[i].rel_date.year * 365) 
				> (SortUpArray[j].rel_date.day + SortUpArray[j].rel_date.month * 30 + SortUpArray[j].rel_date.year * 365))
					{
						swap(SortUpArray[i], SortUpArray[j]);
					}
				}
			}
		}
		break;
		case 4:
		{
			for (int i = 0; i < sort_up_element - 1; i++)
			{
				for (int j = i + 1; j < sort_up_element; j++)
				{
					if ((SortUpArray[i].per_storage.day + SortUpArray[i].per_storage.month * 30 + SortUpArray[i].per_storage.year * 365) 
				> (SortUpArray[j].per_storage.day + SortUpArray[j].per_storage.month * 30 + SortUpArray[j].per_storage.year * 365))
					{
						swap(SortUpArray[i], SortUpArray[j]);
					}
				}
			}
		}
		break;
		case 5:
		{
			for (int i = 0; i < sort_up_element - 1; i++)
			{
				for (int j = i + 1; j < sort_up_element; j++)
				{
					if (SortUpArray[i].form > SortUpArray[j].form)
					{
						swap(SortUpArray[i], SortUpArray[j]);
					}
				}
			}
		}
		break;
		case 6:
		{
			for (int i = 0; i < sort_up_element - 1; i++)
			{
				for (int j = i + 1; j < sort_up_element; j++)
				{
					if (SortUpArray[i].lot_size > SortUpArray[j].lot_size)
					{
						swap(SortUpArray[i], SortUpArray[j]);
					}
				}
			}
		}
	break;
	default:
		cerr << "�� ������� �������� �������!" << endl;
	break;
	}
	cout << "���������� ���������!" << endl;
	system("pause");
	system("cls");
}

void SortDownElement(medicine *SortDownArray, int &sort_down_element)
{
	medicine temp;
	cout << "1 ����������� �� ����\n"
		<< "2 ����������� �� ��������\n"
		<< "3 ����������� �� ���� �������\n"
		<< "4 ����������� �� ����� ��������\n"
		<< "5 ����������� �� ����� ��������\n"
		<< "6 ����������� �� ������� ������" << endl;
	int variant_down = (_getch() - 48);
	switch (variant_down)
	{
	case 1:
	{
		for (int i = 0; i < sort_down_element - 1; i++)
		{
			for (int j = i + 1; j < sort_down_element; j++)
			{
				if (SortDownArray[i].code < SortDownArray[j].code)
				{
					swap(SortDownArray[i], SortDownArray[j]);
				}
			}
		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < sort_down_element - 1; i++)
		{
			for (int j = i + 1; j < sort_down_element; j++)
			{
				if (SortDownArray[i].name < SortDownArray[j].name)
				{
					swap(SortDownArray[i], SortDownArray[j]);
				}
			}
		}
	}
	break;
	case 3:
	{
		for (int i = 0; i < sort_down_element - 1; i++)
		{
			for (int j = i + 1; j < sort_down_element; j++)
			{
				if ((SortDownArray[i].rel_date.day + SortDownArray[i].rel_date.month * 30 + SortDownArray[i].rel_date.year * 365) 
					< (SortDownArray[j].rel_date.day + SortDownArray[j].rel_date.month * 30 + SortDownArray[j].rel_date.year * 365))
				{
					swap(SortDownArray[i], SortDownArray[j]);
				}
			}
		}
	}
	break;
	case 4:
	{
		for (int i = 0; i < sort_down_element - 1; i++)
		{
			for (int j = i + 1; j < sort_down_element; j++)
			{
				if ((SortDownArray[i].per_storage.day + SortDownArray[i].per_storage.month * 30 + SortDownArray[i].per_storage.year * 365) < (SortDownArray[j].per_storage.day + SortDownArray[j].per_storage.month * 30 + SortDownArray[j].per_storage.year * 365))
				{
					swap(SortDownArray[i], SortDownArray[j]);
				}
			}
		}
	}
	break;
	case 5:
	{
		for (int i = 0; i < sort_down_element - 1; i++)
		{
			for (int j = i + 1; j < sort_down_element; j++)
			{
				if (SortDownArray[i].form < SortDownArray[j].form)
				{
					swap(SortDownArray[i], SortDownArray[j]);
				}
			}
		}
	}
	break;
	case 6:
	{
		for (int i = 0; i < sort_down_element - 1; i++)
		{
			for (int j = i + 1; j < sort_down_element; j++)
			{
				if (SortDownArray[i].lot_size < SortDownArray[j].lot_size)
				{
					swap(SortDownArray[i], SortDownArray[j]);
				}
			}
		}
	}
	break;
	default:
		cerr << "�� ������� �������������� �������!" << endl;
	break;
	}
	cout << "���������� ���������!" << endl;
	system("pause");
	system("cls");
}


//////////////////////////////////���� �������������� �������//////////////////////////////////

void DeleteTimeOver(medicine *DelTimeArray, int &del_time_element)
{
	time_t timenow = time(NULL);
	tm timeinfo;
	localtime_s(&timeinfo, &timenow);
	int count_day = (timeinfo.tm_mday),
		count_month = (timeinfo.tm_mon + 1),
		count_year = (timeinfo.tm_year + 1900);
	int count = 0;
	for (int i = 0; i < del_time_element; i++)
	{
		if ((DelTimeArray[i].per_storage.day <= count_day) 
			&& (DelTimeArray[i].per_storage.month <= count_month) 
			&& (DelTimeArray[i].per_storage.year <= count_year))
		{
			for (int j = i; j < del_time_element - 1; ++j)
			{
				DelTimeArray[j] = DelTimeArray[j + 1];
			}
			--del_time_element;
			count++;
		}
	}
	cout << "������� " << count << " ���������!" << endl;
	system("pause");
	system("cls");
}

void MaxSize(medicine *SizeArray, int &size_element)
{
	int summ = 0;
	for (int i = 0; i < size_element - 1; i++)
	{
		for (int j = i + 1; j < size_element; j++)
		{
			if (SizeArray[i].lot_size < SizeArray[j].lot_size)
			{
				swap(SizeArray[i], SizeArray[j]);
			}
		}
	}
	for (int i = 0; i < size_element; i++)
	{
		summ += SizeArray[i].lot_size;
	}
	if (size_element > 0) { summ /= size_element; }
	for (int i = 0; i < size_element; i++)
	{
		if (SizeArray[i].lot_size >= summ)
		{
			cout << SizeArray[i].code << endl;
			cout << SizeArray[i].name << endl;
			MiniShowRel(SizeArray, i);
			MiniShowStorage(SizeArray, i);
			cout << SizeArray[i].form << endl;
			cout << SizeArray[i].lot_size << endl;
		}
	}
	system("pause");
	system("cls");
}

void Perishable(medicine *PSArray, int &ps_element)
{
	int summ = 0;
	for (int i = 0; i < ps_element; i++)
	{
		summ += (fabs(PSArray[i].per_storage.month - PSArray[i].rel_date.month) + (fabs(PSArray[i].per_storage.year - PSArray[i].rel_date.year) * 12));
	}
	if (ps_element > 0) { summ /= ps_element; }
	for (int i = 0; i < ps_element; i++)
	{
		if ((fabs(PSArray[i].per_storage.month - PSArray[i].rel_date.month) + (fabs(PSArray[i].per_storage.year - PSArray[i].rel_date.year) * 12)) <= summ)
		{
			cout << PSArray[i].code << endl;
			cout << PSArray[i].name << endl;
			MiniShowRel(PSArray, i);
			MiniShowStorage(PSArray, i);
			cout << PSArray[i].form << endl;
			cout << PSArray[i].lot_size << endl;
		}
	}
	system("pause");
	system("cls");
}

////////////////////////////////////���� ������� ��������//////////////////////////////////////

void CheckCode(medicine *CheckArray, string &temp_string, int check_element)
{
	bool done = false;
	while (done != true)
	{
		bool temp = false;
		if (temp_string.find_first_not_of("0123456789") != std::string::npos)
		{
			cout << "�� ����� ����������� ��������, ��������� �������!" << endl;
			cin >> temp_string;
		}
		else
		{
			for (int i = 0; i < check_element; i++)
			{
				if (CheckArray[i].code == stoi(temp_string))
				{
					temp = true;
				}
			}
			if (temp == true)
			{
				cout << "����� ��� ��� �������, ��������� �������!" << endl;
				cin >> temp_string;
			}
			else
			{
				done = true;
			}
		}
	}
}

void CheckDateRel(string &temp_date_check)
{
	bool done = false;
	while (done != true)
	{
		if (isdigit(temp_date_check[0]) && isdigit(temp_date_check[1]) && isdigit(temp_date_check[3]) && isdigit(temp_date_check[4])
			&& isdigit(temp_date_check[6]) && isdigit(temp_date_check[7]) && isdigit(temp_date_check[8]) && isdigit(temp_date_check[9]))
		{
			if ((temp_date_check[2] == '/' && temp_date_check[5] == '/') || (temp_date_check[2] == '.' && temp_date_check[5] == '.'))
			{
				done = true;
			}
			else
			{
				cout << "�� ����� �������� ��������, ��������� �������!" << endl;
				cin >> temp_date_check;
			}
		}
		else
		{
			cout << "�� ����� �������� ��������, ��������� �������!" << endl;
			cin >> temp_date_check;
		}
	}
}

void CheckDateStorage(string &temp_storage_check)
{
	bool done = false;
	while (done != true)
	{
		if (isdigit(temp_storage_check[0]) && isdigit(temp_storage_check[1])
			&& isdigit(temp_storage_check[3]) && isdigit(temp_storage_check[4]) && isdigit(temp_storage_check[5]) && isdigit(temp_storage_check[6]))
		{
			if ((temp_storage_check[2] == '/') || (temp_storage_check[2] == '.'))
			{
				done = true;
			}
			else
			{
				cout << "�� ����� �������� ��������, ��������� �������!" << endl;
				cin >> temp_storage_check;
			}
		}
		else
		{
			cout << "�� ����� �������� ��������, ��������� �������!" << endl;
			cin >> temp_storage_check;
		}
	}
}

void CheckSize(string &temp_string)
{
	bool done = false;
	while (done != true)
	{
		if (temp_string.find_first_not_of("0123456789") != std::string::npos)
		{
			cout << "�� ����� ����������� ��������, ��������� �������!" << endl;
			cin >> temp_string;
		}
		else
		{
			done = true;
		}
	}
}
#endif