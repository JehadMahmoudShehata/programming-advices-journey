#pragma once
#include<iostream>
#include<stack>

using namespace std;

class clsMyString
{

private:

	stack<string>_UndoStack;
	stack<string>_RedoStack;
	string _Value = "";
	

public:

	void SetValue(string Value)
	{
		_UndoStack.push(_Value);
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string Value;

	void Undo()
	{
		
		if (!_UndoStack.empty())
		{
			_RedoStack.push(_Value);
			_Value = _UndoStack.top();
			_UndoStack.pop();
		}
		
	}

	void Redo()
	{
		if (!_RedoStack.empty())
		{
			_UndoStack.push(_Value);
			_Value = _RedoStack.top();
			_RedoStack.pop();
		}
	}

	
};

