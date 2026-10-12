#pragma once
#include<iostream>

using namespace std;

template<class T>
class clsDynamicArray
{
protected:

	int _Size = 0;

public:

	T* OriginalArray = nullptr;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
		{
			Size = 0;
		}

		_Size = Size;
		OriginalArray = new T[Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int index, T Value)
	{
		if (index >= _Size  || index < 0)
		{
			return false;
		}

		OriginalArray[index] = Value;
		return true;
	}

	bool IsEmpty()
	{
		return (_Size == 0) ? true : false;
	}

	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}

		cout << "\n";
	}

};

