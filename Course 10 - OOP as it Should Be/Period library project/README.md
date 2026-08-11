# ⏳ clsPeriod Library

A robust, lightweight C++ Period Utility Library built using Object-Oriented Programming (OOP) principles. This library provides a complete toolkit for managing date ranges, evaluating timeline overlaps, and calculating period durations through a dual-interface model (Static Utility Functions and Instance Methods).

---

## 🚀 Features

* **Period Management & Encapsulation:** Safely encapsulates start and end dates using `clsDate` composition objects with custom properties.
* **Overlap Evaluation:** Determines whether two date ranges intersect or overlap on a timeline (`IsOverlapPeriods`).
* **Period Length Calculation:** Computes the total duration of a period in days, with support for boundary end-date inclusion (`GetPeriodLengthInDays`).
* **Date Inclusion Verification:** Checks whether a specific `clsDate` falls within a period's start and end boundaries (`IsDateInPeriod`).
* **Dual-Interface Model:** Offers flexibility by supporting both static utility calls (`clsPeriod::IsDateInPeriod(...)`) and direct instance operations (`period.IsDateInPeriod(...)`).

---

## 🛠️ Concepts Used

* **Language & Paradigm:** C++ (Object-Oriented Programming with Composition, Method Overloading, and Static Utility Classes).
* **Properties & Encapsulation:** Uses MSVC `__declspec(property)` to seamlessly bind `GetStartDate`/`SetStartDate` and `GetEndDate`/`SetEndDate` to `StartDate` and `EndDate` properties.
* **Pass-by-Reference & Value:** Combines reference parameters (`clsPeriod&`, `clsDate&`) for static operations with pass-by-value wrappers for instance convenience.
* **Range & Timeline Algorithms:** Integrates with `clsDate::CompareDates` and `clsDate::_enDateCompare` enum states (`_Before`, `_After`) to perform range checking and interval intersection calculations.
