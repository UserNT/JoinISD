#include<iostream>
#include<conio.h>
#include<string>
#include<array>
#include<memory>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<iterator>

//���������� MSDN
using namespace std;

void Show(int a)
{
	//a += 2;
	cout << a << ' ';
}

int main()
{
	setlocale(LC_ALL, "Russian");

	list<int> a(3, 5);
	vector<int> b(10);
	b[0] = 12;

	back_insert_iterator<vector<int>> p(b);

	copy(a.begin(), a.end(), p);

	for (int i : b)
	{
		cout << i << ' ';
	}

	//map<int, string> a;//����� ���������� ������
	//pair<int,string> p(12, "fdf");//���� ������ �������������� map
	//pair<int, string> p1(1, "fdf");
	//a.insert(p);
	//a.insert(p1);

	//auto result = a.find(12);

	//cout << (*result).first();
	//set<int> a;//<set>; � ��������� ��� �� ���� ������(������ �� ����������� �����), ���� ��� �������
	//set<int> b;
	//for (int i = 1; i <= 10; i++)
	//	a.insert(i);
	//for (int i = 7; i <= 12; i++)
	//	b.insert(i);

	//for (int i : a)
	//{
	//	cout << i << ' ';
	//}

	//cout << endl;

	//for (int i : b)
	//{
	//	cout << i << ' ';
	//}

	//cout << endl;

	////set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(a,a.begin()));//����������� ���� ��������
	////
	////for (int i : a)
	////{
	////	cout << i << ' ';
	////}
	//
	//set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(a, a.begin()));

	//for (int i : a)
	//	{
	//		cout << i << ' ';
	//	}
	
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
	
	//����� ��������� �� ��������� �����. ��������� <memory>. ���������� ������� ��� ��������� �� ������� ������ !!!�����  weak_ptr !!!
	
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


	//vector<int> a;//������ ������������ ��������������
	//vector<int> b(2,20);

	//for (int i = 9; i >= 0; i--)
	//{
	//	a.push_back(i + 1);
	//}

	////vector<int>::iterator ia = a.begin();//���������� ���������

	////a.erase(a.begin() + 2, a.begin() + 5);//������� �������� ��

	////a.insert(a.end(), b.begin(), b.end());// ��������� � �.���() �������� ��.\
	//
	////a.resize(20);
	//
	///*for (auto i : a)
	//{
	//	cout << i << ' ';
	//}*/

	//sort(a.rbegin(), a.rend());//���������� �� ��������;(a.begin(), a.end() - �� �����������);��������� <algorithm>

	//random_shuffle(a.begin(), a.end());// ��������� ����������;��������� <algorithm>
	//
	//vector<int>::iterator a1 = find(a.begin(), a.end(), 7); // find - ���������� �������� �� �� ���������� "7"

	//cout << *a1;
	//
	//for_each(a.begin(), a.end(),Show);// ��������� ������� Show ��� ������� �� �������;��������� <algorithm>

	//queue<int> a;//<queue>

	//list<int> b;//-����������� ������; ������� �������� �������� �������, ���������� � �������� ��� � �������

	

	_getch();
	return 0;
}