#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "readInput.h"
#include "myString.h"
#include "timing.h"
#include "myString.h"


using std::cout;
using std::cin;
using std::string;
using std::vector;



namespace myDate {

	struct stDate {

		short day = 0;
		short month = 0;
		short year = 0;


	};


	bool LeapYear(short year) {

		return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);

	}

	short DaysInYear(short year) {

		return LeapYear(year) ? 366 : 365;

	}

	short HoursInYear(short year) {

		return DaysInYear(year) * 24;

	}

	int MinutesInYear(short year) {

		return HoursInYear(year) * 60;

	}

	int SecondsInYear(short year) {

		return MinutesInYear(year) * 60;

	}


	short DaysInMonth(short year, short month) {

		short days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return LeapYear(year) && month == 2 ? 29 : days[month];

	}


	short CalculatorTheDay(short year, short month, short day) {

		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

	}

	short CalculatorTheDay(stDate date) {

		return CalculatorTheDay(date.year, date.month, date.day);

	}

	string DayName(short day) {

		string Days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return Days[day];

	}


	short GetTotalOfDayFromTheBeginningOfYear(short year, short month, short day) {

		short total = 0;

		for (short i = 1; i < month; i++) {

			total += DaysInMonth(year, i);

		}

		return total + day;

	}

	short GetTotalOfDayFromTheBeginningOfYear(stDate date) {

		return GetTotalOfDayFromTheBeginningOfYear(date.year, date.month, date.day);

	}
	
	stDate ReadDate() {

		stDate date;

		date.year = readIn::ReadNumber("\n    Enter a year: ");
		date.month = readIn::ReadNumber("    Enter a month: ");
		date.day = readIn::ReadNumber("    Enter a day: ");

		return date;

	}

	stDate ReadCurrentDate() {

		stDate date;

		Mytime::stTime time;
		Mytime::GetSpecificDateTiming(time);

		date.year = time.year;
		date.month = time.monthOfYear;
		date.day = time.dayOfMonth;

		return date;

	}
	

	stDate AddDaysToDate(short daysToadding, short year, short month, short day) {

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

		stDate date;

		date.year = year;
		date.day = dayOrder;

		return date;

	}

	stDate DateFromDayOrderInAYear(short dayOrder, short year) {

		stDate date;
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

		date.day = dayOrder;
		date.month = currentMonth;
		date.year = year;

		return date;

	}


	bool Date1BeforeDate2(stDate date1, stDate date2) {

		if (date1.year < date2.year)
			return true;

		if (date1.year > date2.year)
			return false;

		if (date2.year == date1.year) {

			return GetTotalOfDayFromTheBeginningOfYear(date1.year, date1.month, date1.day) <
				GetTotalOfDayFromTheBeginningOfYear(date2.year, date2.month, date2.day) ? true : false;

		}

	}

	bool Date1EqualDate2(stDate date1, stDate date2) {

		return date1.year != date2.year ? false : date1.month != date2.month ? false : date1.day != date2.day ? false : true;

	}

	bool Date1AfterDate2(stDate date1, stDate date2) {

		return !(Date1BeforeDate2(date1, date2)) && !(Date1EqualDate2(date1, date2));

	}


	enum enResultFromComber { Equal = 0, After = 1, Before = 2 };
	enResultFromComber ComberTwoDates(stDate date1, stDate date2) {

		return Date1BeforeDate2(date1, date2) ? enResultFromComber::Before : Date1EqualDate2(date1, date2) ? enResultFromComber::Equal :
			enResultFromComber::After;

	}

	void PrintReultOfComberTwoDates(stDate date1, stDate date2) {

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


	bool IsLastDayInMonth(stDate date) {

		return date.day == DaysInMonth(date.year, date.month);

	}

	bool IsLastMonthInYear(short month) {

		return month == 12;

	}



	stDate IncreaseDateByOneDay(stDate date) {

		if (IsLastDayInMonth(date)) {

			date.day = 1;

			if (IsLastMonthInYear(date.month)) {

				date.month = 1;
				date.year++;

			}
			else {

				date.month++;

			}

		}
		else {

			date.day++;

		}

		return date;

	}

	stDate DecreaseDateByOneDay(stDate date) {

		if (date.day == 1) {


			if (date.month == 1) {

				date.month = 12;
				date.year--;

			}
			else {

				date.month--;

			}

			date.day = myDate::DaysInMonth(date.year, date.month);

		}
		else {

			date.day--;

		}

		return date;

	}


	stDate IncreaseDateByXDays(short dayAdding, stDate date) {

		for (short i = 0; i < dayAdding; i++) {

			date = IncreaseDateByOneDay(date);

		}

		return date;

	}

	stDate DecreaseDateByXDays(short dayDecreasing, stDate date) {

		for (short i = dayDecreasing; i > 0; i--) {

			date = DecreaseDateByOneDay(date);

		}

		return date;

	}


	stDate IncreaseDateByOneWeek(stDate date, short increase = 7) {

		return date = IncreaseDateByXDays(increase, date);

	}

	stDate DecreaseDateByOneWeek(stDate date, short decrease = 7) {

		return date = DecreaseDateByXDays(decrease, date);

	}


	stDate IncreaseDateByXWeeks(short weekAdding, stDate date) {

		date = IncreaseDateByOneWeek(date, weekAdding * 7);

		return date;

	}

	stDate DecreaseDateByXWeeks(short weekDecreasing, stDate date) {

		date = DecreaseDateByOneWeek(date, weekDecreasing * 7);

		return date;

	}



	stDate IncreaseDateByOneMonth(stDate date) {

		if (IsLastMonthInYear(date.month)) {

			date.month = 1;
			date.year++;

		}
		else {

			date.month++;

		}

		date.day > DaysInMonth(date.year, date.month) ? date.day = DaysInMonth(date.year, date.month) : date.day = date.day;

		return date;

	}

	stDate DecreaseDateByOneMonth(stDate date) {

		if (date.month == 1) {

			date.month = 12;
			date.year--;

		}
		else {

			date.month--;

		}

		date.day > DaysInMonth(date.year, date.month) ? date.day = DaysInMonth(date.year, date.month) : date.day = date.day;

		return date;

	}


	stDate IncreaseDateByXMonths(short monthAdding, stDate date) {

		for (short i = 0; i < monthAdding; i++) {

			date = IncreaseDateByOneMonth(date);

		}

		return date;

	}

	stDate DecreaseDateByXMonths(short monthDecreasing, stDate date) {

		for (short i = monthDecreasing; i > 0; i--) {

			date = DecreaseDateByOneMonth(date);

		}

		return date;

	}


	stDate IncreaseDateByOneYear(stDate date, short increase = 1) {

		date.year += increase;

		date.day > DaysInMonth(date.year, date.month) ? date.day = DaysInMonth(date.year, date.month) : date.day = date.day;

		return date;

	}

	stDate DecreaseDateByOneYear(stDate date, short Decrease = 1) {

		date.year -= Decrease;

		date.day > DaysInMonth(date.year, date.month) ? date.day = DaysInMonth(date.year, date.month) : date.day = date.day;

		return date;

	}



	stDate IncreaseDateByXYears(short yearAdding, stDate date) {

		date = IncreaseDateByOneYear(date, yearAdding);

		return date;

	}

	stDate DecreaseDateByXYears(short yearDecreasing, stDate date) {

		date = DecreaseDateByOneYear(date, yearDecreasing);

		return date;

	}


	stDate IncreaseDateByXYearsFaster(short yearAdding, stDate date) {

		date.year += yearAdding;

		return date;

	}

	stDate DecreaseDateByXYearsFaster(short yearDecreasing, stDate date) {

		date.year -= yearDecreasing;

		return date;

	}



	stDate IncreaseDateByOneDecade(stDate date, short increase = 1) {

		date.year += increase * 10;

		return date;

	}

	stDate DecreaseDateByOneDecade(stDate date, short Decrease = 1) {

		date.year -= Decrease * 10;

		return date;

	}


	stDate IncreaseDateByXDecades(short decadeAdding, stDate date) {

		date = IncreaseDateByOneDecade(date, decadeAdding);

		return date;

	}

	stDate DecreaseDateByXDecades(short decadeDecreasing, stDate date) {

		date = DecreaseDateByOneDecade(date, decadeDecreasing);

		return date;

	}


	stDate IncreaseDateByXDecadesFaster(short decadeAdding, stDate date) {

		date.year += decadeAdding * 10;

		return date;

	}

	stDate DecreaseDateByXDecadesFaster(short decadeDecreasing, stDate date) {

		date.year -= decadeDecreasing * 10;

		return date;

	}


	stDate IncreaseDateByOneCentury(stDate date, short increase = 1) {

		date.year += increase * 100;

		return date;

	}

	stDate DecreaseDateByOneCentury(stDate date, short Decrease = 1) {

		date.year -= Decrease * 100;

		return date;

	}


	stDate IncreaseDateByOneMillennium(stDate date, short increase = 1) {

		date.year += increase * 1000;

		return date;

	}

	stDate DecreaseDateByOneMillennium(stDate date, short Decrease = 1) {

		date.year -= Decrease * 1000;

		return date;

	}



	int YourAgeInDays(stDate birthday) {

		Mytime::stTime date;
		Mytime::GetSpecificDateTiming(date);

		int counter = 0;

		LeapYear(birthday.year) ? counter += 366 : counter += 365;
		counter -= GetTotalOfDayFromTheBeginningOfYear(birthday.year, birthday.month, birthday.day);

		while (true) {

			birthday.year++;

			if (birthday.year != date.year) {

				LeapYear(birthday.year) ? counter += 366 : counter += 365;

			}
			else {

				counter += GetTotalOfDayFromTheBeginningOfYear(date.year, date.monthOfYear, date.dayOfMonth);
				return counter;

			}

		}


	}


	short DiffreneceBetweenTwoDates(stDate date1, stDate date2, bool includeingEndDay = false) {

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


	bool IsEndOfWeek(short number) {

		return number != 6 ? false : true;

	}

	bool IsWeekend(short number) {

		return (number == 6 || number == 5) ? true : false;

	}

	bool IsBusiness(short number) {

		return !IsWeekend(number);

	}


	short DayUntilTheEndOfWeek(short number) {

		return 6 - number;

	}

	short DayUntilTheEndOfMonth(stDate date) {

		return DaysInMonth(date.year, date.month) - date.day;

	}

	short DayUntilTheEndOfYear(stDate date) {

		return DaysInYear(date.year) - myDate::GetTotalOfDayFromTheBeginningOfYear(date.year, date.month, date.day);

	}


	short VacationDays(stDate fromDate, stDate toDate) {

		short days = 0;
		while (Date1BeforeDate2(fromDate, toDate)) {

			if (!IsWeekend(CalculatorTheDay(fromDate)))
				days++;

			fromDate = IncreaseDateByOneDay(fromDate);

		}

		return days;

	}

	stDate ReturnVacationDays(stDate fromDate, short vactionDays) {

		short counter = 0;
		while (counter < vactionDays) {

			if (!IsWeekend(CalculatorTheDay(fromDate)))
				counter++;

			fromDate = IncreaseDateByOneDay(fromDate);

		}

		return fromDate;

	}


	short PeriodLength(stDate startDate1, stDate endDate1, bool includeingEndDay = false) {

		return DiffreneceBetweenTwoDates(startDate1, endDate1, includeingEndDay);

	}

	bool IsOverlapPeriods(stDate startDate1, stDate endDate1, stDate startDate2, stDate endDate2) {

		if (myDate::Date1EqualDate2(startDate1, startDate2))
			return true;
		else if (myDate::Date1EqualDate2(startDate1, endDate2))
			return true;
		else if (myDate::Date1EqualDate2(endDate1, startDate2))
			return true;
		else if (myDate::Date1EqualDate2(endDate1, endDate2))
			return true;


		if (myDate::Date1BeforeDate2(startDate1, startDate2)) {

			return myDate::Date1BeforeDate2(startDate1, startDate2) && myDate::Date1AfterDate2(endDate1, startDate2);

		}

		IsOverlapPeriods(startDate2, endDate1, startDate1, endDate2);

	}

	bool IsOverlapPeriodsFatster(stDate startDate1, stDate endDate1, stDate startDate2, stDate endDate2) {

		return !(myDate::Date1AfterDate2(startDate2, endDate1) || myDate::Date1AfterDate2(startDate1, endDate2));

	}

	bool IsDayOverlapInPeriod(stDate startDate1, stDate endDate1, stDate day) {

		return !(myDate::Date1AfterDate2(day, endDate1) || myDate::Date1AfterDate2(startDate1, day));

	}

	short CountOverlapDays(stDate startDate1, stDate endDate1, stDate startDate2, stDate endDate2) {

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


	bool ValideDate(stDate date) {

		return (DaysInMonth(date.year, date.month) < date.day || date.day < 1) ? false : (date.month < 1 || date.month > 12) ? false : true;

	}
	

	stDate StringToDate(string date) {

		stDate stDate;
		vector <string> result;

		str::SpiltString(date, "/", result);

		stDate.day = std::stoi(result[0]);
		stDate.month = std::stoi(result[1]);
		stDate.year = std::stoi(result[2]);

		return stDate;

	}

	string DateToString(stDate date) {

		/*vector <string> result;
		result.push_back(std::to_string(date.day));
		result.push_back(std::to_string(date.month));
		result.push_back(std::to_string(date.year));

		string stringDate = str::JoinString(result, "/");

		return stringDate;*/

		return std::to_string(date.day) + '/' + std::to_string(date.month) + '/' + std::to_string(date.year);

	}


	enum enFormatingDate { DayFirst = 0, MonthFirst = 1, YearFirst = 3, Separated = 4 };

	void  FormatDate(stDate date, string demilitor, enFormatingDate formatDate) {

		switch (formatDate) {

		case enFormatingDate::DayFirst:
			cout << date.day << demilitor << date.month << demilitor << date.year << '\n';
			break;

		case enFormatingDate::MonthFirst:
			cout << date.month << demilitor << date.day << demilitor << date.year << '\n';
			break;

		case enFormatingDate::YearFirst:
			cout << date.year << demilitor << date.month << demilitor << date.day << '\n';
			break;

		case enFormatingDate::Separated:
			cout << "Day: " << date.day << ", Month: " << date.month << ", Year: " << date.year << '\n';
			break;

		}

	}

	string FormateDate(stDate date, string DateFormat = "dd/mm/yyyy") {

		string formattedDate = "";

		formattedDate = str::ReplaceWord(DateFormat, "dd", std::to_string(date.day));
		formattedDate = str::ReplaceWord(formattedDate, "mm", std::to_string(date.month));
		formattedDate = str::ReplaceWord(formattedDate, "yyyy", std::to_string(date.year));

		return formattedDate;

	}


}