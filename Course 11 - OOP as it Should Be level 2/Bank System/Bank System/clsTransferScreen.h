#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"


class clsTransferScreen:protected clsScreen
{

private:

	static void _PrintClientCard(const clsBankClient & Client)
	{
		cout << "\nClient Card:";
		cout << "\n_________________________________\n";
		cout << "\nFull Name    : " << Client.GetFullName();
		cout << "\nAcc Number   : " << Client.GetAccountNumber();
		cout << "\nBalanace     : " << Client.GetAccountBalance();
		cout << "\n_________________________________\n\n\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;

	}

	static double _ReadAmount(const clsBankClient &SourceClient)
	{
		double Amount = 0;
		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount <= 0 || Amount > SourceClient.AccountBalance)
		{
			if (Amount <= 0)
			{
				cout << "\nInvalid Amount! Enter an amount greater than 0: ";
			}

			else {

				cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			}

			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}


public :

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen ");
		cout << "\nPlease Enter Account Number to Transfer From: ";
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(SourceClient);

		cout << "\nPlease Enter Account Number To Transfer To: ";
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		while (DestinationClient.GetAccountNumber() == SourceClient.GetAccountNumber())
		{
				cout << "\nIt Is The Same Client!! , You Can NOT Transfer To The Same Client!! Enter Another One Exist: ";
				DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		}

		_PrintClientCard(DestinationClient);

		double TransferAmount = clsTransferScreen::_ReadAmount(SourceClient);
	
		char YesOrNo = 'n';
		cout << "\nAre You Sure You Want To Perform This Operation Y/N ?  ";
		cin >> YesOrNo;

		if (toupper(YesOrNo) == 'Y')
		{
			if (SourceClient.Transfer(TransferAmount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully!\n";
			}
			else
			{
				cout << "\nOops, Transfer Failed! Amount exceeds balance or invalid data.\n";
			}
			
		}

		else
		{
			cout << "\nOperation Cancelled!\n";
		}
		
		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);

		
		

	}

};

