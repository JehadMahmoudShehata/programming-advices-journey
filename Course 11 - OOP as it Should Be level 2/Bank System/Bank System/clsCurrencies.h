#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h"

using namespace std;


class clsCurrencies
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrencies _ConvertLinetoCurrencyObject(string& Line, string Seperator = "#//#")
	{

		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrencies(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			stod(vCurrencyData[3]));

	}

	static vector<clsCurrencies>_LoadCurrenciesDataFromFile()
	{
		vector <clsCurrencies>vCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;
			while (getline(MyFile, Line))
			{

				clsCurrencies currency = _ConvertLinetoCurrencyObject(Line);

				vCurrency.push_back(currency);
			}

			MyFile.close();

		}

		return vCurrency;
	}

	static string _ConverCurrencyObjectToLine(clsCurrencies& Currency, string Seperator = "#//#")
	{
		
		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.GetCountry() + Seperator;
		stCurrencyRecord += Currency.GetCurrencyCode() + Seperator;
		stCurrencyRecord += Currency.GetCurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.GetRate());

		return stCurrencyRecord;

	}

	static void _SaveCurrencyDataToFile(vector <clsCurrencies> &vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrencies &C : vCurrencys)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector<clsCurrencies>_vCurrencies;
		_vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrencies& C : _vCurrencies)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this;
				// Alternative Approach: Handles edge cases where multiple countries share the same currency (e.g., EUR, XOF).
				//break;
			}
		}

		_SaveCurrencyDataToFile(_vCurrencies);		

	}

	static clsCurrencies _GetEmptyCurrencyObject()
	{
		return clsCurrencies(enMode::EmptyMode, "", "", "", 0);
	}


public:

	clsCurrencies(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	static vector <clsCurrencies> GetAllUSDRates()
	{

		return _LoadCurrenciesDataFromFile();

	}

	bool IsEmpty() const
	{
		return (_Mode == enMode::EmptyMode);
	}

	//Read-Only Mode
	string GetCountry()const
	{
		return _Country;
	}

	string GetCurrencyCode()const
	{
		return _CurrencyCode;
	}

	string GetCurrencyName()const
	{
		return _CurrencyName;
	}

    void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float GetRate()const
	{
		return _Rate;
	}

	static  clsCurrencies FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrencies Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static  clsCurrencies FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrencies Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.GetCountry()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode)
	{

		clsCurrencies C1 = clsCurrencies::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector <clsCurrencies> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	//1. My Code:

	static float Convert(clsCurrencies Currency1, clsCurrencies Currency2, float Amount)
	{
		float AmountinUSD = (Amount / Currency1.GetRate());

		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountinUSD;
		}

		else
		{
			return (Currency2.GetRate() * AmountinUSD);
		}

	}

	//2. Instructor Implementation:

	/*float ConvertToUSD(float Amount)
	{

		return (float)(Amount / GetRate());

	}

	float ConvertToOtherCurrency(float Amount, clsCurrencies Currency2)
	{

		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.GetRate());

	}*/

};

