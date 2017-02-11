//Считать и записать имя
#include <std_lib_facilities.h>
int main()
{
	setlocale(LC_ALL,"Russian");
	
	string first_name;
	string second_name;
	cout << "Введите свое имя и отчество: ";
	cin >> first_name >> second_name;
	cout << "Привееет, " << first_name << " " << second_name <<"!!!\n";

	keep_window_open();
	return 0;
}