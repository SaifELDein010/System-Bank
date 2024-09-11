#pragma once

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

namespace readIn {


	// vaildet if take anything else numebr?
	int VaildationNumber(int number) {

		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a vaild one: " << std::endl;

			cin >> number;

		}

		return number;

	}



	int ReadNumber(string message) {

		int number = 0;

		cout << message;
		cin >> number;

		number = VaildationNumber(number);

		return number;

	}

	int ReadFromToRangeOfNumbers(string message, int from, int to) {

		int number = 0;

		do {

			cout << message;
			cin >> number;

			number = VaildationNumber(number);

		} while (number < from || number > to);

		return number;

	}

	int ReadFromNumber(string message, int from) {

		int number = 0;

		do {

			cout << message;
			cin >> number;

			number = VaildationNumber(number);

		} while (number < from);

		return number;

	}

	int ReadToNumber(string message, int to) {

		int number = 0;

		do {

			cout << message;
			cin >> number;

			number = VaildationNumber(number);

		} while (number > to);

		return number;

	}

	short ReadFromToRangeOfNumbersShort(string message, int from, int to) {

		short number = 0;

		do {

			cout << message;
			cin >> number;

			number = VaildationNumber(number);

		} while (number < from || number > to);

		return number;

	}


	double ReadFromNumberDouble(string message, int from) {

		double number = 0;

		do {

			cout << message;
			cin >> number;

			number = VaildationNumber(number);

		} while (number < from);

		return number;

	}

	string ReadText(string message) {

		string name = "";

		cout << message;
		getline(cin >> std::ws, name);

		return name;

	}

	char ReadCharacter(string message) {

		char letter = ' ';

		cout << message;
		cin >> letter;

		return letter;

	}


	string Format(short number, string form) {

		string word = "";

		for (short i = 0; i < number; i++) {

			word += form;

		}

		return word;

	}

}