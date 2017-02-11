//—читать и записать им€ и возраст
#include <std_lib_facilities.h>
int main()
{
	setlocale(LC_ALL,"Russian");
	
	string first_name;
	double age;

	cout << "¬ведите свое им€ и возраст: ";
	cin >> first_name >> age;
	cout << "ѕривееет, " << first_name << ", ¬аш возраст в мес€цах = " << age*12 << endl;

	keep_window_open();
	return 0;
}