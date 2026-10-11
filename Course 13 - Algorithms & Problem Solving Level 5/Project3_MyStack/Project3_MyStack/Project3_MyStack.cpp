#include <iostream>
#include"clsMyStack.h"

using namespace std;

int main()
{
	clsMyStack<int>MyStack;

	MyStack.Push(10);
	MyStack.Push(20);
	MyStack.Push(30);
	MyStack.Push(40);
	MyStack.Push(50);

	cout << "\nStack : \n";
	MyStack.Print();

	cout << "\nStack Size   : " << MyStack.Size();
	cout << "\nStack Top    : " << MyStack.Top();
	cout << "\nStack Bottom : " << MyStack.Bottom();

	MyStack.Pop();
	cout << "\n\nStack after pop(): \n";
	MyStack.Print();

	
	// DISCLAIMER: Pure LIFO purists look away! 
	// We hijacked a FIFO Queue via inheritance and forced it to act like a Stack 
	// just to satisfy project requirements. Don't try this in strict production! 
	
	//Extension #1
	cout << "\n\nItem(2) : " << MyStack.GetItem(2);

	//Extension #2
	MyStack.Reverse();
	cout << "\n\nStack after reverse(): \n";
	MyStack.Print();

	//Extension #3
	MyStack.UpdateItem(2, 600);
	cout << "\n\nStack after Updating Item (2) to 600 : \n";
	MyStack.Print();

	//Extension #4
	MyStack.InsertAfter(2, 800);
	cout << "\n\nStack after Inserting 800 after item(2) : \n";
	MyStack.Print();

	//Extension #5
	MyStack.InsertAtFront(1000);
	cout << "\n\nStack after Inserting 1000 at Top : \n";
	MyStack.Print();

	//Extension #6
	MyStack.InsertAtBack(2000);
	cout << "\n\nStack after Inserting 2000 at Bottom : \n";
	MyStack.Print();
	cout << "\nStack Size   : " << MyStack.Size();


	//Extension #7
	MyStack.Clear();
	cout << "\n\nStack after Clear() : \n";
	MyStack.Print();
	cout << "\nStack Size   : " << MyStack.Size();


	system("pause>0");
	return 0;
}


