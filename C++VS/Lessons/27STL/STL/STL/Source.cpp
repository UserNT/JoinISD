#include<iostream>
#include<conio.h>
#include<string>
#include<array>
#include<memory>
#include<vector>

//���������� MSDN
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	/*string ��������� <string>*/

	/*string str("Hello Vitos");
	string str2("Hello Vitos");
	str += " Viktorovich";	
	getline(cin, str);
	cin.get();
	cout << str;*/

	/*array ��������� <array>; ��������� ������ � ������������ ������������*/

	/*array<int, 10> arr;
	arr[0] = 'f';
	arr[1] = 'b';
	cout << arr.max_size();*/

	//����� ���������. -������������� ����������� ����� ������;-���� ��������� �� ���� ������ ������
	//��� ��������

	/*auto_ptr<string> p(new string("sfdfdf"));
	auto p1 = p;
	cout << *p;*/
	
	//����� ��������� �� ��������� �����. ��������� <memory>. ���������� ������� ��� ��������� �� ������� ������
	
	/*shared_ptr<string> p(new string("sfdfdf"));
	auto p1 = p;
	cout << *p;
	cout << endl;
	p.~shared_ptr();
	cout << p1;*/

	//vector ��������� <vector>, ������������ ������; ��� �������� �������(���� ������ � ������ �����������)

	//int arr[2] = { 1, 2 };	
	//vector<int> a(arr, arr+2);//arr - ��������� �� ������ ��. , arr+2 - ��������� �� ��������� �� ��������� ��.
	//cout << a[0] << ' ' << a[1];

	//vector<int> a(3,0);// 0 ����������� 3 ����

	//for(int i = 0; i < a.size(); i++) // a.size() - ��� ����� �������������� �����

	/*for (auto i : a)// ���� ��� ������� ���������� �������
	{
		i = 222;
		cout << i << endl;
	}

	for (auto i : a)
	{
		
		cout << i << endl;
	}						*///���� ��� ����� �������


	/*for (auto &i : a)
	{
		i = 222;
		cout << i << endl;
	}

	for (auto i : a)
	{

		cout << i << endl;
	}						*///���� c ����� �������


	vector<int> a;//������ ������������ ��������������

	/*for (int i = 0; i < 10; i++)
	{
		a.push_back(i + 1);
	}*/

	for (auto i : a)
	{
		cout << i << ' ';
	}

	cout << endl << a.size();

	_getch();
	return 0;
}