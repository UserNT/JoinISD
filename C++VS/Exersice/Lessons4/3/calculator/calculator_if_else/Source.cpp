#include<iostream>
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	setlocale(LC_ALL,"Russian");

	float a,b,result;
	char operation;

	cout << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << "�����������" << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << endl << endl;
	
	cout << "������� ��� ����� � �������� ������� ���������� ��������� : \n";
	cout << "������� ������ �����: ";
	cin >> a;
	cout << "������� ������ �����: ";
	cin >> b;
	cout << "������� ��������: ";
	cin >> operation;

	if(operation == '+')
		result = a + b;
	else if(operation == '-')	
		     result = a - b;
		 else if(operation == '*')
			      result = a * b;
			  else if(operation == '/')
				       result = a / b;
			        else{
					     cout << "�� ����� ������������ ��������!\n";
					     getch();
						 return -1;
					    }

		/*
		case '+': result = a+b; break;
		case '-': result = a-b; break;
		case '*': result = a*b; break;
		case '/': result = a/b; break;
		default : cout << "�� ����� ������������ ��������!"; break;
		*/
	
	cout << endl;
	
	cout << "��������� = " << result << endl;

	getch();
	return 0;
}