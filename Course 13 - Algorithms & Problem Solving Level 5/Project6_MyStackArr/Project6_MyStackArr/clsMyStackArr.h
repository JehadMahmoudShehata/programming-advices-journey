#pragma once
#include"clsMyQueueArr.h"


template<class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:

	//OverRidding
	void Push(T Item)
	{
		clsMyQueueArr<T>::_MyList.InsertAtBegining(Item);

	}

	T Top()
	{
		return clsMyQueueArr<T>::Front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::Back();
	}
	
};

