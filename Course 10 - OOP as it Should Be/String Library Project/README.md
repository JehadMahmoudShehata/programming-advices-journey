# 🧵 clsString Library

A robust, lightweight C++ String Utility Library built using Object-Oriented Programming (OOP) principles. This library provides a complete toolkit for string manipulation, text analysis, and data formatting through a dual-interface model (Static Utility Functions and Instance Methods).

---

## 🚀 Features

* **Case Transformations:** Converts entire strings to upper/lowercase, capitalizes or lower-cases the first letter of each word, and inverts letter cases dynamically.
* **Text Analysis & Counting:** Calculates word counts, capital/small letter frequencies, vowel counts, and specific character occurrences with case-sensitivity options.
* **Whitespace Trimming:** Removes leading, trailing, or all surrounding whitespace (`TrimLeft`, `TrimRight`, `Trim`) cleanly.
* **Tokenization & Joining:** Splits strings into `vector<string>` tokens using custom delimiters and joins vectors or standard array elements into single formatted strings.
* **Text Cleaning & Manipulation:** Erases punctuation marks, reverses word order within sentences, and offers flexible search-and-replace functionality.

---

## 🛠️ Concepts Used

* **Language & Paradigm:** C++ (Object-Oriented Programming with Method Overloading and Static Utility Classes).
* **STL Containers & Iterators:** Uses `std::vector<string>` for dynamic token handling and `vector<string>::iterator` for reverse word traversal.
* **User-Defined Types & Enums:** Employs enums (`enWhatToCount`) for type-safe character counting filters.
* **Properties & Encapsulation:** Uses MSVC `__declspec(property)` to seamlessly bind `GetValue` and `SetValue` to an intuitive `Value` property.
* **Logic & Algorithm Design:** String parsing via `std::string::find()`, `substr()`, `erase()`, and character inspect functions (`toupper`, `tolower`, `ispunct`, `isupper`).
