#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstring>

using namespace std;

const int S = 40;
struct Cars
{
	int price;	
	char model[S];
	char type[S];
};

void InputCar(Cars &c, istream &io)
{
	io >> c.price >> c.model >> c.type;	
}

void OutputCar(Cars &c, ostream &os)
{
	os << c.price << " " << c.model << " " << c.type;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Cars a;
	Cars b;

	cout << "������� ��������������� ������ � ������ ����, �����, ���: ";
	InputCar(a, cin);
	cout << "��������� ������: ";
	OutputCar(a, cout);
	cout << endl;

	char nameFile[S];
	ofstream fout;
	
	cout << "������� ��� ����� ��� ���������� ������: ";
	cin >> nameFile;	
	strcat_s(nameFile, ".txt");
	fout.open(nameFile);
	OutputCar(a, fout);
	cout << "���������� ������ � ����..." << endl;

	fout.close();	

	ifstream fin;
	cout << "������� ��� ����� ��� ���������� ������: ";
	cin >> nameFile;
	strcat_s(nameFile, ".txt");
	fin.open(nameFile);
	if (!fin.is_open())
	{
		cout << "������ ����� �� ����������!";
		return -1;
	}	

	cout << "a: ";
	OutputCar(a, cout);
	cout << endl;
	InputCar(b, fin);
	//fin >> b.price;
	//fin >> b.model;
	//fin >> b.type;
	fin.close();
	cout << "b: ";		
 	OutputCar(b, cout);	
	
	cout << endl;

	_getch();
	return 0;
}