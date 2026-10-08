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

    //=============================
    // Extension 5 ---> Get Node 
    //=============================

    cout << "\n\nExtension 5 ---> Get Node";

    clsDblLinkedList<int>MydblLinkedList5;
    MydblLinkedList5.InsertAtBeginning(5);
    MydblLinkedList5.InsertAtBeginning(4);
    MydblLinkedList5.InsertAtBeginning(3);
    MydblLinkedList5.InsertAtBeginning(2);
    MydblLinkedList5.InsertAtBeginning(1);

    cout << "\nLinked List Content:\n";
    MydblLinkedList5.PrintList();

    clsDblLinkedList <int>::Node* N;
        
    N = MydblLinkedList5.GetNode(2);

    cout << "\nNode Value is: " << N->Value << endl;

    //=============================
    // Extension 6 ---> Get Item 
    //=============================

    cout << "\n\nExtension 6 ---> Get Item";


    clsDblLinkedList<int>MydblLinkedList6;
    MydblLinkedList6.InsertAtBeginning(5);
    MydblLinkedList6.InsertAtBeginning(4);
    MydblLinkedList6.InsertAtBeginning(3);
    MydblLinkedList6.InsertAtBeginning(2);
    MydblLinkedList6.InsertAtBeginning(1);

    cout << "\nLinked List Content:\n";
    MydblLinkedList6.PrintList();

    cout << "\nItem(2) Value is: " << MydblLinkedList6.GetItem(2);

    //=============================
    // Extension 7 ---> Update Item 
    //=============================

    cout << "\n\nExtension 7 ---> Update Item";

    clsDblLinkedList<int>MydblLinkedList7;
    MydblLinkedList7.InsertAtBeginning(5);
    MydblLinkedList7.InsertAtBeginning(4);
    MydblLinkedList7.InsertAtBeginning(3);
    MydblLinkedList7.InsertAtBeginning(2);
    MydblLinkedList7.InsertAtBeginning(1);

    cout << "\nLinked List Content:\n";
    MydblLinkedList7.PrintList();

    MydblLinkedList7.UpdateItem(2, 500);
    cout << "\nLinked List Content After Updating Item(2):\n";
    MydblLinkedList7.PrintList();



    system("pause>0");
    return 0;
}


