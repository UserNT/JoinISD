//������� � �������� ���
#include <std_lib_facilities.h>
int main()
{
	setlocale(LC_ALL,"Russian");
	
	string first_name;
	string second_name;
	cout << "������� ���� ��� � ��������: ";
	cin >> first_name >> second_name;
	cout << "��������, " << first_name << " " << second_name <<"!!!\n";

	keep_window_open();
	return 0;
}