#pragma once
#include<iostream>
#include"clsDblLinkedList.h"

using namespace std;

template<class T>
class clsMyQueue
{
protected:

	clsDblLinkedList<T>_MyList;

public:

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	void Push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void Pop()
	{
		
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T Front()
	{
		return _MyList.GetItem(0);
	}

	T Back()
	{
		return _MyList.GetItem(Size() - 1);
	}
};

