#include <std_lib_facilities.h>
int main()
{
	setlocale(LC_ALL,"Russian");	
	
	cout << "Пожалуйста, введите значение с плавающей точкой: ";
	int n;
	double temp;
	cin >> n;
	cout << "n == " << n
		 << "\nn+1 == " << n+1
		 << "\nтри раза по n == " << 3*n
		 << "\nдва раза по n == " << 2*n
		 << "\nn в квадрате == " << n*n
		 << "\nполовина n == " << n/2
		 << "\nостаток от деления на 3 == " << n%3;
	temp = n;
	cout << "\nкорень квадратный из n == " << sqrt(temp)
		 << '\n';

	keep_window_open();
	return 0;
}