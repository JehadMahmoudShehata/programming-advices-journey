#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include"clsScreen.h"
#include"clsCurrenciesScreen.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyClaculater.h"

using namespace std;

class clsCurrencyMainScreen:protected clsScreen
{
private:

    enum enCurrenciesMainMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculater = 4, eMainMenue = 5
    };

    static short _ReadCurrencyMainScreenOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadshortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToCurrencyMainScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Main Menue Screen...\n";
        system("pause>0");
        ShowCurrenciesMain();
    }

    static void _ShowListCurrenciesScreen()
    {
        //cout << "\nList Curriencies List Screen Will Be Here\n";
        clsCurrenciesScreen::ShowListCurrenciesScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nList Find Currency Screen Will Be Here\n";
        clsFindCurrency::ShowFindCurencyScreen(); 
    }

    static void _ShowUpdateRateScreen()
    {
       //cout << "\nUpdate Rate Screen Will Be Here\n";
        clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculaterScreen()
    {
       //cout << "\nCurrency Calculater Screen Will Be Here\n";
        clsCurrencyCalculater::ShowCurrencyCalculaterScreen();
    }

    static void _PerfromsCurrencyMainScreenOption(const enCurrenciesMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyMainScreen();
            break;
        }
        case enCurrenciesMainMenueOptions::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMainScreen();
            break;

        case enCurrenciesMainMenueOptions::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyMainScreen();
            break;

        case enCurrenciesMainMenueOptions::eCurrencyCalculater:
            system("cls");
            _ShowCurrencyCalculaterScreen();
            _GoBackToCurrencyMainScreen();
            break;

        case enCurrenciesMainMenueOptions::eMainMenue:
           
            break;
        }

    }


public:

	static void ShowCurrenciesMain()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("   Currency Exchange Main Screen ");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculater.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromsCurrencyMainScreenOption((enCurrenciesMainMenueOptions)_ReadCurrencyMainScreenOption());
	}


};

