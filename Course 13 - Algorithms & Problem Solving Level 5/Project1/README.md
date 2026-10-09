# Generic Doubly Linked List (C++)

A generic, template-based **Doubly Linked List** implementation in C++ featuring core pointer manipulation techniques and 8 useful library extensions for dynamic data management.

---

## 🚀 Features & Methods

### Core Operations
- `InsertAtBeginning(T Value)`: Inserts a new node at the head.
- `InsertAtEnd(T Value)`: Appends a node to the tail.
- `DeleteFirstNode()`: Removes the first node.
- `DeleteLastNode()`: Removes the last node.
- `DeleteNode(Node*& NodeToDelete)`: Deletes a specific node by reference.
- `Find(T Value)`: Searches for a node with a specific value.
- `PrintList()`: Displays all elements in sequential order.

### 🧩 Extended Operations (Extensions 1 to 8)
| Extension | Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :---: | :---: |
| **Extension 1** | `Size()` | Returns the total count of nodes | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |
| **Extension 2** | `IsEmpty()` | Checks if the list has no elements | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |
| **Extension 3** | `Clear()` | Deletes all nodes and resets the list | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **Extension 4** | `Reverse()` | Reverses the direction of pointers in-place | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **Extension 5** | `GetNode(int Index)` | Retrieves a pointer to the node at a given zero-based index | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **Extension 6** | `GetItem(int Index)` | Returns the value contained in the node at a given index | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **Extension 7** | `UpdateItem(int Index, T NewValue)` | Updates the value of a node at a given index | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **Extension 8** | `InsertAfter(int Index, T NewValue)` | Overloaded method to insert a value after a specified index | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |

---

## 💻 Code Example

```cpp
#include <iostream>
#include "clsDblLinkedList.h"

int main() {
    clsDblLinkedList<int> list;

    // Insertion
    list.InsertAtBeginning(10);
    list.InsertAtBeginning(20);
    list.InsertAtEnd(30);

    // Using Extensions
    std::cout << "List Size: " << list.Size() << std::endl; // 3
    
    // Reverse
    list.Reverse();
    
    // Get & Update Item
    list.UpdateItem(0, 99);
    std::cout << "First Item: " << list.GetItem(0) << std::endl; // 99

    return 0;
}