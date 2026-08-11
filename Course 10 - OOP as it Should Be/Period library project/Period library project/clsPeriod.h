#pragma once
#include <iostream>
#include"clsDate.h"

using namespace std;

class clsPeriod
{

private:
	clsDate _StartDate;
	clsDate _EndDate;

public:

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		_StartDate = StartDate;
		_EndDate = EndDate;

	}

    void SetStartDate(clsDate StartDate)
    {
        _StartDate = StartDate;
    }

    clsDate GetStartDate()
    {
        return _StartDate;
    }

    __declspec(property(get = GetStartDate, put = SetStartDate)) clsDate StartDate;

    void SetEndDate(clsDate EndDate)
    {
        _EndDate = EndDate;
    }

    clsDate GetEndDate()
    {
        return _EndDate;
    }

    __declspec(property(get = GetEndDate, put = SetEndDate)) clsDate EndDate;

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();

    }


// ===================================================
//  PERIODS OPERATIONS 
// ===================================================



    static bool IsOverlapPeriods(clsPeriod &Period1, clsPeriod &Period2)
    {
        return !((clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::_enDateCompare::_Before) ||
            (clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::_enDateCompare::_After));
    }

    bool IsOverlapPeriods(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    static int GetPeriodLengthInDays(clsPeriod &Period, bool IncludeEndDate = false)
    {
        return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
    }

    int GetPeriodLengthInDays()
    {
        return GetPeriodLengthInDays(*this);
    }

    static bool IsDateInPeriod(clsPeriod &Period, clsDate &Date)
    {
        return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::_enDateCompare::_Before ||
            clsDate::CompareDates(Date, Period.EndDate) == clsDate::_enDateCompare::_After);
    }

    bool IsDateInPeriod(clsDate Date)
    {
        return IsDateInPeriod(*this, Date);
    }

  
};

