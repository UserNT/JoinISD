#include<conio.h>
#include<fstream>
#include"book.h"

using namespace std;
using Library::book;

int main()
{
	setlocale(LC_ALL, "Russian");

	book B("Principi prorammirovanija", "Straustrup", "Teaching");

	book C;

	C.setTitle("Cinderela");
	C.setGenre("�airy tale");
	C.setPrice(50.45);

	cout << "\t\t\t���������� � ����� \"B\"\n\n";
	B.Print(cout);

	ofstream os;
	os.open("Text.txt");

	cout << "\t\t\t������ ���������� � ����� \"C\" � ���� \"Text.txt\"...";
	C.Print(os);

	_getch();
	return 0;
}