# 🚀 Stack Implementation using Inheritance & Queue in C++

A custom **Stack** data structure (`clsMyStackArr`) built in C++ by inheriting from the `clsMyQueueArr` class, demonstrating **Object-Oriented Programming (OOP) Inheritance** and method overriding (LIFO behavior built on top of FIFO semantics).

---

## 📌 Overview

This project implements a Stack data structure (Last-In, First-Out) by inheriting from `clsMyQueueArr`. By overriding the `Push` method to insert elements at the beginning (`InsertAtBegining`), elements added last come out first, perfectly satisfying Stack operations while reusing queue and dynamic array functionalities.

---

## 🛠️ Key Features & Overrides

### 🔹 Stack-Specific Operations (LIFO)
* `Push(Item)`: Overrides the queue's push method to insert items at the front (`InsertAtBegining`), ensuring LIFO behavior.
* `Top()`: Returns the element at the top of the stack (utilizes `Front()`).
* `Bottom()`: Returns the element at the bottom of the stack (utilizes `Back()`).

### 🔹 Inherited Operations from Queue & Dynamic Array
* `Pop()`: Removes the top element from the stack.
* `Size()`: Returns the total number of elements in the stack.
* `IsEmpty()`: Checks if the stack is empty.
* `Print()`: Displays all elements currently in the stack.
* `GetItem(Index)`: Retrieves an element by its index.
* `Reverse()`: Reverses the stack order.
* `UpdateItem(Index, Value)`: Updates an item at a specific index.
* `Clear()`: Clears all elements from the stack.

---

## 💡 Architecture & Design Pattern

* **Inheritance**: `clsMyStackArr<T>` inherits publicly from `clsMyQueueArr<T>`, reusing its internal mechanisms and extended methods.
* **Method Overriding**: Customizes the insertion strategy (`Push`) to switch from Queue's FIFO to Stack's LIFO.
* **Template Class**: Fully generic to support any data type.

---

## 💻 Usage Example

```cpp
#include <iostream>
#include "clsMyStackArr.h"

using namespace std;

int main()
{
    clsMyStackArr<int> MyStack;

    // Push elements to the stack
    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);

    cout << "Stack Top: " << MyStack.Top() << endl;       // Output: 30
    cout << "Stack Bottom: " << MyStack.Bottom() << endl; // Output: 10

    // Pop element
    MyStack.Pop();
    cout << "Stack Top after Pop: " << MyStack.Top() << endl; // Output: 20

    return 0;
}