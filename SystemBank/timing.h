#pragma once
#pragma warning(disable : 4996)

#include <ctime>
#include <iostream>

using std::cout;
using std::cin;
using std::string;


namespace Mytime {


	string GetLocalTime() {

		time_t t = std::time(0);
		char* Timing = std::ctime(&t);

		return Timing;

	}

	string GetUTCTime() {

		time_t t = std::time(0);
		char* Timing = std::ctime(&t);

		tm* time0 = std::gmtime(&t);
		Timing = std::asctime(time0);
		
		return Timing;

	}

	struct stTime {

		int year				   = 0;
		int monthOfYear			   = 0;
		int dayOfMonth			   = 0;
		int hours				   = 0;
		int minutes				   = 0;
		int seconds				   = 0;
		int daySinceSunday		   = 0;
		int daySinceJan			   = 0;
		int hourOfDayLightSaving   = 0;
		

	};

	stTime GetSpecificDateTiming(stTime &DateAndTiming) {

		time_t t = std::time(0);
		tm* Timing = std::localtime(&t);

		DateAndTiming.year = Timing->tm_year + 1900;
		DateAndTiming.monthOfYear = Timing->tm_mon + 1;
		DateAndTiming.daySinceSunday = Timing->tm_wday;
		DateAndTiming.hours = Timing->tm_hour;
		DateAndTiming.hourOfDayLightSaving = Timing->tm_isdst;
		DateAndTiming.minutes = Timing->tm_min;
		DateAndTiming.daySinceJan = Timing->tm_yday;
		DateAndTiming.dayOfMonth = Timing->tm_mday;
		DateAndTiming.seconds = Timing->tm_sec;

		return DateAndTiming;

	}



}