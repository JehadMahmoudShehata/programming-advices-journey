# 🚀 Project 2: MyQueue Implementation (using Doubly Linked List)

> *Warning: This Queue has identity issues. It acts like a Queue, but deep down inside, it's just a disguised Double Linked List! 👀*

---

## 📌 About the Project
This project implements a custom **Queue** data structure in C++ using templates (`template <class T>`). Instead of building it from scratch using primitive arrays or standard linked list nodes, it is built by leveraging our pre-existing `clsDblLinkedList` class, demonstrating clean software design and code reusability.

## 🏛️ OOP Principles Applied
- **Composition :** The `clsMyQueue` class utilizes an instance of `clsDblLinkedList<T>` as a protected member (`_MyList`). This is a clear implementation of the **Has-A** relationship (Composition), where the Queue relies on the Doubly Linked List to handle its underlying data storage and core operations.

## ⚙️ Core & Extension Features
The Queue provides a comprehensive set of operations with their respective time complexities:
- `IsEmpty()`: Checks if the queue is empty $\mathcal{O}(1)$.
- `Push(T Item)`: Adds an item to the back of the queue $\mathcal{O}(n)$ (due to traversing the list to the end since a Tail pointer isn't used).
- `Pop()`: Removes the front item from the queue $\mathcal{O}(1)$.
- `Size()`: Returns the total number of elements $\mathcal{O}(1)$.
- `Front()`: Returns the first element in the queue $\mathcal{O}(1)$.
- `Back()`: Returns the last element in the queue $\mathcal{O}(n)$.
- **Extended Features:** Includes advanced methods such as `Reverse()`, `Clear()`, `GetItem()`, `UpdateItem()`, and `InsertAfter()` by wrapping the underlying list capabilities.

