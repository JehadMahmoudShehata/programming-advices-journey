#pragma once
#include<iostream>
#include"clsMyQueue.h"

using namespace std;

    // DISCLAIMER: Real stacks hate this! We are hijacking a Queue via inheritance 
	// and forcing it to work backward just to satisfy the project requirements. 
	// Pure OOP purists look away! 

template<class T>
class clsMyStack :public clsMyQueue<T>
{

public:

	//Overridding
	void Push(T Value)
	{
		clsMyQueue<T>::_MyList.InsertAtBeginning(Value);
	}

	
	T Top()
	{
		return clsMyQueue<T>::Front();
	}

	T Bottom()
	{
		return clsMyQueue<T>::Back();
	}

	

};

