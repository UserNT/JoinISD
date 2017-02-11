//—читать и записать им€ и возраст
#include <std_lib_facilities.h>
int main()
{
	setlocale(LC_ALL,"Russian");
	
	int count;
	cout << "Enter int: ";
	cin >> count;
	string name;
	cout << "Enter string: ";
	cin >> name;
	int c2 = count+2;
	string s2 = name + " Jr. ";
	cout << " s2: " << s2;

	cout << "¬ведите свое им€ и возраст: ";
	

	keep_window_open();
	return 0;
}