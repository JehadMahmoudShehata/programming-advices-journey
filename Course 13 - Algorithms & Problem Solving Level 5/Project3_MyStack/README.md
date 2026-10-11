# 🚀 Project: MyStack Implementation (Inheritance & Queue Hijacking!)

> **⚠️ Warning:** Real stacks hate this! We are artificially hijacking a FIFO Queue via inheritance and forcing it to work backward just to satisfy project requirements. Pure LIFO purists, please look away! 🙈🛑

---

## 📌 About the Project

This project implements a custom `Stack` data structure (LIFO - Last In, First Out) in C++ using templates (`template <class T>`). 

Instead of building a stack from scratch or cleanly applying composition, this implementation takes a wild architectural shortcut: it **publicly inherits** from our pre-existing `clsMyQueue` class and bends its behavior to act like a Stack! It's a fantastic exercise in understanding method overriding, class hierarchies, and why strict theoretical OOP rules sometimes get bent in real-world scenarios.

---

## 🏛️ OOP Principles Applied

- **Inheritance (The "Rebel" Approach):** `clsMyStack` inherits from `clsMyQueue<T>`. While classic OOP design frowns upon forcing a Stack to be a specialized Queue, this demonstrates powerful code reuse and polymorphism.
- **Method Overriding & Adaptation:** 
  - The `Push()` method is overridden to route through the underlying doubly linked list's `InsertAtBeginning()`, turning a queue entry point upside down.
  - Core stack terminologies (`Top` and `Bottom`) are cleanly mapped over the queue's `Front` and `Back` mechanisms.

---

## ⚙️ Core & Extension Features

The Stack provides a robust set of operations (many inherited or adapted from the underlying Queue and Linked List engines):
.
- **`Push(T Item)`**: Adds an item to the top of the stack $O(1)$.
- **`Pop()`**: Removes the top item from the stack $O(1)$.
- **`Size()`**: Returns the total number of elements $O(1)$.
- **`Top()`**: Returns the top element of the stack $O(1)$.
- **`Bottom()`**: Returns the bottom element of the stack $O(n)$ (depending on list traversal).
- **Extended Features:** Thanks to our inherited infrastructure, the stack also supports advanced operations like `Reverse()`, `Clear()`, `GetItem()`, `UpdateItem()`, `InsertAfter()`, `InsertAtFront()`, and `InsertAtBack()`.