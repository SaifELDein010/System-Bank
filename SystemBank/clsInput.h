#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using std::cout;
using std::cin;
using std::string;

class clsDate;

class clsInput {


private:

	static int _VaildationNumber(int number) {

		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a vaild one: " << std::endl;

			cin >> number;

		}

		return number;

	}


public:

	static short ReadShortNumber(string message) {

		short number = 0;

		cout << message;
		cin >> number;

		number = _VaildationNumber(number);

		return number;

	}

	static short ReadNumber(string message, short from, short to) {

		short number = 0;

		cout << message;
		cin >> number;

		while (number < from || number > to) {

			cout << number << " Is out of range between[" << from << ':' << to << "] \n";
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}

	static short ReadNumberFrom(string message, short from) {

		short number = 0;

		cout << message;
		cin >> number;

		while (number < from) {

			cout << number << " Is out of range\n" << message;
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}

	static short ReadNumberTo(string message, short to) {

		short number = 0;

		cout << message;
		cin >> number;

		while (number > to) {

			cout << number << " Is out of range\n";
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}


	static int ReadNumber(string message) {

		int number = 0;

		cout << message;
		cin >> number;

		number = _VaildationNumber(number);

		return number;

	}

	static int ReadNumber(string message, int from, int to) {

		int number = 0;

		cout << message;
		cin >> number;

		while (number < from || number > to) {

			cout << number << " Is out of range between[" << from << ':' << to << "] \n" << message;
			cin >> number;

			number = _VaildationNumber(number);

		}
	
		return number;

	}

	static int ReadNumberFrom(string message, int from) {

		int number = 0;

		cout << message;
		cin >> number;

		while (number < from) {

			cout << number << " Is out of range\n" << message;
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}

	static int ReadNumberTo(string message, int to) {

		int number = 0;

		cout << message;
		cin >> number;

		while (number > to) {

			cout << number << " Is out of range\n";
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}


	static float ReadFloatNumber(string message) {

		float number = 0.0f;

		cout << message;
		cin >> number;

		number = _VaildationNumber(number);

		return number;

	}

	static float ReadNumber(string message, float from, float to) {

		float number = 0.0f;

		cout << message;
		cin >> number;

		while (number < from || number > to) {

			cout << number << " Is out of range between[" << from << ':' << to << "] \n";
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}

	static float ReadNumberFrom(string message, float from) {

		float number = 0.0f;

		cout << message;
		cin >> number;

		while (number < from) {

			cout << number << " Is out of range\n";
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}

	static float ReadNumberTo(string message, float to) {

		float number = 0.0f;

		cout << message;
		cin >> number;

		while (number > to) {

			cout << number << " Is out of range\n";
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}


	static double ReadDoubleNumber(string message) {

		double number = 0.0;

		cout << message;
		cin >> number;

		number = _VaildationNumber(number);

		return number;

	}

	static double ReadNumber(string message, double from, double to) {

		double number = 0.0;

		cout << message;
		cin >> number;

		while (number < from || number > to) {

			cout << number << " Is out of range between[" << from << ':' << to << "] \n";
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}

	static double ReadNumberFrom(string message, double from) {

		double number = 0.0;

		cout << message;
		cin >> number;

		while (number < from) {

			cout << number << " Is out of range\n" << message;
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}

	static double ReadNumberTo(string message, double to) {

		double number = 0.0;

		cout << message;
		cin >> number;

		while (number > to) {

			cout << number << " Is out of range\n";
			cin >> number;

			number = _VaildationNumber(number);

		}

		return number;

	}


	static string ReadText(string message) {

		string name = "";

		cout << message;
		getline(cin >> std::ws, name);

		return name;

	}

	static char ReadCharacter(string message) {

		char letter = ' ';

		cout << message;
		cin >> letter;

		return letter;

	}

	static bool ReadState(string message) {

		bool letter = true;

		cout << message;
		cin >> letter;

		return letter;

	}



	static string Format(short number, string form) {

		string word = "";

		for (short i = 0; i < number; i++) {

			word += form;

		}

		return word;

	}


	static bool IsBetween(short number, short from, short to) {

		if (from > to)
			return IsBetween(number, to, from);

		return !(number < from || number > to);

	}

	static bool IsBetween(int number, int from, int to) {

		if (from > to)
			return IsBetween(number, to, from);

		return !(number < from || number > to);

	}

	static bool IsBetween(float number, float from, float to) {

		if (from > to)
			return IsBetween(number, to, from);

		return !(number < from || number > to);

	}

	static bool IsBetween(double number, double from, double to) {

		if (from > to)
			return IsBetween(number, to, from);

		return !(number < from || number > to);

	}

	/*static bool IsDateBetween(clsDate date, clsDate fromDate, clsDate toDate) {

		if (clsDate::Date1AfterDate2(fromDate, toDate))
			return IsDateBetween(date, toDate, fromDate);

		return !(clsDate::Date1AfterDate2(date, fromDate) || clsDate::Date1AfterDate2(date, toDate));

	}*/

	
	/*static bool IsVaildDate(clsDate* num) {

		return clsDate::ValideDate(*num);

	}*/


};

