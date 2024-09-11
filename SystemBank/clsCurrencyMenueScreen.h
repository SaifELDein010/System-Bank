#pragma once

#include <iostream>
#include <string>
#include "clsCurrency.h"
#include "clsInput.h"
#include "clsScreen.h"
#include "clsListCurrenices.h"
#include "clsFindCurrency.h"
#include "clsUpdateRate.h"
#include "clsCurrencyCalculator.h"

using namespace std;


class clsCurrencyMenueScreen : protected clsScreen {

private:

	enum _enCurrencyExchangeMenueOption
	{
		enListCurrenices = 1, enFindCurrency = 2, enUpdateRate = 3, enCurrencyCalculator = 4, enMainMenue = 5,
	};

	static void _Restert() {

		system("color F");
		system("cls");

	}

	static void _GoBack(string message) {

		cout << message;
		system("Pause>0");
		_Restert();
		CurrencyExchangeMenueScreen();

	}

	static short _ReadNumberOfOption() {

		cout << clsInput::Format(5, "\t");
		short num = clsInput::ReadNumber("Choose what do you want to do?[1To5] ", 1, 5);
		return num;

	}


	static void _ShowListCurrenicesScreen() {

		//cout << "\nList Currenices screen will be here...\n";
		clsListCurrenices::ShowClientList();

	}

	static void _ShowFindCurrencyScreen() {

		//cout << "\nFind Currency screen will be here...\n";
		clsFindCurrency::ShowFindCountry();

	}

	static void _ShowUpdateRateScreen() {

		//cout << "\nUpdate Rate screen will be here...\n";
		clsUpdateRate::ShowUpdateCurrencyRate();

	}

	static void _ShowCurrencyCalculatorScreen() {

		//cout << "\nCurrency Calculator screen will be here...\n";
		clsCurrencyCalculator::ShowCurrencyCalculator();

	}



	static void _PerfromMainMenueOption(_enCurrencyExchangeMenueOption CurrencyExchangeMenueOption) {

		switch (CurrencyExchangeMenueOption)
		{

		case clsCurrencyMenueScreen::enListCurrenices:
			_Restert();
			_ShowListCurrenicesScreen();
			_GoBack("\n\n Press any key to go back to Currency Exchange menue...");
			break;


		case clsCurrencyMenueScreen::enFindCurrency:
			_Restert();
			_ShowFindCurrencyScreen();
			_GoBack("\n\n Press any key to go back to Currency Exchange menue...");
			break;


		case clsCurrencyMenueScreen::enUpdateRate:
			_Restert();
			_ShowUpdateRateScreen();
			_GoBack("\n\n Press any key to go back to Currency Exchange menue...");
			break;


		case clsCurrencyMenueScreen::enCurrencyCalculator:
			_Restert();
			_ShowCurrencyCalculatorScreen();
			_GoBack("\n\n Press any key to go back to Currency Exchange menue...");
			break;


		case clsCurrencyMenueScreen::enMainMenue:
			break;


		
		}
	
	}


public:

	static void CurrencyExchangeMenueScreen() {

		_Restert();
		ScreenHeader("\t Currency Exchange menue");

		cout << '\n' << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';
		cout << clsInput::Format(5, "\t") << clsInput::Format(9, " ") << "Currency Exchange menue\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';

		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[1] List Currenices\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[2] Find Currency\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[3] Update Rate\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[4] Currency Calculator\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[5] Main menue\n";

		cout << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';

		_PerfromMainMenueOption((_enCurrencyExchangeMenueOption)_ReadNumberOfOption());

	}



};

