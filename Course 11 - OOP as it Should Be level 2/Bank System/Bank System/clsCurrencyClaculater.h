#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrencies.h"
#include "clsInputValidate.h"

using namespace std;


//1. My Code:
class clsCurrencyCalculater:protected clsScreen
{

private :

    static bool _ReadAnswer()
    {
        cout << "\nDo You Want To Perform Another Calculation  Y/N ? ";
        return (toupper(clsInputValidate::ReadChar()) == 'Y');

    }

    static string _ReadCurrencyCode()
    {
        return clsInputValidate::ReadString();
    }

    static float _ReadAmount()
    {
        cout << "\nEnter Amount To Exchange: ";
        return clsInputValidate::ReadFloatNumber();
    }

    static clsCurrencies _GetCurrency(string Answer)
    {
        return clsCurrencies::FindByCode(Answer);
    }

    static void _PrintCurrencyCard(const clsCurrencies& Currency)
    {
        cout << "\n________________________________\n";
        cout << "\nCountry      : " << Currency.GetCountry();
        cout << "\nCode         : " << Currency.GetCurrencyCode();
        cout << "\nName         : " << Currency.GetCurrencyName();
        cout << "\nRate(1$) =   : " << Currency.GetRate();
        cout << "\n________________________________\n\n";
    }

    static void _ConvertCurrency1ToCurrency2(const clsCurrencies &Currency1 , const clsCurrencies &Currency2 , float Amount )
    {

        float AmountInUSD = (Amount / Currency1.GetRate());

        if (Currency2.GetCurrencyCode() == "USD")
        {
            cout << "\nConvert From:";
            _PrintCurrencyCard(Currency1);
            cout << Amount << " " << Currency1.GetCurrencyCode() << " = " << " "
                << clsCurrencies::Convert(Currency1, Currency2, Amount) << " " << Currency2.GetCurrencyCode() << "\n\n";
        }
        else
        {
            cout << "\nConvert From:";
            _PrintCurrencyCard(Currency1);
            if (Currency1.GetCurrencyCode() != "USD")
            {
                cout << Amount << " " << Currency1.GetCurrencyCode() << " = " << " "
                    << AmountInUSD << " " << "USD" << "\n\n";
            }
            cout << "\nConverting From USD To:\n";
            cout << "\nConvert To:";
            _PrintCurrencyCard(Currency2);
            cout << Amount << " " << Currency1.GetCurrencyCode() << " = " << " "
                << clsCurrencies::Convert(Currency1, Currency2, Amount) << " " << Currency2.GetCurrencyCode() << "\n\n";
        }
    }

public:

	static void ShowCurrencyCalculaterScreen()
	{
        bool Continue = true;

        do {

            system("cls");
            _DrawScreenHeader("\t Currency Calculator Screen");

            cout << "\nPlease Enter Currency1 Code: \n";
            clsCurrencies Currency1 = _GetCurrency(_ReadCurrencyCode());

            while (Currency1.IsEmpty())
            {
                cout << "\nCurrency is not found, choose another one: ";
                Currency1 = _GetCurrency(_ReadCurrencyCode());
            }

            cout << "\nPlease Enter Currency2 Code: \n";
            clsCurrencies Currency2 = _GetCurrency(_ReadCurrencyCode());

            while (Currency2.IsEmpty())
            {
                cout << "\nCurrency is not found, choose another one: ";
                Currency2 = _GetCurrency(_ReadCurrencyCode());
            }

            _ConvertCurrency1ToCurrency2(Currency1, Currency2, _ReadAmount());
            Continue = _ReadAnswer();

        } while(Continue);

        
	}

};

//2. Instructor Implementation:

//class clsCurrencyCalculatorScreen :protected clsScreen
//{
//
//private:
//
//    static float _ReadAmount()
//    {
//
//        cout << "\nEnter Amount to Exchange: ";
//        float Amount = 0;
//        Amount = clsInputValidate::ReadFloatNumber();
//        return Amount;
//
//    }
//
//    static clsCurrency _GetCurrency(string Message)
//    {
//        string CurrencyCode;
//        cout << Message << endl;
//
//        CurrencyCode = clsInputValidate::ReadString();
//        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
//        {
//
//            cout << "\nCurrency is not found, choose another one: ";
//            CurrencyCode = clsInputValidate::ReadString();
//
//        }
//        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
//        return Currency;
//    }
//
//    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
//    {
//        cout << "\n" << Title << "\n";
//        cout << "_____________________________\n";
//        cout << "\nCountry       : " << Currency.Country();
//        cout << "\nCode          : " << Currency.CurrencyCode();
//        cout << "\nName          : " << Currency.CurrencyName();
//        cout << "\nRate(1$) =    : " << Currency.Rate();
//        cout << "\n_____________________________\n\n";
//
//    }
//
//    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
//    {
//        _PrintCurrencyCard(Currency1, "Convert From:");
//        float AmountInUSD = Currency1.ConvertToUSD(Amount);
//        cout << Amount << " " << Currency1.CurrencyCode()
//           << " = " << AmountInUSD << " USD\n";
//        if (Currency2.CurrencyCode() == "USD")
//        {
//            return;
//        }
//        cout << "\nConverting from USD to:\n";
//        _PrintCurrencyCard(Currency2, "To:");
//        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
//        cout << Amount << " " << Currency1.CurrencyCode()
//
//            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();
//    }
//
//
//public:
//
//    static void ShowCurrencyCalculatorScreen()
//    {
//        char Continue = 'y';
//
//        while (Continue == 'y' || Continue == 'Y')
//        {
//            system("cls");
//            _DrawScreenHeader("\tUpdate Currency Screen");
//
//            clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
//            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
//
//            float Amount = _ReadAmount();
//
//            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);
//
//            cout << "\n\nDo you want to perform another calculation? y/n ? ";
//            cin >> Continue;
//
//        }
//
//    }
//};
