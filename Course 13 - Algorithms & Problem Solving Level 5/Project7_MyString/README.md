# 🚀 Undo & Redo Project using Stack in C++ (MyString)

A practical implementation of an **Undo / Redo** feature built in C++ using two standard `std::stack` containers (`_UndoStack` and `_RedoStack`) along with C++ property syntax (`__declspec(property)`).

---

## 📌 Overview

This project demonstrates how text editors and software applications handle state management for `Undo` and `Redo` actions. Every time a new value is assigned to the string property, the previous state is pushed onto the undo stack, allowing seamless navigation back and forth through text history.

---

## 🛠️ Key Features & Methods

* **Property Syntax (`__declspec(property)`)**: Simplifies syntax so that getting and setting string values feels like working with native properties.
* **`Undo()`**: Reverts to the previous state by popping from the Undo stack and pushing the current state to the Redo stack.
* **`Redo()`**: Restores the forward state by popping from the Redo stack and pushing the current state back to the Undo stack.

---

## 💻 Usage Example

```cpp
#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{
    clsMyString S1;

    S1.Value = "Jehad";
    S1.Value = "Jehad2";
    
    cout << "Current Value: " << S1.Value << endl; // Output: Jehad2

    // Undo action
    S1.Undo();
    cout << "After Undo: " << S1.Value << endl;    // Output: Jehad

    // Redo action
    S1.Redo();
    cout << "After Redo: " << S1.Value << endl;    // Output: Jehad2

    return 0;
}