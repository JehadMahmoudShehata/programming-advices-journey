#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsUser.h"
#include"clsDate.h"



using namespace std;

class clsBankClient:public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	struct stTransferLogRecord;

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stof(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(const clsBankClient & Client , string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	static vector <clsBankClient>_LoadClientsDataFromFile()
	{
		vector<clsBankClient>vClient;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				
				vClient.push_back(Client);
			}

			MyFile.close();

		}

		return vClient;
	}

	/*static void _SaveClientsDataToFile(const vector <clsBankClient>& vClient)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (const clsBankClient& C : vClient)
			{
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}*/

	static void _SaveClientsDataToFile(const vector <clsBankClient>& vClient)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (const clsBankClient& C : vClient)
			{
				if (C._MarkedForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();

		}

	}

	void _Update() const
	{
		vector <clsBankClient>_vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;

			}
		}

		_SaveClientsDataToFile(_vClient);
	}

	void _AddDataLineToFile(const string &stDataLine)const
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew()const
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	 string _PrepareTransferLogRecord(clsBankClient&DestinationClient , const double& Amount,const string& PerformedByUserName ,string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord = clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += _AccountNumber + Seperator;
		TransferLogRecord += DestinationClient._AccountNumber + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(_AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient._AccountBalance) + Seperator;
		TransferLogRecord += PerformedByUserName;


		return TransferLogRecord;
	}

	 void _RegisterTransferLog(clsBankClient& DestinationClient, const double& Amount , const string & PerformedByUserName)
	 {

		 fstream MyFile;
		 string LogsInfo = _PrepareTransferLogRecord(DestinationClient, Amount, PerformedByUserName);

		 MyFile.open("TransferLog.txt", ios::out | ios::app);


		 if (MyFile.is_open())
		 {

			 MyFile << LogsInfo << endl;

			 MyFile.close();
		 }
	 }

	 static stTransferLogRecord _ConvertTransferLogLineToRecord(const string& Line, string Seperator = "#//#")
	 {
		 stTransferLogRecord TransferLogRecord;

		 vector<string>vTransferLogRecord = clsString::Split(Line, Seperator);

		 TransferLogRecord.DateAndTime = vTransferLogRecord[0];
		 TransferLogRecord.SourceAccount = vTransferLogRecord[1];
		 TransferLogRecord.DestinationAccount = vTransferLogRecord[2];
		 TransferLogRecord.Amount = stod(vTransferLogRecord[3]);
		 TransferLogRecord.SourceBalance = stod(vTransferLogRecord[4]);
		 TransferLogRecord.DestinationBalance = stod(vTransferLogRecord[5]);
		 TransferLogRecord.UserName = vTransferLogRecord[6];

		 return TransferLogRecord;

	 }


public:

	clsBankClient(enMode Mode, const string &FirstName, const string &LastName,const string &Email, const string &Phone, const string &AccountNumber,const string &PinCode,const float &AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferLogRecord 
	{
		string DateAndTime;
		string SourceAccount;
		string DestinationAccount;
		double Amount;
		double SourceBalance;
		double DestinationBalance;
		string UserName;

	};

	bool IsEmpty()const
	{
		return (_Mode == enMode::EmptyMode);
	}

	//Property Get Read-Only

	string GetAccountNumber()const
	{
		return _AccountNumber;
	}

	//Property Set

	void SetPinCode(const string& PinCode)
	{
		_PinCode = PinCode;
	}

	//Property Get

	string GetPinCode() const
	{
		return _PinCode;
	}

	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	//Property Set

	void SetAccountBalance(const float& AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	//Property Get

	float GetAccountBalance() const
	{
		return _AccountBalance;
	}

	_declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;


	//No UI Related Code Inside Object Code 
	/*void Print() const
	{
		cout << "\nClient Card :";
		cout << "\n___________________";
		cout << "\nFirstName   : " << GetFirstName();
		cout << "\nLastName    : " << GetLastName();
		cout << "\nFull Name   : " << GetFullName();
		cout << "\nEmail       : " << GetEmail();
		cout << "\nPhone       : " << GetPhone();
		cout << "\nAcc. Number : " << GetAccountNumber();
		cout << "\nPassword    : " << GetPinCode();
		cout << "\nBalance     : " << GetAccountBalance();
		cout << "\n___________________\n";

	}*/

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber , string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode()==PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(GetAccountNumber()))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}

			else

			_AddNew();
			_Mode = enMode::UpdateMode;
			return enSaveResults::svSucceeded;
		}

		}

	}

    static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return(!Client.IsEmpty());

	}

	bool Delete() 
	{
		vector<clsBankClient>_vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(_vClient);
		*this = _GetEmptyClientObject();

		return true;

	}

	static vector <clsBankClient> GetClientsList() 
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();

		double TotalBalance = 0;

		for (const clsBankClient &Client : vClients)
		{
			TotalBalance+= Client.GetAccountBalance();

		}

		return TotalBalance;
	}

	void Deposit(const double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(const double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else 
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
		
	}

	bool Transfer(const double &Amount, clsBankClient &DestinationClient ,const string &PerformedByUserName)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(DestinationClient, Amount, PerformedByUserName);

		return true;

	}

	static vector<stTransferLogRecord>GetTransFerLogList()
	{
		vector<stTransferLogRecord>vTransferLogRecord;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;
			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile, Line))
			{

				TransferLogRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferLogRecord);
			}

			MyFile.close();

		}

		return vTransferLogRecord;
	}
    

};

