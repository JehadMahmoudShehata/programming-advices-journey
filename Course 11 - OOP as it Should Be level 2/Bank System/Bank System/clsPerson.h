#pragma once
#include <iostream>
#include <string>
#include "clsInterfaceCommunication.h"

using namespace std;

// clsPerson implements the clsInterfaceCommunication interface (fulfilling the communication contract)

class clsPerson : public clsInterfaceCommunication
{

private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(const string &FirstName, const string &LastName, const string &Email, const string &Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	}

	//Property Set
	
	void SetFirstName(const string &FirstName)
	{
		_FirstName = FirstName;
	}

	//Property Get

	string GetFirstName() const
	{
		return _FirstName;
	}

	_declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	//Property Set

	void SetLastName(const string &LastName)
	{
		_LastName = LastName;
	}

	//Property Get

	string GetLastName() const
	{
		return _LastName;
	}

	_declspec(property(get = GetLastName, put = SetLastName))string LastName;

	//Property Set

	void SetEmail(const string &Email)
	{
		_Email = Email;
	}

	//Property Get

	string GetEmail() const
	{
		return _Email;
	} 

	_declspec(property(get = GetEmail, put = SetEmail))string Email;

	//Property Set

	void SetPhone(const string &Phone)
	{
		_Phone = Phone;
	}

	//Property Get

	string GetPhone() const
	{
		return _Phone;
	}

	_declspec(property(get = GetPhone, put = SetPhone))string Phone;

	string GetFullName() const
	{
		return _FirstName + " " + _LastName;
	}

	// Override interface functions. Changing method names or parameters will prevent compilation
	// as clsPerson must strictly adhere to the base interface signature.

	void SendEmail(string Subject, string Body)override
	{

	}

	void SendFax(string Subject, string Body)override
	{

	}

	void SendSMS(string Subject, string Body)override
	{

	}


};

