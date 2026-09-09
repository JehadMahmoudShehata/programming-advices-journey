#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"


class clsWithdrawScreen:protected clsScreen
{
private:

    static void _PrintClient(const clsBankClient &Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.GetFullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nPin Code    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

	static void ShowWithdrawScreen()
	{

        _DrawScreenHeader("\t   Withdraw Screen ");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount <= 0 || Amount > Client1.GetAccountBalance())
        {
            if (Amount <= 0)
                cout << "\nInvalid amount! Please enter a positive number: ";
            else
                cout << "\nCannot withdraw, Insufficient Balance! Exceeds balance of ["
                << Client1.GetAccountBalance() << "]. Enter another amount: ";

            Amount = clsInputValidate::ReadDblNumber();
        }

        cout << "\nAre you sure you want to perform this transaction? Y/N ";
        char Answer = clsInputValidate::ReadChar();
        //cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount Withdrawn Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.GetAccountBalance() << endl;
            }
            else
            {
                cout << "\nCannot withdraw, Insufficient Balance!\n";
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

	}

};

