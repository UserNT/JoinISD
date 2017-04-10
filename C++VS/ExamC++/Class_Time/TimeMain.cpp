#include <iostream>
#include "Time.h"
#include <stdlib.h>

using namespace std;
using namespace mayTime;

int main()
{
	TTime a(18, 49, 30);
	a.IncrementMinute(120);
	a.PrintTime();

	cout << "\n\n" << "For exit press any key...\n";
	cin.get();

	return 0;
}