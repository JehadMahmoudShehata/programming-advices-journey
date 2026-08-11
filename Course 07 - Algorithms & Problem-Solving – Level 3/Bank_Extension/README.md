# 🏦 Bank System - Extension Project

A console-based Banking Management System built in C++. This extension project upgrades the core system by integrating a comprehensive sub-menu for dynamic financial transactions and total ledger balance tracking.

---

## 🚀 Features

* **Advanced Multi-Menu System:** Seamlessly navigates between the Main Menu (7 options) and a dedicated Transactions Menu (4 options).
* **Dynamic Client Deposits:** Performs deposit operations on specific client accounts, updating the system balance instantly with confirmation prompts.
* **Validated Client Withdrawals:** Handles withdrawal requests with active validation checks to ensure the requested amount does not exceed the client's current balance.
* **Live Total Balances Ledger:** Generates a real-time summary screen displaying all clients' balances alongside the total accumulated liquidity within the bank.

---

## 🛠️ Concepts Used

* **Language:** C++
* **User-Defined Types:** 
  * Enums to manage both Main Menu (`enMainMenueOptions`) and Transactions Menu (`enTransactionsMenueOptions`) choices safely.
  * Structs (`sClient`) to bundle multi-attribute client profiles and tracking states (`MarkForDelete`).
* **Logic & Control:** Nested switch-cases for multi-level menu routing, reference passing (`&`) in vectors to safely mutate account funds during live runtime operations, and tailored tabular loops using `<iomanip>`.
* **Data Persistence (File Handling):** Full integration with a local flat-file database (`Clients.txt`) using file streams (`fstream`) to persistently commit financial mutations (deposits/withdrawals) and parse client string records via custom token splitting.

---

## 📐 System Design & Requirements

Below is the architectural layout and requirements logic used to construct the system:

![System Layout](./Bank%20_Extension%20Project.png)