# 🏦 Bank & Currency Management System (OOP)

 A console-based banking system engineered in C++ using Object-Oriented Programming (OOP) . This system encapsulates complete client financial operations, role-based user access management, multi-currency conversion .

---

## 🌟 Key Technical Highlights

* **C++ Templates:** Generic input validation engine (`clsInputValidate`) supporting full type safety for numbers and ranges without redundant code duplication.
* **Granular Bitwise Security:** Role-based access control system operating via bitwise permission masks.
* **Encrypted Credentials & Audit Logging:** Custom logic for user Password encryption, automated login history logs, and full account transfer tracking.
* **Clean Architecture:** Strict separation of concerns dividing Core Models, Service Utility Libraries, and Abstract UI Screen Layers.

---

## ✨ Key Features

### 🔐 Authentication
- Secure login with username and encrypted password
- Maximum 3 failed login attempts before lockout
- Login activity logged automatically with timestamp

### 👥 Client Management
- Add, delete, update, and find clients
- Each client has: Name, Email, Phone, Account Number, PIN, Balance

### 💰 Transactions
- Deposit and withdraw funds
- Transfer money between accounts
- View total balances across all clients
- Full transfer log with timestamp and user info

### 💱 Currency Exchange
- List all world currencies with USD rates (170+ currencies)
- Find currency by code or country
- Update currency exchange rates
- Currency calculator between any two currencies

### 👤 User Management
- Add, delete, update, and find system users
- Role-based access control per feature
- Login register showing all login history

---

## 📐 Bitwise Permission Index

| Module | Flag Value | Access Rights |
| :--- | :---: | :--- |
| **All Access** | `-1` | Full Administrative Privileges |
| **Client Registry** | `1` | View Client Records |
| **New Client** | `2` | Register New Account |
| **Remove Client** | `4` | Terminate Account |
| **Update Client** | `8` | Edit Account Details |
| **Search Client** | `16` | Locate Specific Records |
| **Transactions** | `32` | Deposits, Withdrawals, Transfers |
| **User Admin** | `64` | System Account Management |
| **Security Logs** | `128` | Access Authentication Records |
| **Currency Suite** | `256` | Currency Rates & Calculator |

---

## 📂 Data Files

| File | Description |
|------|-------------|
| `Clients.txt` | Stores all bank client records |
| `Users.txt` | Stores system users with encrypted passwords |
| `Currencies.txt` | Stores 170+ world currencies with USD rates |
| `LoginRegister.txt` | Audit log of all login activity |
| `TransfersLog.txt` | Log of all transfer transactions |

---

### Default Login
```
Username: User5
Password: 1234
```

---
