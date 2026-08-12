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

	clsPeriod(const clsDate &StartDate , const clsDate &EndDate)
	{
		_StartDate = StartDate;
		_EndDate = EndDate;

	}

    void SetStartDate(const clsDate &StartDate)
    {
        _StartDate = StartDate;
    }

    clsDate GetStartDate() const
    {
        return _StartDate;
    }

    __declspec(property(get = GetStartDate, put = SetStartDate)) clsDate StartDate;

    void SetEndDate(const clsDate &EndDate)
    {
        _EndDate = EndDate;
    }

    clsDate GetEndDate() const
    {
        return _EndDate;
    }

    __declspec(property(get = GetEndDate, put = SetEndDate)) clsDate EndDate;

    void Print() const 
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();

    }


// ===================================================
//  PERIODS OPERATIONS 
// ===================================================



    static bool IsOverlapPeriods(const clsPeriod &Period1, const clsPeriod &Period2)
    {
        return !((clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::_enDateCompare::_Before) ||
            (clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::_enDateCompare::_After));
    }

    bool IsOverlapPeriods(const clsPeriod &Period2) const
    {
        return IsOverlapPeriods(*this, Period2);
    }

    static int GetPeriodLengthInDays(const clsPeriod &Period, bool IncludeEndDate = false)
    {
        return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
    }

    int GetPeriodLengthInDays() const
    {
        return GetPeriodLengthInDays(*this);
    }

    static bool IsDateInPeriod(const clsPeriod &Period, const clsDate &Date) 
    {
        return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::_enDateCompare::_Before ||
            clsDate::CompareDates(Date, Period.EndDate) == clsDate::_enDateCompare::_After);
    }

    bool IsDateInPeriod(const clsDate &Date) const
    {
        return IsDateInPeriod(*this, Date);
    }

  
};

