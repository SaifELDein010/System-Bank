#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsInput.h"
#include "clsString.h"
#include "clsScreen.h"

using namespace std;

class clsCurrencyCalculator : protected clsScreen {

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

	static void ShowCurrencyCalculator() {

		ScreenHeader("\tCurrency Calculator");

		string code1 = clsString::ChangeLettersCase(clsInput::ReadText("\nEnter currency 1 code number? "), true);

		while (!clsCurrency::IsCurrencyExist(code1)) {

			code1 = clsInput::ReadText("code not found, Enter another code? ");

		}

		clsCurrency currency1 = clsCurrency::FindByCode(code1);


		string code2 = clsString::ChangeLettersCase(clsInput::ReadText("\nEnter currency 2 code number? "), true);

		while (!clsCurrency::IsCurrencyExist(code2)) {

			code2 = clsInput::ReadText("code not found, Enter another code? ");

		}

		clsCurrency currency2 = clsCurrency::FindByCode(code2);


		float amount = clsInput::ReadFloatNumber("\nEnter amount to exchange: ");
		float exchangeAmount = 0.0f;
		float exchangeAmount2 = 0.0f;

		if (code1 == "USD") {

			exchangeAmount = amount * currency2.Rate();

			cout << "\nConvert From USD To:\n" << clsInput::Format(25, "_") << '\n';
			_PrintCountryCard(currency2);

			cout << '\n' << amount << code1 << " = " << exchangeAmount << code2;



		}
		else if (code2 == "USD") {

			exchangeAmount = amount / currency1.Rate();

			cout << "\nConvert From:\n" << clsInput::Format(25, "_") << '\n';
			_PrintCountryCard(currency1);

			cout << '\n' << amount << code2 << " = " << exchangeAmount << code1;


		}
		else {

			exchangeAmount = amount / currency1.Rate();

			cout << "\nConvert From:\n" << clsInput::Format(25, "_") << '\n';
			_PrintCountryCard(currency1);

			cout << '\n' << amount << code2 << " = " << exchangeAmount << code1;

			exchangeAmount2 = exchangeAmount * currency2.Rate();

			cout << "\nConvert From USD To:\n" << clsInput::Format(25, "_") << '\n';
			_PrintCountryCard(currency2);

			cout << '\n' << exchangeAmount << "USD" << " = " << exchangeAmount2 << code2;


		}

	}


};

