#pragma once
#include <iostream>
#include<string>
#include <cstdlib> 
#include <ctime> 
#include "clsDate.h"

using namespace std;

class clsUtility
{


public:

	clsUtility()
	{

	}

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, MixChars = 5 };

	//===================================
	//          Generates 
	//===================================

	static void Srand()
	{
		srand((unsigned)time(NULL));

	}

	static int RandomNumber(int From, int To)
	{
		int RandNum = rand() % (To - From + 1) + From;

		return RandNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}

		case enCharType::MixChars:
			return char(RandomNumber(65, 122));
			break;

		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
		}
	}

	//===================================
	//          Swaping 
	//===================================

	static void Swap(int& A, int& B)
	{
		int Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(double& A, double& B)
	{
		double Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& A, string& B)
	{
		string Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	//===================================
	//           Array
	//===================================

	static void ShuffleArray(int arr[], int arrLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[], int arrLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From, int To)
	{
		for (short i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}

	static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType CharType, short WordLength)
	{
		for (short i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, WordLength);
	}

	static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType CharType)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(CharType);
		}
	}

	//===================================
	//           Tabs
	//===================================

	static string Tabs(short NumberOfTabs)
	{
		return string(NumberOfTabs, '\t');
	}

	//===================================
	//    EncryptText & DecryptionText
	//===================================

	static string EncryptText(string Text, const short& EncryptionKey)
	{

		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;

	}

	static string DecryptionText(string Text, const short& EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}


};



