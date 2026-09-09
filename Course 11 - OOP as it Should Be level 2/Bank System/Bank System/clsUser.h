#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include"ClsDate.h"
#include <vector>
#include <fstream>
#include "clsUtility.h"


using namespace std;
class clsUser : public clsPerson
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;

    struct stLoginRegisterRecord;

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4],clsUtility::DecryptionText(vUserData[5]), stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(const clsUser &User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.GetFirstName() + Seperator;
        UserRecord += User.GetLastName() + Seperator;
        UserRecord += User.GetEmail() + Seperator;
        UserRecord += User.GetPhone() + Seperator;
        UserRecord += User.GetUserName() + Seperator;
        UserRecord += clsUtility::EncryptText(User.GetPassword()) + Seperator;
        UserRecord += to_string(User.GetPermissions());

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }    

    static void _SaveUsersDataToFile(const vector <clsUser> &vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (const clsUser& U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update() 
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew() const
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(const string &stDataLine) const
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _PrepareLogInRecord(string Seperator ="#//#")
    {
         
         string LogInRecord = "";
         LogInRecord = clsDate::GetSystemDateTimeString() + Seperator;
         LogInRecord += _UserName + Seperator;
         LogInRecord += clsUtility::EncryptText(_Password) + Seperator;
         LogInRecord += to_string(_Permissions);
         
         return LogInRecord;
    }

    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(const string &Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;

        vector<string>vLoginRegisterData = clsString::Split(Line, Seperator);

        LoginRegisterRecord.DateAndTime = vLoginRegisterData[0];
        LoginRegisterRecord.UserName = vLoginRegisterData[1];
        LoginRegisterRecord.PassWord = clsUtility::DecryptionText(vLoginRegisterData[2]);
        LoginRegisterRecord.Permissions = stoi(vLoginRegisterData[3]);

        return LoginRegisterRecord;

    }


public:

    clsUser(enMode Mode, const string &FirstName,const  string &LastName,
        const string &Email,const  string &Phone, const string &UserName, const string &Password,
        const int &Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64 ,pLoginRegister = 128 , pCurrencyExchange = 256
    };

    struct stLoginRegisterRecord 
    {
        string DateAndTime;
        string UserName;
        string PassWord;
        int Permissions;
    };

    bool IsEmpty() const
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted() const
    {
        return _MarkedForDelete;
    }

    string GetUserName()const
    {
        return _UserName;
    }

    void SetUserName(const string &UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(const string &Password)
    {
        _Password = Password;
    }

    string GetPassword()const
    {
        return _Password;
    }

    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(const int &Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions() const
    {
        return _Permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(const string &UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(const string &UserName,const  string &Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName && User.GetPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(const string &UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool IsAdmin()const
    {
        return _Permissions == enPermissions::eAll;

    }

    bool Delete()
    {

        if (IsAdmin())
        {
            return false;
        }

        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

      
        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == UserName)
            {
                    U._MarkedForDelete = true;
                    break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(const string &UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    void ClearObject()
    {
        *this = _GetEmptyUserObject();
    }

    bool CheckAccessPermission(enPermissions Permission)const
    {
        if (this->Permissions == enPermissions::eAll)
        {
            return true;
        }

        if ((Permission & this->Permissions) == Permission)
        {
            return true;
        }

        else
        {
            return false;
        }

    }

    void RegisterLogIn()
    {
        fstream MyFile;
        string LogsInfo = _PrepareLogInRecord();

        MyFile.open("LoginRegister.txt", ios::out | ios::app);


        if (MyFile.is_open())
        {

            MyFile << LogsInfo << endl;

            MyFile.close();
        }
    }

    static vector<stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector<stLoginRegisterRecord>vLoginRegisterRecord;
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {

                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);
            }

            MyFile.close();

        }

        return vLoginRegisterRecord;
    }


};


