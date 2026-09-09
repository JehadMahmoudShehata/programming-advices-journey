#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrencies.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRate : protected clsScreen
{
private:

    static string _ReadCurrencyCode()
    {
        cout << "\nPlease Enter Currency Code: ";
        return clsInputValidate::ReadString();
    }

    static clsCurrencies _GetCurrency(string Answer)
    {
        return clsCurrencies::FindByCode(Answer);
    }

    static void _PrintCurrencyCard(const clsCurrencies& Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n________________________________\n";
        cout << "\nCountry      : " << Currency.GetCountry();
        cout << "\nCode         : " << Currency.GetCurrencyCode();
        cout << "\nName         : " << Currency.GetCurrencyName();
        cout << "\nRate(1$) =   : " << Currency.GetRate();
        cout << "\n________________________________\n\n";
    }

    static float _ReadNewRate()
    {
        cout << "\n\nUpdate Currency Rate:";
        cout << "\n____________________\n";
        cout << "\nEnter New Rate: ";
        return clsInputValidate::ReadFloatNumber();
    }

    static bool _UpdateRateAnswer()
    {
        cout << "\nAre You Sure You Want To Update The Rate Of This Currency Y/N? ";
        char Answer = clsInputValidate::ReadChar();
        if (toupper(Answer) == 'Y')
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

public:

    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Screen");
        clsCurrencies Currency = _GetCurrency(_ReadCurrencyCode());

        while (Currency.IsEmpty())
        {
            cout << "\nCurrency is not found, choose another one: ";
            Currency = _GetCurrency(_ReadCurrencyCode());
        }

        _PrintCurrencyCard(Currency);
        if (_UpdateRateAnswer())
        {
           
            Currency.UpdateRate(_ReadNewRate());
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrencyCard(Currency);
        }
        else
        {
            cout << "\nFailed to update.\n";
        }
    }

};

