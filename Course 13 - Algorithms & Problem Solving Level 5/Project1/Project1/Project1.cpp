#include <iostream>
#include"clsDblLinkedList.h"
using namespace std;

int main()
{
    clsDblLinkedList<int>MydblLinkedList;
    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node * N1 = MydblLinkedList.Find(2);
    if (N1 != nullptr)
    {
        cout << "\nNode With Value " << N1->Value << " is FOUND =)\n";
    }
    else {
        cout << "\nNode is NOT FOUND =(\n";
    }

    MydblLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter Inserting 500 after 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAtEnd(700);
    cout << "\nAfter Inserting 700 at end:\n";
    MydblLinkedList.PrintList();


    clsDblLinkedList<int>::Node* N2 = MydblLinkedList.Find(4);
    MydblLinkedList.DeleteNode(N2);
    cout << "\nAfter Deleting 4:\n";
    MydblLinkedList.PrintList();


    MydblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MydblLinkedList.PrintList();

    cout << "\nAfter Deleting Last Node:\n";
    MydblLinkedList.DeleteLastNode();
    MydblLinkedList.PrintList();

    //===========================
    //    Extension 1 ---> SIZE 
    //===========================

    cout << "\n\nExtension 1 ---> SIZE\n\n";

    clsDblLinkedList<int>MydblLinkedList1;

    MydblLinkedList1.InsertAtBeginning(6);
    MydblLinkedList1.InsertAtBeginning(5);
    MydblLinkedList1.InsertAtBeginning(4);
    MydblLinkedList1.InsertAtBeginning(3);
    MydblLinkedList1.InsertAtBeginning(2);
    MydblLinkedList1.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList1.PrintList();

    cout << "\nNumber of Iteme in the Linked List: " << MydblLinkedList1.Size();

    //===========================
    //  Extension 2 ---> IsEmpty 
    //===========================

    cout << "\n\nExtension 2 ---> IsEmpty";

    clsDblLinkedList<int>MydblLinkedList2;

    if (MydblLinkedList2.IsEmpty())
    {
        cout << "\n\nYes List Is Empty.\n";
    }
    else
    {
        cout << "\n\nNo List Is NOT Empty.\n";
    }

    MydblLinkedList2.InsertAtBeginning(7);
    MydblLinkedList2.InsertAtBeginning(6);
    MydblLinkedList2.InsertAtBeginning(5);
    MydblLinkedList2.InsertAtBeginning(4);
    MydblLinkedList2.InsertAtBeginning(3);
    MydblLinkedList2.InsertAtBeginning(2);
    MydblLinkedList2.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList2.PrintList();

    cout << "\nNumber of Iteme in the Linked List: " << MydblLinkedList2.Size();

    if (MydblLinkedList2.IsEmpty())
    {
        cout << "\n\nYes List Is Empty.\n";
    }
    else
    {
        cout << "\n\nNo List Is NOT Empty.\n";
    }


   //===========================
   //  Extension 3 ---> Clear 
   //===========================

    cout << "\n\nExtension 3 ---> Clear";

    clsDblLinkedList<int>MydblLinkedList3;
    
    MydblLinkedList3.InsertAtBeginning(4);
    MydblLinkedList3.InsertAtBeginning(3);
    MydblLinkedList3.InsertAtBeginning(2);
    MydblLinkedList3.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList3.PrintList();

    cout << "\nNumber of Iteme in the Linked List: " << MydblLinkedList3.Size();

    cout << "\nExecuting .Clear()";
    MydblLinkedList3.Clear();
    cout << "\nNumber of Iteme in the Linked List: " << MydblLinkedList3.Size();


    //===========================
    // Extension 4 ---> Reverse 
    //===========================

    cout << "\n\nExtension 4 ---> Reverse";

    clsDblLinkedList<int>MydblLinkedList4;

    MydblLinkedList4.InsertAtBeginning(5);
    MydblLinkedList4.InsertAtBeginning(4);
    MydblLinkedList4.InsertAtBeginning(3);
    MydblLinkedList4.InsertAtBeginning(2);
    MydblLinkedList4.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList4.PrintList();

    MydblLinkedList4.Reverse();

    cout << "\nLinked List Contenet after reverse:\n";
    MydblLinkedList4.PrintList();

    system("pause>0");
    return 0;
}


