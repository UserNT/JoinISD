#include <std_lib_facilities.h>
int main()
{
	setlocale(LC_ALL,"Russian");	
	
	cout << "����������, ������� �������� � ��������� ������: ";
	int n;
	double temp;
	cin >> n;
	cout << "n == " << n
		 << "\nn+1 == " << n+1
		 << "\n��� ���� �� n == " << 3*n
		 << "\n��� ���� �� n == " << 2*n
		 << "\nn � �������� == " << n*n
		 << "\n�������� n == " << n/2
		 << "\n������� �� ������� �� 3 == " << n%3;
	temp = n;
	cout << "\n������ ���������� �� n == " << sqrt(temp)
		 << '\n';

	keep_window_open();
	return 0;
}