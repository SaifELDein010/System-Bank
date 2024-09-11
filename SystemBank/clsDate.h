#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "clsInput.h"
#include "clsString.h"
#include "timing.h"


using std::cout;
using std::cin;
using std::string;
using std::vector;

class clsInput;

class clsDate
{

private:
	
	short _Year = 0;
	short _Month = 0;
	short _Day = 0;
	
	short _Hour = 0;
	short _Mintue = 0;
	short _Second = 0;


public:


	clsDate() {

		Mytime::stTime time;
		Mytime::GetSpecificDateTiming(time);

		_Year = time.year;
		_Month = time.monthOfYear;
		_Day = time.dayOfMonth;


	}

	clsDate(short day, short month, short year) {

		_Year = year;
		_Month = month;
		_Day = day;

	}
	
	clsDate(short DayOrder, short year) {

		clsDate date;
		date = date.DateFromDayOrderInAYear(DayOrder, year);

		_Year = date._Year;
		_Month = date._Month;
		_Day = date._Day;

	}

	clsDate(string sDate) {

		clsDate date;
		date = date.StringToDate(sDate);

		_Year = date._Year;
		_Month = date._Month;
		_Day = date._Day;

	}

	void SetYear(short year) {
		_Year = year;
	}

	short GetYear() {
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;


	void SetMonth(short month) {
		_Month = month;
	}

	short GetMonth() {
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;


	void SetDay(short day) {
		_Day = day;
	}

	short GetDay() {
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;


	static void PrintDate(clsDate date) {

		cout << DateToString(date) << '\n';

	}
	void PrintDate() {

		return PrintDate(*this);

	}

	static bool LeapYear(short year) {

		return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);

	}
	bool LeapYear() {

		return LeapYear(_Year);

	}

	static short DaysInYear(short year) {

		return LeapYear(year) ? 366 : 365;

	}
	short DaysInYear() {

		return DaysInYear(_Year);

	}

	static short HoursInYear(short year) {

		return DaysInYear(year) * 24;

	}
	short HoursInYear() {

		return HoursInYear(_Year);

	}

	static int MinutesInYear(short year) {

		return HoursInYear(year) * 60;

	}
	int MinutesInYear() {

		return MinutesInYear(_Year);

	}

	static int SecondsInYear(short year) {

		return MinutesInYear(year) * 60;

	}
	int SecondsInYear() {

		return SecondsInYear(_Year);

	}

	static short DaysInMonth(short year, short month) {

		short days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return LeapYear(year) && month == 2 ? 29 : days[month];

	}
	short DaysInMonth() {

		return DaysInMonth(_Year, _Month);

	}


	static short CalculatorTheDay(short year, short month, short day) {

		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

	}
	short CalculatorTheDay() {
	
		return CalculatorTheDay(_Year, _Month, _Day);

	}


	static string DayName(short day) {

		string Days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return Days[day];

	}
	string DayName() {

		return DayName(_Day);

	}


	static short GetTotalOfDayFromTheBeginningOfYear(short year, short month, short day) {

		short total = 0;

		for (short i = 1; i < month; i++) {

			total += DaysInMonth(year, i);

		}

		return total + day;

	}
	short GetTotalOfDayFromTheBeginningOfYear() {

		return GetTotalOfDayFromTheBeginningOfYear(_Year, _Month, _Day);

	}


	/*static clsDate ReadDate() {

		clsDate date;

		date._Year = clsInput::ReadNumber("\n    Enter a year: ");
		date._Month = clsInput::ReadNumber("    Enter a month: ");
		date._Day = clsInput::ReadNumber("    Enter a day: ");

		return date;

	}*/

	static clsDate ReadCurrentDate() {

		clsDate date;

		Mytime::stTime time;
		Mytime::GetSpecificDateTiming(time);

		date._Year = time.year;
		date._Month = time.monthOfYear;
		date._Day = time.dayOfMonth;

		return date;

	}

	static clsDate ReadCurrentDateAndTime() {

		clsDate date;

		Mytime::stTime time;
		Mytime::GetSpecificDateTiming(time);

		date._Year = time.year;
		date._Month = time.monthOfYear;
		date._Day = time.dayOfMonth;

		date._Hour = time.hours;
		date._Mintue = time.minutes;
		date._Second = time.seconds;

		return date;

	}


	static clsDate AddDaysToDate(short daysToadding, short year, short month, short day) {

		short dayInYear = 0;
		short dayOrder = daysToadding + GetTotalOfDayFromTheBeginningOfYear(year, month, day);

		while (true) {

			LeapYear(year) ? dayInYear = 366 : dayInYear = 365;

			if (dayInYear < dayOrder) {

				dayOrder -= dayInYear;
				year++;

			}
			else {
				break;
			}

		}

		clsDate date;

		date._Year = year;
		date._Day = dayOrder;

		return date;

	}
	clsDate AddDaysToDate(short daysToadding) {

		return AddDaysToDate(daysToadding, _Year, _Month, _Day);

	}


	static clsDate DateFromDayOrderInAYear(short dayOrder, short year) {

		clsDate orderDate;
		short currentMonth = 0;

		for (short i = 1; i <= 12; i++) {

			if (dayOrder > DaysInMonth(year, i)) {

				dayOrder -= DaysInMonth(year, i);

			}
			else {

				currentMonth = i;
				break;

			}

		}

		orderDate._Day = dayOrder;
		orderDate._Month = currentMonth;
		orderDate._Year = year;

		return orderDate;

	}
	void DateFromDayOrderInAYear(short dayOrder) {

		*this = DateFromDayOrderInAYear(dayOrder, _Year);

	}


	static bool Date1BeforeDate2(clsDate date1, clsDate date2) {

		if (date1._Year < date2._Year)
			return true;

		if (date1._Year > date2._Year)
			return false;

		if (date2._Year == date1._Year) {

			return GetTotalOfDayFromTheBeginningOfYear(date1._Year, date1._Month, date1._Day) <
				GetTotalOfDayFromTheBeginningOfYear(date2._Year, date2._Month, date2._Day) ? true : false;

		}

	}
	bool DateBeforeDate2(clsDate date2) {

		return Date1BeforeDate2(*this, date2);

	}

	static bool Date1EqualDate2(clsDate date1, clsDate date2) {

		return date1._Year != date2._Year ? false : date1._Month != date2._Month ? false : date1._Day != date2._Day ? false : true;

	}
	bool DateEqualDate2(clsDate date2) {

		return Date1EqualDate2(*this, date2);

	}

	static bool Date1AfterDate2(clsDate date1, clsDate date2) {

		return !(Date1BeforeDate2(date1, date2)) && !(Date1EqualDate2(date1, date2));

	}
	bool DateAfterDate2(clsDate date2) {

		return Date1AfterDate2(*this, date2);

	}


	static enum enResultFromComber { Equal = 0, After = 1, Before = 2 };
	static enResultFromComber ComberTwoDates(clsDate date1, clsDate date2) {

		return Date1BeforeDate2(date1, date2) ? enResultFromComber::Before : Date1EqualDate2(date1, date2) ? enResultFromComber::Equal :
			enResultFromComber::After;

	}
	enResultFromComber ComberTwoDates(clsDate date2) {

		return ComberTwoDates(*this, date2);

	}

	static void PrintReultOfComberTwoDates(clsDate date1, clsDate date2) {

		switch (ComberTwoDates(date1, date2)) {

		case enResultFromComber::Before:
			cout << " >> Compare result = Date1 is before Date2\n";
			break;

		case enResultFromComber::Equal:
			cout << " >> Compare result = Date1 is Equal Date2\n";
			break;

		default:
			cout << " >> Compare result = Date1 is after Date2\n";

		}


	}
	void PrintReultOfComberTwoDates(clsDate date2) {
		
		PrintReultOfComberTwoDates(*this, date2);

	}

	static bool IsLastDayInMonth(clsDate date) {

		return date._Day == DaysInMonth(date._Year, date._Month);

	}
	bool IsLastDayInMonth() {

		return IsLastDayInMonth(*this);

	}

	static bool IsLastMonthInYear(short month) {

		return month == 12;

	}
	bool IsLastMonthInYear() {

		return IsLastMonthInYear(_Month);

	}



	static clsDate IncreaseDateByOneDay(clsDate date) {   // _Day  _Month  _Year

		if (IsLastDayInMonth(date)) {

			date._Day = 1;

			if (IsLastMonthInYear(date._Month)) {

				date._Month = 1;
				date._Year++;

			}
			else {

				date._Month++;

			}

		}
		else {

			date._Day++;

		}

		return date;

	}
	clsDate IncreaseDateByOneDay() {
		return IncreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate date) {

		if (date._Day == 1) {


			if (date._Month == 1) {

				date._Month = 12;
				date._Year--;

			}
			else {

				date._Month--;

			}

			date._Day = DaysInMonth(date._Year, date._Month);

		}
		else {

			date._Day--;

		}

		return date;

	}
	clsDate DecreaseDateByOneDay() {
		return DecreaseDateByOneDay(*this);
	}


	static clsDate IncreaseDateByXDays(short dayAdding, clsDate date) {

		for (short i = 0; i < dayAdding; i++) {

			date = IncreaseDateByOneDay(date);

		}

		return date;

	}
	clsDate IncreaseDateByXDays(short dayAdding) {
		return IncreaseDateByXDays(dayAdding,*this);
	}

	static clsDate DecreaseDateByXDays(short dayDecreasing, clsDate date) {

		for (short i = dayDecreasing; i > 0; i--) {

			date = DecreaseDateByOneDay(date);

		}

		return date;

	}
	clsDate DecreaseDateByXDays(short dayAdding) {
		return DecreaseDateByXDays(dayAdding, *this);
	}


	static clsDate IncreaseDateByOneWeek(clsDate date, short increase = 7) {

		return date = IncreaseDateByXDays(increase, date);

	}
	clsDate IncreaseDateByOneWeek(short increase = 7) {
		return IncreaseDateByOneWeek(*this, increase);
	}

	static clsDate DecreaseDateByOneWeek(clsDate date, short decrease = 7) {

		return date = DecreaseDateByXDays(decrease, date);

	}
	clsDate DecreaseDateByOneWeek(short increase = 7) {
		return DecreaseDateByOneWeek(*this, increase);
	}

	static clsDate IncreaseDateByXWeeks(short weekAdding, clsDate date) {

		date = IncreaseDateByOneWeek(date, weekAdding * 7);

		return date;

	}
	clsDate IncreaseDateByXWeeks(short weekAdding) {
		return IncreaseDateByXWeeks(weekAdding, *this);
	}

	static clsDate DecreaseDateByXWeeks(short weekDecreasing, clsDate date) {

		date = DecreaseDateByOneWeek(date, weekDecreasing * 7);

		return date;

	}
	clsDate DecreaseDateByXWeeks(short weekDecreasing) {
		return DecreaseDateByXWeeks(weekDecreasing, *this);
	}


	static clsDate IncreaseDateByOneMonth(clsDate date) {

		if (IsLastMonthInYear(date._Month)) {

			date._Month = 1;
			date._Year++;

		}
		else {

			date._Month++;

		}

		date._Day > DaysInMonth(date._Year, date._Month) ? date._Day = DaysInMonth(date._Year, date._Month) : date._Day = date._Day;

		return date;

	}
	clsDate IncreaseDateByOneMonth() {
		return IncreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate date) {

		if (date._Month == 1) {

			date._Month = 12;
			date._Year--;

		}
		else {

			date._Month--;

		}

		date._Day > DaysInMonth(date._Year, date._Month) ? date._Day = DaysInMonth(date._Year, date._Month) : date._Day = date._Day;

		return date;

	}
	clsDate DecreaseDateByOneMonth() {
		return DecreaseDateByOneMonth(*this);
	}


	static clsDate IncreaseDateByXMonths(short monthAdding, clsDate date) {

		for (short i = 0; i < monthAdding; i++) {

			date = IncreaseDateByOneMonth(date);

		}

		return date;

	}
	clsDate IncreaseDateByXMonths(short monthAdding) {
		return IncreaseDateByXMonths(monthAdding, *this);
	}

	static clsDate DecreaseDateByXMonths(short monthDecreasing, clsDate date) {

		for (short i = monthDecreasing; i > 0; i--) {

			date = DecreaseDateByOneMonth(date);

		}

		return date;

	}
	clsDate DecreaseDateByXMonths(short monthDecreasing) {
		return DecreaseDateByXMonths(monthDecreasing, *this);
	}


	static clsDate IncreaseDateByOneYear(clsDate date, short increase = 1) {

		date._Year += increase;

		date._Day > DaysInMonth(date._Year, date._Month) ? date._Day = DaysInMonth(date._Year, date._Month) : date._Day = date._Day;

		return date;

	}
	clsDate IncreaseDateByOneYear(short increase = 1) {
		return IncreaseDateByOneYear(*this, increase);
	}

	static clsDate DecreaseDateByOneYear(clsDate date, short Decrease = 1) {

		date._Year -= Decrease;

		date._Day > DaysInMonth(date._Year, date._Month) ? date._Day = DaysInMonth(date._Year, date._Month) : date._Day = date._Day;

		return date;

	}
	clsDate DecreaseDateByOneYear(short Decrease = 1) {
		return DecreaseDateByOneYear(*this, Decrease);
	}


	static clsDate IncreaseDateByXYears(short yearAdding, clsDate date) {

		date = IncreaseDateByOneYear(date, yearAdding);

		return date;

	}
	clsDate IncreaseDateByXYears(short yearAdding) {
		return IncreaseDateByXYears(yearAdding, *this);
	}

	static clsDate DecreaseDateByXYears(short yearDecreasing, clsDate date) {

		date = DecreaseDateByOneYear(date, yearDecreasing);

		return date;

	}
	clsDate DecreaseDateByXYears(short yearDecreasing) {
		return DecreaseDateByXYears(yearDecreasing, *this);
	}


	static clsDate IncreaseDateByXYearsFaster(short yearAdding, clsDate date) {

		date._Year += yearAdding;

		return date;

	}
	clsDate IncreaseDateByXYearsFaster(short yearAdding) {
		return IncreaseDateByXYearsFaster(yearAdding, *this);
	}

	static clsDate DecreaseDateByXYearsFaster(short yearDecreasing, clsDate date) {

		date._Year -= yearDecreasing;

		return date;

	}
	clsDate DecreaseDateByXYearsFaster(short yearDecreasing) {
		return DecreaseDateByXYearsFaster(yearDecreasing, *this);
	}


	static clsDate IncreaseDateByOneDecade(clsDate date, short increase = 1) {

		date._Year += increase * 10;

		return date;

	}
	clsDate IncreaseDateByOneDecade(short increase = 1) {
		return IncreaseDateByOneDecade(*this, increase);
	}

	static clsDate DecreaseDateByOneDecade(clsDate date, short Decrease = 1) {

		date._Year -= Decrease * 10;

		return date;

	}
	clsDate DecreaseDateByOneDecade(short Decrease = 1) {
		return DecreaseDateByOneDecade(*this, Decrease);
	}


	static clsDate IncreaseDateByXDecades(short decadeAdding, clsDate date) {

		date = IncreaseDateByOneDecade(date, decadeAdding);

		return date;

	}
	clsDate IncreaseDateByXDecades(short decadeAdding) {
		return IncreaseDateByXDecades(decadeAdding, *this);
	}

	static clsDate DecreaseDateByXDecades(short decadeDecreasing, clsDate date) {

		date = DecreaseDateByOneDecade(date, decadeDecreasing);

		return date;

	}
	clsDate DecreaseDateByXDecades(short decadeDecreasing) {
		return DecreaseDateByXDecades(decadeDecreasing, *this);
	}


	static clsDate IncreaseDateByXDecadesFaster(short decadeAdding, clsDate date) {

		date._Year += decadeAdding * 10;

		return date;

	}
	clsDate IncreaseDateByXDecadesFaster(short decadeAdding) {
		return IncreaseDateByXDecadesFaster(decadeAdding, *this);
	}

	static clsDate DecreaseDateByXDecadesFaster(short decadeDecreasing, clsDate date) {

		date._Year -= decadeDecreasing * 10;

		return date;

	}
	clsDate DecreaseDateByXDecadesFaster(short decadeDecreasing) {
		return DecreaseDateByXDecadesFaster(decadeDecreasing, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate date, short increase = 1) {

		date._Year += increase * 100;

		return date;

	}
	clsDate IncreaseDateByOneCentury(short increase = 1) {
		return IncreaseDateByOneCentury(*this, increase);
	}

	static clsDate DecreaseDateByOneCentury(clsDate date, short Decrease = 1) {

		date._Year -= Decrease * 100;

		return date;

	}
	clsDate DecreaseDateByOneCentury(short Decrease = 1) {
		return DecreaseDateByOneCentury(*this, Decrease);
	}


	static clsDate IncreaseDateByOneMillennium(clsDate date, short increase = 1) {

		date._Year += increase * 1000;

		return date;

	}
	clsDate IncreaseDateByOneMillennium(short increase = 1) {	
		return IncreaseDateByOneMillennium(*this, increase);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate date, short Decrease = 1) {

		date._Year -= Decrease * 1000;

		return date;

	}
	clsDate DecreaseDateByOneMillennium(short Decrease = 1) {
		return DecreaseDateByOneMillennium(*this, Decrease);
	}


	static int YourAgeInDays(clsDate birthday) {

		Mytime::stTime date;
		Mytime::GetSpecificDateTiming(date);

		int counter = 0;

		LeapYear(birthday._Year) ? counter += 366 : counter += 365;
		counter -= GetTotalOfDayFromTheBeginningOfYear(birthday._Year, birthday._Month, birthday._Day);

		while (true) {

			birthday._Year++;

			if (birthday._Year != date.year) {

				LeapYear(birthday._Year) ? counter += 366 : counter += 365;

			}
			else {

				counter += GetTotalOfDayFromTheBeginningOfYear(date.year, date.monthOfYear, date.dayOfMonth);
				return counter;

			}

		}


	}
	int YourAgeInDays() {

		return YourAgeInDays(*this);

	}

	static short DiffreneceBetweenTwoDates(clsDate date1, clsDate date2, bool includeingEndDay = false) {

		int day = 0;
		short increase = 1;

		if (Date1BeforeDate2(date1, date2)) {

			while (Date1BeforeDate2(date1, date2)) {

				day++;
				date1 = IncreaseDateByOneDay(date1);

			}

		}
		else {

			increase = -1;

			while (!Date1BeforeDate2(date1, date2)) {

				day--;
				date2 = IncreaseDateByOneDay(date2);

			}
		}

		return includeingEndDay ? ++day * increase : day * increase;

	}
	short DiffreneceBetweenTwoDates(clsDate date2, bool includeingEndDay = false) {

		return DiffreneceBetweenTwoDates(*this, date2, includeingEndDay);

	}


	static bool IsEndOfWeek(short number) {

		return number != 6 ? false : true;

	}

	static bool IsWeekend(short number) {

		return (number == 6 || number == 5) ? true : false;

	}

	static bool IsBusiness(short number) {

		return !IsWeekend(number);

	}


	static short DayUntilTheEndOfWeek(short number) {

		return 6 - number;

	}

	static short DayUntilTheEndOfMonth(clsDate date) {

		return DaysInMonth(date._Year, date._Month) - date._Day;

	}
	short DayUntilTheEndOfMonth() {
		return DayUntilTheEndOfMonth(*this);
	}

	static short DayUntilTheEndOfYear(clsDate date) {

		return DaysInYear(date._Year) - GetTotalOfDayFromTheBeginningOfYear(date._Year, date._Month, date._Day);

	}
	short DayUntilTheEndOfYear() {
		return DayUntilTheEndOfYear(*this);
	}


	static short VacationDays(clsDate fromDate, clsDate toDate) {

		short days = 0;
		while (Date1BeforeDate2(fromDate, toDate)) {

			if (!IsWeekend(CalculatorTheDay(fromDate._Year, fromDate._Month, fromDate._Day)))
				days++;

			fromDate = IncreaseDateByOneDay(fromDate);

		}

		return days;

	}
	short VacationDays(clsDate toDate) {
		return VacationDays(*this, toDate);
	}

	static clsDate ReturnVacationDays(clsDate fromDate, short vactionDays) {

		short counter = 0;
		while (counter < vactionDays) {

			if (!IsWeekend(CalculatorTheDay(fromDate._Year, fromDate._Month, fromDate._Day)))
				counter++;

			fromDate = IncreaseDateByOneDay(fromDate);

		}

		return fromDate;

	}
	clsDate ReturnVacationDays(short vactionDays) {
		return ReturnVacationDays(*this, vactionDays);
	}


	static short PeriodLength(clsDate startDate1, clsDate endDate1, bool includeingEndDay = false) {

		return DiffreneceBetweenTwoDates(startDate1, endDate1, includeingEndDay);

	}

	static bool IsOverlapPeriods(clsDate startDate1, clsDate endDate1, clsDate startDate2, clsDate endDate2) {

		if (Date1EqualDate2(startDate1, startDate2))
			return true;
		else if (Date1EqualDate2(startDate1, endDate2))
			return true;
		else if (Date1EqualDate2(endDate1, startDate2))
			return true;
		else if (Date1EqualDate2(endDate1, endDate2))
			return true;


		if (Date1BeforeDate2(startDate1, startDate2)) {

			return Date1BeforeDate2(startDate1, startDate2) && Date1AfterDate2(endDate1, startDate2);

		}

		IsOverlapPeriods(startDate2, endDate1, startDate1, endDate2);

	}

	static bool IsOverlapPeriodsFatster(clsDate startDate1, clsDate endDate1, clsDate startDate2, clsDate endDate2) {

		return !(Date1AfterDate2(startDate2, endDate1) || Date1AfterDate2(startDate1, endDate2));

	}

	static bool IsDayOverlapInPeriod(clsDate startDate1, clsDate endDate1, clsDate day) {

		return !(Date1AfterDate2(day, endDate1) || Date1AfterDate2(startDate1, day));

	}

	static short CountOverlapDays(clsDate startDate1, clsDate endDate1, clsDate startDate2, clsDate endDate2) {

		if (!IsOverlapPeriodsFatster(startDate1, endDate1, startDate2, endDate2))
			return 0; // Periods are not overlap.

		short dayCounter = 0;
		if (Date1BeforeDate2(startDate1, startDate2)) {

			if (Date1BeforeDate2(endDate2, endDate1))
				return PeriodLength(startDate2, endDate2);

			while (Date1BeforeDate2(startDate2, endDate1)) {

				dayCounter++;
				startDate2 = IncreaseDateByOneDay(startDate2);

			}

			return dayCounter;

		}

		CountOverlapDays(startDate2, endDate2, startDate1, endDate1);

	}



	static bool ValideDate(clsDate date) {

		return (DaysInMonth(date._Year, date._Month) < date._Day || date._Day < 1) ? false : (date._Month < 1 || date._Month > 12) ? false : true;

	}
	bool ValideDate() {
		return ValideDate(*this);
	}

	static clsDate StringToDate(string date) {

		clsDate stDate;
		vector <string> result;

		clsString::Spilt(date, "/", result);

		stDate._Day = std::stoi(result[0]);
		stDate._Month = std::stoi(result[1]);
		stDate._Year = std::stoi(result[2]);

		return stDate;

	}

	static string DateToString(clsDate date) {

		return std::to_string(date._Day) + '/' + std::to_string(date._Month) + '/' + std::to_string(date._Year);

	}
	string DateToString() {
		return DateToString(*this);
	}
	static string DateAndTimeToString(clsDate date) {

		return std::to_string(date._Day) + '/' + std::to_string(date._Month) + '/' + std::to_string(date._Year) + " - " +
			std::to_string(date._Hour) + ':' + std::to_string(date._Mintue) + ':' + std::to_string(date._Second);

	}
	string DateAndTimeToString() {
		return DateAndTimeToString(*this);
	}


	static enum enFormatingDate { DayFirst = 0, MonthFirst = 1, YearFirst = 3, Separated = 4 };

	static void  FormatDate(clsDate date, string demilitor, enFormatingDate formatDate) {

		switch (formatDate) {

		case enFormatingDate::DayFirst:
			cout << date._Day << demilitor << date._Month << demilitor << date._Year << '\n';
			break;

		case enFormatingDate::MonthFirst:
			cout << date._Month << demilitor << date._Day << demilitor << date._Year << '\n';
			break;

		case enFormatingDate::YearFirst:
			cout << date._Year << demilitor << date._Month << demilitor << date._Day << '\n';
			break;

		case enFormatingDate::Separated:
			cout << "Day: " << date._Day << ", Month: " << date._Month << ", Year: " << date._Year << '\n';
			break;

		}

	}
	void  FormatDate(string demilitor, enFormatingDate formatDate) {
		FormatDate(*this, demilitor, formatDate);
	}

	static string FormateDate(clsDate date, string DateFormat = "dd/mm/yyyy") {

		string formattedDate = "";

		formattedDate = clsString::ReplaceWord(DateFormat, "dd", std::to_string(date._Day));
		formattedDate = clsString::ReplaceWord(formattedDate, "mm", std::to_string(date._Month));
		formattedDate = clsString::ReplaceWord(formattedDate, "yyyy", std::to_string(date._Year));

		return formattedDate;

	}
	string FormateDate(string DateFormat = "dd/mm/yyyy") {

		return FormateDate(*this, DateFormat);

	}

};

