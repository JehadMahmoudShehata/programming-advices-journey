#pragma once
#include"clsScreen.h"
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"

using namespace std;

class clsTransferLogScreen:protected clsScreen
{
private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateAndTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccount;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccount;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.SourceBalance;
		cout << "| " << setw(10) << left << TransferLogRecord.DestinationBalance;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;

	}

public:

	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord>vTransferLogRecord = clsBankClient::GetTransFerLogList();
		string Title = " Transfer Log List Screen";
		string Subtitle = "\t ( " + to_string(vTransferLogRecord.size()) + " ) Record(s).";
		_DrawScreenHeader(Title, Subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "S.Acc";
		cout << "| " << left << setw(8) << "D.Acc";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferLogRecord.empty())
			cout << "\t\t\t\tNo Users Available In the System!\n";

		else

			for (const clsBankClient::stTransferLogRecord& Record : vTransferLogRecord)
			{

				_PrintTransferLogRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

