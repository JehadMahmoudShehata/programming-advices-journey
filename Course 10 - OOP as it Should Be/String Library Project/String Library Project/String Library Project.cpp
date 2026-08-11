#include <iostream>
#include "clsString.h"

using namespace std;

int main()

{
    clsString String1;
    clsString String2("Jehad");

    String1.Value = "Jehad Mahmoud";

    cout << "String1 = " << String1.Value << endl;
    cout << "String2 = " << String2.Value << endl;



    cout << "Number of words: " << String1.CountWords() << endl;
    cout << "Number of words: " << String1.CountWords("Fadi ahmed rateb omer") << endl;
    cout << "Number of words: " <<clsString::CountWords("Jehad Mahmoud Shehata Ali") << endl;



    clsString String3("hi how are you?");
    cout << "String 3 = " << String3.Value << endl;
    cout << "String Length = " << String3.Length() << endl;


    cout << "\nString After Upper First Letter Of Each Word:\n";
    String3.UpperFirstLetterOfEachWord();
    cout << String3.Value << endl;



    cout << "\nString After Lower First Letter Of Each Word:\n";
    String3.LowerFirstLetterOfEachWord();
    cout << String3.Value << endl;



    cout << "\nString After Upper All String:\n";
    String3.UpperAllString();
    cout << String3.Value << endl;

    

    cout << "\nString After Lower All String:\n";
    String3.LowerAllString();
    cout << String3.Value << endl;

    

    cout << "After inverting a : " << clsString::InvertLetterCase('a') << endl;



    cout << "\nString After Invert All Letter:\n";
    String3.Value = "AbCdEfg";
    String3.InvertAllLettersCase();
    cout << String3.Value << endl;
    String3.InvertAllLettersCase();
    cout << String3.Value << endl;

    

    cout << "Capital Letters count : " << clsString::CountLetters("Jehad Mahmoud Shehata", clsString::CapitalLetters) << endl << endl;
    String3.Value = "Welcome to Egypt";
    cout << String3.Value << endl;
    cout << "Capital Letters count :" << String3.CountCapitalLetters() << endl;




    cout << "Small Letters count :" << String3.CountSmallLetters() << endl;


    cout << "vowels count :" << String3.CountVowels() << endl;

    

    cout << "letter E count :" << String3.CountSpecificLetter('E', false) << endl;

    

    cout << "is letter u vowel? " << clsString::IsVowel('u')  << endl;


    cout << "Words Count : " << String3.CountWords() << endl;



    vector<string> vString;
    vString = String3.Split(" ");
    cout << "\nTokens = " << vString.size() << endl;
    for (string& s : vString)
    {
        cout << s << endl;
    }




    String3.Value = "    Jehad Mahmoud Shehata     ";
    cout << "\nString     = " << String3.Value;


    String3.Value = "    Jehad Mahmoud Shehata     ";
    String3.TrimLeft();
    cout << "\n\nTrim Left  = " << String3.Value;


    String3.Value = "    Jehad Mahmoud Shehata     ";
    String3.TrimRight();
    cout << "\nTrim Right = " << String3.Value;

    

    String3.Value = "    Jehad Mahmoud Shehata     ";
    String3.Trim();
    cout << "\nTrim       = " << String3.Value;

    

    
    vector<string> vString1 = { "Mohammed","Faid","Ali","Maher" };
    cout << "\n\nJoin String From Vector: \n";
    cout << clsString::JoinString(vString1, " ");





    string arrString[] = { "Mohammed","Faid","Ali","Maher" };
    cout << "\n\nJoin String From array: \n";
    cout << clsString::JoinString(arrString, 4, " ");



    String3.Value = "Jehad Mahmoud Shehata";
    cout << "\n\nString     = " << String3.Value;

    String3.ReverseWordsInString();
    cout << "\nReverse Words : " << String3.Value << endl;


    
    String3.Value = "Jehad Mahmoud Shehata";
    cout << "\nReplace : " << String3.ReplaceWord("Mahmoud", "Ali") << endl;

    

    String3.Value = "This is: a simple text, with punctuations.";
    cout << "\n\nString     = " << String3.Value;


    String3.RemovePunctuationsFromString(); cout << "\nRemove Punctuations : " << String3.Value
        << endl;

    system("pause>0");
    return 0;
};

