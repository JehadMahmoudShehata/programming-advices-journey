#include <iostream>
#include "clsUtility.h"

using namespace std;

int main()
{
//===================================
//          Generates 
//===================================

	clsUtility::Srand();
	
	cout << clsUtility::RandomNumber(1, 10) << endl;
	cout << clsUtility::GetRandomCharacter(clsUtility::CapitalLetter) << endl;
	cout << clsUtility::GenerateWord(clsUtility::MixChars, 8) << endl;
	cout << clsUtility::GenerateKey(clsUtility::MixChars) << endl;
	clsUtility::GenerateKeys(10, clsUtility::MixChars);

	cout << "\n\n";

//===================================
// 	           Swaping 
//===================================

	//Swap Int
	int X = 10, Y = 20;
	//Before Swaping
	cout << X << "  " << Y << endl;
	//After Swaping
	clsUtility::Swap(X, Y);
	cout << X << "  " << Y << endl;

	//Swap double
	double A = 10.5, B = 20.3;
	//Before Swaping
	cout << A << "  " << B << endl;
	//After Swaping
	clsUtility::Swap(A, B);
	cout << A << "  " << B << endl;

	//Swap string
	string S1 = "Jehad", S2 = "Mahmoud";
	//Before Swaping
	cout << S1 << "  " << S2 << endl;
	//After Swaping
	clsUtility::Swap(S1, S2);
	cout << S1 << "  " << S2 << endl;

	//Swap Date
	clsDate Date1(1, 1, 2002), Date2(16, 10, 2002);
	//Before Swaping
	cout << Date1.DateToString() << "    " << Date2.DateToString() << endl;
	//After Swaping
	clsUtility::Swap(Date1, Date2);
	cout << Date1.DateToString() << "    " << Date2.DateToString() << endl;


//===================================
//           Array
//===================================

	//Int Array
	int Arr1[5] = { 1,2,3,4,5 };
	clsUtility::ShuffleArray(Arr1, 5);
	cout << "\nArray After Shuffle:\n";
	for (short i = 0; i < 5; i++)
	{
		cout << Arr1[i] << endl;
	}

	//String Array
	string Arr2[5] = { "Jehad","Mahmoud","Shehata","Ali","Sarah" };
	clsUtility::ShuffleArray(Arr2, 5);
	cout << "\nArray After Shuffle:\n";
	for (short i = 0; i < 5; i++)
	{
		cout << Arr2[i] << endl;
	}

	int Arr3[5];
	clsUtility::FillArrayWithRandomNumbers(Arr3, 5 , 20 , 50);
	cout << "\nArray After Fill:\n";
	for (short i = 0; i < 5; i++)
	{
		cout << Arr3[i] << endl;
	}


	string Arr4[5];
	clsUtility::FillArrayWithRandomWords(Arr4, 5, clsUtility::MixChars, 8);
	cout << "\nArray After Fill:\n";
	for (short i = 0; i < 5; i++)
	{
		cout << Arr4[i] << endl;
	}

	string Arr5[5];
	clsUtility::FillArrayWithRandomKeys(Arr5, 5, clsUtility::MixChars);
	cout << "\nArray After Filling Keys:\n";
	for (short i = 0; i < 5; i++)
	{
		cout << Arr5[i] << endl;
	}

//===================================
//           Tabs
//===================================

	cout << "Text1" << clsUtility::Tabs(5) << "Text2\n";

//===================================
//     EncryptText & DecryptionText
//===================================

	const short EncryptionKey = 2;
	string TextAfterEncryption, TextAfterDecryption;
	string Text = "Jehad Mahmoud";
	TextAfterEncryption = clsUtility::EncryptText(Text, EncryptionKey);
	//TextAfterDecryption = clsUtility::DecryptionText(Text, EncryptionKey);
	TextAfterDecryption = clsUtility::DecryptionText(TextAfterEncryption, EncryptionKey);

	cout << "Text Before Encryption: " << Text << endl;
	cout << "Text After Encryption: " << TextAfterEncryption << endl;
	cout << "Text After Decryption: " << TextAfterDecryption << endl;

	system("pause>0");

	return 0;

   
}

