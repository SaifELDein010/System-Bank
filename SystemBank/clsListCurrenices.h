#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsInput.h"
#include "clsScreen.h"


class clsListCurrenices : protected clsScreen {

private:

	static void _Header() {

		cout << clsInput::Format(10, " ") << clsInput::Format(104, "_") << '\n';

		cout << '\n' << clsInput::Format(10, " ")
			<< "|" << std::left << std::setw(30) << "Country"
			<< "|" << std::left << std::setw(10) << "Code"
			<< "|" << std::left << std::setw(30) << "Name"
			<< "|" << std::left << std::setw(9) << "Rate/($1)\n";


		cout << clsInput::Format(10, " ") << clsInput::Format(104, "_") << "\n\n";

	}

	static void _FormattingInfo(clsCurrency currencyRate) {

		cout << clsInput::Format(10, " ") << "|" << std::left << std::setw(30) << currencyRate.Country();
		cout << "|" << std::left << std::setw(10) << currencyRate.CurrencyCode();
		cout << "|" << std::left << std::setw(30) << currencyRate.CurrencyName();
		cout << "|" << std::left << std::setw(9) << currencyRate.Rate();

	}

public:

	static void ShowClientList() {

		vector <clsCurrency> currenices = clsCurrency::GetCurrenciesList();

		short manyOfCountry = currenices.size();

		string title = "\t       currenices list";
		string subTitle = "\t     (" + to_string(currenices.size()) + ") Country(s).";

		// client list(..) client (s).

		ScreenHeader(title, subTitle);
		_Header();

		if (manyOfCountry == 0) {
			cout << "\t\t\t\tNo Country Available in the system!";
		}
		else {

			for (clsCurrency& n : currenices) {

				_FormattingInfo(n);
				cout << '\n';

			}

			cout << "\n" << clsInput::Format(10, " ") << clsInput::Format(104, "_") << '\n';

		}

	}



};