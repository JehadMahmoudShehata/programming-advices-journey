#pragma once
#include "clsScreen.h"
#include<iostream>
#include<iomanip>
#include"clsCurrencies.h"



class clsCurrenciesScreen:protected clsScreen
{

private:

	static void _PrintCurrenciesList(const clsCurrencies& Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetCountry();
		cout << "| " << setw(8) << left << Currency.GetCurrencyCode();
		cout << "| " << setw(45) << left << Currency.GetCurrencyName();
		cout << "| " << setw(10) << left << Currency.GetRate();
	
	}


public:

	static void ShowListCurrenciesScreen()
	{
		system("cls");

		string Titel = "   Currencies List  Screen ";

		vector<clsCurrencies>vCurrencies = clsCurrencies::GetCurrenciesList();
		string SubTitle = "\t ( " + to_string(vCurrencies.size()) + " ) Currencies";
		
		_DrawScreenHeader(Titel, SubTitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrencies.empty())
		{
			cout << "\t\t\t\tNo Currencies Available In the System!";
		}

		else
		{
			for (const clsCurrencies& Currency : vCurrencies)
			{

				_PrintCurrenciesList(Currency);
				cout << endl;
			}

			cout << setw(8) << left << "" << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

		}



	}

};

