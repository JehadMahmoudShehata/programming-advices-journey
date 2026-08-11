# 🏦 Bank System (Core Project)

A console-based Banking Management System built in C++. This project focuses on flat-file database handling, clean record tracking, and multi-functional financial management through an interactive menu.

---

## 🚀 Features

* **Client Database Management:** Displays all clients' records formatted beautifully in a tabular layout (Account Number, PIN, Name, Phone, and Balance).
* **Secure Client Creation:** Safely inserts new clients into the database with active validation to ensure unique account numbers.
* **Controlled Record Deletion:** Marks records for deletion first (soft-delete) before fully cleansing and updates the file storage.
* **Dynamic Information Updating:** Allows updating a client's pin code, full name, phone number, and ledger balance seamlessly.
* **Instant Record Lookups:** Searches the local system to retrieve and view a detailed, structured profile card for any specific client.

---

## 🛠️ Concepts Used

* **Language:** C++
* **User-Defined Types:** 
  * Enums for managing main menu selections cleanly.
  * Structs to bundle multi-attribute client profiles and tracking state (`MarkForDelete`).
* **Logic & Control:** Functions, Vectors (`std::vector`) for dynamic memory caching, and input formatting (`<iomanip>`).
* **Data Persistence (File Handling):** Full integration with a local flat-file database (`Clients.txt`) using file streams (`fstream`) to read and write records persistently, backed by a custom string splitting algorithm for parsing.

---

## 📐 Game Design & Layout

Below is the architectural layout and requirements logic used to construct the System:

![System Layout](./Bank1_Project%20-%20Design%20Layout.png)
