#include <iostream>
#include "clsInputValidate.h"

using namespace std;

int main()
{
	cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
	cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(12, 8, 2026), clsDate(18, 8, 2026)) << endl;
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(18, 8, 2026), clsDate(12, 8, 2026)) << endl;


	cout << "Please Enter a Number: \n";
	int x = clsInputValidate::ReadIntNumber("Invalid Number ,Enter Again: \n");
	cout << "x = " << x << endl;

	cout << "Please Enter a Number between 1 and 5: \n";
	int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is NOT within range ,enter again :\n");
	cout << "y = " << y << endl;

	cout << "Please Enter a Double Number: \n";
	double a = clsInputValidate::ReadDblNumber("Invalid Number ,Enter Again: \n");
	cout << "a = " << a << endl;

	cout << "Please Enter a Double Number between 1 and 5: \n";
	double b = clsInputValidate::ReadDblNumberBetween(1, 5, "Number is NOT within range ,enter again :\n");
	cout << "y = " << b << endl;


	cout << clsInputValidate::IsValideDate(clsDate(35, 12, 2026)) << endl;

	system("pause>0");

	return  0;
}

