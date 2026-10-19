# 🚀 Queue Implementation using Dynamic Array & Composition in C++

A custom **Queue** data structure (`clsMyQueueArr`) built in C++ using a **Dynamic Array** (`clsDynamicArray`) as an underlying container, applying Object-Oriented Programming (OOP) **Composition**.

---

## 📌 Overview

This project demonstrates how to build a Queue data structure on top of an existing Dynamic Array implementation using **Composition** instead of Inheritance. By delegating internal operations to `clsDynamicArray`, the queue maintains FIFO (First-In, First-Out) semantics while supporting extended utility operations.

---

## 🛠️ Key Features & Methods

### 🔹 Standard Queue Operations
* `Push(Item)`: Adds an item to the back of the queue (using `InsertAtEnd`).
* `Pop()`: Removes the item at the front of the queue (using `DeleteFirstItem`).
* `Front()`: Returns the item at the front of the queue.
* `Back()`: Returns the item at the back of the queue.
* `Size()`: Returns the total number of elements in the queue.
* `IsEmpty()`: Checks if the queue contains no elements.
* `Print()`: Displays all elements in the queue.

### 🔹 Extended Operations
* `GetItem(Index)`: Retrieves an element by its 0-based position.
* `Reverse()`: Reverses the order of items in the queue in-place.
* `UpdateItem(Index, Value)`: Updates the element at a specified index.
* `InsertAfter(Index, Value)`: Inserts a new value right after the specified index.
* `InsertAtFront(Value)`: Pushes an element directly to the front of the queue.
* `InsertAtBack(Value)`: Pushes an element directly to the back of the queue.
* `Clear()`: Clears all elements from the queue.

---

## 💡 Architecture & Design Pattern

* **Composition over Inheritance**: `clsMyQueueArr` owns a Protected `clsDynamicArray<T> _MyList` instance rather than inheriting from it, keeping the queue interface clean and encapsulated.
* **Template Class**: Generic implementation allowing the queue to store any data type (`int`, `string`, custom objects, etc.).

---

## 💻 Usage Example

```cpp
#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;

int main()
{
    clsMyQueueArr<int> MyQueue;

    // Enqueue elements
    MyQueue.Push(10);
    MyQueue.Push(20);
    MyQueue.Push(30);

    cout << "Front element: " << MyQueue.Front() << endl; // Output: 10
    cout << "Back element: "  << MyQueue.Back()  << endl; // Output: 30

    // Dequeue element
    MyQueue.Pop();

    cout << "Front element after Pop: " << MyQueue.Front() << endl; // Output: 20

    return 0;
}