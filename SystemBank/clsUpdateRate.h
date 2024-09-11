#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsInput.h"
#include "clsString.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateRate : protected clsScreen {

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

	static void ShowUpdateCurrencyRate() {

		ScreenHeader("\tUpdate Currency Rate");

		string code = clsString::ChangeLettersCase(clsInput::ReadText("Enter code number? "), true);

		clsCurrency currency = clsCurrency::FindByCode(code);

		if (!currency.IsEmpty()) {

			cout << "\nCountry Found :-)\n";

		}
		else {

			cout << "\nCountry Was not Found :-(\n";

		}

		_PrintCountryCard(currency);

		char areYousure = clsInput::ReadCharacter("\nAre you sure do you want to update currency? y/n? ");

		if (tolower(areYousure) == 'y') {
			cout << "\n\n\nUpdate currency Rate\n" << clsInput::Format(25, "_") << '\n';
			currency.UpdateRate(clsInput::ReadNumberFrom("Enter New Rate: ", 0.0f));

			_PrintCountryCard(currency);
		}
		else {

			return;

		}
	}


};

