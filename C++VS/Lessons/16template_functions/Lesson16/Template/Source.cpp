#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

template<typename T1, typename T2>

auto Print(T1 a, T2 b) -> decltype(a+b)
{
	auto c = a + b;
	return c;
}

//T sum(T a, T b)
//{
//	return a + b;
//}
//
//struct A
//{
//	int a;
//};

int main()
{
	setlocale(LC_ALL, "Russian");

	/*A a = {2};
	A b;

	b = sum<A>(a, a) << endl;
	cout << b.a << endl;

	string str = "Hello";

	cout << sum(str, (string)" Olgushka");*/

	cout << Print(12.3, 3.4);

	_getch();
	return 0;
}