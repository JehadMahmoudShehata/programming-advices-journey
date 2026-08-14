#pragma once
#include <iostream>
#include "clsDate.h"
#include <string>
#include"clsUtility.h"

using namespace std;


class clsInputValidate
{

public:

	clsInputValidate()
	{
	}

	static bool IsNumberBetween(int Numb,  int From,  int To)
	{
		if (From > To)
		{
			clsUtility::Swap(From, To);
			
		}
		return ((Numb >= From) && (Numb <= To));
	}

	static bool IsNumberBetween(double Numb, double From,  double To)
	{
		if (From > To)
		{
			clsUtility::Swap(From, To);

		}
		return ((Numb >= From) && (Numb <= To));
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		 // return (clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom))
		 // && (clsDate::IsDate1BeforeDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo));
			
		if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
		{
			clsDate::SwapDates(DateTo, DateFrom);

		}

		return !(clsDate::IsDate1AfterDate2(Date, DateTo)) && !(clsDate::IsDate1BeforeDate2(Date, DateFrom));

	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter Again : \n")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
		
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is NOT within range ,enter again :\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number ,From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		
		return Number;

	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter Again : \n")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;

	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is NOT within range ,enter again :\n")
	{
		double Number = ReadDblNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}


};

