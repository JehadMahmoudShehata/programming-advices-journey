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
	cout << "\n\nExtension 01 (Resize)";
	MyDynamicArray.Resize(2);
	cout << "\nArray Size : " << MyDynamicArray.Size();
	cout << "\nArray Items after Resize to 2: \n";
	MyDynamicArray.PrintList();

	MyDynamicArray.Resize(10);
	cout << "\nArray Size : " << MyDynamicArray.Size();
	cout << "\nArray Items after Resize to 10: \n";
	MyDynamicArray.PrintList();


	//Extension 02 -----> GetItem
	cout << "\n\nExtension 02 (GetItem)";
	clsDynamicArray<int>MyDynamicArray2(6);

	MyDynamicArray2.SetItem(0, 10);
	MyDynamicArray2.SetItem(1, 20);
	MyDynamicArray2.SetItem(2, 30);
	MyDynamicArray2.SetItem(3, 40);
	MyDynamicArray2.SetItem(4, 50);
	MyDynamicArray2.SetItem(5, 60);


	cout << "\nIs Empty ? " << MyDynamicArray2.IsEmpty();
	cout << "\nArray Size : " << MyDynamicArray2.Size() << "\n\n";
	cout << "\nArray Items: \n";

	MyDynamicArray2.PrintList();

	cout << "\nItem(2): " << MyDynamicArray2.GetItem(2) << "\n";

	//Extension 03 -----> Reverse
	cout << "\n\nExtension 03 (Reverse)";
	MyDynamicArray2.Reverse();

	cout << "\nArray Items After Reverse: \n";
	MyDynamicArray2.PrintList();



	//Extension 04 -----> Clear
	cout << "\n\nExtension 04 (Clear)";
	MyDynamicArray2.clear();

	cout << "\nArray Items After Clear: \n";
	MyDynamicArray2.PrintList();

	//Extension 05 -----> DeleteItemAtIndex
	cout << "\n\nExtension 05 (DeleteItemAtIndex)";

	clsDynamicArray<int>MyDynamicArray3(5);

	MyDynamicArray3.SetItem(0, 10);
	MyDynamicArray3.SetItem(1, 20);
	MyDynamicArray3.SetItem(2, 30);
	MyDynamicArray3.SetItem(3, 40);
	MyDynamicArray3.SetItem(4, 50);


	cout << "\nIs Empty ? " << MyDynamicArray3.IsEmpty();
	cout << "\nArray Size : " << MyDynamicArray3.Size() << "\n\n";
	cout << "\nArray Items: \n";

	MyDynamicArray3.PrintList();

	MyDynamicArray3.DeleteItemAt(2);
	cout << "\nArray Items After Deleting Item (2): \n";
	cout << "\nArray Size : " << MyDynamicArray3.Size() << "\n";
	MyDynamicArray3.PrintList();

	//Extension 06 -----> DeleteFirstItem
	cout << "\n\nExtension 06 (DeleteFirstItem)";

	clsDynamicArray<int>MyDynamicArray4(5);

	MyDynamicArray4.SetItem(0, 10);
	MyDynamicArray4.SetItem(1, 20);
	MyDynamicArray4.SetItem(2, 30);
	MyDynamicArray4.SetItem(3, 40);
	MyDynamicArray4.SetItem(4, 50);

	cout << "\nIs Empty ? " << MyDynamicArray4.IsEmpty();
	cout << "\nArray Size : " << MyDynamicArray4.Size() << "\n\n";
	cout << "\nArray Items: \n";

	MyDynamicArray4.PrintList();

	MyDynamicArray4.DeleteFirstItem();

	cout << "\nArray Items After Deleting FirstItem : \n";
	cout << "\nArray Size : " << MyDynamicArray4.Size() << "\n";
	MyDynamicArray4.PrintList();

	//Extension 07 -----> DeleteLastItem
	cout << "\n\nExtension 07 (DeleteLastItem)";

	MyDynamicArray4.DeleteLastItem();

	cout << "\nArray Items After Deleting LastItem : \n";
	cout << "\nArray Size : " << MyDynamicArray4.Size() << "\n";
	MyDynamicArray4.PrintList();

	//Extension 08 -----> Find By Value
	cout << "\n\nExtension 08 (FindByValue)";

	clsDynamicArray<int>MyDynamicArray5(5);

	MyDynamicArray5.SetItem(0, 10);
	MyDynamicArray5.SetItem(1, 20);
	MyDynamicArray5.SetItem(2, 30);
	MyDynamicArray5.SetItem(3, 40);
	MyDynamicArray5.SetItem(4, 50);

	cout << "\nIs Empty ? " << MyDynamicArray5.IsEmpty();
	cout << "\nArray Size : " << MyDynamicArray5.Size() << "\n\n";
	cout << "\nArray Items: \n";

	MyDynamicArray5.PrintList();

	int Index = MyDynamicArray5.Find(30);
	if (Index == -1)
	{
		cout << "\nItem Was Not Found =(\n";
	}
	else
	{
		cout << "\n30 is Found at Index : " << Index;
	}

	//Extension 09 -----> Delete By Value
	cout << "\n\nExtension 09 (DeleteByValue)";

	MyDynamicArray5.DeleteItemByValue(30);

	cout << "\nArray Items After Deleting 30 : \n";
	cout << "\nArray Size : " << MyDynamicArray5.Size() << "\n";

	MyDynamicArray5.PrintList();

	system("pause>0");
	return 0;
}


