#pragma once
#include "clsCurrencies.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include<iostream>

using namespace std;

// =======================================================================================
// My Implementation: Optimized Memory Usage, Input Validation, and Single Responsibility
// =======================================================================================

class clsFindCurrency : protected clsScreen
{
private:

	static short _ReadFindBy()
	{
		short Answer;
		cout << "\nFind By [1] Code Or [2] Country : ";
		Answer = clsInputValidate::ReadshortNumberBetween(1, 2, "Please Choose The Way You Want To Find Currency [1]Code Or [2]Country: ");

		return Answer;
	}
	
	static string _ReadCurrencyCode()
	{
		string Answer;
		cout << "\nPlease Enter Currency Code: ";
		Answer = clsInputValidate::ReadString();
		return Answer;
	}

	static string _ReadCountryName()
	{
		string Answer;
		cout << "\nPlease Enter Country Name : ";
		Answer = clsInputValidate::ReadString();
		return Answer;
	}

	static clsCurrencies _GetCurrency(short Answer)
	{
		if (Answer == 1)
		{
			return clsCurrencies::FindByCode(_ReadCurrencyCode());
		}

		if (Answer == 2)
		{
			return clsCurrencies::FindByCountry(_ReadCountryName());

		}

		
	}

	static void _PrintCurrencyCard(const clsCurrencies& Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n________________________________\n";
		cout << "\nCountry      : " << Currency.GetCountry();
		cout << "\nCode         : " << Currency.GetCurrencyCode();
		cout << "\nName         : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) =   : " << Currency.GetRate();
		cout << "\n________________________________\n\n\n";


	}


public:

	static void ShowFindCurencyScreen()
	{
		_DrawScreenHeader("  Find Currency Screen");

		clsCurrencies Currency = _GetCurrency(_ReadFindBy());

		if (Currency.IsEmpty())
		{
			cout << "\nSorry Currency Does NOT exist =( \n";
		}

		else 
		{
			cout << "\nCurrency Found =) \n";
			_PrintCurrencyCard(Currency);
		}


	}


};


 // ============================================================================
 //                 Doctor's Reference Implementation
 // ============================================================================

/*class clsFindCurrencyScreen :protected clsScreen
{

private:
	static void _PrintCurrency(clsCurrencies Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.GetCountry();
		cout << "\nCode       : " << Currency.GetCurrencyCode();
		cout << "\nName       : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) = : " << Currency.GetRate();

		cout << "\n_____________________________\n";

	}

	static void _ShowResults(clsCurrencies Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t  Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;

		cin >> Answer;

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrencies Currency = clsCurrencies::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrencies Currency = clsCurrencies::FindByCountry(Country);
			_ShowResults(Currency);
		}

	}

};*/



