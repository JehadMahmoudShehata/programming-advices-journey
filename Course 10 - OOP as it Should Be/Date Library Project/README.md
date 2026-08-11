# 📅 clsDate Library

A robust, lightweight C++ Date Utility Library built using Object-Oriented Programming (OOP) principles. This library provides a complete toolkit for date manipulation, calendar math, vacation tracking, and date formatting through a dual-interface model (Static Utility Functions and Instance Methods).

---

## 🚀 Features

* **Date Construction & Conversions:** Initializes dates from system time, formatted strings (`DD/MM/YYYY`), or day-orders in a year, and converts dates seamlessly back to formatted strings.
* **Leap Year & Calendar Math:** Determines leap years, calculates exact days in any given month or year, and computes day-of-the-week orders along with short names (e.g., `Sun`, `Mon`, `Jan`, `Feb`).
* **Validation & Comparisons:** Validates calendar dates against real-world boundaries and compares two dates to determine relative order (`Before`, `Equal`, `After`).
* **Date Incrementation & Arithmetic:** Increases or decreases dates by single or multiple days, automatically handling month and year boundary rollovers.
* **Business & Vacation Utilities:** Differentiates between business days and weekends, and calculates actual return dates from vacations by skipping non-working days.

---

## 🛠️ Concepts Used

* **Language & Paradigm:** C++ (Object-Oriented Programming with Method Overloading and Static Utility Classes).
* **System Time Integration:** Employs `<ctime>` structures (`time_t`, `tm`, `localtime`) for precise real-time system date retrieval.
* **STL Containers:** Uses `std::vector<string>` for parsing and tokenizing custom-delimited date strings.
* **User-Defined Types & Enums:** Employs type-safe enums (`enDateCompare`) for explicit and readable comparison results.
* **Algorithmic Calendar Logic:** Applies Zeller’s Congruence-based formulas for day-of-week computation, leap year logic rules, and day-order offset algorithms.