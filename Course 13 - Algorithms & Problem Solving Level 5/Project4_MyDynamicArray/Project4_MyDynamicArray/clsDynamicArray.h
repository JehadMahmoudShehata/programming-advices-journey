#pragma once
#include<iostream>

using namespace std;

template<class T>
class clsDynamicArray
{
protected:

	int _Size = 0;
	T* _TempArray = nullptr;

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

	void Resize(int NewSize)
	{
		//My Solution
		if (NewSize == Size())
		{
			return;
		}

		if (NewSize <= 0 )
		{
			delete[] OriginalArray;
			OriginalArray = nullptr;
			_Size = 0;
			return;
		}

		_TempArray = new T[NewSize];

		int limit = (NewSize < Size()) ? NewSize : Size();
		// You Can Use min() function , by including #include<algorithm> lib and just write int Limit = min(Newsize ,_size);

		for (int i = 0; i < limit; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		delete[]OriginalArray;
		_Size = NewSize;
		OriginalArray = _TempArray;

		//Doctor Solution
		/*void Resize(int NewSize)
        {
       
        if (NewSize < 0)
        {
            NewSize = 0;
        };

        _TempArray = new T[NewSize];

        //limit the original size to the new size if it is less.
        if (NewSize < _Size)
            _Size = NewSize;

        //copy all data from original array until the size
        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = _TempArray;
      
        } */

	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		// My Solution 
		// Time Complexity O(N/2) / Space Complexity O(1);

		if (IsEmpty())
		{
			return;
		}

		int Start = 0;
		int End = Size() - 1;

		while (Start < End)
		{
			T Temp = OriginalArray[Start];
			OriginalArray[Start] = OriginalArray[End];
			OriginalArray[End] = Temp;

			Start++;
			End--;

		}

		// Doctor Solution
		//Time Complexity O(N) , Space Complexity O(N)

		/* void  Reverse()

        {
        _TempArray = new T[_Size];
        int counter = 0;
        for (int i = _Size - 1; i >= 0; i--)
        {
            _TempArray[counter] = OriginalArray[i];
            counter++;
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        }*/

	}

	void clear()
	{
		//My Solution
		if (!IsEmpty())
		{
			delete[] OriginalArray;
			OriginalArray = nullptr;
			_Size = 0;

		}
		//You Can Reuse Resize() Function , By Writing Resize(0);


		//Doctor Solution
		/*
		void Clear()
        {
	       _Size = 0;
	       _TempArray = new T[0]; 
	       delete[] OriginalArray;
	       OriginalArray = _TempArray;

         }*/
	}

	bool DeleteItemAt(int Index)
	{
		//My Solution 
		// Time Complexity O(N) / Space Complexity O(1);

		if (IsEmpty() || Index < 0 || Index >= Size())
		{
			return false;
		}

		if (Index < Size())
		{
			for (int i = Index; i < Size() - 1; i++)
			{
				
				OriginalArray[i] = OriginalArray[i + 1];
				
			}
		}

		Resize(Size() - 1);
		return true;

		// Doctor Solution
	    //Time Complexity O(N) , Space Complexity O(N) 
		/*
		bool DeleteItemAt(int index)
        {

           if (index >= _Size || index <0)
           {
            return false;
           }

           _Size--;

            _TempArray = new T[_Size];

          //copy all before index

          for (int i = 0; i < index; i++)
          {
            _TempArray[i] = OriginalArray[i];
          }

        //copy all after index
          for (int i = index + 1; i < _Size + 1; i++)
          {
            _TempArray[i - 1] = OriginalArray[i];
          }

           delete[] OriginalArray;
           OriginalArray = _TempArray;
           return true;

        }*/
	}

};

