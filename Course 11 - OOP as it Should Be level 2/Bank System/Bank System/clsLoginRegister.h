#pragma once
#include"clsScreen.h"
#include<iostream>
#include<iomanip>
#include"clsUser.h"



using namespace std;


class clsLoginRegister:protected clsScreen
{

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateAndTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.PassWord;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;

    }


public:

	static void ShowLoginRegister()
	{

        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

		system("cls");
		vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecord = clsUser::GetLoginRegisterList();
		string Title = " Login Register List Screen";
		string Subtitle = "\t ( " + to_string(vLoginRegisterRecord.size()) + " ) Record(s).";
		_DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.empty())
            cout << "\t\t\t\tNo Users Available In the System!\n";
        else

            for (const clsUser::stLoginRegisterRecord & Record : vLoginRegisterRecord)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}

};

