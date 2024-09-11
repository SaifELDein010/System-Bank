#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsInput.h"
#include "clsString.h"
#include "clsScreen.h"

using namespace std;


class clsFindCurrency : protected clsScreen {

private:

	static void _PrintCountryCard(clsCurrency currency) {

		cout << "\nCountry Card: \n" << clsInput::Format(25, "_");

		cout << "\nCountry   : " << currency.Country();
		cout << "\nCode      : " << currency.CurrencyCode();
		cout << "\nName      : " << currency.CurrencyName();
		cout << "\nRate/($1) : " << currency.Rate();

		cout << '\n' << clsInput::Format(25, "_");
	}


public:

	static void ShowFindCountry() {

		ScreenHeader("\t   Find Country");

		short number = clsInput::ReadNumber("\nFind By: [1] Code or [2] Country? ", 1, 2);

		string code = "";
		string country = "";

		clsCurrency currency = clsCurrency::FindByCode("");

		switch (number) {

		case 1:
			code = clsString::ChangeLettersCase(clsInput::ReadText("Enter code number? "), true);
			currency = clsCurrency::FindByCode(code);

			break;

		case 2:
			country = clsString::ChangeLettersCase(clsInput::ReadText("Enter country name? "), true);
			currency = clsCurrency::FindByCountry(country);

			break;

		}


		if (!currency.IsEmpty()) {

			cout << "\nCountry Found :-)\n";

		}
		else {

			cout << "\nCountry Was not Found :-(\n";

		}

		_PrintCountryCard(currency);

	}

};