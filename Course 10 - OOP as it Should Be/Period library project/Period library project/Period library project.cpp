#include <iostream>
#include "clsPeriod.h"

using namespace std;

int main()
{
    clsPeriod Period1(clsDate(1, 1, 2022), clsDate(10, 1, 2022));
    Period1.Print();

    cout << "\n";

    clsPeriod Period2(clsDate(3, 1, 2022), clsDate(5, 1, 2022));
    Period2.Print();

    cout << "\n";


    cout << Period1.IsOverlapPeriods(Period2) << endl;


    cout << clsPeriod::IsOverlapPeriods(Period1, Period2) << endl;

    cout << "\n";

    cout << Period1.GetPeriodLengthInDays();

    cout << "\n";
    cout << clsPeriod::GetPeriodLengthInDays(Period2);


    clsDate Date;
    Date.Day = 1;
    Date.Month = 1;
    Date.Year = 2022;

    cout << "\n";

    cout << Period1.IsDateInPeriod(Date);

    cout << "\n";


    return 0;
}



