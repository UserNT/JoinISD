#include<iostream>
#include<conio.h>

using namespace std;
//определяет произведение матриц произвольного размера
int main()
{
	setlocale(LC_ALL, "Russian");

	int temp = 0;
	/*
	int A[S][S];
	int B[S][S];
	*/

	int row1, column1row2, column2;


	cout << "Умножение матриц определено для двух матриц у которых\n"
		<< "кол-во столбцов первой матрицы равно кол-ву строк второй.\n\n";

	cout << "Введите кол-во строк и столбцов первой матрици: ";
	cin >> row1 >> column1row2;
	int** arr1 = new int*[row1];
	for (int i(0); i < row1; i++)
		arr1[i] = new int[column1row2];

	cout << "Введите кол-во столбцов второй матрици: ";
	cin >> column2;
	int** arr2 = new int*[column1row2];
	for (int i(0); i < column1row2; i++)
		arr2[i] = new int[column2];

	int** result = new int*[row1];
	for (int i(0); i < row1; i++)
		result[i] = new int[column2];


	cout << "Введите элементы первой матрици \n";
	for (int i(0); i < row1; i++)
		for (int j(0); j < column1row2; j++)
		{
			cout << "a[" << i << "]" << "[" << j << "] = ";
			cin >> arr1[i][j];
		}

	cout << "Введите элементы второй матрици \n";
	for (int i(0); i < column1row2; i++)
		for (int j(0); j < column2; j++)
		{
			cout << "b[" << i << "]" << "[" << j << "] = ";
			cin >> arr2[i][j];
		}


	//Произведение матриц
	for (int i(0); i < row1; i++)
		for (int j(0); j < column2; j++)
		{
			for (int k(0); k < column1row2; k++)
				temp += arr1[i][k] * arr2[k][j];
			result[i][j] = temp;
			temp = 0;
		}

	for (int i(0); i < row1; i++)
		delete [] arr1[i];
	delete[] arr1;

	for (int i(0); i < column1row2; i++)
		delete[] arr2[i];
	delete[] arr2;

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
	for (int i(0); i < row1; i++)
	{
		for (int j(0); j < column2; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	for (int i(0); i < row1; i++)
		delete[] result[i];
	delete[] result;

	_getch();
	return 0;
}