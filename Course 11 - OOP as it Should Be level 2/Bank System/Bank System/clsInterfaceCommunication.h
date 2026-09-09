#pragma once
#include<iostream>
#include<string>

using namespace std;


//this class applies Abstract/Interface principle (OOP) with class clsPerson
// This is a Pure Abstract Class (Interface in C++)
// It enforces a communication contract for any derived class (clsPerson , e.g.)

class clsInterfaceCommunication
{
	
public:
	// Pure Virtual Functions (No implementation here, must be overridden in derived classes)
	virtual void SendEmail(string Text, string Subject) = 0;
	virtual void SendFax(string Text, string Subject) = 0;
	virtual void SendSMS(string Text, string Subject) = 0;

};

