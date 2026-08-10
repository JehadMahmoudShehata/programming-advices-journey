#include <iostream>
#include "clsString.h"

using namespace std;


int main()
{
	clsString String1;
	clsString String2("Jehad");


	String1.Value = "Mahmoud";

	cout << "\nPrint Value Of Object:\n";


	cout << "String 1 : " << String1.Value << endl;
	cout << "String 2 : " << String2.Value << endl;
	
	cout << "\n\nString Length:\n";

	cout << "String 1 : " << String1.Length() << endl;
	cout << "String 2 : " << String2.Length() << endl;


	cout << "\nNumber Of Words:\n";
	cout << "Number Of Words : " << String1.CountWords() << endl;
	cout << "Number Of Words : " << String2.CountWords() << endl;
	cout << "Number Of Words : " << String1.CountWords("Yara Mahmoud Shehata") << endl;
	cout << "Number Of Words : " << String2.CountWords("Jehad Mahmoud Shehata Ali") << endl;
	cout << "Number Of Words : " << clsString::CountWords("Maria Ali") << endl;

	cout << "\nFirst Letter Of Each Word";
	String1.PrintFirstLetterOfEachWord();
	cout << "\n";
	String2.PrintFirstLetterOfEachWord();
	cout << "\n";
	clsString::PrintFirstLetterOfEachWord("Maria Ali");



	cout << "\nString After Upper First Letter Of Each Word:\n";
	String1.UpperFirstLetterOfEachWord();
	cout << String1.Value << endl;
    String2.UpperFirstLetterOfEachWord();
	cout << String2.Value << endl;
	cout << clsString::UpperFirstLetterOfEachWord("maria ali") << endl;


	cout << "\nString After Lower First Letter Of Each Word:\n";
	String1.LowerFirstLetterOfEachWord();
	cout << String1.Value << endl;
	String2.LowerFirstLetterOfEachWord();
	cout << String2.Value << endl;
	cout << clsString::LowerFirstLetterOfEachWord("Maria Ali") << endl;

	cout << "\nString After Upper All String:\n";
    String1.UpperAllString();
	cout << String1.Value << endl;
	String2.UpperAllString();
	cout << String2.Value << endl;
	cout << clsString::UpperAllString("Maria Ali") << endl;



	cout << "\nString After Lower All String:\n";
    String1.LowerAllString();
	cout << String1.Value << endl;
    String2.LowerAllString();
	cout << String2.Value << endl;
	cout << clsString::LowerAllString("Maria Ali") << endl;


	cout << "\nString After Remove Punctuations:\n";
	cout << clsString::RemovePunctuationsFromString("Maria <? Ali") << endl;


	cout << "\nCharacter After Invert Letter Case:\n";
	cout << clsString::InvertLetterCase('A');

	cout << "\nString After Invert All Letter:\n";
	String1.InvertAllLettersCase();
	cout << String1.Value << endl;
	String2.InvertAllLettersCase();
	cout << String2.Value << endl;
	cout << clsString::InvertAllLettersCase("Maria Ali") << endl;

	cout << "Count Letters" << endl;
	cout << clsString::CountLetters("Jehad Mahmoud") << endl;

	cout << "Count Capital Letters" << endl;
	cout << String1.CountCapitalLetters() << endl;
	cout << String2.CountCapitalLetters() << endl;
	cout << clsString::CountCapitalLetters("JeHaD Mahmoud") << endl;

	cout << "Count Small Letters" << endl;
	cout << String1.CountSmallLetters() << endl;
	cout << String2.CountSmallLetters() << endl;
	cout << clsString::CountSmallLetters("JeHaD Mahmoud") << endl;

	cout << "Count Specific Letter" << endl;
	cout << String1.CountSpecificLetter(String1.Value,'A') << endl;
	cout << String2.CountSpecificLetter(String2.Value,'m') << endl;
	cout << clsString::CountSpecificLetter("Jehad", 'a') << endl;

	cout << "Is Vowel True = 1 , False = 0 " << endl;
	cout << clsString::IsVowel('a') << endl;

	cout << "Count Vowels" << endl;
	cout << String1.CountVowels() << endl;
	cout << String2.CountVowels() << endl;
	cout << clsString::CountVowels("Hello , Iam Jahooda\n");

	cout << "\nVector Split:" << endl;
	vector<string>vString = clsString::Split("String1,Value", ",");
	for (string& sWord : vString)
	{
		cout << sWord << endl;
	}

	vString = String1.Split(" ");
	for (string& sWord : vString)
	{
		cout << sWord << endl;
	}

	cout << "\nTrim Left:" << endl;
	clsString String3("    Jehad              ");
	String3.TrimLeft();
	cout << String3.Value << endl;
	cout << clsString::TrimLeft("  Mahmoud         ") << endl;
	

	cout << "\nTrim Right:" << endl;
	String3.TrimRight();
	cout << String3.Value << endl;
	cout << clsString::TrimRight("  Mahmoud         ") << endl;

	cout << "\nTrim :" << endl;
	String3.Trim();
	cout << String3.Value << endl;
	cout << clsString::Trim("  Mahmoud         ") << endl;

	cout << "\n Vector Join String:" << endl;
	vector<string>vString1 = { "ali","amr","omar" };
	cout << clsString::JoinString(vString1, " , ");
	cout << endl << endl;

	cout << "\n Dynamic Array[] Join String:" << endl;
	string arr[] = { "ali","amr","omar" , "saad" };
	cout << clsString::JoinString(arr, 4, " , ");
	cout << endl << endl;

	cout << "\n Reverse Words In String:" << endl;
	String1.ReverseWordsInString();
	cout << String1.Value;
	cout << endl;
	String2.ReverseWordsInString();
	cout << String2.Value;
	cout << endl;
	String3.ReverseWordsInString();
	cout << String3.Value;
	cout << endl;
	cout << clsString::ReverseWordsInString("Hello , Iam Jehad") << endl;
	
	cout << "\n Replace Word:" << endl;
	cout << clsString::ReplaceWord("Jehad Mahmoud", "Jehad", "Mahmoud");
	cout << endl;
	cout << String1.ReplaceWord("MAHMOUD", "Jehad");


	system("pause>0");
	return 0;


}