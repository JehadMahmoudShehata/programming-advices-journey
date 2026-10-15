#include <iostream>
#include"clsDynamicArray.h"

using namespace std;

int main()
{
	clsDynamicArray<int>MyDynamicArray(5);

	MyDynamicArray.SetItem(0, 10);
	MyDynamicArray.SetItem(1, 20);
	MyDynamicArray.SetItem(2, 30);
	MyDynamicArray.SetItem(3, 40);
	MyDynamicArray.SetItem(4, 50);


	cout << "\nIs Empty ? " << MyDynamicArray.IsEmpty();
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n\n";
	cout << "\nArray Items: \n";

	MyDynamicArray.PrintList();

	//Extension 01 --> Resize
	MyDynamicArray.Resize(2);
	cout << "\nArray Size : " << MyDynamicArray.Size();
	cout << "\nArray Items after Resize to 2: \n";
	MyDynamicArray.PrintList();

	MyDynamicArray.Resize(10);
	cout << "\nArray Size : " << MyDynamicArray.Size();
	cout << "\nArray Items after Resize to 10: \n";
	MyDynamicArray.PrintList();

	system("pause>0");
	return 0;
}


