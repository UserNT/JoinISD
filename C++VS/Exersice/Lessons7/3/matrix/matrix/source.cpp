#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;
//определяет произведение матриц 3 на 3
int main()
{
	setlocale(LC_ALL, "Russian");
	
	const int S = 3;
	int temp = 0;
	int A[S][S];
	int B[S][S];
	int C[S][S];
	
	cout << "Введите элементы первой матрици \n";
	for(int i(0); i < S; i++)	
		for(int j(0); j < S; j++)
		{
			cout << "a[" << i << "]" << "[" << j << "] = ";
			cin >> A[i][j];
		}	
	
	cout << "Введите элементы второй матрици \n";
	for(int i(0); i < S; i++)	
		for(int j(0); j < S; j++)
		{
			cout << "b[" << i << "]" << "[" << j << "] = ";
			cin >> B[i][j];
		}


	//Произведение матриц
	for(int i(0); i < S; i++)
		for(int j(0); j < S; j++)
		{
			for(int k(0); k < S; k++)
				temp += A[i][k]*B[k][j];
			C[i][j] = temp;
			temp = 0;
		}	

	/*
	C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[0][2]*B[2][0];
	C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1] + A[0][2]*B[2][1];
	C[0][2] = A[0][0]*B[0][2] + A[0][1]*B[1][2] + A[0][2]*B[2][2];

	C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0] + A[1][2]*B[2][0];
	C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1] + A[1][2]*B[2][1];
	C[1][2] = A[1][0]*B[0][2] + A[1][1]*B[1][2] + A[1][2]*B[2][2];

	C[2][0] = A[2][0]*B[0][0] + A[2][1]*B[1][0] + A[2][2]*B[2][0];
	C[2][1] = A[2][0]*B[0][1] + A[2][1]*B[1][1] + A[2][2]*B[2][1];
	C[2][2] = A[2][0]*B[0][2] + A[2][1]*B[1][2] + A[2][2]*B[2][2];
	*/
	cout << "Результат равен: \n";
	for(int i(0); i < S; i++)	
	{	
		for(int j(0); j < S; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	
	_getch();
	return 0;
}