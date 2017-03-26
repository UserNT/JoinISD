#include<iostream>
#include<conio.h>
#include<string>
#include<array>
#include<memory>
#include<vector>

//библиотека MSDN
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	/*string заголовок <string>*/

	/*string str("Hello Vitos");
	string str2("Hello Vitos");
	str += " Viktorovich";	
	getline(cin, str);
	cin.get();
	cout << str;*/

	/*array заголовок <array>; статичный массив с стандартными исключениями*/

	/*array<int, 10> arr;
	arr[0] = 'f';
	arr[1] = 'b';
	cout << arr.max_size();*/

	//умные указатели. -автоматически освобождают динам память;-один указатель на одну ячейку памяти
	//без загловка

	/*auto_ptr<string> p(new string("sfdfdf"));
	auto p1 = p;
	cout << *p;*/
	
	//может указывать на несколько ячеек. заголовок <memory>. деструктор удаляет все указатели на участок памяти
	
	/*shared_ptr<string> p(new string("sfdfdf"));
	auto p1 = p;
	cout << *p;
	cout << endl;
	p.~shared_ptr();
	cout << p1;*/

	//vector заголовок <vector>, динамический массив; без указания размера(либо размер в момент определения)

	//int arr[2] = { 1, 2 };	
	//vector<int> a(arr, arr+2);//arr - указатель на первый эл. , arr+2 - указатель на следуйщий за последним эл.
	//cout << a[0] << ' ' << a[1];

	//vector<int> a(3,0);// 0 повторяется 3 раза

	//for(int i = 0; i < a.size(); i++) // a.size() - без учета дополнительных ячеек

	/*for (auto i : a)// цикл для прохода контейнера вектора
	{
		i = 222;
		cout << i << endl;
	}

	for (auto i : a)
	{
		
		cout << i << endl;
	}						*///цикл без измен вектора


	/*for (auto &i : a)
	{
		i = 222;
		cout << i << endl;
	}

	for (auto i : a)
	{

		cout << i << endl;
	}						*///цикл c измен вектора


	vector<int> a;//размер определяется инициализацией

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