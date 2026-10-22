# 🎟️ Queue Line Management Project

A C++ implementation of a Customer Queue Line Management system, developed as part of the Programming Advices C++ roadmap. This project simulates real-world queue operations, ticket issuance, waiting time calculations, and client tracking.

---

## 📂 Project Versions & Branches

You can explore different implementation approaches used during the development of this project by switching between the branches:

*   **[Version 1: My Solution (Struct-based Approach)](https://github.com/JehadMahmoudShehata/programming-advices-journey/tree/main)**
    *   Implemented using standalone `structs` (`stTime`, `stDate`, `_stTicketInfo`) and direct queue management logic.
    *   Focuses on problem-solving, manual array/queue operations, and custom logic for RTL/LTR printing.

*   **[Version 2: Doctor Solution (OOP & Nested Class Approach)](https://github.com/JehadMahmoudShehata/programming-advices-journey/tree/v2-doctor-solution)**[cite: 2]
    *   An advanced Object-Oriented Programming (OOP) refactoring.
    *   Utilizes **Nested Classes** (`clsTicket` inside `clsQueueLine`) to achieve better encapsulation, clean code principles, and separation of concerns.

---

## 🚀 Features

*   **Ticket Issuance:** Automatically generates sequential ticket numbers based on a given prefix (e.g., A1, A2, A3).
*   **Time & Date Tracking:** Integrates system time and date for each issued ticket.
*   **Queue Statistics:** Tracks total tickets, served clients, and current waiting clients in real-time.
*   **Waiting Time Calculation:** Dynamically calculates expected serve time for waiting clients.
*   **Visual Ticket Lines:** Supports printing the queue line in both Right-to-Left (RTL) and Left-to-Right (LTR) directions using temporary queues and stacks.