#include <iostream>
#include"clsMyQueue.h"

using namespace std;

int main()
{
	clsMyQueue<int>MyQueue;

	MyQueue.Push(10);
	MyQueue.Push(20);
	MyQueue.Push(30);
	MyQueue.Push(40);
	MyQueue.Push(50);

	cout << "\nQueue: \n";
	MyQueue.Print();

	cout << "\nQueue Size : " << MyQueue.Size();
	cout << "\nQueue Front: " << MyQueue.Front();
	cout << "\nQueue Back : " << MyQueue.Back();

	MyQueue.Pop();


	cout << "\n\nQueue After Pop() : \n";
	MyQueue.Print();


	// DISCLAIMER: Real queues hate this! We are violating the strict FIFO rule 
    // because project requirements forced us to unlock all Linked List superpowers.
	
	//Extension #1

	cout << "\n\nItem(2) : " << MyQueue.GetItem(2);

	//Extension #2
	MyQueue.Reverse();
	cout << "\n\nQueue After Reverse() : \n";
	MyQueue.Print();

	//Extension #3
	MyQueue.UpdateItem(2, 600);
	cout << "\n\nQueue After Updating Item(2) to 600 : \n";
	MyQueue.Print();

	//Extension #4
	MyQueue.InsertAfter(2, 800);
	cout << "\n\nQueue After Inserting 800 after Item(2) : \n";
	MyQueue.Print();

	//Extension #5
	MyQueue.InsertAtFront(1000);
	cout << "\n\nQueue After Inserting 1000 at Front : \n";
	MyQueue.Print();

	//Extension #6
	MyQueue.InsertAtBack(2000);
	cout << "\n\nQueue After Inserting 2000 at Back : \n";
	MyQueue.Print();
	cout << "\nQueue Size : " << MyQueue.Size();


	//Extension #7
	MyQueue.Clear();
	cout << "\n\nQueue After Clear() : \n";
	MyQueue.Print();
	cout << "\nQueue Size : " << MyQueue.Size();




	system("pause>0");
	return 0;


}


