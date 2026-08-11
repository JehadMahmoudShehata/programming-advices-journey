# 🏦 Bank Management System - Extension 2

A C++ Console Application for managing bank clients, financial transactions, and system users with **Bitwise Permission System**

This extension project builds upon the core banking system by introducing a comprehensive user management module, permission-based access control , and permission-based navigation across the system.

---

## 🚀 Features

### 👥 Client Management

* **List Clients:** Displays all registered clients in a formatted table.
* **Add New Client:** Adds new client accounts with unique account numbers.
* **Delete Client:** Safely removes client records after confirmation.
* **Update Client:** Modifies existing client information.
* **Find Client:** Searches for a specific client using their account number.

### 💳 Transactions Module

* **Deposit:** Adds funds to a specific client account with confirmation.
* **Withdraw:** Withdraws funds with validation to ensure the requested amount does not exceed the client's current balance.
* **Total Balances:** Displays all client balances and calculates the total balance across all accounts.

### 🛡️ User & Access Management

* **User Management:** Supports listing, adding, deleting, updating, and finding system users.
* **Access Control:** Grants or restricts access to system features based on user permissions.
* **Bitwise Permission System:** Uses permission flags to control access to different system operations.
* **Admin Safety Guard:** Prevents the deletion of the master `Admin` account.
* **Login System:** Authenticates users using their username and password before granting access to the main system.

---

## 🔐 Permissions System (Bitwise Operations)

The project uses **Bitwise Operators** to implement a fine-grained user permission system.

Each permission is represented by a specific bit flag:

- `pListClients = 1` ($2^0$)
- `pAddNewClient = 2` ($2^1$)
- `pDeleteClient = 4` ($2^2$)
- `pUpdateClients = 8` ($2^3$)
- `pFindClient = 16` ($2^4$)
- `pTransactions = 32` ($2^5$)
- `pManageUsers = 64` ($2^6$)
- `eAll = -1` (Full Access)

### How It Works

* **Checking Permissions:** The `&` (Bitwise AND) operator is used to check whether the current user has a specific permission bit.

* **Combining Permissions:** The project combines permission values using the `+=` operator, since each permission is represented by a unique power of two. Bitwise OR (`|`) can also be used as a common alternative for combining independent permission flags.

* **Full Access:** The special permission value `eAll = -1` grants the user full access to all system features.

For a detailed explanation of Bitwise AND (`&`) and OR (`|`) operators, including truth tables and practical examples:

📘 **Deep Dive:** Want to understand how the Bitwise Permission System works under the hood? Check out the full **[Bitwise Operators Explanation & Logic](./Bitwise_explain/)**.

---

## 🛠️ Concepts Used

* **Language:** C++

* **User-Defined Types:**
  * Structs (`sClient` and `stUser`) to organize client and user data.
  * Enums to manage Main Menu, Transactions Menu, Manage Users Menu, and Permission options.

* **Data Structures:**
  * Vectors (`vector`) for loading and managing client and user records in memory.

* **Logic & Control:**
  * Switch-case statements for menu navigation.
  * Functions for modular and reusable program logic.
  * Reference passing (`&`) to modify client and user records safely.
  * Bitwise AND (`&`) for permission validation.
  * Permission flags based on powers of two.

* **File & String Handling:**
  * Custom string splitting using delimiters.
  * Converting text file records into structured data.
  * Converting structured records back into text lines.
  * `fstream` for reading, writing, appending, and updating data stored in local text files.
  * The system saves updated data back to the text files.

* **User Permissions:**
  * User authentication.
  * Permission-based feature access.
  * Full-access Admin permission.

---

## 📁 Data Storage

The application stores client and user data in text files.

* `Clients.txt`: Stores client records using the `#//#` delimiter.

* `Users.txt`: Stores user credentials and their associated permission values.

The system loads records from these files into vectors, performs the required operations, and saves updated data back to the files.

---
## 📐 System Architecture & Flowchart

Below is the System Flowchart illustrating the overall application logic, menu navigation, file data flow, user authentication, and permission validation process:

![Bank System Flowchart](./Bank_Extension_2.png)
---

