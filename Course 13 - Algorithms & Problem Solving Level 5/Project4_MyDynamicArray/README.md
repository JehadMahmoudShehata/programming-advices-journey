# 🚀 Dynamic Array Implementation in C++

A comprehensive C++ implementation of a custom **Dynamic Array** (`clsDynamicArray`) built from scratch using C++ templates and manual dynamic memory management.

---

## 📌 Overview

This project explores how dynamic arrays work under the hood. It demonstrates lower-level memory management using `new[]` and `delete[]`, efficient resizing strategies, array manipulation algorithms, and boundary safety checks.

---

## 🛠️ Features & Extensions

The `clsDynamicArray<T>` template class provides a full suite of array operations and utility extensions:

### 🔹 Core & Utility Methods
* `Size()`: Returns the current number of elements in the array.
* `IsEmpty()`: Checks whether the array is empty.
* `SetItem(index, value)`: Updates the value at a given index with bounds checking.
* `GetItem(index)`: Retrieves the element at the specified index.
* `PrintList()`: Displays all array elements in sequence.

### 🔹 Resizing & Memory Management
* `Resize(NewSize)`: Dynamically reallocates array memory to fit a new size while preserving existing elements.
* `Reverse()`: Reverses the order of elements in-place with $\mathcal{O}(n/2)$ time complexity and $\mathcal{O}(1)$ space complexity.
* `Clear()`: Frees allocated memory and resets the array size to 0.

### 🔹 Deletion Methods
* `DeleteItemAt(index)`: Removes the element at the specified index and resizes the array.
* `DeleteFirstItem()`: Removes the first element in the array.
* `DeleteLastItem()`: Removes the last element in the array.
* `DeleteItemByValue(value)`: Searches for a value and deletes its first occurrence.

### 🔹 Insertion Methods
* `InsertAt(index, value)`: Inserts a new element at a specific index.
* `InsertAtBegining(value)`: Inserts an element at the start of the array.
* `InsertBefore(index, value)`: Inserts an element right before the target index.
* `InsertAfter(index, value)`: Inserts an element right after the target index.
* `InsertAtEnd(value)`: Appends an element to the end of the array.

---

## 💻 Usage Example

```cpp
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{
    clsDynamicArray<int> MyArray(5);

    MyArray.SetItem(0, 10);
    MyArray.SetItem(1, 20);
    MyArray.SetItem(2, 30);

    cout << "Array Size: " << MyArray.Size() << endl;
    MyArray.PrintList(); // Output: 10 20 30 0 0

    // Resize array
    MyArray.Resize(3);
    MyArray.PrintList(); // Output: 10 20 30

    return 0;
}