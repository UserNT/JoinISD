//������� � �������� ��� � �������
#include <std_lib_facilities.h>
int main()
{
	setlocale(LC_ALL,"Russian");
	
	string first_name;
	double age;

	cout << "������� ���� ��� � �������: ";
	cin >> first_name >> age;
	cout << "��������, " << first_name << ", ��� ������� � ������� = " << age*12 << endl;

	keep_window_open();
	return 0;
}