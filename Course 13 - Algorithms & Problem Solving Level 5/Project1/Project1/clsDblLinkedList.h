#pragma once
#include<iostream>

using namespace std;


template<class T>
class clsDblLinkedList
{

protected:

	int _Size = 0;
	
public:

	class Node
	{
	public:

		T Value;
		Node* Next;
		Node* Prev;

	};

	Node* Head = nullptr;

	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new Node();

		NewNode->Next = Head;
		NewNode->Value = Value;
		NewNode->Prev = nullptr;

		if (Head != nullptr)
		{
			Head->Prev = NewNode;
		}
		Head = NewNode;
		_Size++;
	}

	void PrintList()
	{
		Node* Current = Head;

		if (Current == nullptr)
		{
			cout << "\nLinked List Is Empty\n";
		}

		while (Current != nullptr)
		{
			cout << Current->Value << " ";
			Current = Current->Next;
		}

		cout << "\n";
	}

	Node *Find(T Value)
	{
		Node* Current = Head;

		while (Current != nullptr)
		{
			if (Current->Value == Value)
			{
				return Current;
			}

			Current = Current->Next;
		}

		return nullptr;
	}

	void InsertAfter(Node* Current, T Value)
	{
		Node* NewNode = new Node();
		 
		NewNode->Value = Value;
		NewNode->Next = Current->Next;
		NewNode->Prev = Current;

		if (Current->Next != nullptr)
		{
			Current->Next->Prev = NewNode;
		}

		Current->Next = NewNode;
		_Size++;

	}

	void InsertAtEnd(T Value)
	{
		Node* Current = Head;
		Node* NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Next = nullptr;

		if (Head == nullptr)
		{
			NewNode->Prev = nullptr;
			Head = NewNode;
			return;
		}

		while (Current->Next != nullptr)
		{
			Current = Current->Next;
		}
	
		NewNode->Prev = Current;
		Current->Next = NewNode;
		_Size++;

	}

	void DeleteNode(Node*& NodeToDelete)
	{
		
		if (Head == nullptr || NodeToDelete == nullptr)
		{
			return;
		}

		if (Head == NodeToDelete)
		{
			Head = NodeToDelete->Next;
		}

		if (NodeToDelete->Next != nullptr)
		{
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}

		if (NodeToDelete->Prev != nullptr)
		{
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}

		delete NodeToDelete;
		_Size--;

	}

	void DeleteFirstNode()
	{
		Node* Temp = Head;

		if (Head == nullptr)
		{
			return;
		}

		Head = Head->Next;
		if (Head != nullptr)
		{
			Head->Prev = nullptr;
		}
		delete Temp;
		_Size--;

	}

	void DeleteLastNode()
	{
		if (Head == nullptr)
		{
			return;
		}

		if (Head->Next == nullptr)
		{
			delete Head;
			Head = nullptr;
			return;
		}

		Node* Current = Head;
		while (Current->Next->Next != nullptr)
		{
			Current = Current->Next;
		}

		Node* Temp = Current->Next;
		Current->Next = nullptr;
		delete Temp;
		_Size--;

	}

	int Size()
	{
		return _Size;

	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}


};

