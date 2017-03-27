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

//библиотека MSDN
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

	//map<int, string> a;//могут повторятся данные
	//pair<int,string> p(12, "fdf");//пара которй инициализируют map
	//pair<int, string> p1(1, "fdf");
	//a.insert(p);
	//a.insert(p1);

	//auto result = a.find(12);

	//cout << (*result).first();
	//set<int> a;//<set>; в множестве сет не повт данные(сохран по уникальному ключу), сорт при вставке
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

	////set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(a,a.begin()));//объединение двух множеств
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
	
	//может указывать на несколько ячеек. заголовок <memory>. деструктор удаляет все указатели на участок памяти !!!лучше  weak_ptr !!!
	
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


	//vector<int> a;//размер определяется инициализацией
	//vector<int> b(2,20);

	//for (int i = 9; i >= 0; i--)
	//{
	//	a.push_back(i + 1);
	//}

	////vector<int>::iterator ia = a.begin();//объявление итератора

	////a.erase(a.begin() + 2, a.begin() + 5);//удаляем диапазон эл

	////a.insert(a.end(), b.begin(), b.end());// вставляем с а.епд() диапазон эл.\
	//
	////a.resize(20);
	//
	///*for (auto i : a)
	//{
	//	cout << i << ' ';
	//}*/

	//sort(a.rbegin(), a.rend());//сортировка по убыванию;(a.begin(), a.end() - по возростанию);заголовок <algorithm>

	//random_shuffle(a.begin(), a.end());// случайная сортировка;заголовок <algorithm>
	//
	//vector<int>::iterator a1 = find(a.begin(), a.end(), 7); // find - возвращает итератор на эл содержащий "7"

	//cout << *a1;
	//
	//for_each(a.begin(), a.end(),Show);// выполнить функцию Show для каждого эл вектора;заголовок <algorithm>

	//queue<int> a;//<queue>

	//list<int> b;//-двухсвязный список; быстрее работает операция вставки, сортировки и удаления чем в векторе

	

	_getch();
	return 0;
}