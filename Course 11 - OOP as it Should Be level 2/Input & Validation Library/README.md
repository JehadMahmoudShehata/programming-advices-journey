
# 🛡️ Input & Validation Library

A C++ header-only utility class (clsInputValidate) for validating user inputs, numbers, ranges, and dates using simple OOP principles.

## ✨ Features
- **Safe Input Reading:** Handles invalid numeric input by checking `!(cin >> Number)`, resetting the stream state with `cin.clear()`, and clearing invalid input using `numeric_limits`.
- **Number Range Validation:** Supports validation of both (`int`) and (`double`) values within a specified range.
- **Date Validation:** Provides functions for validating dates and checking whether a date falls within a specified range.
- **Automatic Range Swapping:** Automatically swaps From and To when they are provided in reverse order using `clsUtility::Swap` and `clsDate::SwapDates`.
- **Continuous Validation:** Repeatedly prompts the user until a valid input is entered or the value falls within the required range.
- **Static Utility Methods:** All validation methods are static and can be called directly without creating an object.